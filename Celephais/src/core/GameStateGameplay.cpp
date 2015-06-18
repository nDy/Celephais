/*
 * GameStateGameplay.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#include "GameStateGameplay.hpp"

GameStateGameplay::GameStateGameplay(Game* g, TextureManager* tx,
		GameState* next, unsigned int sizex, unsigned int sizey,
		unsigned int playerPosx, unsigned int playerPosy) :
		GameState(g, tx) {

	this->setNext(next);

	this->exitX = 0;
	this->exitY = 0;

	this->world = new World(&view, this, sizex, sizey, playerPosx, playerPosy);

}

void GameStateGameplay::loadTextures() {

}

void GameStateGameplay::draw(const float dt) {
	this->game->window.setView(this->view);

	this->world->draw();

}

void GameStateGameplay::update(const float dt) {
	if (this->world->player->getx() / 32 == this->exitX
			&& this->world->player->gety() / 32 == this->exitY)
		this->game->changeState(this->nextState);
}

void GameStateGameplay::handleInput() {
	sf::Event event;

	while (this->game->window.pollEvent(event)) {
		switch (event.type) {
		/* Close the window */
		case sf::Event::Closed: {
			game->window.close();
			break;
		}
			/* Resize the window
			 case sf::Event::Resized: {*
			 this->view->setSize(event.size.width, event.size.height);
			 break;
			 }*
			 */
		case sf::Event::KeyPressed: {
			world->handleEvents(event);
		}
			break;
		default:
			break;
		}
	}
}

void GameStateGameplay::setNext(GameState* gs) {
	this->nextState = gs;
}

void GameStateGameplay::setExit(unsigned int x, unsigned int y) {
	this->exitX = x;
	this->exitY = y;
}

GameStateGameplay::~GameStateGameplay() {
	// TODO Auto-generated destructor stub
}

