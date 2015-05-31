/*
 * GameStateLogin.h
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#ifndef GAMESTATELOGIN_HPP_
#define GAMESTATELOGIN_HPP_

#include "GameState.hpp"

class GameStateLogin: public GameState {
private:
	sf::View view;
public:
	GameStateLogin(Game* game);

	void draw(const float dt);
	void update(const float dt);
	void handleInput();
	void loadgame();

	virtual ~GameStateLogin();
};

#endif /* GAMESTATELOGIN_HPP_ */
