#include "View.h"


void View::view()
{
	ALLEGRO_DISPLAY* display;
	try {
		if (!al_init()) {
			throw std::runtime_error(std::string("Cannot initialize ALLEGRO 5"));
		}
		display = al_create_display(1280, 800);
		if (!display) {
			throw std::runtime_error(std::string("cannot initialize display"));
		}
	}
	catch (std::runtime_error& error) {
		std::cout << "Runtime error: " << error.what();
		return;
	}

	try {
		if (start.start(display, graphics))
			return; // hard exit

		do {
			if (settings.start(display, graphics, configuration))
				return; // hard exit
		} while (game.start(display, graphics, configuration));
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what();
	}
	catch(NewException e){
		std::cout<< e.what();
	}
}
