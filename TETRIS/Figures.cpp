#include "Figures.h"

void Figures::draw_square(float x, float y)
{
    al_init_primitives_addon();
	ALLEGRO_BITMAP* square = al_load_bitmap("square.png");
    al_draw_filled_rectangle(x , y, x+ 50, y  + 50,color);
    al_draw_bitmap(square, x , y , 0);
    al_draw_rectangle(x , y, x +50, y + 50, al_map_rgb(29, 29, 29), 3);
}
