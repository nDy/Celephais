/*
 * Dialogue.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#include "Dialogue.h"
#include "../core/GameStateAsleep.hpp"

Dialogue::Dialogue(std::string str, GameState* gs) {
	this->f = new sf::Font();
	this->text = new sf::Text();
	this->gs = gs;
	if (!this->f->loadFromFile("fonts/Test.ttf")) {
		// error...
	}
	this->text->setFont(*f);
	this->text->setString(str);
	this->text->setCharacterSize(24);
	this->text->setColor(sf::Color::White);
	//this->text->setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void Dialogue::draw() {
	sf::RectangleShape bg;
	bg.setSize(sf::Vector2f(800 - 20, 2 * 600 / 5));
	bg.setOutlineColor(sf::Color::Black);
	bg.setOutlineThickness(5);
	bg.setFillColor(sf::Color(0, 0, 0, 180));
	bg.setPosition(
			((GameStateAsleep*) this->gs)->world->player->getx() - 400 + 10,
			((GameStateAsleep*) this->gs)->world->player->gety() + 50);
	this->text->setPosition(
			((GameStateAsleep*) this->gs)->world->player->getx() - 400 + 40,
			((GameStateAsleep*) this->gs)->world->player->gety() + 70);
	this->gs->game->window.draw(bg);
	this->gs->game->window.draw(*text);
}

Dialogue::~Dialogue() {
	// TODO Auto-generated destructor stub
}

void Dialogue::drawOverCinematic() {
	sf::RectangleShape bg;
	bg.setSize(sf::Vector2f(800 - 20, 2 * 600 / 5));
	bg.setOutlineColor(sf::Color::Black);
	bg.setOutlineThickness(5);
	bg.setFillColor(sf::Color(0, 0, 0, 180));
	bg.setPosition(10, 400 + 50);
	this->text->setPosition(40, 400 + 70);
	this->gs->game->window.draw(bg);
	this->gs->game->window.draw(*text);
}
