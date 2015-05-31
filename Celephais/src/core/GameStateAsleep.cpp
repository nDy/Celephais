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

	this->player = new Body("Player1", "media/testToken.png", this, this->map,
			2, 2);
	this->obstacle = new Body("Obstacle", "media/testToken.png", this,
			this->map, 5, 5);
	this->view.setCenter(player->getx(), player->gety());
	oldx = player->getx();
	oldy = player->gety();

	this->game->window.setView(this->view);
}

void GameStateAsleep::loadTextures() {

}

void GameStateAsleep::draw(const float dt) {

	//actual drawing
	this->game->window.clear(sf::Color::Red);
	if (this->oldx != this->player->getx()
			|| this->oldy != this->player->gety()) {
		this->view.move((float) this->player->getx() - (float) this->oldx,
				(float) this->player->gety() - (float) this->oldy);
		this->game->window.setView(this->view);
		this->oldx = this->player->getx();
		this->oldy = this->player->gety();
	}
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
			else if (event.key.code == sf::Keyboard::Right) {
				this->player->setPos((this->player->getx() / 32) + 1,
						this->player->gety() / 32);
			} else if (event.key.code == sf::Keyboard::Left) {
				this->player->setPos((this->player->getx() / 32) - 1,
						this->player->gety() / 32);
			} else if (event.key.code == sf::Keyboard::Up) {
				this->player->setPos(this->player->getx() / 32,
						(this->player->gety() / 32) - 1);
			} else if (event.key.code == sf::Keyboard::Down) {
				this->player->setPos(this->player->getx() / 32,
						(this->player->gety() / 32) + 1);
			}
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

