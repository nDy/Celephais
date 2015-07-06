/*
 * GameStateLogin.h
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATELOGIN_HPP_
#define CORE_GAMESTATELOGIN_HPP_

#include "GameState.hpp"

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class GameStateLogin: public GameState {
private:
	sf::View view;

	sf::RectangleShape userbg;
	sf::RectangleShape passbg;
	sf::Text *textuserinput;
	sf::Text *textpassinput;
	sf::Text *textuser;
	sf::Text *textpass;
	sf::Font *f;

	//dbstuff
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;

	bool userenabled;
	bool passenabled;
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
