/*
 * Intro.hpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#ifndef SCENES_INTRO_HPP_
#define SCENES_INTRO_HPP_

#include <list>
#include "../core/GameStateCinematic.hpp"
#include "../core/Dialogue.hpp"


class Intro: public GameStateCinematic {

public:
	Intro(Game*);
	virtual ~Intro();
};

#endif /* SCENES_INTRO_HPP_ */
