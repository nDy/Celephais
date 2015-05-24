/*
 * Menu.hpp
 *
 *  Created on: May 23, 2015
 *      Author: ndy
 */

#ifndef MENU_HPP_
#define MENU_HPP_

#include "GameState.hpp"

class Menu: public GameState {
private:
	sf::View view;
public:
	Menu(Game* game);

	void draw(const float dt);
	void update(const float dt);
	void handleInput();

	virtual ~Menu();
};

#endif /* MENU_HPP_ */
