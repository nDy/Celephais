/*
 * TalkingBody.h
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#ifndef WORLD_TALKINGBODY_H_
#define WORLD_TALKINGBODY_H_

#include "Body.hpp"

class TalkingBody: public Body {
	// Actions list/map/vector
	// Dialogue list/map/vector
public:
	TalkingBody();
	TalkingBody(std::string, std::string, GameState*, Map*, unsigned int,
			unsigned int);
	void speak();
	virtual ~TalkingBody();
};

#endif /* WORLD_TALKINGBODY_H_ */
