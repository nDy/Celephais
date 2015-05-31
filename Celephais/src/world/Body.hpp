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
public:
	enum {
		FRONT, BACK, LEFT, RIGHT
	};
private:
	std::string type;
	sf::Sprite img;
	unsigned int posx, posy;

	//visibilidad del personaje
	Map* map;
public:
	GameState* gs;
	Body();
	Body(std::string, std::string, GameState*, Map*, unsigned int,
			unsigned int);
	void draw();
	bool setPos(unsigned int, unsigned int);
	void setTexture(sf::Texture&);
	unsigned int getx();
	unsigned int gety();
	std::string getType();
	virtual ~Body();
};

#endif /* WORLD_BODY_HPP_ */
