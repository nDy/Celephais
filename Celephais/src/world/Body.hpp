/*
 * Body.hpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#ifndef WORLD_BODY_HPP_
#define WORLD_BODY_HPP_

#include <string>
#include "../core/GameState.hpp"

class Map;

class Body {
private:
	std::string type;
	sf::Sprite img;
	GameState* gs;
	unsigned int posx, posy;

	//visibilidad del personaje
	Map* map;
public:
	Body();
	Body(std::string, std::string, GameState*, Map*, unsigned int,
			unsigned int);
	void draw();
	bool setPos(unsigned int, unsigned int);
	unsigned int getx();
	unsigned int gety();
	std::string getType();
	virtual ~Body();
};

#endif /* WORLD_BODY_HPP_ */
