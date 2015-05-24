/*
 * Menu.cpp
 *
 *  Created on: May 23, 2015
 *      Author: ndy
 */

#include "Menu.hpp"

Menu::Menu(Game* game) {
	this->game = game;
}

void Menu::draw(const float dt) {
	this->game->window.setView(this->view);

	this->game->window.clear(sf::Color::Black);
}

void Menu::update(const float dt) {
}

void Menu::handleInput() {
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
		}
		default:
			break;
		}
	}
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

