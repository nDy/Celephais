/*
 * GameState.hpp
 *
 *  Created on: May 23, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATE_HPP_
#define CORE_GAMESTATE_HPP_

#include "Game.hpp"

class GameState {
public:

	Game* game;

	TextureManager* texmgr;

	GameState(Game*, TextureManager*);

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;
	virtual void loadTextures() = 0;

	virtual ~GameState();
};

#endif /* CORE_GAMESTATE_HPP_ */
