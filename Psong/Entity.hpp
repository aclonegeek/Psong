#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity {
public:
	Entity() {

	}

	virtual void load(std::string filename) {
		texture.loadFromFile("assets/gfx/sprites/" + filename);
		sprite.setTexture(texture);
	}

	virtual void update(float dt) {
		sprite.move(velocity.x * dt, velocity.y * dt);
	}

	virtual void reset(int windowWidth, int windowHeight) {
		sprite.setPosition(windowWidth / 2, windowHeight / 2 - sprite.getGlobalBounds().height / 2);
	}

	bool checkCollision(Entity entity) {
		return this->sprite.getGlobalBounds().intersects(entity.sprite.getGlobalBounds());
	}

	sf::Vector2f velocity;
	sf::Sprite sprite;
private:
	sf::Texture texture;
};