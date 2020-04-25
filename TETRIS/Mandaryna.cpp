#include "Mandaryna.h"
#include "start.h"
#include "Settings.h"
#include "allegro5/allegro.h"
#include"allegro5/allegro_font.h"
#include"allegro5/allegro_ttf.h"
#include"allegro5/allegro_primitives.h"
#include "Table.h"
#include<iostream>


void Mandaryna::draw(float &x, float y,int direction) // switch
{
    if (direction == 1) {
        if (x + 100 >= 600)
            x -= 50;
        al_draw_filled_rectangle(x, y, x + 50, y + 50, this->color);
        al_draw_filled_rectangle(x + 50, y, x + 100, y + 50, this->color);
        al_draw_filled_rectangle(x + 50, y + 50, x + 100, y+100 , this->color);
        al_draw_filled_rectangle(x + 100, y, x + 150, y + 50, this->color);

    }

    if (direction == 2) {
        al_draw_filled_rectangle(x, y, x + 50, y + 50, this->color);
        al_draw_filled_rectangle(x, y + 50, x + 50, y + 100, this->color);
        al_draw_filled_rectangle(x, y + 100, x + 50, y + 150, this->color);
        al_draw_filled_rectangle(x+50 , y+50, x + 100, y + 100, this->color);
    }

    if (direction == 3) {
        if (x + 100 >= 600)
            x -= 50;
        al_draw_filled_rectangle(x, y, x + 50, y + 50, this->color);

        al_draw_filled_rectangle(x+50, y , x+100, y + 50, this->color);
        al_draw_filled_rectangle(x +100, y, x+150, y+50 , this->color);
        al_draw_filled_rectangle(x+50, y -50, x + 100, y , this->color);
    }

    if (direction == 4) {
        al_draw_filled_rectangle(x, y, x + 50, y + 50, this->color);

        al_draw_filled_rectangle(x+50 , y, x +100, y + 50, this->color);
        al_draw_filled_rectangle(x+50 , y-50, x+100 , y , this->color);
        al_draw_filled_rectangle(x +50, y + 50, x+100, y + 100, this->color);
    }
}


bool Mandaryna::checkright(float x, float y, int direction) // true kiedy moge
{
    if (direction == 1 or direction ==3) {
        if (x + 150 >= 600)
            return false;
        else
            return true;
    }
    if (direction == 2 or direction == 4) {
        if (x + 100 >= 600)
            return false;
        else
            return true;
    }

}

bool Mandaryna::checkdown(float x, float y, int direction, Table::element table[10][11]) // true jesli cos jest 
{
    int a,b;
    a= (int)((x-100) / 50) ;
    b = (int)((y-150) / 50);
    if (direction == 1) {
        if (table[a][b].enable == true or table[a + 1][b].enable == true or table[a + 2][b].enable == true or table[a + 1][b + 1].enable == true or y == 650)
            return true;
        else
            return false;

    }
    if (direction == 2) {
        if (table[a][b].enable == true or table[a][b+1].enable == true or table[a][b+2].enable == true or table[a + 1][b + 1].enable == true or y==600)
            return true;
        else
            return false;
    }

    if (direction == 3) {
        if (table[a][b].enable == true or table[a + 1][b].enable == true or table[a + 2][b].enable == true or table[a][b - 1].enable == true or y == 700)
            return true;
        else
            return false;
    }

    if (direction == 4) {
        if (table[a][b].enable == true or table[a + 1][b].enable == true or table[a + 1][b-1].enable == true or table[a + 1][b + 1].enable == true or y == 650)
            return true;
        else
            return false;
    }

}

void Mandaryna::save(float x, float y, int direction, Table::element table[10][11])
{
    int a, b;
    a = (int)((x - 100) / 50);
    b = (int)((y - 150) / 50) -1;

    if (direction == 1) {
        table[a][b].enable = true;         // ustawianie czy jest zajête
        table[a + 1][b].enable = true;
        table[a + 2][b].enable = true;
        table[a + 1][b + 1].enable = true; 

        table[a][b].color=this->color;      //ustawianie koloru
        table[a + 1][b].color = this->color;
        table[a + 2][b].color = this->color;
        table[a + 1][b + 1].color = this->color;
    }
    if (direction == 2) {
        table[a][b].enable = true;      // ustawianie czy jest zajête
        table[a][b + 1].enable = true;
        table[a][b + 2].enable = true;
        table[a + 1][b + 1].enable = true;

        table[a][b].color = this->color;       //ustawianie koloru
        table[a][b + 1].color = this->color;
        table[a][b + 2].color = this->color;
        table[a + 1][b + 1].color = this->color;

    }

    if (direction == 3) {
        table[a][b].enable = true;      // ustawianie czy jest zajête
        table[a + 1][b].enable = true;
        table[a + 2][b].enable = true;
        table[a+1][b - 1].enable = true;

        table[a][b].color = this->color;        //ustawianie koloru
        table[a + 1][b].color = this->color;
        table[a + 2][b].color = this->color;
        table[a+1][b - 1].color = this->color;

    }

    if (direction == 4) {
        table[a][b].enable = true;      // ustawianie czy jest zajête
        table[a + 1][b].enable = true;
        table[a + 1][b - 1].enable = true;
        table[a + 1][b + 1].enable = true;

        table[a][b].color = this->color;         //ustawianie koloru
        table[a + 1][b].color = this->color;
        table[a + 1][b - 1].color = this->color;
        table[a + 1][b + 1].color = this->color;
    } 
}



