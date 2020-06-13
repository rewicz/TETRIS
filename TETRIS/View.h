#pragma once
#include "Graphics.h"
#include "Start.h"
#include "Game.h"
#include "End.h"
#include "Settings.h"
#include "Configuration.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <stdexcept>
#include "NewException.h"

class View
{
	Graphics graphics;
	Configuration configuration;

	Start start;
	Settings settings;
	Game game;
public:
	void view();
};

