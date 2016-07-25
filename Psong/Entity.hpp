#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity {
public:
	Entity() {

	}

	virtual void load(std::string filename) {
		m_texture.loadFromFile("assets/gfx/sprites/" + filename);
		sprite.setTexture(m_texture);
	}

	virtual void update(const sf::Time dt) {
		sprite.move(velocity.x * dt.asSeconds(), velocity.y * dt.asSeconds());
	}

	bool checkCollision(Entity entity) {
		return this->sprite.getGlobalBounds().intersects(entity.sprite.getGlobalBounds());
	}

	sf::Sprite getSprite() {
		return sprite;
	}

	sf::Vector2f velocity;
protected:
	sf::Sprite sprite;
private:
	sf::Texture m_texture;
};