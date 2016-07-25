#pragma once
#include <cstdlib>
#include <ctime>

#include "Ball.hpp"

Ball::Ball(Paddle& paddle1, Paddle& paddle2) 
	: m_paddle1(&paddle1)
	, m_paddle2(&paddle2) {
	this->load("ball.png");
}

void Ball::update(const sf::Time dt, const int windowWidth, const int windowHeight) {
	if (m_sprite.getPosition().x < 0) {
		m_paddle2->incrementScore();
		m_sprite.setPosition(windowWidth / 2.0f, windowHeight / 2.0f - m_sprite.getGlobalBounds().height / 2.0f);
	}

	if (m_sprite.getPosition().x + m_sprite.getGlobalBounds().width > windowWidth) {
		m_paddle1->incrementScore();
		m_sprite.setPosition(windowWidth / 2.0f, windowHeight / 2.0f - m_sprite.getGlobalBounds().height / 2.0f);
	}

	if (m_sprite.getPosition().y < 0 ||
		m_sprite.getPosition().y + m_sprite.getGlobalBounds().height > windowHeight) {
		this->velocity.y *= -1;
	}

	Entity::update(dt);
}

void Ball::reset(const int windowWidth, const int windowHeight) {
	std::srand((unsigned int)std::time(0));
	int rand = std::rand() % 4 + 1;
	
	m_sprite.setPosition(windowWidth / 2.0f, windowHeight / 2.0f - m_sprite.getGlobalBounds().height / 2.0f);

	switch (rand) {
	case 1:
		velocity.x = m_speed;
		velocity.y = -m_speed;
		break;
	case 2:
		velocity.x = -m_speed;
		velocity.y = -m_speed;
		break;
	case 3:
		velocity.x = -m_speed;
		velocity.y = m_speed;
		break;
	case 4:
		velocity.x = m_speed;
		velocity.y = m_speed;
		break;
	}
}