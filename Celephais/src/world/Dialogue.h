/*
 * Dialogue.h
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#ifndef WORLD_DIALOGUE_H_
#define WORLD_DIALOGUE_H_

#include <string>
#include <SFML/Graphics.hpp>
#include "../core/GameState.hpp"

class Dialogue {
	sf::Text text;
	sf::Font f;
	GameState* gs;
public:
	Dialogue(std::string, GameState*);
	void draw();
	virtual ~Dialogue();
};

#endif /* WORLD_DIALOGUE_H_ */
