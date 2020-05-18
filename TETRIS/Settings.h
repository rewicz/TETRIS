
#include "Graphics.h"
#include "Configuration.h"
#include "allegro5/allegro.h"
#include"allegro5/allegro_font.h"
#include"allegro5/allegro_ttf.h"
#include <iostream>

class Settings{
private:
	Configuration conf;
public:
	bool start(ALLEGRO_DISPLAY* display, Graphics graphics,Configuration &configuration);
};
