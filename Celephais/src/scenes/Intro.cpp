/*
 * Intro.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#include "Intro.hpp"
#include "../core/GameStateAsleep.hpp"

Intro::Intro(Game* game) :
		GameState(game, new TextureManager()) {
	next = false;
	activateNext = 0;
	this->d = new std::list<Dialogue>();

// intro buildup
	this->texmgr->loadTexture("first", "media/background.png");
	sf::Sprite first;
	first.setTexture(this->texmgr->getRef("first"));
	this->background.push_back(first);

	std::list<Dialogue> chatterings;
	chatterings.push_back(
			Dialogue("In a dream Kuranes saw the city in the valley...", this));
	chatterings.push_back(
			Dialogue(
					"and the seacoast beyond, and the snowy peak overlooking the sea",
					this));
	chatterings.push_back(
			Dialogue(
					"and the gaily painted galleys that sail out of the harbour",
					this));
	chatterings.push_back(
			Dialogue("toward distant regions where the sea meets the sky...",
					this));

	for (std::list<Dialogue>::iterator it = chatterings.begin();
			it != chatterings.end(); it++)
		d->push_back(*it);

	this->texmgr->loadTexture("second", "media/background.png");
	sf::Sprite sec;
	sec.setTexture(this->texmgr->getRef("second"));
	this->background.push_back(sec);

	chatterings.clear();
	chatterings.push_back(
			Dialogue(
					"In a dream it was also that he came by his name of Kuranes",
					this));
	chatterings.push_back(
			Dialogue("for when awake he was called by another name", this));

	for (std::list<Dialogue>::iterator it = chatterings.begin();
			it != chatterings.end(); it++)
		d->push_back(*it);

}

void Intro::draw(const float dt) {
	this->game->window.draw(this->background.front());

	if (!this->d->empty())
		this->d->front().drawOverCinematic();
}

void Intro::update(const float dt) {

	this->activateNext += dt;
	if (this->activateNext >= 0.25 && next) {
		this->d->pop_front();
		this->next = false;
		this->activateNext = 0;
	}

	if (this->d->size() == 2 && this->background.size() == 2)
		this->background.pop_front();
	if (this->d->size() == 0 && this->background.size() == 1) {
		d->push_back(
				Dialogue(
						"toward distant regions where the sea meets the sky...",
						this));
		this->game->popState();
		this->game->changeState(new GameStateAsleep(this->game));
	}

}

void Intro::handleInput() {

	sf::Event event;

	while (this->game->window.pollEvent(event)) {
		if (this->activateNext >= 0.25) {
			if (!this->d->empty())
				this->dialogueEvents(event);
		}
	}
}

void Intro::loadTextures() {
}

void Intro::dialogueEvents(sf::Event event) {
	if (event.key.code == sf::Keyboard::Space) {
		this->next = true;
	}
}

Intro::~Intro() {
}

