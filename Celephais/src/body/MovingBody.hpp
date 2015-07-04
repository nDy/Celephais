/*
 * MovingBody.hpp
 *
 *  Created on: Jul 4, 2015
 *      Author: ndy
 */

#ifndef BODY_MOVINGBODY_HPP_
#define BODY_MOVINGBODY_HPP_
#include "Body.hpp"

class MovingBody: public Body {
	unsigned int orientation;
	Animation walkingAnimationUp;
	Animation walkingAnimationDown;
	Animation walkingAnimationLeft;
	Animation walkingAnimationRight;
public:
	MovingBody(GameState*, Map*, unsigned int, unsigned int);
	void turn(unsigned int);
	unsigned int getOrientation();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	virtual ~MovingBody();
};

#endif /* BODY_MOVINGBODY_HPP_ */
