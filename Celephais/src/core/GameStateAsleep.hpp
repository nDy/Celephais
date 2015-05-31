/*
 * GameStateAsleep.hpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATEASLEEP_HPP_
#define CORE_GAMESTATEASLEEP_HPP_

#include "GameState.hpp"
#include "../world/Map.hpp"
#include "../world/Body.hpp"
#include "../characters/Kuranes.h"

class GameStateAsleep: public GameState {
public:
private:
	sf::View view;

	unsigned int oldx, oldy;

	Kuranes* player;

	Body* obstacle;

	Map* map;

public:
	GameStateAsleep(Game* game);

	void draw(const float dt);
	void update(const float dt);
	void handleInput();
	void loadTextures();

	virtual ~GameStateAsleep();
};

#endif /* CORE_GAMESTATEASLEEP_HPP_ */
