#pragma once
#include "allegro5/allegro.h"
#include "Graphics.h"
#include "Table.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_image.h"
#include "NewException.h"

class End 
{
public:
	bool start(ALLEGRO_DISPLAY* display, int points, Graphics graphics);

};

