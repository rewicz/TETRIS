#pragma once
#include "allegro5/allegro.h"
#include "Mandaryna.h"
#include "Figures.h"

class Game{

	Mandaryna mandaryna;
	//more
	Figures* figures;
	void set_new_figure();
	void set_new_color();
public:
	void start();

};
