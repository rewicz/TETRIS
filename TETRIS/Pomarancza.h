#pragma once
#include "Figures.h"
#include "Table.h"
#include"allegro5/allegro_primitives.h"

class Pomarancza :
	public Figures
{
public:
	void draw(float &x, float y, int direction);
	bool checkright(float x, float y, int direction);
	bool checkdown(float x, float y, int direction, Table::element table[10][11]);
	void save(float x, float y, int direction, Table::element table[10][11]);

};

