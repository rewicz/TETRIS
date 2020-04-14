// TETRIS.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include"allegro5/allegro.h"
#include"Start.h"
#include"Game.h"



int main(int argc, char** argv)
{

    al_init();
    Game game;
    game.start();
    Start start;
    start.view();
    

    std::cout << "tu";

    return 0;
}

