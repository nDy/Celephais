/*
 * Intro.hpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#ifndef SCENES_INTRO_HPP_
#define SCENES_INTRO_HPP_

#include "../core/Dialogue.h"
#include <list>

class Intro: public GameState {

	std::list<int> control;

	std::list<sf::Sprite> background;

	std::list<Dialogue>* d;

	float activateNext;
	bool next;

public:
	Intro(Game*);
	void dialogueEvents(sf::Event);
	void draw(const float dt);
	void update(const float dt);
	void handleInput();
	void loadTextures();

	virtual ~Intro();
};

#endif /* SCENES_INTRO_HPP_ */
