#pragma once
#ifndef FIGHTSTATE_H
#define FIGHTSTATE_H

#include "Playable.h"
#include "GameState.h"
#include "Hero.h"
#include "Enemy.h"
#include "EndState.h"

enum class HERO_STATE{INITIAL, ENEMY_TURN, HERO_TURN, NOTHING};
enum class MESSAGE_TYPE{START = 4, HIT, MISS, WAS_HIT, WAS_MISS, ENEMY_DIED, HERO_DIED};

class FightState : public GameState {
public:
	//Constructor & Destructor
	FightState(Playable& state);
	~FightState() = default;

	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;

	void setBackground() override;

	void updateUpperMessage();
	void heroAttack();
	void enemyAttack();

private:
	Playable& state_;
	
	std::shared_ptr<Hero> h;
	std::shared_ptr<Enemy> e;
	short s;
	sf::String message;
	sf::Text messageT;

	short type;

	bool heroTurn;
	bool hasThrow;
	bool enemyTurn;

	//background
	sf::Texture background;
	sf::Sprite backgroundS;
	sf::Text heroCAText;
	sf::Text enemyCAText;
	bool start;
	sf::Text heroInitiative;
	sf::Text enemyInitiative;
	sf::Text mm;
	sf::Text number;
	sf::Texture rect;
	sf::Sprite rectS;

	//Dice
	sf::Texture diceT;
	sf::Sprite diceS;
	int heroResult;
	int enemyResult;

	sf::Text heroNumber;
	sf::Text enemyNumber;

	//Time
	sf::Clock timer;

};

#endif 
