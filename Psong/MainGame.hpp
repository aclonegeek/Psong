#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"

class MainGame {
public:
	MainGame();
	void initialize(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, const float& dt);
	void render(sf::RenderWindow& window);
	void destroy(sf::RenderWindow& window);
private:
	Ball ball;
	Paddle paddle1;
	Paddle paddle2;
	sf::Font font;
	sf::Text score1;
	sf::Text score2;
};