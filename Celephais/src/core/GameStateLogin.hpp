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

	void draw(sf::Time dt);
	void update(sf::Time dt);
	void handleInput();
	void loadgame();
	void loadTextures();
	void setNext(GameState*);

	virtual ~GameStateLogin();
};

#endif /* CORE_GAMESTATELOGIN_HPP_ */
