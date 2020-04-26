#pragma once
#include "allegro5/allegro.h"

class Table
{

public:
	struct element {
		bool enable=false;
		ALLEGRO_COLOR color;
	};
	int points;
	element table[10][11];
	void print();
	void check(int speed);
	void delete_line(int x);
};

