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
	this->texmgr->loadTexture("first", "media/Intro/View1.png");
	sf::Sprite first;
	first.setTexture(this->texmgr->getRef("first"));
	first.scale(0.7, 0.7);
	first.setPosition(-50, 0);
	this->background.push_back(first);

	std::list<Dialogue> chatterings;
	chatterings.push_back(
			Dialogue("In a dream Kuranes saw the city in the valley...", this));
	chatterings.push_back(
			Dialogue("...and the seacoast beyond, and the snowy peak...", this));
	chatterings.push_back(Dialogue("...overlooking the sea", this));
	chatterings.push_back(Dialogue("And the gaily painted galleys...", this));
	chatterings.push_back(Dialogue("...that sail out of the harbor", this));
	chatterings.push_back(Dialogue("Toward distant regions where...", this));
	chatterings.push_back(Dialogue("...where the sea meets the sky.", this));

	for (std::list<Dialogue>::iterator it = chatterings.begin();
			it != chatterings.end(); it++)
		d->push_back(*it);

	this->texmgr->loadTexture("second", "media/Intro/View2.png");
	sf::Sprite sec;
	sec.setTexture(this->texmgr->getRef("second"));
	sec.scale(0.7, 0.7);
	sec.setPosition(-50, 0);
	this->background.push_back(sec);

	chatterings.clear();
	chatterings.push_back(Dialogue("In a dream it was also...", this));
	chatterings.push_back(
			Dialogue("that he came by his name of Kuranes...", this));
	chatterings.push_back(
			Dialogue("for when awake he was called by another name.", this));

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
		/* Close the window */

		if (event.type == sf::Event::Closed) {
			game->window.close();
			return;
		}
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

