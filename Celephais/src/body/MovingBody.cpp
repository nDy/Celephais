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
	this->setMapPos((this->getx() / 32) - 1, this->gety() / 32);
	//this->setPos((this->getx() / 32) - 1, this->gety() / 32);
	this->moving = true;
}

void MovingBody::moveRight() {
	this->turn(Body::RIGHT);
	this->setMapPos((this->getx() / 32) + 1, (this->gety() / 32));
	//this->setPos((this->getx() / 32) + 1, (this->gety() / 32));
	this->moving = true;
}

void MovingBody::moveUp() {
	this->turn(Body::BACK);
	this->setMapPos(this->getx() / 32, (this->gety() / 32) - 1);
	//this->setPos(this->getx() / 32, (this->gety() / 32) - 1);
	this->moving = true;
}

void MovingBody::moveDown() {
	this->turn(Body::FRONT);
	this->setMapPos(this->getx() / 32, (this->gety() / 32) + 1);
	//this->setPos(this->getx() / 32, (this->gety() / 32) + 1);
	this->moving = true;
}

unsigned int MovingBody::getOrientation() {
	return this->orientation;
}

void MovingBody::update(sf::Time dt) {
	if (this->moving) {
		switch (this->getOrientation()) {
		case Body::FRONT:
			animatedSprite.setPosition(animatedSprite.getPosition().x,
					animatedSprite.getPosition().y + 32 * dt.asSeconds());
			if (animatedSprite.getPosition().y >= this->gety()) {
				animatedSprite.setPosition(this->getx(), this->gety());
				animatedSprite.stop();
				this->moving = false;
			}
			break;
		case Body::BACK:
			animatedSprite.setPosition(animatedSprite.getPosition().x,
					animatedSprite.getPosition().y - 32 * dt.asSeconds());
			if (animatedSprite.getPosition().y <= this->gety()) {
				animatedSprite.setPosition(this->getx(), this->gety());
				animatedSprite.stop();
				this->moving = false;
			}
			break;
		case Body::RIGHT:
			animatedSprite.setPosition(
					animatedSprite.getPosition().x + 32 * dt.asSeconds(),
					animatedSprite.getPosition().y);
			if (animatedSprite.getPosition().x >= this->getx()) {
				animatedSprite.setPosition(this->getx(), this->gety());
				animatedSprite.stop();
				this->moving = false;
			}
			break;
		case Body::LEFT:
			animatedSprite.setPosition(
					animatedSprite.getPosition().x - 32 * dt.asSeconds(),
					animatedSprite.getPosition().y);
			if (animatedSprite.getPosition().x <= this->getx()) {
				animatedSprite.setPosition(this->getx(), this->gety());
				animatedSprite.stop();
				this->moving = false;
			}
			break;
		default:
			break;
		}
	}
	if (moving)
		animatedSprite.update(dt);
}

MovingBody::~MovingBody() {
	// TODO Auto-generated destructor stub
}

