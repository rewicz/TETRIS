#pragma once
#include "allegro5/allegro.h"
#include "Graphics.h"
#include "Mandaryna.h"
#include "Pomarancza.h"
#include "Marchewka.h"
#include "Figures.h"
#include "Jablko.h"
#include "Configuration.h"


class Game{

	Mandaryna mandaryna;
	Pomarancza pomarancza;
	Marchewka marchewka;
	Jablko jablko;
	Figures* figure, *newfigure;
	
	int level = 1, objects = 1 ,points = 0;

	void set_new_figure();
	void set_new_color();
	void set_configuration(Configuration configuration);
public:
	bool start(ALLEGRO_DISPLAY* display, Graphics graphics,Configuration configuration);

};
