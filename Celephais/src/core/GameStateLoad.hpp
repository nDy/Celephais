/*
 * GameStateLoad.hpp
 *
 *  Created on: Jul 13, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATELOAD_HPP_
#define CORE_GAMESTATELOAD_HPP_

#include "GameState.hpp"

class GameStateLoad: public GameState {
private:
	sf::Sprite background;

	sf::Font *f;

	sf::RectangleShape savingbg;

	sf::Text *texttagone;
	sf::Text *texttagtwo;
	sf::Text *texttagthree;
	sf::Text *textlvlone;
	sf::Text *textlvltwo;
	sf::Text *textlvlthree;

	sf::RectangleShape buttonNew;
	sf::Text *textButtonNew;

public:
	GameStateLoad(Game* game);

	void draw(sf::Time dt);
	void update(sf::Time dt);
	void handleInput();
	void loadTextures();
	void setNext(GameState*);
	void loadSavegames();
	void load(int);

	virtual ~GameStateLoad();
};

#endif /* CORE_GAMESTATELOAD_HPP_ */
