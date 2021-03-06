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
#include "../body/MovingBody.hpp"
#include "../core/GameState.hpp"
#include <list>
#include "../core/Dialogue.hpp"

class World {

	float oldx, oldy;

	sf::View* view;

	GameState* gs;

	std::list<Dialogue>* d;

	bool moving;

	int movingCount;

	bool __insertBody(Body*, unsigned int, unsigned int);

public:
	MovingBody* player;

	Map* map;

	World(sf::View*, GameState*, unsigned int, unsigned int, unsigned int,
			unsigned int);
	void handleEvents(sf::Event);
	void mapEvents(sf::Event);
	void dialogueEvents(sf::Event);
	void draw();
	void update(sf::Time dt);
	Body*& insertBody(std::string, std::string, unsigned int, unsigned int,
			unsigned int);
	Tile*& at(unsigned int, unsigned int);
	void setTile(Tile, unsigned int, unsigned int);
	unsigned int sizeX();
	unsigned int sizeY();
	virtual ~World();
};

#endif /* WORLD_WORLD_HPP_ */
