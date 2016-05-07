#include "MainGame.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Psong");
	sf::Clock clock;

	MainGame game;
	game.initialize(window);

	while (window.isOpen()) {
		sf::Event event;
		float dt = clock.restart().asSeconds();

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			game.initialize(window);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		window.clear();
		game.update(window, dt);
		game.render(window);
		window.display();
	}
	return 0;
}