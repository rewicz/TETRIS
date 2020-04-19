#include "Mandaryna.h"
#include "start.h"
#include "Settings.h"
#include "allegro5/allegro.h"
#include"allegro5/allegro_font.h"
#include"allegro5/allegro_ttf.h"
#include"allegro5/allegro_primitives.h"
#include<iostream>


void Mandaryna::draw(float x, float y,int direction) // switch
{
    if (direction == 1) {
        if (x + 100 >= 600)
            x -= 50;
        al_draw_filled_rectangle(x, y, x + 50, y + 50, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x + 50, y, x + 100, y + 50, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x + 50, y + 50, x + 100, y+100 , al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x + 100, y, x + 150, y + 50, al_map_rgb(255, 0, 255));

    }

    if (direction == 2) {
        al_draw_filled_rectangle(x, y, x + 50, y + 50, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x, y + 50, x + 50, y + 100, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x, y + 100, x + 50, y + 150, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x+50 , y+50, x + 100, y + 100, al_map_rgb(255, 0, 255));
    }

    if (direction == 3) {
        if (x + 100 >= 600)
            x -= 50;
        al_draw_filled_rectangle(x, y, x + 50, y + 50, al_map_rgb(255, 0, 255));

        al_draw_filled_rectangle(x+50, y , x+100, y + 50, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x +100, y, x+150, y+50 , al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x+50, y -50, x + 100, y , al_map_rgb(255, 0, 255));
    }

    if (direction == 4) {
        al_draw_filled_rectangle(x, y, x + 50, y + 50, al_map_rgb(255, 0, 255));

        al_draw_filled_rectangle(x+50 , y, x +100, y + 50, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x+50 , y-50, x+100 , y , al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x +50, y + 50, x+100, y + 100, al_map_rgb(255, 0, 255));
    }
}

bool Mandaryna::checkleft(float x, float y, int direction)
{
    if (direction == 1) {
        
        x == 100;


    }

    if (direction == 2) {
        al_draw_filled_rectangle(x, y, x + 50, y + 50, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x, y + 50, x + 50, y + 100, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x, y + 100, x + 50, y + 150, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x + 50, y + 50, x + 100, y + 100, al_map_rgb(255, 0, 255));
    }

    if (direction == 3) {
        al_draw_filled_rectangle(x, y, x + 50, y + 50, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x, y + 50, x + 50, y + 100, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x - 50, y + 50, x, y + 100, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x + 50, y + 50, x + 100, y + 100, al_map_rgb(255, 0, 255));
    }

    if (direction == 4) {
        al_draw_filled_rectangle(x, y, x + 50, y + 50, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x, y + 50, x + 50, y + 100, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x, y + 100, x + 50, y + 150, al_map_rgb(255, 0, 255));
        al_draw_filled_rectangle(x - 50, y + 50, x, y + 100, al_map_rgb(255, 0, 255));
    }

    return true;
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

bool Mandaryna::checkdown(float x, float y, int direction, bool table[10][11]) // true jesli cos jest 
{
    int a,b;
    a= (int)((x-100) / 50) ;
    b = (int)((y-150) / 50);
    if (direction == 1) {
        if (table[a][b] == true or table[a + 1][b] == true or table[a + 2][b] == true or table[a + 1][b + 1] == true or y==650)
            return true;
        else
            return false;

    }
    if (direction == 2) {
        if (table[a][b] == true or table[a][b+1] == true or table[a][b+2] == true or table[a + 1][b + 1] == true or y==600)
            return true;
        else
            return false;
    }

    if (direction == 3) {
        if (table[a][b] == true or table[a + 1][b] == true or table[a + 2][b] == true or table[a][b - 1] == true or y == 700)
            return true;
        else
            return false;
    }

    if (direction == 4) {
        if (table[a][b] == true or table[a + 1][b] == true or table[a + 1][b-1] == true or table[a + 1][b + 1] == true or y == 650)
            return true;
        else
            return false;
    }

}

void Mandaryna::save(float x, float y, int direction, bool  table[10][11])
{
    int a, b;
    a = (int)((x - 100) / 50);
    b = (int)((y - 150) / 50) -1;

    std::cout << a << std::endl << b;
    if (direction == 1) {
        table[a][b] = true;
        table[a + 1][b] = true;
        table[a + 2][b] = true;
        table[a + 1][b + 1] = true;
    }
    if (direction == 2) {
        table[a][b] = true;
        table[a][b + 1] = true;
        table[a][b + 2] = true;
        table[a + 1][b + 1] = true;

    }

    if (direction == 3) {
        table[a][b] = true;
        table[a + 1][b] = true;
        table[a + 2][b] = true;
        table[a+1][b - 1] = true;

    }

    if (direction == 4) {
        table[a][b] = true;
        table[a + 1][b] = true;
        table[a + 1][b - 1] = true;
        table[a + 1][b + 1] = true;
    }
    if (table[0][10] == true)
        std::cout << "trzeci chuj";
    
}



