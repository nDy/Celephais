/*
 * GameStateCinematic.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#include "GameStateCinematic.hpp"
#include "../core/GameStateAsleep.hpp"

GameStateCinematic::GameStateCinematic(Game* g, TextureManager* tx) :
		GameState(g, tx) {
	this->c = 0;
	next = false;
	activateNext = 0;
	this->d = new std::list<Dialogue>();

}

void GameStateCinematic::addDialogue(const Dialogue& dialogue) {
	this->d->push_back(dialogue);
	this->c++;
}

void GameStateCinematic::addBackground(std::string name, std::string file) {
	this->texmgr->loadTexture(name, file);
	sf::Sprite aux;
	aux.setTexture(this->texmgr->getRef(name));
	this->background.push_back(aux);
	// manage control
	this->control.push_back(this->c);
	this->c = 0;
}

void GameStateCinematic::draw(const float dt) {
	if (!this->background.empty())
		this->game->window.draw(this->background.front());

	if (!this->d->empty())
		this->d->front().drawOverCinematic();
}

void GameStateCinematic::update(const float dt) {
	this->activateNext += dt;
	if (this->activateNext >= 0.25 && next) {
		this->d->pop_front();
		this->c++;
		this->next = false;
		this->activateNext = 0;
	}

	if (this->control.empty()) {
		this->game->changeState(new GameStateAsleep(this->game));
	} else if (this->c == this->control.front()) {
		this->background.pop_front();
		this->control.pop_front();
		this->c = 0;
	}
}

void GameStateCinematic::handleInput() {
	sf::Event event;

	while (this->game->window.pollEvent(event)) {
		/* Close the window */

		if (event.type == sf::Event::Closed) {
			game->window.close();
			return;
		}

		if (event.key.code == sf::Keyboard::Space
				&& this->activateNext >= 0.25) {
			if (!this->d->empty())
				this->next = true;
		}
	}

}

void GameStateCinematic::loadTextures() {
}

GameStateCinematic::~GameStateCinematic() {
	// TODO Auto-generated destructor stub
}

