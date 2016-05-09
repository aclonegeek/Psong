#pragma once

#include "Entity.hpp"

class Paddle : public Entity {
public:
	Paddle(bool playerOne);
	void setPlayerOne(bool playerOne);
	void update(float dt, int windowWidth, int windowHeight);
	void reset(int windowWidth, int windowHeight);
	const int getScore();
	void incrementScore();
private:
	const float speed = 500.0f;
	bool playerOne;
	int score;
};