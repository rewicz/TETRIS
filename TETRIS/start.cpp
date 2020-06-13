#include "start.h"
#include "Settings.h"
#include "Graphics.h"
#include "allegro5/allegro.h"
#include"allegro5/allegro_font.h"
#include"allegro5/allegro_ttf.h"
#include "allegro5/allegro_image.h"
#include"allegro5/allegro_primitives.h"
#include "NewException.h"
#include <iostream>

bool Start::start(ALLEGRO_DISPLAY* display, Graphics graphics)
{
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();

    ALLEGRO_FONT* Silicone = al_load_font("Silicone.ttf", 100, NULL);
    if(!Silicone)
        throw (NewException("Silicone.ttf"));

    ALLEGRO_FONT* AveBetwan = al_load_font("AveBetwan_PERSONAL_USE.ttf", 30, NULL);
    if(!AveBetwan)
        throw NewException("AveBetwan_PERSONAL_USE.ttf");
    ALLEGRO_COLOR yellow = al_map_rgb(255, 255, 0);
    ALLEGRO_COLOR red = al_map_rgb(255, 50, 50);
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);

    ALLEGRO_BITMAP* background = al_load_bitmap("start.png");
    if(!background)
        throw NewException("start.png");

    al_draw_bitmap(background, 0, 0, 0);
    graphics.print_text(Silicone,640, 120, red, "TETRIS");
    graphics.print_text(AveBetwan,1000, 450, white, "Blazej Rakwic");
    al_flip_display();
    al_rest(3.0f);
    graphics.print_text(AveBetwan, 640, 300, yellow, "Press ENTER to continue");

    al_flip_display();

    al_install_keyboard();

    bool done = false, draw = true, key_escape = false;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    ALLEGRO_EVENT events;   

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));

    while (!done) {

        al_wait_for_event(event_queue, &events); 

        if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (events.keyboard.keycode) {
            case ALLEGRO_KEY_ENTER:
                done = true;
                break;
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                key_escape = true;
            }
        }//esle
        else if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
            key_escape = true;
        }
        //migaj¹ce
    }
    return key_escape;
}

