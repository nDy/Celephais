/*
 * Kuranes.h
 *
 *  Created on: May 31, 2015
 *      Author: ndy
 */

#ifndef CHARACTERS_KURANES_H_
#define CHARACTERS_KURANES_H_
#include "../world/Body.hpp"

class Kuranes: public Body {
public:
	Kuranes(GameState*, Map*, unsigned int, unsigned int);
	void turn(unsigned int);
	virtual ~Kuranes();
};

#endif /* CHARACTERS_KURANES_H_ */
