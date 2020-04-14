
#include "Settings.h"
#include "Game.h"
#include "allegro5/allegro.h"
#include"allegro5/allegro_font.h"
#include"allegro5/allegro_ttf.h"
#include <iostream>



void Settings::view()
{
    Game game;

    al_clear_to_color(al_map_rgb(0, 0, 0));

    ALLEGRO_FONT* font = al_load_font("Silicone.ttf", 60, NULL);

    al_draw_text(font, al_map_rgb(255, 255, 0), 640, 150, ALLEGRO_ALIGN_CENTER, "START");

    al_flip_display();


    al_install_keyboard();
    bool done = false, draw = true;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());



    while (!done) {

        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (events.keyboard.keycode) {
            case ALLEGRO_KEY_ENTER:
                //      game.view;
                break;
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            }
        }

    }
    al_destroy_font(font);
}
