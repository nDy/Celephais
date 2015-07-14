/*
 * Dialogue.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#include "Dialogue.hpp"

#include "../core/GameStateGameplay.hpp"

#include "RoundedRectangleShape.hpp"

#include <list>

Dialogue::Dialogue(std::string str, GameState* gs) {

	this->f = new sf::Font();
	this->text = new sf::Text();
	this->gs = gs;
	if (!this->f->loadFromFile("fonts/Dialogue.ttf")) {
		// error...
	}
	this->text->setFont(*f);
	this->text->setString(str);
	this->text->setCharacterSize(18);
	this->text->setColor(sf::Color::White);
	//this->text->setStyle(sf::Text::Bold | sf::Text::Underlined);

}

void Dialogue::draw() {

	sf::RectangleShape bg(sf::Vector2f(800 - 20, 2 * 600 / 5));
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

	if (text->getLocalBounds().width < this->gs->game->window.getSize().x - 200)
		this->gs->game->window.draw(*text);
	else {
		sf::Text aux(*text);
		int auxline = 0;
		int prev = 0;
		for (size_t i = 0; i < aux.getString().getSize(); ++i) {
			if (aux.getString().toAnsiString().at(i) == ' ')
				prev = i;

			if (aux.findCharacterPos(i).x > 700) {
				sf::Text line(aux);
				line.setString(aux.getString().substring(0, prev));
				line.move(0, auxline * 30);
				this->gs->game->window.draw(line);
				++auxline;
				aux.setString(
						aux.getString().substring(prev + 1,
								aux.getString().getSize() - prev));
				i = 0;
				prev = 0;
				if (aux.findCharacterPos(i).x < 700
						&& !aux.getString().isEmpty()) {
					sf::Text endingLine(aux);
					endingLine.setString(aux.getString());
					endingLine.move(0, auxline * 30);
					this->gs->game->window.draw(endingLine);
					break;
				}
			}
		}
	}
}

Dialogue::~Dialogue() {
// TODO Auto-generated destructor stub
}

void Dialogue::drawOverCinematic() {

	sf::RectangleShape bg(sf::Vector2f(800 - 20, 2 * 600 / 5));
	bg.setOutlineColor(sf::Color::Black);
	bg.setOutlineThickness(5);
	bg.setFillColor(sf::Color(0, 0, 0, 180));

	bg.setPosition(
			this->gs->game->window.getSize().x/2 - 400 + 10,
			this->gs->game->window.getSize().y/2 + 50);
	this->text->setPosition(
			this->gs->game->window.getSize().x/2 - 400 + 40,
			this->gs->game->window.getSize().y/2 + 70);
	this->gs->game->window.draw(bg);

	if (text->getLocalBounds().width < this->gs->game->window.getSize().x - 200)
		this->gs->game->window.draw(*text);
	else {
		sf::Text aux(*text);
		int auxline = 0;
		int prev = 0;
		for (size_t i = 0; i < aux.getString().getSize(); ++i) {
			if (aux.getString().toAnsiString().at(i) == ' ')
				prev = i;

			if (aux.findCharacterPos(i).x > 700) {
				sf::Text line(aux);
				line.setString(aux.getString().substring(0, prev));
				line.move(0, auxline * 30);
				this->gs->game->window.draw(line);
				++auxline;
				aux.setString(
						aux.getString().substring(prev + 1,
								aux.getString().getSize() - prev));
				i = 0;
				prev = 0;
				if (aux.findCharacterPos(i).x < 700
						&& !aux.getString().isEmpty()) {
					sf::Text endingLine(aux);
					endingLine.setString(aux.getString());
					endingLine.move(0, auxline * 30);
					this->gs->game->window.draw(endingLine);
					break;
				}
			}
		}
	}
}
