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

class Body {
private:
	std::string type;
	sf::Sprite img;
	GameState* gs;
	unsigned int posx,posy;
public:
	Body(std::string, std::string, GameState*);
	void draw();
	void setPos(unsigned int,unsigned int);
	unsigned int getx();
	unsigned int gety();
	virtual ~Body();
};

#endif /* WORLD_BODY_HPP_ */
