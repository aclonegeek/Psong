#pragma once

#include "Entity.hpp"
#include "Paddle.hpp"

class Ball : public Entity {
public:
	Ball(Paddle& paddle1, Paddle& paddle2);
	void update(const float dt, const int windowWidth, const int windowHeight);
	void reset(const int windowWidth, const int windowHeight);
private:
	Paddle* paddle1;
	Paddle* paddle2;
	const float speed = 200.0f;
};