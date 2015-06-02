/*
 * World.h
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#ifndef WORLD_WORLD_HPP_
#define WORLD_WORLD_HPP_

#include "../world/Map.hpp"
#include "../body/Body.hpp"
#include "../characters/Kuranes.h"
#include "../core/GameState.hpp"
#include "../core/Dialogue.h"
#include <list>

class World {

	unsigned int oldx, oldy;

	Map* map;

	sf::View* view;

	GameState* gs;

	std::list<Dialogue>* d;

public:
	Kuranes* player;

	World(sf::View*, GameState*);
	void handleEvents(sf::Event);
	void mapEvents(sf::Event);
	void dialogueEvents(sf::Event);
	void draw();
	virtual ~World();
};

#endif /* WORLD_WORLD_HPP_ */
