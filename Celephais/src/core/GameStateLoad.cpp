/*
 * GameStateLoad.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: ndy
 */

#include "GameStateLoad.hpp"

#include "../scenes/Intro.hpp"
#include "../scenes/London.hpp"
#include "../scenes/Room.hpp"

GameStateLoad::GameStateLoad(Game* game) :
		GameState(game, new TextureManager()) {
	this->view = this->game->window.getView();
	// TODO Auto-generated constructor stub

	this->texmgr->loadTexture("LoginBg", "media/LoginBg.png");
	this->background.setTexture(this->texmgr->getRef("LoginBg"));

	this->texttagone = new sf::Text();
	this->textlvlone = new sf::Text();

	this->texttagtwo = new sf::Text();
	this->textlvltwo = new sf::Text();

	this->texttagthree = new sf::Text();
	this->textlvlthree = new sf::Text();

	this->f = new sf::Font();
	if (!this->f->loadFromFile("fonts/Dialogue.ttf")) {
		// error...
	}

	this->texttagone->setFont(*f);
	this->texttagone->setString(std::string("First Slot:"));
	this->texttagone->setCharacterSize(18);
	this->texttagone->setColor(sf::Color::White);

	this->texttagtwo->setFont(*f);
	this->texttagtwo->setString(std::string("Second Slot:"));
	this->texttagtwo->setCharacterSize(18);
	this->texttagtwo->setColor(sf::Color::White);

	this->texttagthree->setFont(*f);
	this->texttagthree->setString(std::string("Third Slot:"));
	this->texttagthree->setCharacterSize(18);
	this->texttagthree->setColor(sf::Color::White);

	this->textlvlone->setFont(*f);
	this->textlvlone->setString(std::string(""));
	this->textlvlone->setCharacterSize(18);
	this->textlvlone->setColor(sf::Color::White);

	this->textlvltwo->setFont(*f);
	this->textlvltwo->setString(std::string(""));
	this->textlvltwo->setCharacterSize(18);
	this->textlvltwo->setColor(sf::Color::White);

	this->textlvlthree->setFont(*f);
	this->textlvlthree->setString(std::string(""));
	this->textlvlthree->setCharacterSize(18);
	this->textlvlthree->setColor(sf::Color::White);

	this->savingbg.setPosition(
			sf::Vector2f(
					this->game->window.getSize().x / 2
							- this->savingbg.getSize().x / 2,
					this->game->window.getSize().y / 2
							- this->savingbg.getSize().y / 2));

	this->texttagone->setPosition(
			this->game->window.getSize().x / 2 - 100
					- this->texttagone->getLocalBounds().width / 2,
			this->game->window.getSize().y / 2 - 100
					- this->texttagone->getLocalBounds().height / 2);
	this->textlvlone->setPosition(
			this->game->window.getSize().x / 2 + 100
					- this->textlvlone->getLocalBounds().width / 2,
			this->game->window.getSize().y / 2 - 100
					- this->textlvlone->getLocalBounds().height / 2);

	this->texttagtwo->setPosition(
			this->game->window.getSize().x / 2 - 100
					- this->texttagone->getLocalBounds().width / 2,
			this->game->window.getSize().y / 2
					- this->texttagone->getLocalBounds().height / 2);
	this->textlvltwo->setPosition(
			this->game->window.getSize().x / 2 + 100
					- this->textlvlone->getLocalBounds().width / 2,
			this->game->window.getSize().y / 2
					- this->textlvlone->getLocalBounds().height / 2);

	this->texttagthree->setPosition(
			this->game->window.getSize().x / 2 - 100
					- this->texttagthree->getLocalBounds().width / 2,
			this->game->window.getSize().y / 2 + 100
					- this->texttagthree->getLocalBounds().height / 2);
	this->textlvlthree->setPosition(
			this->game->window.getSize().x / 2 + 100
					- this->textlvlthree->getLocalBounds().width / 2,
			this->game->window.getSize().y / 2 + 100
					- this->textlvlthree->getLocalBounds().height / 2);

	this->loadSavegames();

	//button
	buttonNew.setSize(sf::Vector2f(200, 40));
	buttonNew.setPosition(sf::Vector2f(500, 500));
	buttonNew.setFillColor(sf::Color::White);
	buttonNew.setOutlineColor(sf::Color::Black);
	buttonNew.setOutlineThickness(4);

	this->textButtonNew = new sf::Text(sf::String("New Game"), *f, 20);
	this->textButtonNew->setColor(sf::Color::Black);
	this->textButtonNew->setPosition(520, 505);

}

void GameStateLoad::draw(sf::Time dt) {
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	pos *= 0.5f;
	this->view.setCenter(pos);
	//draw bg
	this->game->window.draw(this->background);

	this->game->window.draw(savingbg);
	this->game->window.draw(*texttagone);
	this->game->window.draw(*textlvlone);
	this->game->window.draw(*texttagtwo);
	this->game->window.draw(*textlvltwo);
	this->game->window.draw(*texttagthree);
	this->game->window.draw(*textlvlthree);
	this->game->window.draw(buttonNew);
	this->game->window.draw(*textButtonNew);
}

