/*
 * Tile.h
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#ifndef WORLD_TILE_HPP_
#define WORLD_TILE_HPP_

#include "../body/Body.hpp"
#include <string>

class Tile: public Body {
public:
	Body* top;

	Tile();
	Tile(std::string, std::string, GameState*, Map* m);
	void drawTile();
	virtual ~Tile();
};

#endif /* WORLD_TILE_HPP_ */
