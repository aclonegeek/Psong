#pragma once

#include "Entity.hpp"
#include "Paddle.hpp"

class Ball : public Entity {
public:
	Ball();
	void update(const float dt, const int windowWidth, const int windowHeight);
	void reset(const int windowWidth, const int windowHeight);
private:
	const float speed = 200.0f;
};