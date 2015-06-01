/*
 * Body.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "Body.hpp"
#include "Map.hpp"

Body::Body() {
	this->type = Body::SILENT;
	this->gs = nullptr;
	this->map = nullptr;
	this->posx = 0;
	this->posy = 0;
	this->img.setPosition(0, 0);
}

Body::Body(std::string name, std::string file, GameState* g, Map* m,
		unsigned int x, unsigned int y, unsigned int type) {
	this->type = type;
	this->name = name;
	this->gs = g;
	this->map = m;
	this->gs->texmgr->loadTexture(name, file);
	this->img.setTexture(this->gs->texmgr->getRef(name));
	this->posx = x;
	this->posy = y;
	this->img.setPosition(x * 32, y * 32);
	this->map->at(x, y)->top = this;
}

void Body::draw() {
	this->gs->game->window.draw(this->img);
}

bool Body::setPos(unsigned int x, unsigned int y) {
	if (x >= this->map->getDimX() || y >= this->map->getDimY())
		return false;
	if (this->map->at(x, y)->top == nullptr) {
		this->map->at(this->posx, this->posy)->top = nullptr;
		this->map->at(x, y)->top = this;
		this->posx = x;
		this->posy = y;
		this->img.setPosition(x * 32, y * 32);

		return true;
	}

	return false;
}

unsigned int Body::getx() {
	return this->posx * 32;
}

unsigned int Body::gety() {
	return this->posy * 32;
}

std::string Body::getName() {
	return this->name;
}

unsigned int Body::getType() {
	return this->type;
}

void Body::setType(unsigned int type) {
	this->type = type;
}

Body::~Body() {
	// TODO Auto-generated destructor stub
}

void Body::setTexture(sf::Texture& tex) {
	this->img.setTexture(tex);
}
