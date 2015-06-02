/*
 * GameStateGameplay.h
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATEGAMEPLAY_H_
#define CORE_GAMESTATEGAMEPLAY_H_

#include "GameState.hpp"

class GameStateGameplay: public GameState {
public:
	GameStateGameplay(Game*, TextureManager*);
	virtual ~GameStateGameplay();
};

#endif /* CORE_GAMESTATEGAMEPLAY_H_ */
