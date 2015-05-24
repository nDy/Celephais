/*
 * Game.hpp
 *
 *  Created on: May 23, 2015
 *      Author: ndy
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

class Game {
public:
	Game();

	std::stack<GameState*> states;

	sf::RenderWindow window;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void gameLoop();

	virtual ~Game();
};

#endif /* GAME_HPP_ */
