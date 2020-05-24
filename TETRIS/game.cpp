
#include "Game.h"
#include "Figures.h"
#include "start.h"
#include "Settings.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_image.h"
#include <iostream>
#include <string>
#include "Table.h"

struct element {
    bool enable;
    ALLEGRO_COLOR color;
};

void Game::set_new_figure()
{
    srand(time(NULL));
    int chosen = rand() % objects+1;
    switch (chosen) {
    case 1:
        newfigure = &jablko;
        break;

    case 2:
        newfigure = &mandaryna;
        break;

    case 3:
        newfigure = &marchewka;
        break;

    case 4:
        newfigure = &pomarancza;
        break;

    }

}

void Game::set_new_color()
{

    srand(time(NULL));

    ALLEGRO_COLOR colors[10] = {    al_map_rgb(255,0,0) , al_map_rgb(255,192,203) ,
                                     al_map_rgb(255,215,0) ,al_map_rgb(255,165,0) ,
                                      al_map_rgb(106,90,205) ,al_map_rgb(255,0,255) ,
                                       al_map_rgb(0,255,0) ,al_map_rgb(102,205,170) ,
                                        al_map_rgb(255,255,240) ,al_map_rgb(112,128,144) ,
    
    };
    int chosen = rand() % 10;

    newfigure->color = colors[chosen];
}
void Game::set_configuration(Configuration conf) {
    level = conf.level;
    objects=conf.objects;
}



bool Game::start(ALLEGRO_DISPLAY *display, Graphics graphics,Configuration configuration)
{
    set_configuration(configuration);
    set_new_figure();
    set_new_color();
    Table table;
    End end;


    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();





    al_install_keyboard();

    const float FPS = 60;

    ALLEGRO_TIMER* timer = al_create_timer(1 / FPS);

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    ALLEGRO_BITMAP* frame = al_load_bitmap("mainframe.png");
    ALLEGRO_BITMAP* background = al_load_bitmap("background.png");
    ALLEGRO_BITMAP* smallframe = al_load_bitmap("smallframe.png");

    ALLEGRO_FONT* font_silicone = al_load_font("Silicone.ttf", 50, NULL);
    ALLEGRO_FONT* font_silicone_small = al_load_font("Silicone.ttf", 35, NULL);

    ALLEGRO_COLOR yellow = al_map_rgb(255, 255, 0);

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));


    bool done = false, draw = true, done2=false,rotate=false,next=false;
    float x = 300, y = 150, endoffigure=250;
    int direction = 1;


    al_clear_to_color(al_map_rgb(0, 0, 0));
    

    al_start_timer(timer);
    while (!done) { 
        figure = newfigure;
        set_new_figure();
        set_new_color();
        direction = 1;

        //new element
        x = 300;
        y = 150;

        done2 = false;
        while(!done2) {
            //game events
            ALLEGRO_EVENT events;     
            al_draw_bitmap(background, 0, 0, 0);
            al_wait_for_event(event_queue, &events);
            if (events.type == ALLEGRO_EVENT_KEY_DOWN) { // turn
                switch (events.keyboard.keycode) {
                case ALLEGRO_KEY_A:   // turn left
                    direction++;
                    figure->draw_and_check(x, y, direction);
                    break; 

                case ALLEGRO_KEY_S: //turn right
                    direction -= 1;
                    figure->draw_and_check(x, y, direction);
                    break;

                case ALLEGRO_KEY_LEFT:
                    if (!(x <= 100))
                        x -= 50;
                    break;

                case ALLEGRO_KEY_RIGHT:
                    if (figure->checkright(x,y,direction))
                        x += 50;
                    break;

                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    done2 = true;
                    break;
                }
                if (direction == 5)
                    direction = 1;
                if (direction == 0)
                    direction = 4;

            }

            if (events.type == ALLEGRO_EVENT_TIMER) {
                y += level;
                endoffigure += level;               
                draw = true;
            }


            if ((int)y % 50 == 0)//sprawdzenie stykow podzielne przez 50
            {
                if (figure->checkdown(x, y + 50, direction, table.table)) {

                    figure->save(x, y + 50, direction, table.table);

                    if (table.isend())
                    {
                        next = !end.start(display, points, graphics);
                        done = true;
                        draw = false;
                    }

                    done2 = true;

                }

                table.check(level,points);
            }
            


            if (draw) {
                draw = false;

                table.print();

                figure->draw(x, y,direction);
                al_draw_bitmap(frame, -39, 85, 0);
                al_draw_bitmap(smallframe, 700, 20, 0);
                al_draw_bitmap(smallframe, 700, 350, 0);



                graphics.print_text(font_silicone,1010, 160,yellow,"SCORE");
                graphics.print_text(font_silicone,1010, 235,yellow,std::to_string(points));

                graphics.print_text(font_silicone_small,1010, 480,yellow,"NEXT FIGURE");
                newfigure->draw(945, 530, 1);
                al_flip_display();
                al_clear_to_color(al_map_rgb(0, 0, 0));

                
            }
        }       

    }


    al_rest(3.0f);
    al_destroy_font(font_silicone);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(smallframe);

   return next;
}



