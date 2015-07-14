/*
 * GameStateGameplay.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: ndy
 */

#include "GameStateGameplay.hpp"
#include "GameStateLoad.hpp"
#include <string>
#include <iostream>

GameStateGameplay::GameStateGameplay(Game* g, TextureManager* tx,
		GameState* next, unsigned int sizex, unsigned int sizey,
		unsigned int playerPosx, unsigned int playerPosy) :
		GameState(g, tx) {

	this->setNext(next);

	this->exitX = 0;
	this->exitY = 0;

	this->world = new World(&view, this, sizex, sizey, playerPosx, playerPosy);

	paused = false;
	saving = false;

	pausebg.setSize(sf::Vector2f(300, 200));
	pausebg.setFillColor(sf::Color(0, 0, 0, 180));
	pausebg.setOutlineColor(sf::Color::White);
	pausebg.setOutlineThickness(4);

	savingbg.setSize(sf::Vector2f(600, 400));
	savingbg.setFillColor(sf::Color(0, 0, 0, 180));
	savingbg.setOutlineColor(sf::Color::White);
	savingbg.setOutlineThickness(4);

	this->f = new sf::Font();
	this->textload = new sf::Text();
	this->textsave = new sf::Text();
	this->textexit = new sf::Text();

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
//pause
	this->textload->setFont(*f);
	this->textload->setString(std::string("Load"));
	this->textload->setCharacterSize(18);
	this->textload->setColor(sf::Color::White);

	this->textsave->setFont(*f);
	this->textsave->setString(std::string("Save"));
	this->textsave->setCharacterSize(18);
	this->textsave->setColor(sf::Color::White);

	this->textexit->setFont(*f);
	this->textexit->setString(std::string("Exit"));
	this->textexit->setCharacterSize(18);
	this->textexit->setColor(sf::Color::White);

	//savegame

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

}

void GameStateGameplay::loadTextures() {

}

