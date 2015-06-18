/*
 * Room.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: ndy
 */

#include "Room.hpp"
#include "../body/TalkingBody.hpp"
#include "../body/Body.hpp"
#include "../core/Dialogue.hpp"

Room::Room(Game* g) :
		GameStateGameplay(g, new TextureManager(), nullptr, 50, 50, 2, 2) {
	this->setNext(nullptr);
	this->setExit(49, 5);

	this->texmgr->loadTexture("Grass1", "media/tiles/Grass1.png");
	this->texmgr->loadTexture("Sidewalk2", "media/tiles/Sidewalk2.png");

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
				this->world->at(j, i)->setName("Sidewalk2");
				this->world->at(j, i)->setTexture(
						this->texmgr->getRef("Sidewalk2"));
			}
		}
	}

	TalkingBody* peter;
	peter = (TalkingBody*) this->world->insertBody("Peter", "media/Peter.png",
			Body::TALKING, 12, 4);

	std::list<Dialogue> chatterings;
	chatterings.push_back(
			Dialogue("Perhaps it was natural for heam to dream a new name",
					this));
	chatterings.push_back(Dialogue("For he was the last of his family", this));
	chatterings.push_back(
			Dialogue("And alone among the indifferent millions of London",
					this));
	chatterings.push_back(
			Dialogue("So there were not many to speak to him", this));
	chatterings.push_back(Dialogue("And remind him who he had been.", this));
	peter->setDialogue(chatterings);

}

Room::~Room() {
	// TODO Auto-generated destructor stub
}

