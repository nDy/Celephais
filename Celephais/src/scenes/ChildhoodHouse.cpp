/*
 * ChildhoodHouse.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: ndy
 */

#include "ChildhoodHouse.hpp"

#include "../body/TalkingBody.hpp"
#include "../world/Tile.hpp"
#include "../body/Body.hpp"
#include "../core/Dialogue.hpp"
#include <string>
#include <list>
#include <iostream>

ChildhoodHouse::ChildhoodHouse(Game* g) :
		GameStateGameplay(g, new TextureManager(), nullptr, 60, 58) {

	//replace with pointer to next scene
	this->setNext(nullptr);

	this->world->insertBody("Obstacle", "media/testToken.png", Body::SILENT, 4,
			0);
	this->world->insertBody("Obstacle", "media/testToken.png", Body::SILENT, 4,
			1);
	this->world->insertBody("Obstacle", "media/testToken.png", Body::SILENT, 4,
			2);
	this->world->insertBody("Obstacle", "media/testToken.png", Body::SILENT, 4,
			3);
	this->world->insertBody("Obstacle", "media/testToken.png", Body::SILENT, 4,
			4);

	this->texmgr->loadTexture("Grass1", "media/tiles/Grass1.png");
	this->texmgr->loadTexture("Grass2", "media/tiles/Grass2.png");

	for (unsigned int i = 0; i < this->world->sizeY(); ++i) {
		for (unsigned int j = 0; j < this->world->sizeX(); ++j) {
			if (i % 2 == 0) {
				this->world->at(j, i)->setName("Grass1");
				this->world->at(j, i)->setTexture(
						this->texmgr->getRef("Grass1"));
			} else {
				this->world->at(j, i)->setName("Grass2");
				this->world->at(j, i)->setTexture(
						this->texmgr->getRef("Grass2"));
			}
		}
	}

	TalkingBody* peter;
	peter = (TalkingBody*) this->world->insertBody("Peter", "media/Peter.png",
			Body::TALKING, 18, 25);

	std::list<Dialogue> chatterings;
	chatterings.push_back(Dialogue("Hello I am peter!", this));
	chatterings.push_back(Dialogue("Welcome to Celephais!", this));
	peter->setDialogue(chatterings);

}

ChildhoodHouse::~ChildhoodHouse() {
	// TODO Auto-generated destructor stub
}

