/*
 * Tile.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "Tile.hpp"

Tile::Tile() {
	this->top = nullptr;
}

Tile::Tile(std::string type, std::string file, GameState* g, Map* m) :
		Body(type, file, g, m, 0, 0) {

	this->top = nullptr;

}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

void Tile::draw() {
	if (this->getType().size() != 0)
		this->draw();
	if (this->top != nullptr)
		this->top->draw();
}
