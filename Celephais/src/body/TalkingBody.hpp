/*
 * TalkingBody.h
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#ifndef WORLD_TALKINGBODY_HPP_
#define WORLD_TALKINGBODY_HPP_

#include "Body.hpp"
#include "../core/Dialogue.h"
#include <list>

class TalkingBody: public Body {
	std::list<Dialogue> d;
public:
	TalkingBody();
	TalkingBody(std::string, std::string, GameState*, Map*, unsigned int,
			unsigned int);
	void speak(std::list<Dialogue>*);
	virtual ~TalkingBody();
	const std::list<Dialogue>& getDialogue() const;
	void setDialogue(const std::list<Dialogue>& d);
};

#endif /* WORLD_TALKINGBODY_HPP_ */
