#include "test.h"
#include "Game.h"
#include "Figures.h"
#include "start.h"
#include "Settings.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_image.h"
#include <iostream>
#include <string>
#include "Table.h"

void test::go()
{
	al_init();
	ALLEGRO_DISPLAY* display = al_create_display(1280, 800);


	al_init_font_addon();
	if(al_init_ttf_addon())
		std::cout<<"cos";
	if (al_init_image_addon())
		std::cout << "cos";
	al_init_primitives_addon();

	ALLEGRO_FONT* font = al_load_font("Silicone.ttf", 45, NULL);
	ALLEGRO_FONT* font_signature = al_load_font("AveBetwan_PERSONAL_USE.ttf", 30, NULL);
	ALLEGRO_COLOR yellow = al_map_rgb(255, 255, 0);

	ALLEGRO_BITMAP* smallframe = al_load_bitmap("smallframe.png");


	al_draw_bitmap(smallframe, 700, 20, NULL);

	al_flip_display();
	al_rest(100.0f);

	al_destroy_display(display);
}
