#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_image.h"
#include "Jablko.h"
#include "Pomarancza.h"
#include "Marchewka.h"
#include "Mandaryna.h"
#include <string>

class Graphics{
	
public:

	void print_text(ALLEGRO_FONT* font,int x, int y, ALLEGRO_COLOR color, std::string text);
	void print_button(ALLEGRO_FONT* font, int x, int y, ALLEGRO_COLOR color, std::string text,ALLEGRO_BITMAP* bitmap);



};

