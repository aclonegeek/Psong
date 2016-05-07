#pragma once

#include "Paddle.hpp"

Paddle::Paddle(bool playerOne) {
	this->playerOne = playerOne;

	if (this->playerOne) {
		this->load("paddle1.png");
	} else {
		this->load("paddle2.png");
	}
}

void Paddle::setPlayerOne(bool playerOne) {
	this->playerOne = playerOne;
}

void Paddle::update(float dt, int windowWidth, int windowHeight) {
	if (this->playerOne) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			sprite.move(0, -speed * dt);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			sprite.move(0, speed * dt);
		}
	} else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sprite.move(0, -speed * dt);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			sprite.move(0, speed * dt);
		}
	}

	Entity::update(dt);

	if (sprite.getPosition().y < 0) {
		sprite.move(0, speed * dt);
	} else if (sprite.getPosition().y + sprite.getGlobalBounds().height > windowHeight) {
		sprite.move(0, -speed * dt);
	}
}

void Paddle::reset(int windowWidth, int windowHeight) {
	if (this->playerOne) {
		sprite.setPosition(5, windowHeight / 2 - sprite.getGlobalBounds().height / 2);
	} else {
		sprite.setPosition(windowWidth - sprite.getGlobalBounds().width - 5, windowHeight / 2 - sprite.getGlobalBounds().height / 2);
	}
}