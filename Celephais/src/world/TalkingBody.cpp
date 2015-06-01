/*
 * TalkingBody.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#include "TalkingBody.h"

TalkingBody::TalkingBody() :
		Body() {
	// TODO Auto-generated constructor stub

}

TalkingBody::TalkingBody(std::string type, std::string file, GameState* g,
		Map* m, unsigned int x, unsigned int y) :
		Body(type, file, g, m, x, y, Body::TALKING) {
}

TalkingBody::~TalkingBody() {
	// TODO Auto-generated destructor stub
}

