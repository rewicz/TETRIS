#include "Jablko.h"
#include "start.h"
#include "Settings.h"
#include "allegro5/allegro.h"
#include"allegro5/allegro_font.h"
#include"allegro5/allegro_ttf.h"
#include"allegro5/allegro_primitives.h"
#include "Table.h"
#include<iostream>


void Jablko::draw(float &x, float y, int direction) // switch
{

      if (x + 50 >= 600)
            x -= 50;
      draw_square(x, y);
      draw_square(x + 50, y);
      draw_square(x + 50, y + 50);
      draw_square(x , y + 50);

}


bool Jablko::checkright(float x, float y, int direction) // true kiedy moge
{

        if (x + 100 >= 600)
            return false;
        else
            return true;
    

}

bool Jablko::checkdown(float x, float y, int direction, Table::element table[10][11]) // true jesli cos jest 
{
    int a, b;
    a = (int)((x - 100) / 50);
    b = (int)((y - 150) / 50);

    if (table[a][b].enable == true or table[a + 1][b].enable == true or table[a + 1][b+1].enable == true or table[a ][b + 1].enable == true or y == 650)
            return true;
    else
            return false;


}

void Jablko::save(float x, float y, int direction, Table::element table[10][11])
{
    int a, b;
    a = (int)((x - 100) / 50);
    b = (int)((y - 150) / 50) - 1;

        table[a][b].enable = true;         // ustawianie czy jest zajête
        table[a + 1][b].enable = true;
        table[a][b+1].enable = true;
        table[a + 1][b + 1].enable = true;

        table[a][b].color = this->color;      //ustawianie koloru
        table[a + 1][b].color = this->color;
        table[a ][b+1].color = this->color;
        table[a + 1][b + 1].color = this->color;
  
}



