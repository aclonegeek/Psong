#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Psong");

	sf::Texture ballTexture;
	sf::Texture paddle1Texture;
	sf::Texture paddle2Texture;

	sf::Sprite ballSprite;
	sf::Sprite paddle1Sprite;
	sf::Sprite paddle2Sprite;

	ballTexture.loadFromFile("assets/gfx/sprites/ball.png");
	paddle1Texture.loadFromFile("assets/gfx/sprites/paddle1.png");
	paddle2Texture.loadFromFile("assets/gfx/sprites/paddle2.png");

	ballSprite.setTexture(ballTexture);
	paddle1Sprite.setTexture(paddle1Texture);
	paddle2Sprite.setTexture(paddle2Texture);

	// start everything centered
	ballSprite.setPosition(window.getSize().x / 2, window.getSize().y / 2 - ballSprite.getGlobalBounds().height / 2);
	paddle1Sprite.setPosition(5, window.getSize().y / 2 - paddle1Sprite.getGlobalBounds().height / 2);
	paddle2Sprite.setPosition(window.getSize().x - paddle1Sprite.getGlobalBounds().width - 5, window.getSize().y / 2 - paddle2Sprite.getGlobalBounds().height / 2);

	sf::Clock clock;

	const float paddleSpeed = 500.0f;

	while (window.isOpen()) {
		sf::Event event;
		float deltaTime = clock.restart().asSeconds();

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			paddle1Sprite.move(0, -paddleSpeed * deltaTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			paddle1Sprite.move(0, paddleSpeed * deltaTime);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			paddle2Sprite.move(0, -paddleSpeed * deltaTime);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			paddle2Sprite.move(0, paddleSpeed * deltaTime);
		}

		if (paddle1Sprite.getPosition().y < 0) {
			paddle1Sprite.move(0, paddleSpeed * deltaTime);
		} else if (paddle1Sprite.getPosition().y + paddle1Sprite.getGlobalBounds().height > window.getSize().y) {
			paddle1Sprite.move(0, -paddleSpeed * deltaTime);
		}

		if (paddle2Sprite.getPosition().y < 0) {
			paddle2Sprite.move(0, paddleSpeed * deltaTime);
		} else if (paddle2Sprite.getPosition().y + paddle2Sprite.getGlobalBounds().height > window.getSize().y) {
			paddle2Sprite.move(0, -paddleSpeed * deltaTime);
		}

		window.clear();
		window.draw(ballSprite);
		window.draw(paddle1Sprite);
		window.draw(paddle2Sprite);
		window.display();
	}
	return 0;
}