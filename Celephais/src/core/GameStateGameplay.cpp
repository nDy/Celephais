/*
 * GameStateGameplay.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#include "GameStateGameplay.hpp"

GameStateGameplay::GameStateGameplay(Game* g, TextureManager* tx,
		GameState* next, unsigned int sizex, unsigned int sizey) :
		GameState(g, tx) {
	this->setNext(next);

	this->world = new World(&view, this, sizex, sizey);

}

void GameStateGameplay::loadTextures() {

}

void GameStateGameplay::draw(const float dt) {

	this->game->window.setView(this->view);
	this->world->draw();

}

void GameStateGameplay::update(const float dt) {

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

GameStateGameplay::~GameStateGameplay() {
	// TODO Auto-generated destructor stub
}

