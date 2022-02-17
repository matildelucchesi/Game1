#pragma once
#ifndef WEAPONMENUSTATE_H
#define WEAPONMENUSTATE_H

#include "GameState.h"
#include "ConcreteWeapon.h"
#include "ArmorMenuState.h"
#include <memory>

#define NUMBER_OF_WEAPONS 4

enum class WEAPON{ARCH, AX, CROSSBOW, SWORD};

class PlayingState;

class WeaponMenuState : public GameState {
public:
	//Constructor & Destructor
	WeaponMenuState(PlayingState& playingState);
	~WeaponMenuState() = default;

	GameState* handleInput(sf::Event evnt) override;
	void render(sf::RenderTarget* target) override;
	void update() override;
	void initWeaponText();
	void setSprite();

	void chooseWeapon();

	//Background
	void setBackground() override;

private:
	//Arrows
	sf::Texture right;
	sf::Sprite rightArrow;
	sf::Texture left;
	sf::Sprite leftArrow;

	sf::Text text;
	sf::Text weapon[NUMBER_OF_WEAPONS];
	short w;
	PlayingState& play;
	sf::Texture weaponTexture;
	sf::Sprite weaponSprite;
	int cost;
	std::string type;

	//Title
	sf::Text title;
	sf::Font f;
	//Gold Coins
	sf::Text coins;
	std::string strInt;
	//control
	bool canBuy;
	//weapon
	std::string wType;
};

#endif 