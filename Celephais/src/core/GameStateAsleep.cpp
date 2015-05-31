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
	this->map = new Map(9, 7, this);
	this->view.setSize(288, 221);
	this->view.setCenter(144, 110);
	this->game->window.setView(this->view);

	this->player = new Body("Player1", "media/testToken.png", this, this->map,
			2, 2);
	this->obstacle = new Body("Obstacle", "media/testToken.png", this,
			this->map, 5, 5);

}

void GameStateAsleep::loadTextures() {

}

void GameStateAsleep::draw(const float dt) {

	//actual drawing
	this->game->window.clear(sf::Color::Red);
	this->map->draw();

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
			break;
		}
		case sf::Event::KeyPressed: {
			if (event.key.code == sf::Keyboard::Escape)
				this->game->window.close();
			else if (event.key.code == sf::Keyboard::Right)
				this->player->setPos(this->player->getx() + 1,
						this->player->gety());
			else if (event.key.code == sf::Keyboard::Left)
				this->player->setPos(this->player->getx() - 1,
						this->player->gety());
			else if (event.key.code == sf::Keyboard::Up)
				this->player->setPos(this->player->getx(),
						this->player->gety() - 1);
			else if (event.key.code == sf::Keyboard::Down)
				this->player->setPos(this->player->getx(),
						this->player->gety() + 1);
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

