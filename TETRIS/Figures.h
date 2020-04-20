#pragma once
#include "Table.h"
#include "allegro5/allegro.h"

class Figures
{	 
public:
	ALLEGRO_COLOR color;
	virtual void draw(float x, float y,int direcion) = 0;
	virtual bool checkleft(float x, float y, int direction) = 0;
	virtual bool checkright(float x, float y, int direction) = 0;
	virtual bool checkdown(float x, float y, int direction, Table::element table[10][11]) = 0;
	virtual void save(float x, float y, int direction, Table::element  table[10][11])=0;
};

