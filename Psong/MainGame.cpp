#pragma once

#include "MainGame.hpp"

MainGame::MainGame()
	: paddle1(true)
	, paddle2(false)
	, ball(paddle1, paddle1) {

}

void MainGame::initialize(sf::RenderWindow& window) {
	ball.reset(window.getSize().x, window.getSize().y);
	paddle1.reset(window.getSize().x, window.getSize().y);
	paddle2.reset(window.getSize().x, window.getSize().y);
}

void MainGame::update(sf::RenderWindow& window, const float& dt) {
	ball.update(dt, window.getSize().x, window.getSize().y);
	paddle1.update(dt, window.getSize().x, window.getSize().y);
	paddle2.update(dt, window.getSize().x, window.getSize().y);
}

void MainGame::render(sf::RenderWindow& window) {
	window.draw(paddle1.getSprite());
	window.draw(paddle2.getSprite());
	window.draw(ball.getSprite());
}

void MainGame::destroy(sf::RenderWindow& window) {

}