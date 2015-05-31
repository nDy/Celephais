//============================================================================
// Name        : Celephais.cpp
// Author      : Andres Rangel
// Version     :
// Copyright   : Universidad de Los Andes (GPLv3.0)
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "core/Game.hpp"
#include "core/GameStateLogin.hpp"

int main(int argc, char **argv){

    Game game;

    game.pushState(new GameStateLogin(&game));

    game.gameLoop();

	return 0;
}
