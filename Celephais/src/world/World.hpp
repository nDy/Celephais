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
#include <list>
#include "../core/Dialogue.hpp"

class World {

	unsigned int oldx, oldy;

	sf::View* view;

	GameState* gs;

	std::list<Dialogue>* d;

	bool __insertBody(Body*, unsigned int, unsigned int);

public:
	Kuranes* player;

	Map* map;

	World(sf::View*, GameState*, unsigned int, unsigned int, unsigned int,
			unsigned int);
	void handleEvents(sf::Event);
	void mapEvents(sf::Event);
	void dialogueEvents(sf::Event);
	void draw();
	Body*& insertBody(std::string, std::string, unsigned int, unsigned int,
			unsigned int);
	Tile*& at(unsigned int, unsigned int);
	void setTile(Tile, unsigned int, unsigned int);
	unsigned int sizeX();
	unsigned int sizeY();
	virtual ~World();
};

#endif /* WORLD_WORLD_HPP_ */
