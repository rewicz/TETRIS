#pragma once
#include "allegro5/allegro.h"
#include "Mandaryna.h"
#include "Pomarancza.h"
#include "Marchewka.h"
#include "Figures.h"
#include "Jablko.h"

class Game{

	Mandaryna mandaryna;
	Pomarancza pomarancza;
	Marchewka marchewka;
	Jablko jablko;
	//more
	Figures* figures;

	void set_new_figure();
	void set_new_color();
public:
	void start();

};
