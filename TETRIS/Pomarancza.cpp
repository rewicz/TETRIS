#include "Pomarancza.h"

void Pomarancza::draw(float& x, float y, int direction)
{
    if (direction == 1) {
        if (x + 100 >= 600)
            x -= 50;
        draw_square(x, y);
        draw_square(x + 50, y);
        draw_square(x + 100, y + 50);
        draw_square(x + 100, y);

    }

    if (direction == 2) {
        draw_square(x, y);
        draw_square(x , y+ 50);
        draw_square(x, y - 50);
        draw_square(x + 50, y - 50);
    }

    if (direction == 3) {
        if (x + 100 >= 600)
            x -= 50;
        draw_square(x, y);
        draw_square(x + 50, y + 50);
        draw_square(x + 100, y + 50);
        draw_square(x, y+50);
    }

    if (direction == 4) {
        draw_square(x, y+50);
        draw_square(x + 50, y);
        draw_square(x + 50, y - 50);
        draw_square(x + 50, y + 50);

    }

}

bool Pomarancza::checkright(float x, float y, int direction)
{
    if (direction == 1 or direction == 3) {
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

bool Pomarancza::checkdown(float x, float y, int direction, Table::element table[10][11])
{
    int a, b;
    a = (int)((x - 100) / 50);
    b = (int)((y - 150) / 50);
    if (direction == 1) {
        if (table[a][b].enable == true or table[a + 1][b].enable == true or table[a + 2][b].enable == true or table[a + 2][b + 1].enable == true or y == 650)
            return true;
        else
            return false;

    }
    if (direction == 2) {
        if (table[a][b].enable == true or table[a][b + 1].enable == true or table[a][b -1].enable == true or table[a + 1][b - 1].enable == true or y == 650)
            return true;
        else
            return false;
    }

    if (direction == 3) {
        if (table[a][b].enable == true or table[a + 1][b+1].enable == true or table[a + 2][b+1].enable == true or table[a][b + 1].enable == true or y == 650)
            return true;
        else
            return false;
    }

    if (direction == 4) {
        if (table[a][b+1].enable == true or table[a + 1][b].enable == true or table[a + 1][b - 1].enable == true or table[a + 1][b + 1].enable == true or y == 650)
            return true;
        else
            return false;
    }
}

void Pomarancza::save(float x, float y, int direction, Table::element table[10][11])
{
    int a, b;
    a = (int)((x - 100) / 50);
    b = (int)((y - 150) / 50) - 1;

    if (direction == 1) {
        table[a][b].enable = true; 
        table[a + 1][b].enable = true;
        table[a + 2][b].enable = true;
        table[a + 2][b + 1].enable = true;

        table[a][b].color = this->color;      //ustawianie koloru
        table[a + 1][b].color = this->color;
        table[a + 2][b].color = this->color;
        table[a + 2][b + 1].color = this->color;
    }
    if (direction == 2) {
        table[a][b].enable = true;            // czy istnieje
        table[a][b + 1].enable = true;
        table[a][b - 1].enable = true;
        table[a + 1][b - 1].enable = true;

        table[a][b].color = this->color;      //ustawianie koloru
        table[a][b + 1].color = this->color;
        table[a][b - 1].color = this->color;
        table[a + 1][b - 1].color = this->color;

    }

    if (direction == 3) {
        table[a][b].enable = true;      // ustawianie czy jest zajête
        table[a + 1][b + 1].enable = true;
        table[a + 2][b + 1].enable = true;
        table[a][b + 1].enable = true;

        table[a][b].color = this->color;        //ustawianie koloru
        table[a + 1][b + 1].color = this->color;
        table[a + 2][b + 1].color = this->color;
        table[a][b + 1].color = this->color;

    }

    if (direction == 4) {
        table[a][b + 1].enable = true;      // ustawianie czy jest zajête
        table[a + 1][b].enable = true;
        table[a + 1][b - 1].enable = true;
        table[a + 1][b + 1].enable = true;

        table[a][b + 1].color = this->color;         //ustawianie koloru
        table[a + 1][b].color = this->color;
        table[a + 1][b - 1].color = this->color;
        table[a + 1][b + 1].color = this->color;
    }
}
