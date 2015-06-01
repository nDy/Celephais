/*
 * World.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#include "World.h"

World::World(sf::View* view, GameState* gs) {
	this->view = view;
	this->gs = gs;
	this->map = new Map(9, 7, this->gs);
	this->view->setSize(288, 221);
	this->view->setCenter(144, 110);

	this->player = new Kuranes(this->gs, this->map, 2, 2);
	this->map->at(4, 0)->top = new Body("Obstacle", "media/testToken.png", this->gs,
			this->map, 4, 0, Body::SILENT);
	this->map->at(4, 1)->top = new Body("Obstacle", "media/testToken.png", this->gs,
			this->map, 4, 1, Body::SILENT);
	this->map->at(4, 2)->top = new Body("Obstacle", "media/testToken.png", this->gs,
			this->map, 4, 2, Body::SILENT);
	this->map->at(4, 3)->top = new Body("Obstacle", "media/testToken.png", this->gs,
			this->map, 4, 3, Body::SILENT);
	this->map->at(4, 4)->top = new Body("Obstacle", "media/testToken.png", this->gs,
			this->map, 4, 4, Body::SILENT);
	this->view->setCenter(player->getx(), player->gety());
	oldx = player->getx();
	oldy = player->gety();

}

World::~World() {
	// TODO Auto-generated destructor stub
}

void World::draw() {
	if (this->oldx != this->player->getx()
			|| this->oldy != this->player->gety()) {
		this->view->move((float) this->player->getx() - (float) this->oldx,
				(float) this->player->gety() - (float) this->oldy);
		this->gs->game->window.setView(*this->view);
		this->oldx = this->player->getx();
		this->oldy = this->player->gety();
	}

	this->map->draw();
}

void World::handleEvents(sf::Event event) {
	if (event.key.code == sf::Keyboard::Escape)
		this->gs->game->window.close();
	else if (event.key.code == sf::Keyboard::Right) {
		player->moveRight();
	} else if (event.key.code == sf::Keyboard::Left) {
		player->moveLeft();
	} else if (event.key.code == sf::Keyboard::Up) {
		player->moveUp();
	} else if (event.key.code == sf::Keyboard::Down) {
		player->moveDown();
	}
}
