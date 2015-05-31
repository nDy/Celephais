/*
 * Kuranes.cpp
 *
 *  Created on: May 31, 2015
 *      Author: ndy
 */

#include "Kuranes.h"

Kuranes::Kuranes(GameState* gs, Map* m, unsigned int x, unsigned int y) :
		Body("KuranesFront", "media/Kuranes/KuranesFront.png", gs, m, x, y) {
	this->gs->texmgr->loadTexture("KuranesBack",
			"media/Kuranes/KuranesBack.png");
	this->gs->texmgr->loadTexture("KuranesLeft",
			"media/Kuranes/KuranesLeft.png");
	this->gs->texmgr->loadTexture("KuranesRight",
			"media/Kuranes/KuranesRight.png");
}

void Kuranes::turn(unsigned int side) {

	switch (side) {
	case FRONT:
		this->setTexture(this->gs->texmgr->getRef("KuranesFront"));
		break;
	case BACK:
		this->setTexture(this->gs->texmgr->getRef("KuranesBack"));
		break;
	case LEFT:
		this->setTexture(this->gs->texmgr->getRef("KuranesLeft"));
		break;
	case RIGHT:
		this->setTexture(this->gs->texmgr->getRef("KuranesRight"));
		break;
	default:
		break;
	}

}

void Kuranes::moveLeft() {
	this->turn(Body::LEFT);
	this->setPos((this->getx() / 32) - 1, this->gety() / 32);
}

void Kuranes::moveRight() {
	this->turn(Body::RIGHT);
	this->setPos((this->getx() / 32) + 1, (this->gety() / 32));
}

void Kuranes::moveUp() {
	this->turn(Body::BACK);
	this->setPos(this->getx() / 32, (this->gety() / 32) - 1);
}

void Kuranes::moveDown() {
	this->turn(Body::FRONT);
	this->setPos(this->getx() / 32, (this->gety() / 32) + 1);
}

Kuranes::~Kuranes() {
	// TODO Auto-generated destructor stub
}

