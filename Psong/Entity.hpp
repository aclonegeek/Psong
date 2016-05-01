#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity {
public:
	Entity(std::string filename) {
		texture.loadFromFile("assets/gfx/sprites/" + filename);
	}

	virtual void load(std::string filename) {
		texture.loadFromFile("assets/gfx/sprites/" + filename);
		sprite.setTexture(texture);
	}

	virtual void update() {
		sprite.move(velocity.x, velocity.y);
	}

	bool checkCollision(sf::Sprite sprite) {
		return this->sprite.getGlobalBounds().intersects(sprite.getGlobalBounds());
	}

	sf::Vector2f velocity;
private:
	sf::Texture texture;
	sf::Sprite sprite;
};