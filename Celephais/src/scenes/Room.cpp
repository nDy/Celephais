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
		GameStateGameplay(g, new TextureManager(), nullptr, 19, 13, 17, 10) {


	this->gameID = Level::Room;

	//replace with pointer to next scene
	this->setNext(nullptr);
	this->setExit(18, 12);

	this->texmgr->loadTexture("Grass1", "media/tiles/Grass1.png");
	this->texmgr->loadTexture("Water1", "media/tiles/Water1.png");
	this->texmgr->loadTexture("Sidewalk1", "media/tiles/Sidewalk1.png");

	for (unsigned int i = 0; i < this->world->sizeY(); ++i) {
		for (unsigned int j = 0; j < this->world->sizeX(); ++j) {
			if (i >= 7 && j >= 7) {
				this->world->at(j, i)->setName("Sidewalk1");
				this->world->at(j, i)->setTexture(
						this->texmgr->getRef("Sidewalk1"));
			} else {
				this->world->at(j, i)->setName("Water1");
			}
		}
	}

	TalkingBody* peter;
	peter = (TalkingBody*) this->world->insertBody("Peter", "media/Peter.png",
			Body::TALKING, 18, 9);

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

