
#include "Game.h"

struct element {
    bool enable;
    ALLEGRO_COLOR color;
};



void Game::init_colors()
{
    colors.push_back(al_map_rgb(255, 0, 0));
    colors.push_back(al_map_rgb(255, 192, 203));
    colors.push_back(al_map_rgb(255, 215, 0));
    colors.push_back(al_map_rgb(255, 165, 0));
    colors.push_back(al_map_rgb(106, 90, 205));
    colors.push_back(al_map_rgb(255, 0, 255));
    colors.push_back(al_map_rgb(0, 255, 0));
    colors.push_back(al_map_rgb(102, 205, 170));
    colors.push_back(al_map_rgb(255, 255, 240));
    colors.push_back(al_map_rgb(112, 128, 144));


    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(colors.begin(), colors.end(), std::default_random_engine(seed));
}

void Game::set_new_figure()
{
    srand(time(NULL));
    int chosen;
    if (objects != 1) {
        do {
            chosen = rand() % objects + 1;

            switch (chosen) {
            case 1:
                newfigure = dynamic_cast<Figures*>(&jablko);
                break;

            case 2:
                newfigure = dynamic_cast<Figures*>(&mandaryna);
                break;

            case 3:
                newfigure = dynamic_cast<Figures*>(&marchewka);
                break;

            case 4:
                newfigure = dynamic_cast<Figures*>(&pomarancza);
                break;

            }
        } while (typeid(*newfigure) == typeid(*figure));
    }
    else
        newfigure = dynamic_cast<Figures*>(&mandaryna);
}

void Game::set_new_color() //
{
    srand(time(NULL));
    int chosen;
    do
    {
        chosen = rand() % colors.size();

    } while (figure->color.r == colors[chosen].r and colors[chosen].g == newfigure->color.g and colors[chosen].b == newfigure->color.b);

        newfigure->color = colors[chosen];

}

void Game::set_configuration(Configuration conf) {
    level = conf.level;
    objects=conf.objects;
}



bool Game::start(ALLEGRO_DISPLAY *display, Graphics graphics,Configuration configuration)
{  
    al_clear_to_color(al_map_rgb(0, 0, 0));
    set_configuration(configuration);
    init_colors();

    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();

    al_install_keyboard();

    ALLEGRO_TIMER* timer = al_create_timer(1 / FPS);

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    ALLEGRO_BITMAP* frame = al_load_bitmap("mainframe.png");
    if (!frame)
        throw (NewException("mainframe.png"));

    ALLEGRO_BITMAP* background = al_load_bitmap("background.png");
    if (!background)
        throw (NewException("background.png"));

    ALLEGRO_BITMAP* smallframe = al_load_bitmap("smallframe.png");
    if (!smallframe)
        throw (NewException("smallframe.png"));

    ALLEGRO_FONT* font_silicone = al_load_font("Silicone.ttf", 50, NULL);
    ALLEGRO_FONT* font_silicone_small = al_load_font("Silicone.ttf", 35, NULL);

    ALLEGRO_COLOR yellow = al_map_rgb(255, 255, 0);

    ALLEGRO_EVENT events;

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));



    float x = 300, y = 150;
    int direction = 1;
    points = 0;

    mandaryna.color = al_map_rgb(106, 90, 205);
    figure = &mandaryna;
    set_new_figure();
    set_new_color();

    bool done = false, draw = true, done2,rotate=false,next=false;
    al_start_timer(timer);
    while (!done) { 


        //set beggining
        direction = 1;
        x = 300;
        y = 150;

        done2 = false;
        while(!done2) {
 
            //game events

            al_wait_for_event(event_queue, &events);
            if (events.type == ALLEGRO_EVENT_KEY_DOWN) { // turn
                switch (events.keyboard.keycode) {
                case ALLEGRO_KEY_A:   // turn left
                    direction++;
                    figure->draw_and_check(x, y, direction);
                    break; 

                case ALLEGRO_KEY_S: //turn right
                    direction--;
                    figure->draw_and_check(x, y, direction);
                    break;

                case ALLEGRO_KEY_LEFT:  // move left
                    if (!(x <= 100))
                        x -= 50;
                    break;

                case ALLEGRO_KEY_RIGHT:  // move right
                    if (figure->checkright(x,y,direction))
                        x += 50;
                    break;

                case ALLEGRO_KEY_ESCAPE:  // escape
                    done = true;
                    done2 = true;
                    break;
                }
                if (direction == 5)
                    direction = 1;
                if (direction == 0)
                    direction = 4;

            }

            if (events.type == ALLEGRO_EVENT_TIMER) {  // falling down
                y += level;           
                draw = true;
            }


            if ((int)y % 50 == 0)  //check table when devided by 50
            {
                if (figure->checkdown(x, y + 50, direction, table.table)) {
                    figure->save(x, y + 50, direction, table.table);

                    if (table.isend())  // check end
                    {
                        next = !end.start(display, points, graphics);
                        done = true;
                        draw = false;
                    }

                    done2 = true;

                    table.check(level,points);  // check points
                }

            }
            

            if (draw) {  // draw
                draw = false;
                al_draw_bitmap(background, 0, 0, 0); //backqround
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

        //generate new figure
        figure = newfigure;
        set_new_figure();
        set_new_color();
        
    }

    al_rest(3.0f);

    al_destroy_timer(timer);

    al_destroy_event_queue(event_queue);

    al_destroy_bitmap(frame);
    al_destroy_bitmap(background);
    al_destroy_bitmap(smallframe);

    al_destroy_font(font_silicone);
    al_destroy_font(font_silicone_small);


   return next;
}



