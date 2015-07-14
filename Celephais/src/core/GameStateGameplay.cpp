/*
 * GameStateGameplay.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#include "GameStateGameplay.hpp"

GameStateGameplay::GameStateGameplay(Game* g, TextureManager* tx,
		GameState* next, unsigned int sizex, unsigned int sizey,
		unsigned int playerPosx, unsigned int playerPosy) :
		GameState(g, tx) {

	this->setNext(next);

	this->exitX = 0;
	this->exitY = 0;

	this->world = new World(&view, this, sizex, sizey, playerPosx, playerPosy);

	paused = false;

	pausebg.setSize(sf::Vector2f(300, 200));
	pausebg.setFillColor(sf::Color(0, 0, 0, 180));
	pausebg.setOutlineColor(sf::Color::White);
	pausebg.setOutlineThickness(4);

	this->f = new sf::Font();
	this->textload = new sf::Text();
	this->textsave = new sf::Text();
	this->textexit = new sf::Text();

	this->f = new sf::Font();
	if (!this->f->loadFromFile("fonts/Dialogue.ttf")) {
		// error...
	}

	this->textload->setFont(*f);
	this->textload->setString(std::string("Load"));
	this->textload->setCharacterSize(24);
	this->textload->setColor(sf::Color::White);

	this->textsave->setFont(*f);
	this->textsave->setString(std::string("Save"));
	this->textsave->setCharacterSize(24);
	this->textsave->setColor(sf::Color::White);

	this->textexit->setFont(*f);
	this->textexit->setString(std::string("Exit"));
	this->textexit->setCharacterSize(24);
	this->textexit->setColor(sf::Color::White);

}

void GameStateGameplay::loadTextures() {

}

void GameStateGameplay::draw(sf::Time dt) {
	this->game->window.setView(this->view);

	this->world->draw();

	if (paused) {
		this->pausebg.setPosition(
				sf::Vector2f(
						this->world->player->getx()
								- this->pausebg.getSize().x / 2,
						this->world->player->gety()
								- this->pausebg.getSize().y / 2));
		this->textsave->setPosition(
				this->world->player->getx()
						- this->textsave->getLocalBounds().width / 2,
				this->world->player->gety() - 50
						- this->textsave->getLocalBounds().height / 2);
		this->textload->setPosition(
				this->world->player->getx()
						- this->textload->getLocalBounds().width / 2,
				this->world->player->gety()
						- this->textload->getLocalBounds().height / 2);
		this->textexit->setPosition(
				this->world->player->getx()
						- this->textexit->getLocalBounds().width / 2,
				this->world->player->gety() + 50
						- this->textexit->getLocalBounds().height / 2);

		this->game->window.draw(pausebg);
		this->game->window.draw(*textload);
		this->game->window.draw(*textsave);
		this->game->window.draw(*textexit);
	}

}

void GameStateGameplay::update(sf::Time dt) {
	if (!paused) {
		this->world->update(dt);
		if (this->world->player->getx() / 32 == this->exitX
				&& this->world->player->gety() / 32 == this->exitY)
			this->game->changeState(this->nextState);
	}
}

void GameStateGameplay::handleInput() {
	sf::Event event;

	while (this->game->window.pollEvent(event)) {
		switch (event.type) {
		/* Close the window */
		case sf::Event::Closed: {
			game->window.close();
			break;
		}
			/* Resize the window
			 case sf::Event::Resized: {*
			 this->view->setSize(event.size.width, event.size.height);
			 break;
			 }*
			 */
		case sf::Event::KeyPressed: {

			if (event.key.code == sf::Keyboard::Escape)
				paused = !paused;

			if (!paused)
				world->handleEvents(event);
		}
			break;
		default:
			break;
		}
	}
}

void GameStateGameplay::setNext(GameState* gs) {
	this->nextState = gs;
}

void GameStateGameplay::setExit(unsigned int x, unsigned int y) {
	this->exitX = x;
	this->exitY = y;
}

GameStateGameplay::~GameStateGameplay() {
	// TODO Auto-generated destructor stub
}