void GameStateLoad::update(sf::Time dt) {

}

void GameStateLoad::handleInput() {

	sf::Event event;

	while (this->game->window.pollEvent(event)) {

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i position = sf::Mouse::getPosition(this->game->window);

			//slot 1
			if (position.x > this->texttagone->getPosition().x
					&& position.x
							< this->textlvlone->getPosition().x
									+ this->textlvlone->getLocalBounds().width
					&& position.y > this->texttagone->getPosition().y
					&& position.y
							< this->texttagone->getPosition().y
									+ this->texttagone->getLocalBounds().height) {
				this->load(1);
			}

			//slot 2
			if (position.x > this->texttagtwo->getPosition().x
					&& position.x
							< this->textlvltwo->getPosition().x
									+ this->textlvltwo->getLocalBounds().width
					&& position.y > this->texttagtwo->getPosition().y
					&& position.y
							< this->texttagtwo->getPosition().y
									+ this->texttagtwo->getLocalBounds().height) {
				this->load(2);
			}

			//slot 3
			if (position.x > this->texttagthree->getPosition().x
					&& position.x
							< this->textlvlthree->getPosition().x
									+ this->textlvlthree->getLocalBounds().width
					&& position.y > this->texttagthree->getPosition().y
					&& position.y
							< this->texttagthree->getPosition().y
									+ this->texttagthree->getLocalBounds().height) {
				this->load(3);
			}

			if (position.x > this->buttonNew.getPosition().x
					&& position.x
							< this->buttonNew.getPosition().x
									+ this->buttonNew.getSize().x
					&& position.y > this->buttonNew.getPosition().y
					&& position.y
							< this->buttonNew.getPosition().y
									+ this->buttonNew.getSize().y) {
				this->setNext(new ::Intro(this->game));
				this->game->pushState(this->nextState);
			}
		}
	}
}

void GameStateLoad::loadTextures() {

}

void GameStateLoad::setNext(GameState* gs) {
	this->nextState = gs;
}

void GameStateLoad::loadSavegames() {
	//iniciar sesion si los datos del usuario son correctos
	std::string s;
	s = "SELECT * FROM savegames WHERE user = '";
	s.append(this->game->currentPlayer);
	s.append("';");
	this->game->res = this->game->stmt->executeQuery(s);

	bool one, two, three;
	one = false;
	two = false;
	three = false;

	while (this->game->res->next()) {
		if (this->game->res->getInt("slot") == 1) {
			textlvlone->setString(
					sf::String(std::to_string(this->game->res->getInt("lvl"))));
			one = true;
		} else if (this->game->res->getInt("slot") == 2) {
			textlvltwo->setString(
					sf::String(std::to_string(this->game->res->getInt("lvl"))));
			two = true;
		} else if (this->game->res->getInt("slot") == 3) {
			textlvlthree->setString(
					sf::String(std::to_string(this->game->res->getInt("lvl"))));
			three = true;
		}
	}

	if (!one)
		textlvlone->setString("EMPTY");

	if (!two)
		textlvltwo->setString("EMPTY");

	if (!three)
		textlvlthree->setString("EMPTY");

}

void GameStateLoad::load(int slot) {

	switch (slot) {
	case 1:
		if (textlvlone->getString().toAnsiString() == "EMPTY")
			return;
		break;
	case 2:
		if (textlvltwo->getString().toAnsiString() == "EMPTY")
			return;
		break;
	case 3:
		if (textlvlthree->getString().toAnsiString() == "EMPTY")
			return;
		break;
	default:
		break;
	}

	std::string s;

	s = "SELECT * from savegames ";
	s.append("WHERE slot='");
	s.append(std::to_string(slot));
	s.append("' AND user='");
	s.append(this->game->currentPlayer);
	s.append("';");

	this->game->res = this->game->stmt->executeQuery(s);
	if (!this->game->res->next()) {
		//std::cout << "el usuario no existe" << std::endl;
		return;
	}
	GameStateGameplay* aux;
	switch (this->game->res->getInt("lvl")) {
	case Level::London:
		aux = new ::London(this->game);
		std::cout << "crea londres" << std::endl;
		break;
	case Level::Room:
		aux = new ::Room(this->game);
		std::cout << "crea habitacion" << std::endl;
		break;
	default:
		break;
	}
	std::cout << "lvl guardado cargado" << std::endl;
	aux->setPlayerPos(this->game->res->getInt("x"),
			this->game->res->getInt("y"));
	std::cout << "personaje movido" << std::endl;
	this->setNext(aux);
	std::cout << "setnext done" << std::endl;
	this->game->pushState(this->nextState);

}

GameStateLoad::~GameStateLoad() {
	// TODO Auto-generated destructor stub
}

