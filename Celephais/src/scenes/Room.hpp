/*
 * Room.hpp
 *
 *  Created on: Jun 18, 2015
 *      Author: ndy
 */

#ifndef SCENES_ROOM_HPP_
#define SCENES_ROOM_HPP_

#include "../core/GameStateGameplay.hpp"

class Room: public GameStateGameplay {
public:
	Room(Game*);
	virtual ~Room();
};

#endif /* SCENES_ROOM_HPP_ */
