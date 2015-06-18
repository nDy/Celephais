/*
 * Room.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: ndy
 */

#include "Room.hpp"

Room::Room(Game* g) :
		GameStateGameplay(g, new TextureManager(), nullptr, 50, 50, 2, 2) {
	// TODO Auto-generated constructor stub

}

Room::~Room() {
	// TODO Auto-generated destructor stub
}

