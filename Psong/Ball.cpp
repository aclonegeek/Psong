#pragma once

#include "Ball.hpp"

Ball::Ball(Paddle& paddle1, Paddle& paddle2) {
	this->load("ball.png");
	this->paddle1 = &paddle1;
	this->paddle2 = &paddle2;
}

void Ball::update(float dt, int windowWidth, int windowHeight) {
	if (this->checkCollision(*this->paddle1)) {
		this->velocity.x *= -1;
	}

	if (this->checkCollision(*this->paddle2)) {
		this->velocity.x *= -1;
	}

	if (sprite.getPosition().x < 0) {
		sprite.setPosition(windowWidth / 2, windowHeight / 2 - sprite.getGlobalBounds().height / 2);
	}
	if (sprite.getPosition().x + sprite.getGlobalBounds().width > windowWidth) {
		sprite.setPosition(windowWidth / 2, windowHeight / 2 - sprite.getGlobalBounds().height / 2);
	}

	if (sprite.getPosition().y < 0 ||
		sprite.getPosition().y + sprite.getGlobalBounds().height > windowHeight) {
		this->velocity.y *= -1;
	}

	Entity::update(dt);
}