/*
 * GameStateLogin.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "GameStateLogin.hpp"

#include "GameStateLoad.hpp"

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
	userbg.setOutlineColor(sf::Color::Black);
	passbg.setOutlineColor(sf::Color::Black);
	userbg.setOutlineThickness(4);
	passbg.setOutlineThickness(4);

	newuserbg.setSize(sf::Vector2f(200, 40));
	newpassbg.setSize(sf::Vector2f(200, 40));
	newuserbg.setPosition(
			sf::Vector2f(400, this->game->window.getSize().y / 2 - 30));
	newpassbg.setPosition(
			sf::Vector2f(400, this->game->window.getSize().y / 2 + 30));
	newuserbg.setFillColor(sf::Color::White);
	newpassbg.setFillColor(sf::Color::White);
	newuserbg.setOutlineColor(sf::Color::Black);
	newpassbg.setOutlineColor(sf::Color::Black);
	newuserbg.setOutlineThickness(4);
	newpassbg.setOutlineThickness(4);

	this->f = new sf::Font();
	this->textpass = new sf::Text();
	this->textpassinput = new sf::Text();
	this->textuser = new sf::Text();
	this->textuserinput = new sf::Text();
	this->textnewpass = new sf::Text();
	this->textnewpassinput = new sf::Text();
	this->textnewuser = new sf::Text();
	this->textnewuserinput = new sf::Text();

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

	this->textnewuser->setFont(*f);
	this->textnewuser->setString(std::string("Usuario:"));
	this->textnewuser->setCharacterSize(24);
	this->textnewuser->setColor(sf::Color::White);
	this->textnewuser->setPosition(650,
			this->game->window.getSize().y / 2 - 30);

	this->textnewpass->setFont(*f);
	this->textnewpass->setString(std::string("Pass:"));
	this->textnewpass->setCharacterSize(24);
	this->textnewpass->setColor(sf::Color::White);
	this->textnewpass->setPosition(650,
			this->game->window.getSize().y / 2 + 30);

	this->textnewuserinput->setFont(*f);
	this->textnewuserinput->setString(std::string(""));
	this->textnewuserinput->setCharacterSize(24);
	this->textnewuserinput->setColor(sf::Color::Black);
	this->textnewuserinput->setPosition(850,
			this->game->window.getSize().y / 2 - 30);

	this->textnewpassinput->setFont(*f);
	this->textnewpassinput->setString(std::string(""));
	this->textnewpassinput->setCharacterSize(24);
	this->textnewpassinput->setColor(sf::Color::Black);
	this->textnewpassinput->setPosition(850,
			this->game->window.getSize().y / 2 + 30);

	this->game->window.setView(this->view);

	this->userenabled = false;
	this->passenabled = false;

	//button
	buttonLogin.setSize(sf::Vector2f(200, 40));
	buttonLogin.setPosition(
			sf::Vector2f(400, this->game->window.getSize().y / 2 + 100));
	buttonLogin.setFillColor(sf::Color::White);
	buttonLogin.setOutlineColor(sf::Color::Black);
	buttonLogin.setOutlineThickness(4);

	this->textButtonLogin = new sf::Text(sf::String("Iniciar sesion"), *f, 20);
	this->textButtonLogin->setColor(sf::Color::Black);
	this->textButtonLogin->setPosition(420,
			this->game->window.getSize().y / 2 + 105);

	this->game->res = nullptr;

	this->texmgr->loadTexture("LoginBg", "media/LoginBg.png");
	this->background.setTexture(this->texmgr->getRef("LoginBg"));

	//newbs?
	this->textnewb = new sf::Text();
	this->textnewb->setFont(*f);
	this->textnewb->setString(std::string("Am I a newb?"));
	this->textnewb->setCharacterSize(16);
	this->textnewb->setColor(sf::Color::White);
	this->textnewb->setPosition(400, this->game->window.getSize().y / 2 + 160);

	newbcheckbox.setSize(sf::Vector2f(10, 10));
	newbcheckbox.setPosition(
			sf::Vector2f(550, this->game->window.getSize().y / 2 + 165));
	newbcheckbox.setFillColor(sf::Color(255, 255, 255, 100));
	newbcheckbox.setOutlineColor(sf::Color::Black);
	newbcheckbox.setOutlineThickness(4);

	newb = false;
	login = true;

	//open db connection

	/* Create a connection */
	this->game->driver = get_driver_instance();
	this->game->con = this->game->driver->connect("localhost", "game",
			"150553");
	/* Connect to the MySQL test database */
	this->game->con->setSchema("project");

	this->game->stmt = this->game->con->createStatement();
}

