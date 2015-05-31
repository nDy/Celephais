/*
 * Game.cpp
 *
 *  Created on: May 23, 2015
 *      Author: ndy
 */

#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.hpp"
#include "GameState.hpp"

Game::Game() {

	this->window.create(sf::VideoMode(288, 221), "Celephais");
	this->window.setFramerateLimit(60);

	//world 9x7

}

void Game::pushState(GameState* state) {
	this->states.push(state);

	return;
}

void Game::popState() {
	delete this->states.top();
	this->states.pop();

	return;
}

void Game::changeState(GameState* state) {
	if (!this->states.empty())
		popState();
	pushState(state);

	return;
}

GameState* Game::peekState() {
	if (this->states.empty())
		return nullptr;
	return this->states.top();
}

void Game::gameLoop() {
	sf::Clock clock;

	while (this->window.isOpen()) {
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr)
			continue;
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();
	}
}

Game::~Game() {
	while (!this->states.empty())
		popState();
}

