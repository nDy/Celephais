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
	this->a = new Body("token", "media/testToken.png", this);
	this->b = new Body("token", "media/testToken.png", this);
	this->a->setPos(2, 2);
	this->b->setPos(6, 5);
	this->view.setSize(288, 221);
	this->view.setCenter(144, 110);
	this->game->window.setView(this->view);

}

void GameStateAsleep::loadTextures() {
	texmgr->loadTexture("background", "media/background.png");
}

void GameStateAsleep::draw(const float dt) {

	//actual drawing
	this->game->window.clear(sf::Color::Red);
	this->game->window.draw(this->background);
	this->a->draw();
	this->b->draw();

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
			else if (event.key.code == sf::Keyboard::Right)
				this->a->setPos(this->a->getx() + 1, this->a->gety());
			else if (event.key.code == sf::Keyboard::Left)
				this->a->setPos(this->a->getx() - 1, this->a->gety());
			else if (event.key.code == sf::Keyboard::Up)
				this->a->setPos(this->a->getx(), this->a->gety() - 1);
			else if (event.key.code == sf::Keyboard::Down)
				this->a->setPos(this->a->getx(), this->a->gety() + 1);
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

