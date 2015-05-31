/*
 * GameStateLogin.h
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATELOGIN_HPP_
#define CORE_GAMESTATELOGIN_HPP_

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
	void loadTextures();

	virtual ~GameStateLogin();
};

#endif /* CORE_GAMESTATELOGIN_HPP_ */
