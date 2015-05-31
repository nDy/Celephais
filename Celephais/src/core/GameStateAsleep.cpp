/*
 * GameStateAsleep.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "GameStateAsleep.hpp"

GameStateAsleep::GameStateAsleep(Game* game) :
		GameState(game, new TextureManager()) {
	this->map = new Map(9, 7, this);
	this->view.setSize(288, 221);
	this->view.setCenter(144, 110);

	this->player = new Kuranes(this, this->map, 2, 2);
	this->map->at(4, 0)->top = new Body("Obstacle", "media/testToken.png", this,
				this->map, 4, 0);
	this->map->at(4, 1)->top = new Body("Obstacle", "media/testToken.png", this,
			this->map, 4, 1);
	this->map->at(4, 2)->top = new Body("Obstacle", "media/testToken.png", this,
			this->map, 4, 2);
	this->map->at(4, 3)->top = new Body("Obstacle", "media/testToken.png", this,
			this->map, 4, 3);
	this->map->at(4, 4)->top = new Body("Obstacle", "media/testToken.png", this,
			this->map, 4, 4);
	this->view.setCenter(player->getx(), player->gety());
	oldx = player->getx();
	oldy = player->gety();

	this->game->window.setView(this->view);
}

void GameStateAsleep::loadTextures() {

}

void GameStateAsleep::draw(const float dt) {

	this->game->window.clear(sf::Color::Black);
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
				player->moveRight();
			} else if (event.key.code == sf::Keyboard::Left) {
				player->moveLeft();
			} else if (event.key.code == sf::Keyboard::Up) {
				player->moveUp();
			} else if (event.key.code == sf::Keyboard::Down) {
				player->moveDown();
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

