/*
 * Kuranes.h
 *
 *  Created on: May 31, 2015
 *      Author: ndy
 */

#ifndef CHARACTERS_KURANES_H_
#define CHARACTERS_KURANES_H_
#include "../body/Body.hpp"

class Kuranes: public Body {
	unsigned int orientation;
public:
	Kuranes(GameState*, Map*, unsigned int, unsigned int);
	void turn(unsigned int);
	unsigned int getOrientation();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	virtual ~Kuranes();
};

#endif /* CHARACTERS_KURANES_H_ */
