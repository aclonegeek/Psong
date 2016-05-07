#pragma once

#include "MainGame.hpp"

MainGame::MainGame(): paddle1(true), paddle2(false), ball(paddle1, paddle1) {
	
}

void MainGame::initialize(sf::RenderWindow& window) {

}

void MainGame::update(sf::RenderWindow& window, const float& dt) {
	paddle1.update(dt, window.getSize().x, window.getSize().y);
	paddle2.update(dt, window.getSize().x, window.getSize().y);
}

void MainGame::render(sf::RenderWindow& window) {
	window.draw(paddle1.sprite);
	window.draw(paddle2.sprite);
	window.draw(ball.sprite);
}

void MainGame::destroy(sf::RenderWindow& window) {

}