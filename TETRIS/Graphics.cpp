#include "Graphics.h"
#include <iostream>




void Graphics::print_text(ALLEGRO_FONT* font,int x, int y, ALLEGRO_COLOR color, std::string text)
{
    al_draw_text(font, color, x, y, ALLEGRO_ALIGN_CENTER, text.c_str());
}

void Graphics::print_button(ALLEGRO_FONT* font, int x, int y, ALLEGRO_COLOR color, std::string text, ALLEGRO_BITMAP* bitmap)
{    
    al_draw_bitmap(bitmap, x, y, 0);
    print_text(font, x+80, y+25, color, text);
    
}






