/*
 * GameStateAsleep.hpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATEASLEEP_HPP_
#define CORE_GAMESTATEASLEEP_HPP_

#include "../world/World.hpp"
#include "GameState.hpp"

class GameStateAsleep: public GameState {
public:
	World* world;
private:
	sf::View* view;

public:
	GameStateAsleep(Game* game);

	void draw(const float dt);
	void update(const float dt);
	void handleInput();
	void loadTextures();

	virtual ~GameStateAsleep();
};

#endif /* CORE_GAMESTATEASLEEP_HPP_ */
