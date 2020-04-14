#include "start.h"
#include "Settings.h"
#include "allegro5/allegro.h"
#include"allegro5/allegro_font.h"
#include"allegro5/allegro_ttf.h"
#include <iostream>

void Start::view()
{
    Settings settings;
    ALLEGRO_DISPLAY* display;
    display = al_create_display(1280, 800);
    al_set_window_title(display, "TETRIS");

    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT* font_title = al_load_font("Silicone.ttf", 60, NULL);
    ALLEGRO_FONT* font_signature = al_load_font("AveBetwan_PERSONAL_USE.ttf", 30, NULL);
    al_draw_text(font_title, al_map_rgb(255, 255, 0), 640, 150, ALLEGRO_ALIGN_CENTER, "TETRIS");
    al_draw_text(font_signature, al_map_rgb(255, 255, 0), 1000, 500, ALLEGRO_ALIGN_CENTER, "Blazej Rakwic");
    al_flip_display();
    al_rest(3.0f);
    al_draw_text(font_signature, al_map_rgb(255, 255, 0), 640, 400, ALLEGRO_ALIGN_CENTER, "Press enter to continue");
    al_flip_display();


    al_install_keyboard();
    bool done = false, draw = true;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));

    while (!done) {

        ALLEGRO_EVENT events;      
        al_wait_for_event(event_queue, &events); 
        if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (events.keyboard.keycode) {
            case ALLEGRO_KEY_ENTER:
                settings.view();
                done = true;
                break;
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            }
        }
        else if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            done = true;

    }

    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_text(font_signature, al_map_rgb(255, 255, 0), 640, 400, ALLEGRO_ALIGN_CENTER, "BY");
    al_flip_display();
    al_rest(3.0f);

    al_destroy_font(font_title);
    al_destroy_font(font_signature);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
}
