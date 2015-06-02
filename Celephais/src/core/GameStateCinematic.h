/*
 * GameStateCinematic.h
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATECINEMATIC_H_
#define CORE_GAMESTATECINEMATIC_H_

#include "GameState.hpp"

class GameStateCinematic: public GameState {
public:
	GameStateCinematic(Game*, TextureManager*);
	virtual ~GameStateCinematic();
};

#endif /* CORE_GAMESTATECINEMATIC_H_ */
