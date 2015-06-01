/*
 * World.h
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#ifndef WORLD_WORLD_H_
#define WORLD_WORLD_H_

#include "../world/Map.hpp"
#include "../world/Body.hpp"
#include "../characters/Kuranes.h"
#include "../core/GameState.hpp"

class World {

	unsigned int oldx, oldy;

	Kuranes* player;

	Map* map;

	sf::View* view;

	GameState* gs;

public:
	World(sf::View*, GameState*);
	void handleEvents(sf::Event);
	void draw();
	virtual ~World();
};

#endif /* WORLD_WORLD_H_ */
