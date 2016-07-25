#pragma once

#include "Paddle.hpp"

Paddle::Paddle(const bool m_playerOne) 
	: m_playerOne(m_playerOne)
	, m_score(0) {
	if (m_playerOne) {
		load("paddle1.png");
	} else {
		load("paddle2.png");
	}
}

void Paddle::setPlayerOne(const bool playerOne) {
	m_playerOne = playerOne;
}

void Paddle::update(const sf::Time dt, const int windowWidth, const int windowHeight) {
	if (m_playerOne) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			m_sprite.move(0, -m_speed * dt.asSeconds());
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			m_sprite.move(0, m_speed * dt.asSeconds());
		}
	} else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			m_sprite.move(0, -m_speed * dt.asSeconds());
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			m_sprite.move(0, m_speed * dt.asSeconds());
		}
	}

	Entity::update(dt);

	if (m_sprite.getPosition().y < 0) {
		m_sprite.move(0, m_speed * dt.asSeconds());
	} else if (m_sprite.getPosition().y + m_sprite.getGlobalBounds().height > windowHeight) {
		m_sprite.move(0, -m_speed * dt.asSeconds());
	}
}

void Paddle::reset(const int windowWidth, const int windowHeight) {
	m_score = 0;
	
	if (m_playerOne) {
		m_sprite.setPosition(5, windowHeight / 2 - m_sprite.getGlobalBounds().height / 2);
	} else {
		m_sprite.setPosition(windowWidth - m_sprite.getGlobalBounds().width - 5, windowHeight / 2 - m_sprite.getGlobalBounds().height / 2);
	}
}

const std::string Paddle::getScore() const {
	return std::to_string(m_score);
}

void Paddle::incrementScore() {
	m_score++;
}