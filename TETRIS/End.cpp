#include "End.h"

bool End::start(ALLEGRO_DISPLAY* display, int points, Graphics graphics)
{
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();

    ALLEGRO_FONT* font_silicone_big = al_load_font("Silicone.ttf", 100, NULL);
    ALLEGRO_FONT* font_silicone = al_load_font("Silicone.ttf", 50, NULL);
    ALLEGRO_FONT* font_roboto_black_button = al_load_font("Roboto-black.ttf", 25, NULL);
    ALLEGRO_COLOR crimson = al_map_rgb(220, 20, 60);
    ALLEGRO_COLOR aquamarine = al_map_rgb(127, 255, 212);

    ALLEGRO_BITMAP* orange_button = al_load_bitmap("orange_button.png");
    ALLEGRO_BITMAP* red_button = al_load_bitmap("red_button.png");
    ALLEGRO_BITMAP* scoreboard = al_load_bitmap("scoreboard.png");

    graphics.print_text(font_silicone_big, 600, 200, crimson, "GAME OVER");
    al_flip_display();
    al_rest(3.0f);
    al_clear_to_color(al_map_rgb(0, 0, 0));


    al_draw_bitmap(scoreboard,190,-200,0);
    graphics.print_text(font_silicone, 600, 200, crimson, "THIS IS THE END");
    
    
    graphics.print_text(font_silicone, 500, 350, crimson, "SCORE : ");
    graphics.print_text(font_silicone, 700, 350, crimson,std::to_string(points));
    graphics.print_button(font_roboto_black_button, 400, 500, aquamarine, "PLAY AGAIN", orange_button);
    graphics.print_button(font_roboto_black_button, 700, 500, aquamarine, "EXIT", orange_button);
    al_flip_display();

    al_install_mouse();

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_mouse_event_source());
    ALLEGRO_EVENT events;

    bool done = false, key_escape;
    int mouse_x, mouse_y, click_x, click_y;

    while (!done) {
        al_wait_for_event(event_queue, &events);
        if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (events.keyboard.keycode) {
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                key_escape = true;
                break;
            }
        }
        else if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            key_escape = true;
            done = true;     //hard exit
        }
        else if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (events.mouse.button & 1)
            {
                click_x = events.mouse.x;
                click_y = events.mouse.y;
                if (click_x > 400 and click_x < 560 and click_y>500 and click_y < 580){ // again
                    done = true;
                    key_escape = false; 
                }

                else if (click_x > 700 and click_x < 860 and click_y>500 and click_y < 580) {  //exit
                    done = true;
                    key_escape = true;
                
                }
            }
        }
    }

    al_clear_to_color(al_map_rgb(0, 0, 0));


	return key_escape;
}
