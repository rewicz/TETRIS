#include "View.h"
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

void View::view()
{
	//try
	al_init();

	Graphics graphics;
	Configuration configuration;


	ALLEGRO_DISPLAY* display=al_create_display(1280, 800);
	Settings settings;


	Start start;
	Game game;
	End end;

	if (start.start(display, graphics))
		// fast end
		return;
	//try
	do {
		if (settings.start(display, graphics, configuration))
			return;
	} while (game.start(display, graphics, configuration));
	



}
