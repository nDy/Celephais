/*
 * Intro.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: ndy
 */

#include "Intro.hpp"

Intro::Intro(Game* game) :
		GameStateCinematic(game, new TextureManager()) {

// intro buildup

	this->addDialogue(
			Dialogue("In a dream Kuranes saw the city in the valley...", this));

	this->addDialogue(
			Dialogue("...and the seacoast beyond, and the snowy peak...",
					this));
	this->addDialogue(Dialogue("...overlooking the sea", this));
	this->addDialogue(Dialogue("And the gaily painted galleys...", this));
	this->addDialogue(Dialogue("...that sail out of the harbor", this));
	this->addDialogue(Dialogue("Toward distant regions where...", this));
	this->addDialogue(Dialogue("...where the sea meets the sky.", this));
	this->addBackground("first", "media/Intro/View1.png");

	this->addDialogue(Dialogue("In a dream it was also...", this));
	this->addDialogue(Dialogue("that he came by his name of Kuranes...", this));
	this->addDialogue(
			Dialogue("for when awake he was called by another name.", this));

	this->addBackground("second", "media/Intro/View2.png");
}

Intro::~Intro() {
}

