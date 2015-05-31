/*
 * GameStateAsleep.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "GameStateAsleep.hpp"

GameStateAsleep::GameStateAsleep(Game* game) {
	this->game = game;
	this->texmgr = new TextureManager();

	this->loadTextures();

	this->background.setTexture(this->texmgr->getRef("background"));
}
void GameStateAsleep::loadTextures() {
	texmgr->loadTexture("background", "media/background.png");
}

void GameStateAsleep::draw(const float dt) {
	this->game->window.setView(this->view);

	//actual drawing
	this->game->window.clear(sf::Color::Red);
	this->game->window.draw(this->background);

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
			this->view.setSize(event.size.width, event.size.height);
			this->background.setPosition(
					this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
			this->background.setScale(
					float(event.size.width)
							/ float(this->background.getTexture()->getSize().x),
					float(event.size.height)
							/ float(
									this->background.getTexture()->getSize().y));
			break;
		}
		case sf::Event::KeyPressed: {
			if (event.key.code == sf::Keyboard::Escape)
				this->game->window.close();
		}
		default:
			break;
		}
	}
}

GameStateAsleep::~GameStateAsleep() {
	// TODO Auto-generated destructor stub
}

