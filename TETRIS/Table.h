#pragma once
#include "allegro5/allegro.h"

class Table
{

public:
	struct element {
		bool enable=false;
		ALLEGRO_COLOR color;
	};
	int points=0;

	element table[10][11];
	void print();
	void check();
	void delete_line(int x);
};

