/*
 * GameStateGameplay.h
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#ifndef CORE_GAMESTATEGAMEPLAY_HPP_
#define CORE_GAMESTATEGAMEPLAY_HPP_

#include "GameState.hpp"
#include "../world/World.hpp"

class GameStateGameplay: public GameState {

public:
	World* world;
private:
	sf::View view;

public:
	GameStateGameplay(Game*, TextureManager*, GameState*, unsigned int,
			unsigned int);

	void draw(const float dt);
	void update(const float dt);
	void handleInput();
	void loadTextures();
	void setNext(GameState*);
	virtual ~GameStateGameplay();
};

#endif /* CORE_GAMESTATEGAMEPLAY_HPP_ */
