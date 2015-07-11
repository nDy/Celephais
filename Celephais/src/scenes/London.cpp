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
		GameStateGameplay(g, new TextureManager(), nullptr, 35, 35, 7, 11) {

	//replace with pointer to next scene
	this->setNext(new Room(g));
	this->setExit(34, 11);

	///this->world->insertBody("StreetLight", "media/tiles/StreetLight.png",
	//	Body::SILENT, 13, 8);
	//this->world->insertBody("StreetLight", "media/tiles/StreetLight.png",
	//Body::SILENT, 17, 8);
//	this->world->insertBody("StreetLight", "media/tiles/StreetLight.png",
	//Body::SILENT, 25, 8);
	//this->world->insertBody("StreetLight", "media/tiles/StreetLight.png",
	//	Body::SILENT, 29, 8);
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
//edif de esquina
	this->world->insertBody("WHouse", "media/tiles/WHouse1.png", Body::SILENT,
			27, 11);
	this->world->insertBody("WindowHouse", "media/tiles/WindowHouse1.png",
			Body::SILENT, 28, 11);
	this->world->insertBody("WindowHouse", "media/tiles/WindowHouse1.png",
			Body::SILENT, 29, 11);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			30, 11);

	this->world->insertBody("WHouse", "media/tiles/WHouse1.png", Body::SILENT,
			27, 13);
	this->world->insertBody("WindowHouse", "media/tiles/WindowHouse1.png",
			Body::SILENT, 28, 13);
	this->world->insertBody("WindowHouse", "media/tiles/WindowHouse1.png",
			Body::SILENT, 29, 13);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			30, 13);

	//primer edif abajo

	this->world->insertBody("WHouse", "media/tiles/WHouse1.png", Body::SILENT,
			9, 20);
	this->world->insertBody("WindowHouse", "media/tiles/WindowHouse1.png",
			Body::SILENT, 10, 20);
	this->world->insertBody("WDoorHouse", "media/tiles/WDoorHouse1.png",
			Body::SILENT, 11, 20);
	this->world->insertBody("DoorHouse", "media/tiles/DoorHouse1.png",
			Body::SILENT, 12, 20);
	this->world->insertBody("EDoorHouse", "media/tiles/EDoorHouse1.png",
			Body::SILENT, 13, 20);
	this->world->insertBody("WindowHouse", "media/tiles/WindowHouse1.png",
			Body::SILENT, 14, 20);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			15, 20);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			16, 20);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			17, 20);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			18, 20);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			19, 20);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			20, 20);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			21, 20);

// segundo edif abajo

	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			17, 26);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			18, 26);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			19, 26);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			20, 26);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			21, 26);

	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			17, 28);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			18, 28);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			19, 28);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			20, 28);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			21, 28);

	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			17, 30);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			18, 30);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			19, 30);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			20, 30);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			21, 30);

	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			17, 32);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			18, 32);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			19, 32);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			20, 32);
	this->world->insertBody("EHouse", "media/tiles/EHouse1.png", Body::SILENT,
			21, 32);



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
				if ((j > 8 && j < 26 && i > 12 && i <= 15)
						|| (j > 22 && j < 26 && i > 15
								&& i <= this->world->sizeX() - 1)) {
					this->world->at(j, i)->setName("Sidewalk1");
					this->world->at(j, i)->setTexture(
							this->texmgr->getRef("Sidewalk1"));
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

