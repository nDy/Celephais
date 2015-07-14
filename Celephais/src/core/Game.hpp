/*
 * Game.hpp
 *
 *  Created on: May 23, 2015
 *      Author: ndy
 */

#ifndef CORE_GAME_HPP_
#define CORE_GAME_HPP_

#include <stack>
#include <string>
#include <SFML/Graphics.hpp>

#include "../utils/TextureManager.hpp"

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class GameState;

class Game {
private:
	void loadTextures();
public:
	Game();

	std::stack<GameState*> states;

	std::string currentPlayer;
	int currentgameID;

	sf::RenderWindow window;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void gameLoop();

	//dbstuff
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;

	virtual ~Game();
};

#endif /* CORE_GAME_HPP_ */
