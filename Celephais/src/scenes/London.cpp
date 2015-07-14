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
#include <random>

London::London(Game* g) :
		GameStateGameplay(g, new TextureManager(), nullptr, 30, 25, 7, 11) {

	this->gameID = Level::London;

	//replace with pointer to next scene
	this->setNext(new ::Room(g));
	this->setExit(29, 14);

	this->world->insertBody("StreetLight", "media/tiles/StreetLight.png",
			Body::SILENT, 10, 13);
	this->world->insertBody("StreetLight", "media/tiles/StreetLight.png",
			Body::SILENT, 15, 13);
	this->world->insertBody("StreetLight", "media/tiles/StreetLight.png",
			Body::SILENT, 20, 13);
	this->world->insertBody("StreetLight", "media/tiles/StreetLight.png",
			Body::SILENT, 25, 13);
//primer edif
	this->world->insertBody("WHouse", "media/tiles/WHouse1.png", Body::SILENT,
			9, 11);
	this->world->insertBody("WindowHouse", "media/tiles/WindowHouse1.png",
			Body::SILENT, 10, 11);
	this->world->insertBody("WDoorHouse", "media/tiles/WDoorHouse1.png",
			Body::SILENT, 11, 11);
	this->world->insertBody("DoorHouse", "media/tiles/DoorHouse1.png",
			Body::SILENT, 12, 11);
	this->world->insertBody("EDoorHouse", "media/tiles/EDoorHouse1.png",
			Body::SILENT, 13, 11);
	this->world->insertBody("WindowHouse", "media/tiles/WindowHouse1.png",
			Body::SILENT, 14, 11);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			15, 11);
//segundo edif
	this->world->insertBody("WHouse", "media/tiles/WHouse1.png", Body::SILENT,
			18, 11);
	this->world->insertBody("WindowHouse", "media/tiles/WindowHouse1.png",
			Body::SILENT, 19, 11);
	this->world->insertBody("WDoorHouse", "media/tiles/WDoorHouse1.png",
			Body::SILENT, 20, 11);
	this->world->insertBody("DoorHouse", "media/tiles/DoorHouse1.png",
			Body::SILENT, 21, 11);
	this->world->insertBody("EDoorHouse", "media/tiles/EDoorHouse1.png",
			Body::SILENT, 22, 11);
	this->world->insertBody("WindowHouse", "media/tiles/WindowHouse1.png",
			Body::SILENT, 23, 11);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			24, 11);

	this->texmgr->loadTexture("Grass1", "media/tiles/Grass1.png");
	this->texmgr->loadTexture("Grass2", "media/tiles/Grass2.png");
	this->texmgr->loadTexture("Grass3", "media/tiles/Grass3.png");
	this->texmgr->loadTexture("Grass4", "media/tiles/Grass4.png");
	this->texmgr->loadTexture("Water1", "media/tiles/Water1.png");
	this->texmgr->loadTexture("Sidewalk1", "media/tiles/Sidewalk1.png");
	this->texmgr->loadTexture("NLake", "media/tiles/NLake.png");
	this->texmgr->loadTexture("NWLake", "media/tiles/NWLake.png");
	this->texmgr->loadTexture("NELake", "media/tiles/NELake.png");
	this->texmgr->loadTexture("ELake", "media/tiles/ELake.png");
	this->texmgr->loadTexture("WLake", "media/tiles/WLake.png");

	std::random_device rd;
	std::mt19937 mt(rd());
	for (unsigned int i = 0; i < this->world->sizeY(); ++i) {
		for (unsigned int j = 0; j < this->world->sizeX(); ++j) {
			if (i >= 7 && j >= 7) {
				if (j > 8 && j < 30 && i > 12 && i <= 15) {
					this->world->at(j, i)->setName("Sidewalk1");
					this->world->at(j, i)->setTexture(
							this->texmgr->getRef("Sidewalk1"));
				} else if (i == 16) {
					this->world->at(j, i)->setName("NLake");
					this->world->at(j, i)->setTexture(
							this->texmgr->getRef("NLake"));
				} else if (i > 16) {
					this->world->at(j, i)->setName("Water1");
					this->world->at(j, i)->setTexture(
							this->texmgr->getRef("Water1"));
				} else {

					std::uniform_int_distribution<int> distribution(1, 4);
					int dice_roll = distribution(mt);
					switch (dice_roll) {
					case 1:
						this->world->at(j, i)->setName("Grass1");
						this->world->at(j, i)->setTexture(
								this->texmgr->getRef("Grass1"));
						break;
					case 2:
						this->world->at(j, i)->setName("Grass2");
						this->world->at(j, i)->setTexture(
								this->texmgr->getRef("Grass2"));
						break;
					case 3:
						this->world->at(j, i)->setName("Grass3");
						this->world->at(j, i)->setTexture(
								this->texmgr->getRef("Grass3"));
						break;
					case 4:
						this->world->at(j, i)->setName("Grass4");
						this->world->at(j, i)->setTexture(
								this->texmgr->getRef("Grass4"));
						break;

					default:
						break;
					}
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
			Dialogue("Perhaps it was natural for him to dream a new name",
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

