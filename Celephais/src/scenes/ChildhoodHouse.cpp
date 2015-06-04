/*
 * ChildhoodHouse.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: ndy
 */

#include "ChildhoodHouse.hpp"

#include "../body/TalkingBody.hpp"
#include "../core/Dialogue.hpp"
#include <list>

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

