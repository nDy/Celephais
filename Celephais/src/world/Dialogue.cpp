/*
 * Dialogue.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#include "Dialogue.h"
#include "../core/GameStateAsleep.hpp"

Dialogue::Dialogue(std::string str, GameState* gs) {
	this->gs = gs;
	if (!this->f.loadFromFile("fonts/Test.ttf")) {
		// error...
	}
	this->text.setFont(f);
	this->text.setString(str);
	this->text.setCharacterSize(24);
	this->text.setColor(sf::Color::Red);
	this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void Dialogue::draw() {
	//this->gs->game->window.setView(this->gs->game->window.getDefaultView());
	//this->text.setPosition(((GameStateAsleep*) this->gs)->world->player->getx(),
	//		((GameStateAsleep*) this->gs)->world->player->gety());
	//this->gs->game->window.draw(text);
}

Dialogue::~Dialogue() {
	// TODO Auto-generated destructor stub
}

