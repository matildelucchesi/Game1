#ifndef PAUSEDSTATE_H
#define PAUSEDSTATE_H

#include "GameState.h"
#include "Hero.h"
#include "Potion.h"

class PlayingState;
class FirstLevelState;

class PausedState : public GameState {
public:
	//Constructor & Destructor
	PausedState(GameState& pre_State, std::shared_ptr<Hero> hero);
	~PausedState() = default;

	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;
	void setBackground() override;
	void reinitialized(GameState& pre_State, std::shared_ptr<Hero> hero);

private:

	GameState* preState;
	std::shared_ptr<Hero> h;
	std::shared_ptr<Potion> potion[MAX_POTION];
	sf::Text text;
	sf::Text strength;
	sf::Text dexterity;
	sf::Text charisma;
	sf::Text constitution;
	sf::Text wisdom;
	sf::Text intelligence;
	sf::Text value;
	sf::RectangleShape grid[MAX_POTION];
	int max;
	short index;
};

#endif PAUSEDSTATE_H