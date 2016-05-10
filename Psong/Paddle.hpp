#pragma once

#include "Entity.hpp"
#include <string>

class Paddle : public Entity {
public:
	Paddle(const bool playerOne);
	void setPlayerOne(const bool playerOne);
	void update(const float dt, const int windowWidth, const int windowHeight);
	void reset(const int windowWidth, const int windowHeight);
	const std::string getScore();
	void incrementScore();
private:
	const float speed = 500.0f;
	bool playerOne;
	int score;
};