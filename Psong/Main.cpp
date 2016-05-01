// todo:
// 1. fix paddle movement (don't mix the vector2f and hand doing the vals)

#include "MainGame.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Psong");

	sf::Clock clock;
	const float ballSpeed = 300.0f;

	sf::Vector2f ballVelocity;
	ballVelocity.x = ballSpeed;
	ballVelocity.y = ballSpeed;

	while (window.isOpen()) {
		sf::Event event;
		float dt = clock.restart().asSeconds();

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		ballSprite.move(ballVelocity.x * dt, ballVelocity.y * dt);

		window.clear();
		window.draw(ballSprite);
		window.display();
	}
	return 0;
}