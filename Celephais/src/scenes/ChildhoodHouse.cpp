/*
 * ChildhoodHouse.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: ndy
 */

#include "ChildhoodHouse.hpp"

#include "../body/TalkingBody.hpp"
#include "../body/Body.hpp"
#include "../core/Dialogue.hpp"

#include <list>

ChildhoodHouse::ChildhoodHouse(Game* g) :
		GameStateGameplay(g, new TextureManager(), nullptr, 24, 15 , 2, 2) {

	//replace with pointer to next scene
	this->setNext(nullptr);

	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 3, 2);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 7, 2);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 17,
			2);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 20,
			2);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 3, 7);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 7, 7);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 17,
			7);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 20,
			7);

	this->texmgr->loadTexture("Grass1", "media/tiles/Grass1.png");
	this->texmgr->loadTexture("Sidewalk1", "media/tiles/Sidewalk1.png");

	for (unsigned int i = 0; i < this->world->sizeY(); ++i) {
		for (unsigned int j = 0; j < this->world->sizeX(); ++j) {
			if (i == 3 || i == 4 || i == 5 || (i == 2 && (j == 12))
					|| (i == 2 && (j == 13)) || (i == 2 && (j == 14))
					|| (i == 1 && (j == 12)) || (i == 1 && (j == 13))
					|| (i == 1 && (j == 14)) || (i == 0 && (j == 12))
					|| (i == 0 && (j == 13)) || (i == 0 && (j == 14))) {
				this->world->at(j, i)->setName("Grass1");
				this->world->at(j, i)->setTexture(
						this->texmgr->getRef("Grass1"));
			} else {
				this->world->at(j, i)->setName("Sidewalk1");
				this->world->at(j, i)->setTexture(
						this->texmgr->getRef("Sidewalk1"));
			}
		}
	}

	TalkingBody* peter;
	peter = (TalkingBody*) this->world->insertBody("Peter", "media/Peter.png",
			Body::TALKING, 12, 4);

	std::list<Dialogue> chatterings;
	chatterings.push_back(Dialogue("Hello I am peter!", this));
	chatterings.push_back(Dialogue("Welcome to Celephais!", this));
	peter->setDialogue(chatterings);

}

ChildhoodHouse::~ChildhoodHouse() {
	// TODO Auto-generated destructor stub
}

