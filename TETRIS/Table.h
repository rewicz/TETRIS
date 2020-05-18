#pragma once
#include "allegro5/allegro.h"

class Table
{

public:
	struct element {
		bool enable=false;
		ALLEGRO_COLOR color;
	};
	element table[10][11];
	void print();
	void check(int speed, int points);
	void delete_line(int x);
};

