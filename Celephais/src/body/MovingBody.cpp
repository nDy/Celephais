/*
 * MovingBody.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: ndy
 */

#include "MovingBody.hpp"

MovingBody::MovingBody(GameState* gs, Map* m, unsigned int x, unsigned int y) :
		Body("KuranesSS", "media/KuranesSpritesheet.png", gs, m, x, y,
				Body::MOVING) {
	walkingAnimationDown.setSpriteSheet(gs->texmgr->getRef("KuranesSS"));
	walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
	walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimationDown.addFrame(sf::IntRect(0, 0, 32, 32));

	walkingAnimationLeft.setSpriteSheet(gs->texmgr->getRef("KuranesSS"));
	walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
	walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
	walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
	walkingAnimationLeft.addFrame(sf::IntRect(0, 32, 32, 32));

	walkingAnimationRight.setSpriteSheet(gs->texmgr->getRef("KuranesSS"));
	walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
	walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
	walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
	walkingAnimationRight.addFrame(sf::IntRect(0, 64, 32, 32));

	walkingAnimationUp.setSpriteSheet(gs->texmgr->getRef("KuranesSS"));
	walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
	walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
	walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
	walkingAnimationUp.addFrame(sf::IntRect(0, 96, 32, 32));

	this->currentAnimation = &walkingAnimationDown;
	this->orientation = Body::FRONT;

	AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);
	animatedSprite.setPosition(x * 32, y * 32);
}
void MovingBody::turn(unsigned int side) {
	this->orientation = side;
	switch (side) {
	case FRONT:
		currentAnimation = &walkingAnimationDown;
		this->orientation = FRONT;
		break;
	case BACK:
		currentAnimation = &walkingAnimationUp;
		this->orientation = BACK;
		break;
	case LEFT:
		currentAnimation = &walkingAnimationLeft;
		this->orientation = LEFT;
		break;
	case RIGHT:
		currentAnimation = &walkingAnimationRight;
		this->orientation = RIGHT;
		break;
	default:
		break;
	}

}

void MovingBody::moveLeft() {
	this->turn(Body::LEFT);
	this->setPos((this->getx() / 32) - 1, this->gety() / 32);
}

void MovingBody::moveRight() {
	this->turn(Body::RIGHT);
	this->setPos((this->getx() / 32) + 1, (this->gety() / 32));
}

void MovingBody::moveUp() {
	this->turn(Body::BACK);
	this->setPos(this->getx() / 32, (this->gety() / 32) - 1);
}

void MovingBody::moveDown() {
	this->turn(Body::FRONT);
	this->setPos(this->getx() / 32, (this->gety() / 32) + 1);
}

unsigned int MovingBody::getOrientation() {
	return this->orientation;
}

MovingBody::~MovingBody() {
	// TODO Auto-generated destructor stub
}

