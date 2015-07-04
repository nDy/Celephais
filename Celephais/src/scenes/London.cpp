/*
 * ChildhoodHouse.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: ndy
 */

#include "London.hpp"

#include "../body/TalkingBody.hpp"
#include "../body/Body.hpp"
#include "../core/Dialogue.hpp"
#include "Room.hpp"

#include <list>

London::London(Game* g) :
		GameStateGameplay(g, new TextureManager(), nullptr, 35, 21, 7, 11) {

	//replace with pointer to next scene
	this->setNext(new Room(g));
	this->setExit(34, 11);

	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 13,
			8);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 17,
			8);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 25,
			8);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 29,
			8);

	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 13,
			14);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 17,
			14);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 21,
			14);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 25,
			14);
	this->world->insertBody("Faro", "media/tiles/Faro.png", Body::SILENT, 29,
			14);

	this->texmgr->loadTexture("Grass1", "media/tiles/Grass1.png");
	this->texmgr->loadTexture("Water1", "media/tiles/Water1.png");
	this->texmgr->loadTexture("Sidewalk1", "media/tiles/Sidewalk1.png");

	for (unsigned int i = 0; i < this->world->sizeY(); ++i) {
		for (unsigned int j = 0; j < this->world->sizeX(); ++j) {
			if (i >= 7 && j >= 7) {
				if ((i > 9 && i < 13) || (i <= 9 && j >= 20 && j <= 22)) {
					this->world->at(j, i)->setName("Grass1");
					this->world->at(j, i)->setTexture(
							this->texmgr->getRef("Grass1"));
				} else if (i > 15) {
					this->world->at(j, i)->setName("Water1");
					this->world->at(j, i)->setTexture(
							this->texmgr->getRef("Water1"));
				} else {
					this->world->at(j, i)->setName("Sidewalk1");
					this->world->at(j, i)->setTexture(
							this->texmgr->getRef("Sidewalk1"));
				}
			} else {
				this->world->at(j, i)->setName("Water1");
			}
		}
	}

	TalkingBody* peter;
	peter = (TalkingBody*) this->world->insertBody("Peter", "media/Peter.png",
			Body::TALKING, 15, 15);

	std::list<Dialogue> chatterings;
	chatterings.push_back(
			Dialogue("Perhaps it was natural for heam to dream a new name",
					this));

	peter->setDialogue(chatterings);

	chatterings.clear();

	TalkingBody* lucy;

	lucy = (TalkingBody*) this->world->insertBody("Peter", "media/Peter.png",
			Body::TALKING, 23, 15);

	chatterings.push_back(Dialogue("For he was the last of his family", this));
	chatterings.push_back(
			Dialogue("And alone among the indifferent millions of London",
					this));

	lucy->setDialogue(chatterings);

	chatterings.clear();

	chatterings.push_back(
			Dialogue("So there were not many to speak to him", this));
	chatterings.push_back(Dialogue("And remind him who he had been.", this));

}

London::~London() {
	// TODO Auto-generated destructor stub
}

