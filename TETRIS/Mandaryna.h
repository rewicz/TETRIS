#pragma once
#include "Figures.h"
class Mandaryna :
	public Figures
{
public:

	void draw(float x, float y,int direction);
	bool checkleft(float x, float y, int direction);
	bool checkright(float x, float y, int direction);
	bool checkdown(float x, float y, int direction, bool table[10][11]);
	void save(float x, float y, int direction, bool table[10][11]);
};

