/*
 * GameStateAsleep.hpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#ifndef GAMESTATEASLEEP_HPP_
#define GAMESTATEASLEEP_HPP_

#include "GameState.hpp"

class GameStateAsleep: public GameState {
public:
private:
	sf::View view;
public:
	GameStateAsleep(Game* game);

	void draw(const float dt);
	void update(const float dt);
	void handleInput();

	virtual ~GameStateAsleep();
};

#endif /* GAMESTATEASLEEP_HPP_ */
