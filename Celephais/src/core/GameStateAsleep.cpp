/*
 * GameStateAsleep.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "GameStateAsleep.hpp"

GameStateAsleep::GameStateAsleep(Game* game) :
		GameState(game, new TextureManager()) {
	this->view = new sf::View();
	this->world = new World(this->view, this);
	this->game->window.setView(*this->view);
}

void GameStateAsleep::loadTextures() {

}

void GameStateAsleep::draw(const float dt) {

	this->game->window.clear(sf::Color::Black);

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
			/* Resize the window */
		case sf::Event::Resized: {
			this->view->setSize(event.size.width, event.size.height);
			break;
		}
		case sf::Event::KeyPressed: {
			world->handleEvents(event);
		}
			break;
		default:
			break;
		}
	}
}

GameStateAsleep::~GameStateAsleep() {
	// TODO Auto-generated destructor stub
}

