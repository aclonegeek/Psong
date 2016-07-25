#pragma once
#include <string>

#include "Entity.hpp"

class Paddle : public Entity {
public:
	Paddle(const bool playerOne);
	void setPlayerOne(const bool playerOne);
	void update(const sf::Time dt, const int windowWidth, const int windowHeight);
	void reset(const int windowWidth, const int windowHeight);
	const std::string getScore() const;
	void incrementScore();
private:
	const float m_speed = 500.0f;
	bool m_playerOne;
	int m_score;
};