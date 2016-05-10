#pragma once

#include "Ball.hpp"
#include <cstdlib>
#include <ctime>

Ball::Ball(Paddle& paddle1, Paddle& paddle2) 
	: paddle1(&paddle1)
	, paddle2(&paddle2) {
	this->load("ball.png");
}

void Ball::update(const float dt, const int windowWidth, const int windowHeight) {
	if (sprite.getPosition().x < 0) {
		paddle2->incrementScore();
		sprite.setPosition(windowWidth / 2, windowHeight / 2 - sprite.getGlobalBounds().height / 2);
	}

	if (sprite.getPosition().x + sprite.getGlobalBounds().width > windowWidth) {
		paddle1->incrementScore();
		sprite.setPosition(windowWidth / 2, windowHeight / 2 - sprite.getGlobalBounds().height / 2);
	}

	if (sprite.getPosition().y < 0 ||
		sprite.getPosition().y + sprite.getGlobalBounds().height > windowHeight) {
		this->velocity.y *= -1;
	}

	Entity::update(dt);
}

void Ball::reset(const int windowWidth, const int windowHeight) {
	std::srand(std::time(0));
	int rand = std::rand() % 4 + 1;
	
	sprite.setPosition(windowWidth / 2, windowHeight / 2 - sprite.getGlobalBounds().height / 2);

	switch (rand) {
	case 1:
		velocity.x = speed;
		velocity.y = -speed;
		break;
	case 2:
		velocity.x = -speed;
		velocity.y = -speed;
		break;
	case 3:
		velocity.x = -speed;
		velocity.y = speed;
		break;
	case 4:
		velocity.x = speed;
		velocity.y = speed;
		break;
	}
}