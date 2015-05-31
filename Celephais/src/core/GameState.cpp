/*
 * GameState.cpp
 *
 *  Created on: May 23, 2015
 *      Author: ndy
 */

#include "GameState.hpp"

GameState::GameState(Game* g, TextureManager* tex) {
	this->game = g;
	this->texmgr = tex;
}

GameState::~GameState() {
	// TODO Auto-generated destructor stub
}

