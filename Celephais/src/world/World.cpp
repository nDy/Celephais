/*
 * World.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#include "World.hpp"

#include "../body/TalkingBody.hpp"

World::World(sf::View* view, GameState* gs, unsigned int sizex,
		unsigned int sizey) {
	this->d = new std::list<Dialogue>();
	this->view = view;
	this->gs = gs;
	this->map = new Map(sizex, sizey, this->gs); //60*58
	this->view->setSize(800, 600);
	this->view->setCenter(400, 300);

	this->player = new Kuranes(this->gs, this->map, 12, 18);

	this->view->setCenter(player->getx(), player->gety());
	oldx = player->getx();
	oldy = player->gety();

}

bool World::__insertBody(Body* top, unsigned int x, unsigned int y) {
	if (this->map->at(x, y)->top != nullptr)
		return false;
	this->map->at(x, y)->top = top;
	return true;
}

Body*& World::insertBody(std::string name, std::string file, unsigned int type,
		unsigned int x, unsigned int y) {
	static Body* aux;
	switch (type) {
	case Body::SILENT:
		aux = new Body(name, file, this->gs, this->map, x, y, type);
		break;
	case Body::TALKING:
		aux = new TalkingBody(name, file, this->gs, this->map, x, y);
		break;
	default:
		break;
	}

	this->__insertBody(aux, x, y);
	return aux;
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

	if (!this->d->empty())
		d->front().draw();
}

void World::handleEvents(sf::Event event) {
	if (!this->d->empty())
		this->dialogueEvents(event);
	else
		this->mapEvents(event);
}

void World::dialogueEvents(sf::Event event) {
	if (event.key.code == sf::Keyboard::Space) {
		this->d->pop_front();
	}
}

void World::mapEvents(sf::Event event) {
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
	} else if (event.key.code == sf::Keyboard::F) {
		switch (player->getOrientation()) {
		case Body::FRONT:
			if (this->player->gety() / 32 < this->map->getDimY() - 1) {
				if (this->map->at(this->player->getx() / 32,
						this->player->gety() / 32 + 1)->top != nullptr) {
					if (this->map->at(this->player->getx() / 32,
							this->player->gety() / 32 + 1)->top->getType()
							== Body::TALKING) {
						((TalkingBody*) this->map->at(this->player->getx() / 32,
								this->player->gety() / 32 + 1)->top)->speak(d);
					}
				}

			}
			break;
		case Body::BACK:
			if (this->player->gety() != 0) {
				if (this->map->at(this->player->getx() / 32,
						this->player->gety() / 32 - 1)->top != nullptr) {
					if (this->map->at(this->player->getx() / 32,
							this->player->gety() / 32 - 1)->top->getType()
							== Body::TALKING) {
						((TalkingBody*) this->map->at(this->player->getx() / 32,
								this->player->gety() / 32 - 1)->top)->speak(d);
					}
				}

			}
			break;
		case Body::RIGHT:
			if (this->player->getx() / 32 < this->map->getDimX() - 1) {
				if (this->map->at(this->player->getx() / 32 + 1,
						this->player->gety() / 32)->top != nullptr) {
					if (this->map->at(this->player->getx() / 32 + 1,
							this->player->gety() / 32)->top->getType()
							== Body::TALKING) {
						((TalkingBody*) this->map->at(
								this->player->getx() / 32 + 1,
								this->player->gety() / 32)->top)->speak(d);
					}
				}

			}
			break;
		case Body::LEFT:
			if (this->player->getx() != 0) {
				if (this->map->at(this->player->getx() / 32 - 1,
						this->player->gety() / 32)->top != nullptr) {
					if (this->map->at(this->player->getx() / 32 - 1,
							this->player->gety() / 32)->top->getType()
							== Body::TALKING) {
						((TalkingBody*) this->map->at(
								this->player->getx() / 32 - 1,
								this->player->gety() / 32)->top)->speak(d);
					}
				}

			}
			break;
		default:
			break;
		}
	}
}