void GameStateLogin::draw(sf::Time dt) {
	//draw bg
	this->game->window.draw(this->background);

	//draw username textbox
	this->game->window.draw(userbg);
	this->game->window.draw(*textuser);
	this->game->window.draw(*textuserinput);

	//draw pass textbox
	this->game->window.draw(passbg);
	this->game->window.draw(*textpass);
	this->game->window.draw(*textpassinput);

	//draw button
	this->game->window.draw(buttonLogin);
	this->game->window.draw(*textButtonLogin);

	this->game->window.draw(newbcheckbox);
	this->game->window.draw(*textnewb);

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
				int x = this->loginAttempt();
				if (x == 0) {
					//el usuario no existe
				} else if (x == 1) {
					//password incorrecto
				} else {
					//esto no deberia pasar
				}
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
//cuadros de texto
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

			//	boton
			if (position.x > this->buttonLogin.getPosition().x
					&& position.x
							< this->buttonLogin.getPosition().x
									+ this->buttonLogin.getSize().x
					&& position.y > this->buttonLogin.getPosition().y
					&& position.y
							< this->buttonLogin.getPosition().y
									+ this->buttonLogin.getSize().y) {
				//loadgame
				int x = this->loginAttempt();
				if (x == 0) {
					//el usuario no existe
				} else if (x == 1) {
					//password incorrecto
				} else {
					//esto no deberia pasar
				}

			}

			if (position.x > this->newbcheckbox.getPosition().x
					&& position.x
							< this->newbcheckbox.getPosition().x
									+ this->newbcheckbox.getSize().x
					&& position.y > this->newbcheckbox.getPosition().y
					&& position.y
							< this->newbcheckbox.getPosition().y
									+ this->newbcheckbox.getSize().y) {
				newb = !newb;
				if (newb)
					this->newbcheckbox.setFillColor(sf::Color(0, 0, 0, 100));
				else
					this->newbcheckbox.setFillColor(
							sf::Color(255, 255, 255, 100));
			}
		}
	}
}

void GameStateLogin::loadTextures() {
	return;
}

void GameStateLogin::loadgame() {
	this->setNext(new ::GameStateLoad(this->game));
	this->game->pushState(this->nextState);
	return;
}
void GameStateLogin::setNext(GameState* gs) {
	this->nextState = gs;
}

int GameStateLogin::loginAttempt() {
	if (newb) {
		//a;adir el usuario a la bd
		std::string s;
		s = "INSERT INTO users (user, pass)";
		s.append("\n");
		s.append("VALUES ('");
		s.append(this->textuserinput->getString().toAnsiString());
		s.append("', '");
		s.append(this->textpassinput->getString().toAnsiString());
		s.append("');");
		try {
			this->game->stmt->execute(s);
			this->game->currentPlayer.clear();
			this->game->currentPlayer.append(
					this->textuserinput->getString().toAnsiString());

			this->loadgame();

		} catch (sql::SQLException e) {
			//el usuario ya se encuentra en la bd
		}

	} else {
		//iniciar sesion si los datos del usuario son correctos
		std::string s;
		s = "SELECT pass FROM users WHERE user = '";
		s.append(this->textuserinput->getString().toAnsiString());
		s.append("';");
		this->game->res = this->game->stmt->executeQuery(s);
		if (!this->game->res->next()) {
			//std::cout << "el usuario no existe" << std::endl;
			return 0;
		}
		if (this->game->res->getString("pass")
				== this->textpassinput->getString().toAnsiString()) {
			//el juego carga
			this->game->currentPlayer.clear();
			this->game->currentPlayer.append(
					this->textuserinput->getString().toAnsiString());
			this->loadgame();
		} else {
			//std::cout << "password incorrecto" << std::endl;
			return 1;
		}
	}
}

GameStateLogin::~GameStateLogin() {
}
