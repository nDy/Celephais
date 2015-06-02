/*
 * GameStateAsleep.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "GameStateAsleep.hpp"

GameStateAsleep::GameStateAsleep(Game* game) :
		GameState(game, new TextureManager()) {
	this->world = new World(&view, this);

}

void GameStateAsleep::loadTextures() {

}

void GameStateAsleep::draw(const float dt) {

	this->game->window.setView(this->view);
	this->world->draw();

}

void GameStateAsleep::update(const float dt) {

}

void GameStateAsleep::handleInput() {
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

void GameStateAsleep::setNext(GameState* gs) {
	this->nextState = gs;
}

GameStateAsleep::~GameStateAsleep() {
	// TODO Auto-generated destructor stub
}

