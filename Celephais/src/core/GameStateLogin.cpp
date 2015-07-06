/*
 * GameStateLogin.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "GameStateLogin.hpp"

#include "../scenes/London.hpp"
#include <iostream>

GameStateLogin::GameStateLogin(Game* game) :
		GameState(game, new TextureManager()) {
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);

	userbg.setSize(sf::Vector2f(200, 40));
	passbg.setSize(sf::Vector2f(200, 40));
	userbg.setPosition(
			sf::Vector2f(400, this->game->window.getSize().y / 2 - 30));
	passbg.setPosition(
			sf::Vector2f(400, this->game->window.getSize().y / 2 + 30));
	userbg.setFillColor(sf::Color::White);
	passbg.setFillColor(sf::Color::White);
	userbg.setOutlineColor(sf::Color::Blue);
	passbg.setOutlineColor(sf::Color::Blue);
	userbg.setOutlineThickness(4);
	passbg.setOutlineThickness(4);

	this->f = new sf::Font();
	this->textpass = new sf::Text();
	this->textpassinput = new sf::Text();
	this->textuser = new sf::Text();
	this->textuserinput = new sf::Text();

	if (!this->f->loadFromFile("fonts/Test.ttf")) {
		std::cout << "error" << std::endl;
	}

	this->textuser->setFont(*f);
	this->textuser->setString(std::string("Usuario:"));
	this->textuser->setCharacterSize(24);
	this->textuser->setColor(sf::Color::White);
	this->textuser->setPosition(250, this->game->window.getSize().y / 2 - 30);

	this->textpass->setFont(*f);
	this->textpass->setString(std::string("Pass:"));
	this->textpass->setCharacterSize(24);
	this->textpass->setColor(sf::Color::White);
	this->textpass->setPosition(250, this->game->window.getSize().y / 2 + 30);

	this->textuserinput->setFont(*f);
	this->textuserinput->setString(std::string(""));
	this->textuserinput->setCharacterSize(24);
	this->textuserinput->setColor(sf::Color::Black);
	this->textuserinput->setPosition(450,
			this->game->window.getSize().y / 2 - 30);

	this->textpassinput->setFont(*f);
	this->textpassinput->setString(std::string(""));
	this->textpassinput->setCharacterSize(24);
	this->textpassinput->setColor(sf::Color::Black);
	this->textpassinput->setPosition(450,
			this->game->window.getSize().y / 2 + 30);

	this->game->window.setView(this->view);

	this->userenabled = false;
	this->passenabled = false;

	//open db connection

	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("localhost", "game", "150553");
	/* Connect to the MySQL test database */
	con->setSchema("project");

	stmt = con->createStatement();
}

void GameStateLogin::draw(sf::Time dt) {
	//draw username textbox
	this->game->window.draw(userbg);
	this->game->window.draw(*textuser);
	this->game->window.draw(*textuserinput);

	//draw pass textbox
	this->game->window.draw(passbg);
	this->game->window.draw(*textpass);
	this->game->window.draw(*textpassinput);

}

void GameStateLogin::update(sf::Time dt) {
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
			else if (event.key.code == sf::Keyboard::BackSpace) {
				if (userenabled
						&& this->textuserinput->getString().getSize() > 0) {
					sf::String aux;
					aux = this->textuserinput->getString();
					aux.erase(aux.getSize() - 1);
					this->textuserinput->setString(aux);
				}
				if (passenabled
						&& this->textpassinput->getString().getSize() > 0) {
					sf::String aux;
					aux = this->textpassinput->getString();
					aux.erase(aux.getSize() - 1);
					this->textpassinput->setString(aux);
				}
			} else if (event.key.code == sf::Keyboard::Return) {
				std::string s;
				s = "SELECT pass FROM users WHERE user = '";
				s.append(this->textuserinput->getString().toAnsiString());
				s.append("'");
				res = stmt->executeQuery(s);
				if (!res->next()){
					std::cout<<"el usuario no existe"<<std::endl;
					break;
				}
				if (res->getString("pass")
						== this->textpassinput->getString().toAnsiString())
					this->loadgame();
				else
					std::cout << "password incorrecto" << std::endl;

			}

		}
			break;
		case sf::Event::TextEntered:
			if (userenabled) {
				if (event.text.unicode >= 32 && event.text.unicode <= 126) {
					sf::String aux;
					aux = this->textuserinput->getString();
					aux += static_cast<char>(event.text.unicode);
					this->textuserinput->setString(aux);
				}
			}
			if (passenabled) {
				if (event.text.unicode >= 32 && event.text.unicode <= 126) {
					sf::String aux;
					aux = this->textpassinput->getString();
					aux += static_cast<char>(event.text.unicode);
					this->textpassinput->setString(aux);
				}
			}
			break;

		default:
			break;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i position = sf::Mouse::getPosition(this->game->window);
			if (position.x > this->userbg.getPosition().x
					&& position.x
							< this->userbg.getPosition().x
									+ this->userbg.getSize().x
					&& position.y > this->userbg.getPosition().y
					&& position.y
							< this->userbg.getPosition().y
									+ this->userbg.getSize().y) {
				this->userenabled = true;
			} else
				this->userenabled = false;

			if (position.x > this->passbg.getPosition().x
					&& position.x
							< this->passbg.getPosition().x
									+ this->passbg.getSize().x
					&& position.y > this->passbg.getPosition().y
					&& position.y
							< this->passbg.getPosition().y
									+ this->passbg.getSize().y) {
				this->passenabled = true;
			} else
				this->passenabled = false;
		}

	}

}
void GameStateLogin::loadTextures() {
	return;
}

void GameStateLogin::loadgame() {
	this->setNext(new London(this->game));
	this->game->pushState(this->nextState);
	return;
}
void GameStateLogin::setNext(GameState* gs) {
	this->nextState = gs;
}

GameStateLogin::~GameStateLogin() {
	delete stmt;
	delete con;
}
