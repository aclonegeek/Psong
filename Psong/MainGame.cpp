#pragma once

#include "MainGame.hpp"

MainGame::MainGame()
	: paddle1(true)
	, paddle2(false)
	, ball(paddle1, paddle1) {

}

void MainGame::initialize(const sf::RenderWindow& window) {
	ball.reset(window.getSize().x, window.getSize().y);
	paddle1.reset(window.getSize().x, window.getSize().y);
	paddle2.reset(window.getSize().x, window.getSize().y);

	font.loadFromFile("assets/gfx/monoton.ttf");
	score1.setFont(font);
	score2.setFont(font);

	score1.setColor(sf::Color::White);
	score2.setColor(sf::Color::White);

	score1.setString("0");
	score2.setString("0");

	score1.setPosition(3, 3);
	score2.setPosition(window.getSize().x - score2.getGlobalBounds().width - 3, 3);
}

void MainGame::update(const sf::RenderWindow& window, const float& dt) {
	ball.update(dt, window.getSize().x, window.getSize().y);
	paddle1.update(dt, window.getSize().x, window.getSize().y);
	paddle2.update(dt, window.getSize().x, window.getSize().y);

	if (ball.checkCollision(paddle1) || ball.checkCollision(paddle2)) {
		ball.velocity.x *= -1;
	}
}

void MainGame::render(sf::RenderWindow& window) {
	window.draw(score1);
	window.draw(score2);
	window.draw(ball.getSprite());
	window.draw(paddle1.getSprite());
	window.draw(paddle2.getSprite());
}

void MainGame::destroy(const sf::RenderWindow& window) {

}

void MainGame::reset(const sf::RenderWindow& window) {
	ball.reset(window.getSize().x, window.getSize().y);
	paddle1.reset(window.getSize().x, window.getSize().y);
	paddle2.reset(window.getSize().x, window.getSize().y);
	score1.setString("0");
	score2.setString("0");
}