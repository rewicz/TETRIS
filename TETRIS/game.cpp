
#include "Game.h"
#include "Figures.h"
#include "Mandaryna.h"
#include "start.h"
#include "Settings.h"
#include "allegro5/allegro.h"
#include"allegro5/allegro_font.h"
#include"allegro5/allegro_ttf.h"
#include"allegro5/allegro_primitives.h"
#include <iostream>

void Game::start()
{
    bool table[10][11] = {};
    al_init();
    ALLEGRO_DISPLAY* display;
    display = al_create_display(1280, 800);
    al_set_window_title(display, "TETRIS");

    enum DIRECTION { DOWN, UP, LEFT, RIGHT };


    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT* font = al_load_font("Silicone.ttf", 45, NULL);

    al_init_primitives_addon();

   



    al_flip_display();
    al_rest(3.0f);



    al_install_keyboard();

    const float FPS = 60;

    ALLEGRO_TIMER* timer = al_create_timer(1 / FPS);

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));


    bool done = false, draw = true, done2=false;
    float x = 300, y = 150, movespeed = 1, end=250;
    int direction = 1;
    Mandaryna mandaryna;

    Figures *figures=&mandaryna;


    al_clear_to_color(al_map_rgb(0, 0, 0));


    al_start_timer(timer);
    while (!done) {

        //new element
        x = 300;
        y = 150;
        end = 250;
        
        done2 = false;
        while(!done2) {
            //game events
            ALLEGRO_EVENT events;
            al_wait_for_event(event_queue, &events);
            if (events.type == ALLEGRO_EVENT_KEY_DOWN) { // turn
                switch (events.keyboard.keycode) {
                case ALLEGRO_KEY_A:   // turn left
                    direction +=1;
                    break; 

                case ALLEGRO_KEY_S: //turn right
                    direction -= 1;

                    break;

                case ALLEGRO_KEY_LEFT:
                    if (!(x <= 100))
                        x -= 50;
                    break;

                case ALLEGRO_KEY_RIGHT:
                    if (figures->checkright(x,y,direction))
                        x += 50;
                    break;

                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
                }
                if (direction == 5)
                    direction = 1;
                if (direction == 0)
                    direction = 4;

            }

            if (events.type == ALLEGRO_EVENT_TIMER) {
                y += movespeed;
                end += movespeed;               
                draw = true;
            }
            if ((int)y % 50 == 0)//sprawdzenie stykow podzielne przez 50
            {
                std::cout << "chuj";
                if (figures->checkdown(x + 50, y + 50, direction, table)) {
                    figures->save(x, y, direction, table);
                    for (int i = 0; i < 10; i++)
                        for (int j = 0; j < 11; j++)
                            if (table[i][j])
                               al_draw_filled_rectangle((float)i*50+100, j*50+150, i * 50 + 150, j * 50 + 200, al_map_rgb(255, 255, 255));
                    al_flip_display();
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    done2 = true;
                    draw = false;
                }
                if (y == 700) {
                    figures->save(x, y, direction, table);
                    for (int i = 0; i < 10; i++)
                        for (int j = 0; j < 11; j++)
                            if (table[i][j]) {
                                std::cout << "drugi chuj";
                                al_draw_filled_rectangle((float)i * 50 + 100, j * 50 + 150, i * 50 + 150, j * 50 + 200, al_map_rgb(255, 255, 255));
                            }
                                
                    al_flip_display();
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    done2 = true;
                    draw = false;
                }

            }


            if (draw) {
                draw = false;
                al_draw_rectangle(97, 147, 597, 697, al_map_rgb(255, 255, 0), 3);

                for (int i = 0; i < 10; i++)
                    for (int j = 0; j < 11; j++)
                        if (table[i][j])
                            al_draw_filled_rectangle((float)i * 50 + 100, j * 50 + 150, i * 50 + 150, j * 50 + 200, al_map_rgb(255, 255, 255));

                figures->draw(x, y,direction);
                al_flip_display();
                al_clear_to_color(al_map_rgb(0, 0, 0));
            }
        }
    }


    al_rest(3.0f);
    al_destroy_font(font);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);



}