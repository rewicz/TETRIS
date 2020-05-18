
#include "Table.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

void Table::print()
{
    ALLEGRO_BITMAP* square = al_load_bitmap("square.png");
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 11; j++)
            if (table[i][j].enable) {
                al_draw_filled_rectangle((float)i * 50 + 100, j * 50 + 150, i * 50 + 150, j * 50 + 200, table[i][j].color);
                al_draw_bitmap(square, (float)i * 50 + 100, j * 50 + 150, 0);
                al_draw_rectangle((float)i * 50 + 100, j * 50 + 150, i * 50 + 150, j * 50 + 200, al_map_rgb(29,29,29),3);
            }
}

void Table::check(int speed,int points)
{
    int temp = 0;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 10; j++)
            if (table[j][i].enable)
                temp++;

        if (temp == 10) {
            delete_line(i);
            points += speed;  
        }

        temp = 0;
    }
}

void Table::delete_line(int x)
{
    for (; x != 1; x--)
        for (int j = 0; j < 10; j++)
            table[j][x] = table[j][x - 1];  // obni¿enie o 1

    for (int i = 0; i < 10; i++)       // ostatni wiersz
        table[i][0].enable = false;
}
