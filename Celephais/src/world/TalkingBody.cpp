/*
 * TalkingBody.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#include "TalkingBody.hpp"

TalkingBody::TalkingBody() :
		Body() {
	// TODO Auto-generated constructor stub

}

TalkingBody::TalkingBody(std::string type, std::string file, GameState* g,
		Map* m, unsigned int x, unsigned int y) :
		Body(type, file, g, m, x, y, Body::TALKING) {
}

const std::list<Dialogue>& TalkingBody::getDialogue() const {
	return d;
}

void TalkingBody::setDialogue(const std::list<Dialogue>& d) {
	this->d = d;
}

TalkingBody::~TalkingBody() {
	// TODO Auto-generated destructor stub
}

void TalkingBody::speak(std::list<Dialogue>* dlist) {
	for (std::list<Dialogue>::iterator it = this->d.begin();
			it != this->d.end(); it++)
		dlist->push_back(*it);
}
