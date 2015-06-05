/*
 * Map.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "Map.hpp"
#include <iostream>
Map::Map(unsigned int x, unsigned int y, GameState* gs) {
	this->map.resize(y);
	for (unsigned int i = 0; i < y; ++i) {
		this->map.at(i).resize(x);
		for (unsigned int j = 0; j < x; ++j) {
			this->map.at(i).at(j) = new Tile();
			this->map.at(i).at(j)->setMap(this);
			this->map.at(i).at(j)->gs = gs;
			this->map.at(i).at(j)->setPos(j, i);
			this->map.at(i).at(j)->top = nullptr;
		}
	}
	this->gs = gs;

	//this->gs->texmgr->loadTexture("background", "media/background.png");

	//this->background.setTexture(this->gs->texmgr->getRef("background"));
}

Tile*& Map::at(unsigned int x, unsigned int y) {
	return this->map.at(y).at(x);
}

void Map::draw() {
	//this->gs->game->window.draw(this->background);

	for (unsigned int i = 0; i < this->map.size(); ++i) {
		for (unsigned int j = 0; j < this->map.at(i).size(); ++j) {
			this->map.at(i).at(j)->drawTile();
		}
	}
}

unsigned int Map::getDimX() {
	return this->map.at(0).size();
}

unsigned int Map::getDimY() {
	return this->map.size();
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::setTile(Tile* tile, unsigned int x, unsigned int y) {
	this->map.at(y).at(x) = tile;
}
