

#include <iostream>
#include"allegro5/allegro.h"
#include"allegro5/allegro_native_dialog.h"
#include"allegro5/allegro_font.h"
#include"allegro5/allegro_ttf.h"
#include"allegro5/allegro_primitives.h"

/*
int main(int argc, char** argv)
{
    al_init();
    ALLEGRO_DISPLAY* display;
    display = al_create_display(800, 600);
    al_set_window_title(display, "TETRIS");

    enum DIRECTION { DOWN, UP, LEFT, RIGHT };


    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT* font = al_load_font("Silicone.ttf", 45, NULL);
    al_draw_text(font, al_map_rgb(255, 255, 144), 400, 300, ALLEGRO_ALIGN_CENTER, "HELLO");


    //    WYPSUZCZAM NA ZEWNATRZ
    //    al_flip_display();
    //    int value=al_show_native_message_box(display, "Message title","Error", "display window test", NULL, ALLEGRO_MESSAGEBOX_ERROR);


    al_init_primitives_addon();

    al_draw_rounded_rectangle(10, 10, 100, 100, 10, 10, al_map_rgb(255, 255, 0), 7.0);

    //    al_draw_filled_rounded_rectangle(10, 10, 100, 100, 10, 10, al_map_rgb(255, 255, 0));  wypelnione

    al_draw_circle(500, 500, 20, al_map_rgb(255, 255, 0), 3);


    al_flip_display();
    al_rest(3.0f);



    al_install_keyboard();

    const float FPS = 60;

    ALLEGRO_TIMER* timer = al_create_timer(1 / FPS);

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));


    bool done = false, draw = true;
    int x = 100, y = 100, movespeed = 1;
    int dir = DOWN;

    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_start_timer(timer);
    //while (!done) {
    //    //game events
    //    ALLEGRO_EVENT events;
    //    al_wait_for_event(event_queue, &events);
    //    if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
    //        switch (events.keyboard.keycode) {

    //        case ALLEGRO_KEY_DOWN:
    //            y += movespeed;
    //            break;
    //        case ALLEGRO_KEY_UP:
    //            x += movespeed;
    //            break;
    //        case ALLEGRO_KEY_ESCAPE:
    //            done = true;
    //            break;
    //        }
    //    }
    //    al_draw_filled_rectangle(x, y, x + 50, y + 50, al_map_rgb(255, 43, 89));
    //    al_flip_display();
    //    al_clear_to_color(al_map_rgb(0, 0, 0));

    //}


    while (!done) {
        //game events
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (events.keyboard.keycode) {
            case ALLEGRO_KEY_DOWN:
                dir = DOWN;
                break;
            case ALLEGRO_KEY_UP:
                dir = RIGHT;
                break;
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            }
        }

        if (events.type == ALLEGRO_EVENT_TIMER) {
            switch (dir) {
            case DOWN:
                x += movespeed;
                break;
            case RIGHT:
                y += movespeed;
                break;
            }
            draw = true;
        }
        if (draw) {
            draw = false;
            al_draw_filled_rectangle(x, y, x + 50, y + 50, al_map_rgb(255, 43, 89));
            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
        }
    }


    al_rest(3.0f);
    al_destroy_font(font);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    return 0;
}
*/
