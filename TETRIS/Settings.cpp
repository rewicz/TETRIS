
#include "Settings.h"




bool Settings::start(ALLEGRO_DISPLAY* display, Graphics graphics,Configuration &configuration)
{    
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_install_mouse();
    
    ALLEGRO_FONT* font = al_load_font("Silicone.ttf", 45, NULL);
    ALLEGRO_FONT* font_signature = al_load_font("AveBetwan_PERSONAL_USE.ttf", 30, NULL);
    ALLEGRO_FONT* font_roboto_black = al_load_font("Roboto-black.ttf",35,NULL);

    ALLEGRO_FONT* font_roboto_black_button = al_load_font("Roboto-black.ttf", 25, NULL);
    if (!font_roboto_black)
        throw (NewException("Roboto-black.ttf"));

    ALLEGRO_BITMAP* orange_button = al_load_bitmap("orange_button.png");
    if (!orange_button)
        throw (NewException("orange_button.png"));

    ALLEGRO_BITMAP* red_button = al_load_bitmap("red_button.png");
    if (!red_button)
        throw (NewException("red_button.png"));

    ALLEGRO_BITMAP* background = al_load_bitmap("settings.png");
    if (!background)
        throw (NewException("settings.png"));

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    ALLEGRO_COLOR yellow = al_map_rgb(255, 255, 0);

    ALLEGRO_EVENT events;




    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    

    bool done = false, draw = true, key_escape=false;

    int mouse_x, mouse_y,click_x,click_y;

    while (!done) {
        al_wait_for_event(event_queue, &events);
        if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (events.keyboard.keycode) {
            case ALLEGRO_KEY_ENTER:
                configuration = conf;
                done = true;
                break;
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                key_escape = true;
                break;
            }
        }

        else if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { //hard exit
            key_escape = true;
            done = true;  
        }

        else  if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
            mouse_x = events.mouse.x;
            mouse_y = events.mouse.y;
        }

        else if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (events.mouse.button & 1)
            {
                click_x = events.mouse.x;
                click_y = events.mouse.y;
                if (click_x > 240 and click_x < 400 and click_y>200 and click_y < 280)//easy
                    conf.level = 1;

                else if (click_x > 560 and click_x < 720 and click_y>200 and click_y < 280)//normal
                    conf.level = 2;

                else if (click_x > 880 and click_x < 1040 and click_y>200 and click_y < 280)//hard
                    conf.level = 5;

                else if (click_x > 176 and click_x < 336 and click_y>400 and click_y < 480)//one
                    conf.objects = 1;

                else if (click_x > 432 and click_x < 592 and click_y>400 and click_y < 480)//two
                    conf.objects = 2;

                else if (click_x > 688 and click_x < 848 and click_y>400 and click_y < 480)//three
                    conf.objects = 3;

                else if (click_x > 944 and click_x < 1104 and click_y>400 and click_y < 480)//four
                    conf.objects = 4;

                else if (click_x > 346 and click_x < 506 and click_y>600 and click_y < 680)//yes
                    conf.turtotial = false;

                else if (click_x > 773 and click_x < 933 and click_y>600 and click_y < 680)//no
                    conf.turtotial = true;
            }
        }
       
        if (draw) {

            al_draw_bitmap(background, 0, 0, 0);
            graphics.print_text(font, 640, 50, yellow, "SETTINGS");

            graphics.print_text(font_roboto_black, 640, 150, yellow, "LEVEL");
            if (conf.level == 1) {
                graphics.print_button(font_roboto_black_button, 320 - 80, 200, yellow, "EASY", red_button);
                graphics.print_button(font_roboto_black_button, 640 - 80, 200, yellow, "NORMAL", orange_button);
                graphics.print_button(font_roboto_black_button, 960 - 80, 200, yellow, "HARD", orange_button);
            }
            else if (conf.level == 2) {
                graphics.print_button(font_roboto_black_button, 320 - 80, 200, yellow, "EASY", orange_button);
                graphics.print_button(font_roboto_black_button, 640 - 80, 200, yellow, "NORMAL", red_button);
                graphics.print_button(font_roboto_black_button, 960 - 80, 200, yellow, "HARD", orange_button);
            }
            else if (conf.level == 5) {
                graphics.print_button(font_roboto_black_button, 320 - 80, 200, yellow, "EASY", orange_button);
                graphics.print_button(font_roboto_black_button, 640 - 80, 200, yellow, "NORMAL", orange_button);
                graphics.print_button(font_roboto_black_button, 960 - 80, 200, yellow, "HARD", red_button);
            }

            graphics.print_text(font_roboto_black, 640, 350, yellow, "OBJECTS");

            if (conf.objects == 1) {
                graphics.print_button(font_roboto_black_button, 256 - 80, 400, yellow, "ONE", red_button);
                graphics.print_button(font_roboto_black_button, 512 - 80, 400, yellow, "TWO", orange_button);
                graphics.print_button(font_roboto_black_button, 768 - 80, 400, yellow, "THREE", orange_button);
                graphics.print_button(font_roboto_black_button, 1024 - 80, 400, yellow, "FOUR", orange_button);
            }
            else if (conf.objects == 2) {
                graphics.print_button(font_roboto_black_button, 256 - 80, 400, yellow, "ONE", orange_button);
                graphics.print_button(font_roboto_black_button, 512 - 80, 400, yellow, "TWO", red_button);
                graphics.print_button(font_roboto_black_button, 768 - 80, 400, yellow, "THREE", orange_button);
                graphics.print_button(font_roboto_black_button, 1024 - 80, 400, yellow, "FOUR", orange_button);
            } 
            else if (conf.objects == 3) {
                graphics.print_button(font_roboto_black_button, 256 - 80, 400, yellow, "ONE", orange_button);
                graphics.print_button(font_roboto_black_button, 512 - 80, 400, yellow, "TWO", orange_button);
                graphics.print_button(font_roboto_black_button, 768 - 80, 400, yellow, "THREE", red_button);
                graphics.print_button(font_roboto_black_button, 1024 - 80, 400, yellow, "FOUR", orange_button);
            }
            else if (conf.objects == 4) {
                graphics.print_button(font_roboto_black_button, 256 - 80, 400, yellow, "ONE", orange_button);
                graphics.print_button(font_roboto_black_button, 512 - 80, 400, yellow, "TWO", orange_button);
                graphics.print_button(font_roboto_black_button, 768 - 80, 400, yellow, "THREE", orange_button);
                graphics.print_button(font_roboto_black_button, 1024 - 80, 400, yellow, "FOUR", red_button);
            }


            graphics.print_text(font_roboto_black, 640, 550, yellow, "TURTORIAL");

            if (conf.turtotial) {
                graphics.print_button(font_roboto_black_button, 426 - 80, 600, yellow, "YES", orange_button);
                graphics.print_button(font_roboto_black_button, 853 - 80, 600, yellow, "NO", red_button);
            }
            if (!conf.turtotial) {
                graphics.print_button(font_roboto_black_button, 426 - 80, 600, yellow, "NO", red_button);
                graphics.print_button(font_roboto_black_button, 853 - 80, 600, yellow, "YES", orange_button);
            }
            
            graphics.print_text(font_signature, 640, 700, yellow, "Press ENTER to continue");
            al_flip_display();
        }


    }

    al_destroy_font(font);
    al_destroy_font(font_signature);
    al_destroy_font(font_roboto_black);
    al_destroy_font(font_roboto_black_button);

    al_destroy_bitmap(orange_button);
    al_destroy_bitmap(red_button);
    al_destroy_bitmap(background);

    al_destroy_event_queue(event_queue);
    
    
    return key_escape;


}
