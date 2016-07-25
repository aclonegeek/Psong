#include <iostream>

#include "GameState.hpp"
#include "MenuState.hpp"

GameState::GameState(StateManager& stateManager, sf::RenderWindow& window)
	: State{ stateManager, window }
	, m_paddle1{ true }
	, m_paddle2{ false }
	, m_ball{ m_paddle1, m_paddle2 } {
	std::cout << "[GameState] Initialized" << std::endl;

	m_soundBuffer.loadFromFile("assets/audio/hit.wav");
	m_hitSound.setBuffer(m_soundBuffer);
	m_hitSound.setVolume(2.0f);

	m_font.loadFromFile("assets/gfx/monoton.ttf");
	m_score1.setFont(m_font);
	m_score2.setFont(m_font);
	m_score1.setColor(sf::Color::White);
	m_score2.setColor(sf::Color::White);
	m_score1.setPosition(3.0f, 3.0f);
	m_score2.setPosition(m_window.getSize().x - 28.0f, 3.0f);

	reset();
}

void GameState::reset() {
	m_ball.reset(m_window.getSize().x, m_window.getSize().y);
	m_paddle1.reset(m_window.getSize().x, m_window.getSize().y);
	m_paddle2.reset(m_window.getSize().x, m_window.getSize().y);
	m_score1.setString("0");
	m_score2.setString("0");
}

void GameState::pause() {

}

void GameState::resume() {

}

void GameState::processEvents() {
	sf::Event event;

	while (m_window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			m_stateManager.quit();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code) {
				case sf::Keyboard::M:
				{
					std::unique_ptr<State> menuState(new MenuState(m_stateManager, m_window));
					m_stateManager.stateToChangeTo(std::move(menuState));
					break;
				}
				case sf::Keyboard::R:
					reset();
					break;
				case sf::Keyboard::Escape:
					m_stateManager.quit();
					break;
			}
		}
	}
}

void GameState::update(const sf::Time& dt) {
	m_ball.update(dt, m_window.getSize().x, m_window.getSize().y);
	m_paddle1.update(dt, m_window.getSize().x, m_window.getSize().y);
	m_paddle2.update(dt, m_window.getSize().x, m_window.getSize().y);

	m_score1.setString(m_paddle1.getScore());
	m_score2.setString(m_paddle2.getScore());

	if (m_ball.checkCollision(m_paddle1) || m_ball.checkCollision(m_paddle2)) {
		m_hitSound.play();
		m_ball.velocity.x *= -1;
	}
}

void GameState::draw() {
	m_window.clear(sf::Color::Black);
	m_window.draw(m_score1);
	m_window.draw(m_score2);
	m_window.draw(m_ball.getSprite());
	m_window.draw(m_paddle1.getSprite());
	m_window.draw(m_paddle2.getSprite());
	m_window.display();
}