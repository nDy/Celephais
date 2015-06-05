/*
 * Map.hpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#ifndef WORLD_MAP_HPP_
#define WORLD_MAP_HPP_

#include "Tile.hpp"
#include <vector>
#include "../core/GameState.hpp"

class Map {
private:
	std::vector<std::vector<Tile*> > map;
	GameState* gs;
	//sf::Sprite background;

public:
	Map(unsigned int, unsigned int, GameState*);
	void draw();
	unsigned int getDimX();
	unsigned int getDimY();
	Tile*& at(unsigned int, unsigned int);
	void setTile(Tile*, unsigned int, unsigned int);
	virtual ~Map();
};

#endif /* WORLD_MAP_HPP_ */
