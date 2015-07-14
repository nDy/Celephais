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

	sf::Sprite background;

	sf::RectangleShape userbg;
	sf::RectangleShape passbg;
	sf::RectangleShape newuserbg;
	sf::RectangleShape newpassbg;
	sf::Text *textuserinput;
	sf::Text *textpassinput;
	sf::Text *textuser;
	sf::Text *textpass;
	sf::Text *textnewuserinput;
	sf::Text *textnewpassinput;
	sf::Text *textnewuser;
	sf::Text *textnewpass;
	sf::Font *f;

	sf::RectangleShape buttonLogin;
	sf::Text *textButtonLogin;

	sf::Text *textnewb;
	sf::RectangleShape newbcheckbox;

	//dbstuff
	bool userenabled;
	bool passenabled;
	bool newb;
	bool login;

	//paso a carga de partida

public:
	GameStateLogin(Game* game);

	void draw(sf::Time dt);
	void update(sf::Time dt);
	void handleInput();
	void loadgame();
	void loadTextures();
	void setNext(GameState*);
	int loginAttempt();

	virtual ~GameStateLogin();
};

#endif /* CORE_GAMESTATELOGIN_HPP_ */
