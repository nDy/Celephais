/*
 * GameStateLogin.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "GameStateLogin.hpp"

#include "../scenes/Intro.hpp"

GameStateLogin::GameStateLogin(Game* game) :
		GameState(game, new TextureManager()) {
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);

	this->game->window.setView(this->view);

	//open db connection
}

void GameStateLogin::draw(const float dt) {
	//draw username textbox
	//draw pass textbox
}

void GameStateLogin::update(const float dt) {
}

void GameStateLogin::handleInput() {
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

		//get input from string
		case sf::Event::KeyPressed: {
			if (event.key.code == sf::Keyboard::Escape)
				this->game->window.close();
			else if (event.key.code == sf::Keyboard::Space)
				this->loadgame();
			break;
		}
		default:
			break;
		}
	}
}
void GameStateLogin::loadTextures() {
	return;
}

void GameStateLogin::loadgame() {
	this->setNext(new Intro(this->game));
	this->game->pushState(this->nextState);
	return;
}
void GameStateLogin::setNext(GameState* gs) {
	this->nextState = gs;
}

GameStateLogin::~GameStateLogin() {
}
