/*
 * GameStateGameplay.h
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATEGAMEPLAY_HPP_
#define CORE_GAMESTATEGAMEPLAY_HPP_

#include "GameState.hpp"

class GameStateGameplay: public GameState {
public:
	GameStateGameplay(Game*, TextureManager*, GameState*);
	virtual ~GameStateGameplay();
};

#endif /* CORE_GAMESTATEGAMEPLAY_HPP_ */
