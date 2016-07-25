#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entity {
public:
	Entity() {}

	virtual void load(const std::string& filename) {
		m_texture.loadFromFile("assets/gfx/sprites/" + filename);
		m_sprite.setTexture(m_texture);
	}

	virtual void update(const sf::Time dt) {
		m_sprite.move(velocity.x * dt.asSeconds(), velocity.y * dt.asSeconds());
	}

	const bool checkCollision(const Entity& entity) const {
		return this->m_sprite.getGlobalBounds().intersects(entity.m_sprite.getGlobalBounds());
	}

	const sf::Sprite getSprite() const {
		return m_sprite;
	}

	sf::Vector2f velocity;
protected:
	sf::Sprite m_sprite;
private:
	sf::Texture m_texture;
};