#pragma once
#include <SFML/Audio.hpp>

#include "State.hpp"
#include "StateManager.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

class GameState : public State {
public:
	GameState(StateManager& stateManager, sf::RenderWindow& window);

	void pause();
	void resume();

	void processEvents();
	void update(sf::Time dt);
	void draw();
private:
	void reset();

	Ball m_ball;
	Paddle m_paddle1;
	Paddle m_paddle2;

	sf::Font m_font;
	sf::Text m_score1;
	sf::Text m_score2;
	sf::Sound m_hitSound;
	sf::SoundBuffer m_soundBuffer;
};
