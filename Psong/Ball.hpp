#pragma once

#include "Entity.hpp"
#include "Paddle.hpp"

class Ball : public Entity {
public:
	Ball(Paddle& paddle1, Paddle& paddle2);
	void update(const sf::Time dt, const int windowWidth, const int windowHeight);
	void reset(const int windowWidth, const int windowHeight);
private:
	Paddle* m_paddle1;
	Paddle* m_paddle2;
	const float m_speed = 200.0f;
};