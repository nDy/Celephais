/*
 * GameStateGameplay.h
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATEGAMEPLAY_HPP_
#define CORE_GAMESTATEGAMEPLAY_HPP_

#include "GameState.hpp"
#include "../world/World.hpp"

class GameStateGameplay: public GameState {

public:
	World* world;
	unsigned int exitX, exitY;
private:
	sf::View view;

	//pause
	sf::RectangleShape pausebg;
	bool paused;
	sf::Font *f;
	sf::Text *textload;
	sf::Text *textsave;
	sf::Text *textexit;

	//saving
	sf::RectangleShape savingbg;
	bool saving;
	sf::Text *texttagone;
	sf::Text *texttagtwo;
	sf::Text *texttagthree;
	sf::Text *textlvlone;
	sf::Text *textlvltwo;
	sf::Text *textlvlthree;

public:
	GameStateGameplay(Game*, TextureManager*, GameState*, unsigned int,
			unsigned int, unsigned int, unsigned int);

	void draw(sf::Time dt);
	void update(sf::Time dt);
	void handleInput();
	void loadTextures();
	void loadSavegames();
	void setNext(GameState*);
	void setExit(unsigned int, unsigned int);
	void save(int);
	virtual ~GameStateGameplay();
};

#endif /* CORE_GAMESTATEGAMEPLAY_HPP_ */
