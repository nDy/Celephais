/*
 * ChildhoodHouse.hpp
 *
 *  Created on: Jun 4, 2015
 *      Author: ndy
 */

#ifndef SCENES_CHILDHOODHOUSE_HPP_
#define SCENES_CHILDHOODHOUSE_HPP_

#include "../core/GameStateGameplay.hpp"
#include "../body/Body.hpp"

class ChildhoodHouse: public GameStateGameplay {
public:
	ChildhoodHouse(Game*);
	virtual ~ChildhoodHouse();
};

#endif /* SCENES_CHILDHOODHOUSE_HPP_ */