void GameStateGameplay::draw(sf::Time dt) {
	this->game->window.setView(this->view);

	this->world->draw();

	if (paused && !saving) {
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
	} else if (paused && saving) {

		this->savingbg.setPosition(
				sf::Vector2f(
						this->world->player->getx()
								- this->savingbg.getSize().x / 2,
						this->world->player->gety()
								- this->savingbg.getSize().y / 2));

		this->texttagone->setPosition(
				this->world->player->getx() - 100
						- this->texttagone->getLocalBounds().width / 2,
				this->world->player->gety() - 100
						- this->texttagone->getLocalBounds().height / 2);
		this->textlvlone->setPosition(
				this->world->player->getx() + 100
						- this->textlvlone->getLocalBounds().width / 2,
				this->world->player->gety() - 100
						- this->textlvlone->getLocalBounds().height / 2);

		this->texttagtwo->setPosition(
				this->world->player->getx() - 100
						- this->texttagone->getLocalBounds().width / 2,
				this->world->player->gety()
						- this->texttagone->getLocalBounds().height / 2);
		this->textlvltwo->setPosition(
				this->world->player->getx() + 100
						- this->textlvlone->getLocalBounds().width / 2,
				this->world->player->gety()
						- this->textlvlone->getLocalBounds().height / 2);

		this->texttagthree->setPosition(
				this->world->player->getx() - 100
						- this->texttagthree->getLocalBounds().width / 2,
				this->world->player->gety() + 100
						- this->texttagthree->getLocalBounds().height / 2);
		this->textlvlthree->setPosition(
				this->world->player->getx() + 100
						- this->textlvlthree->getLocalBounds().width / 2,
				this->world->player->gety() + 100
						- this->textlvlthree->getLocalBounds().height / 2);

		this->game->window.draw(savingbg);
		this->game->window.draw(*texttagone);
		this->game->window.draw(*textlvlone);
		this->game->window.draw(*texttagtwo);
		this->game->window.draw(*textlvltwo);
		this->game->window.draw(*texttagthree);
		this->game->window.draw(*textlvlthree);
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

			if (event.key.code == sf::Keyboard::Escape) {
				paused = !paused;
				saving = false;
			}

			if (!paused)
				world->handleEvents(event);
		}
			break;
		default:
			break;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i position = sf::Mouse::getPosition(this->game->window);

			position.x = position.x + this->world->player->getx()
					- this->game->window.getSize().x / 2;
			position.y = position.y + this->world->player->gety()
					- this->game->window.getSize().y / 2;

			if (paused && !saving) {
				//exit

				if (position.x > this->textexit->getPosition().x
						&& position.x
								< this->textexit->getPosition().x
										+ this->textexit->getLocalBounds().width
						&& position.y > this->textexit->getPosition().y
						&& position.y
								< this->textexit->getPosition().y
										+ this->textexit->getLocalBounds().height) {
					game->window.close();
				}

				//load

				if (position.x > this->textload->getPosition().x
						&& position.x
								< this->textload->getPosition().x
										+ this->textload->getLocalBounds().width
						&& position.y > this->textload->getPosition().y
						&& position.y
								< this->textload->getPosition().y
										+ this->textload->getLocalBounds().height) {
					this->setNext(new GameStateLoad(this->game));
					this->game->changeState(this->nextState);
				}

				//save

				if (position.x > this->textsave->getPosition().x
						&& position.x
								< this->textsave->getPosition().x
										+ this->textsave->getLocalBounds().width
						&& position.y > this->textsave->getPosition().y
						&& position.y
								< this->textsave->getPosition().y
										+ this->textsave->getLocalBounds().height) {
					saving = true;
					this->loadSavegames();
				}

			} else if (paused && saving) {

				//slot 1
				if (position.x > this->texttagone->getPosition().x
						&& position.x
								< this->textlvlone->getPosition().x
										+ this->textlvlone->getLocalBounds().width
						&& position.y > this->texttagone->getPosition().y
						&& position.y
								< this->texttagone->getPosition().y
										+ this->texttagone->getLocalBounds().height) {
					this->save(1);
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
					this->save(2);
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
					this->save(3);
				}

			}
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

void GameStateGameplay::loadSavegames() {
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

void GameStateGameplay::save(int slot) {

	bool add = false;

	switch (slot) {
	case 1:
		if (textlvlone->getString().toAnsiString() == "EMPTY")
			add = true;
		break;
	case 2:
		if (textlvltwo->getString().toAnsiString() == "EMPTY")
			add = true;
		break;
	case 3:
		if (textlvlthree->getString().toAnsiString() == "EMPTY")
			add = true;
		break;
	default:
		break;
	}

	std::string s;

	if (add) {
		//a;adir el usuario a la bd
		s = "INSERT INTO savegames (slot, lvl, x, y, user)";
		s.append("\n");
		s.append("VALUES ('");
		s.append(std::to_string(slot));
		s.append("', '");
		s.append(std::to_string(this->game->currentgameID));
		s.append("', '");
		s.append(std::to_string(this->world->player->getx() / 32));
		s.append("', '");
		s.append(std::to_string(this->world->player->gety() / 32));
		s.append("', '");
		s.append(this->game->currentPlayer);
		s.append("');");
		try {
			this->game->stmt->execute(s);

		} catch (sql::SQLException e) {
			//esto no deberia pasar
		}
	} else {
		//se actualiza la data
		s = "UPDATE savegames SET lvl='";
		s.append(std::to_string(this->game->currentgameID));
		s.append("', x='");
		s.append(std::to_string(this->world->player->getx() / 32));
		s.append("', y='");
		s.append(std::to_string(this->world->player->gety() / 32));
		s.append("'\n");
		s.append("WHERE slot='");
		s.append(std::to_string(slot));
		s.append("' AND user='");
		s.append(this->game->currentPlayer);
		s.append("';");

		try {
			this->game->stmt->execute(s);

		} catch (sql::SQLException e) {
			std::cout << "no se realiza el update con el query: " << s
					<< std::endl;
		}

	}
	this->loadSavegames();
}

void GameStateGameplay::setPlayerPos(unsigned int x, unsigned int y) {
	this->world->player->setPos(x, y);
}

GameStateGameplay::~GameStateGameplay() {
	// TODO Auto-generated destructor stub
}

