#pragma once

#include "Entity.hpp"
#include "Paddle.hpp"

class Ball : public Entity {
public:
	Ball(Paddle& paddle1, Paddle& paddle2);
	void update(float dt, int windowWidth, int windowHeight);
	void reset(int windowWidth, int windowHeight);
private:
	Paddle* paddle1;
	Paddle* paddle2;

	const float speed = 200.0f;
};