#pragma once
#include "Graphics.h"
#include "Configuration.h"
#include "allegro5/allegro.h"
#include"allegro5/allegro_font.h"
#include"allegro5/allegro_ttf.h"
#include "allegro5/allegro_image.h"
#include "NewException.h"

#include "Table.h"
#include "Game.h"
#include "Figures.h"

class Settings{
	Configuration conf;
public:
	bool start(ALLEGRO_DISPLAY* display, Graphics graphics,Configuration &configuration);
};
