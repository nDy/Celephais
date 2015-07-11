/*
 * Dialogue.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#include "Dialogue.hpp"

#include "../core/GameStateGameplay.hpp"

#include "RoundedRectangleShape.hpp"

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
	sf::RoundedRectangleShape bg(sf::Vector2f(800 - 20, -2 * 600 / 5), 3, 45);
	bg.setOutlineColor(sf::Color::Black);
	bg.setOutlineThickness(5);
	bg.setFillColor(sf::Color(0, 0, 0, 180));

	bg.setPosition(
			((GameStateGameplay*) this->gs)->world->player->getx() - 400 + 10,
			((GameStateGameplay*) this->gs)->world->player->gety() + 50);
	this->text->setPosition(
			((GameStateGameplay*) this->gs)->world->player->getx() - 400 + 40,
			((GameStateGameplay*) this->gs)->world->player->gety() + 70);
	this->gs->game->window.draw(bg);
	this->gs->game->window.draw(*text);
}

Dialogue::~Dialogue() {
	// TODO Auto-generated destructor stub
}

void Dialogue::drawOverCinematic() {
	sf::RectangleShape bg;
	bg.setSize(
			sf::Vector2f(this->gs->game->window.getSize().x - 20,
					2 * this->gs->game->window.getSize().y / 5));
	bg.setOutlineColor(sf::Color::Black);
	bg.setOutlineThickness(5);
	bg.setFillColor(sf::Color(0, 0, 0, 180));
	bg.setPosition(10, this->gs->game->window.getSize().x / 2 - 55);
	this->text->setPosition(40, this->gs->game->window.getSize().x / 2 - 35);
	this->gs->game->window.draw(bg);
	this->gs->game->window.draw(*text);
}
