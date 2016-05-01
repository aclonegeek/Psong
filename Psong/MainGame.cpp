#pragma once

#include "MainGame.hpp"

void MainGame::initialize(sf::RenderWindow& window) {
	paddle1.setPlayerOne(true);
	paddle2.setPlayerOne(false);
}

void MainGame::update(sf::RenderWindow& window, const float& dt) {
	paddle1.update(dt);
	paddle2.update(dt);
}

void MainGame::render(sf::RenderWindow& window) {

}

void MainGame::destroy(sf::RenderWindow& window) {

}