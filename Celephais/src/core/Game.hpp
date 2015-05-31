/*
 * Game.hpp
 *
 *  Created on: May 23, 2015
 *      Author: ndy
 */

#ifndef CORE_GAME_HPP_
#define CORE_GAME_HPP_

#include <stack>
#include <SFML/Graphics.hpp>

#include "../utils/TextureManager.hpp"

class GameState;

class Game {
private:
	void loadTextures();
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

#endif /* CORE_GAME_HPP_ */
