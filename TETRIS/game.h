#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_image.h"
#include "Graphics.h"
#include "Figures.h"
#include "Mandaryna.h"
#include "Pomarancza.h"
#include "Marchewka.h"
#include "Figures.h"
#include "Jablko.h"
#include "Configuration.h"
#include "Table.h"
#include "start.h"
#include "End.h"
#include "allegro5/allegro.h"
#include "NewException.h"

#include <map>
#include <string>
#include <random>
#include <chrono>
#include <iostream>

class Game{
	typedef std::multimap<std::string, int> History;
	Mandaryna mandaryna;
	Pomarancza pomarancza;
	Marchewka marchewka;
	Jablko jablko;
	Figures* figure, *newfigure;
	Table table;
	End end;
	History history;

	std::vector< ALLEGRO_COLOR> colors;
	const float FPS = 60;
	int level = 1, objects = 1 ,points = 0;
	void init_colors();
	void set_new_figure();
	void set_new_color();
	void set_configuration(Configuration configuration);
	void show_history();
	void set_base_settings();
public:
	bool start(ALLEGRO_DISPLAY* display, Graphics graphics,Configuration configuration);
};
