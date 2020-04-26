#pragma once
#include "Table.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

class Figures
{	 
public:

	ALLEGRO_COLOR color;

	void draw_square(float x, float y);
	virtual void draw(float &x, float y,int direcion) = 0;
	virtual bool checkright(float x, float y, int direction) = 0;
	virtual bool checkdown(float x, float y, int direction, Table::element table[10][11]) = 0;
	virtual void save(float x, float y, int direction, Table::element  table[10][11])=0;
};

