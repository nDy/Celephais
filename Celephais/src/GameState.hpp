/*
 * GameState.hpp
 *
 *  Created on: May 23, 2015
 *      Author: ndy
 */

#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include "Game.hpp"

class GameState {
public:

	Game* game;

	GameState();

    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;

	virtual ~GameState();
};

#endif /* GAMESTATE_HPP_ */
