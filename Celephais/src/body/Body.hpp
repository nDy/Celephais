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
#include "../utils/Animation.hpp"
#include "../utils/AnimatedSprite.hpp"

class Map;

class Body {
public:
	enum {
		FRONT, BACK, LEFT, RIGHT, MOVING, TALKING, SILENT
	};

private:
	unsigned int type;
	std::string name;
	sf::Sprite img; //single framed

	unsigned int posx, posy;

	//visibilidad del personaje
	Map* map;
public:
	// set up AnimatedSprite
	AnimatedSprite animatedSprite;
	Animation* currentAnimation;

	GameState* gs;
	Body();
	Body(std::string, std::string, GameState*, Map*, unsigned int, unsigned int,
			unsigned int);
	void update(sf::Time);
	void draw();

	bool setPos(unsigned int, unsigned int);
	bool setMapPos(unsigned int, unsigned int);
	void setTexture(sf::Texture&);
	void setType(unsigned int type);
	void setName(const std::string& name);
	void setMap(Map*);

	sf::Texture* getTexture();
	unsigned int getx();
	unsigned int gety();
	std::string getName();
	unsigned int getType();

	virtual ~Body();

};

#endif /* WORLD_BODY_HPP_ */
