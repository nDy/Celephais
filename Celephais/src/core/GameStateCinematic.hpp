/*
 * GameStateCinematic.h
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATECINEMATIC_HPP_
#define CORE_GAMESTATECINEMATIC_HPP_

#include "Dialogue.hpp"
#include "GameState.hpp"
#include <list>
#include <string>

class GameStateCinematic: public GameState {

	std::list<Dialogue>* d;
	std::list<sf::Sprite> background;

	//control variables
	std::list<int> control;
	int c;
	float activateNext;
	bool next;

public:
	GameStateCinematic(Game*, TextureManager*);
	void addDialogue(const Dialogue&);
	void addBackground(std::string, std::string);

	void draw(const float);
	void update(const float);
	void handleInput();
	void loadTextures();

	virtual ~GameStateCinematic();
};

#endif /* CORE_GAMESTATECINEMATIC_HPP_ */
