/*
 * Body.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "Body.hpp"

Body::Body(std::string type, std::string file, GameState* g) {
	this->type = type;
	this->gs = g;
	this->gs->texmgr->loadTexture(type, file);
	this->img.setTexture(this->gs->texmgr->getRef(type));
}

void Body::draw() {
	this->gs->game->window.draw(this->img);
}

void Body::setPos(unsigned int x, unsigned int y) {
	this->posx = x;
	this->posy = y;
	this->img.setPosition(x * 32, y * 32);
}

unsigned int Body::getx() {
	return this->posx;
}

unsigned int Body::gety() {
	return this->posy;
}

Body::~Body() {
	// TODO Auto-generated destructor stub
}

