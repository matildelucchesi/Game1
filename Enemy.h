#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Animation.h"
#include "FAnimation.h"

using namespace std;

enum class ENEMY_RACE{MINDFLAYER, DARKPRIEST, SKELETON};

class Enemy : public Character {
public:
	//Constructor & Destructor
	Enemy(short race, int lp, int level, float x, float y);
	~Enemy() = default;
	//Features
	void setGameFeatures();
	//Armor & Weapon
	void setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR type) override;
	void setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON type) override;
	//Animation
	void setAnimationTexture();
	Animation& getAnimation();
	//fight animation
	void setFightAnimation();
	void setFightTurnAnimation();
	FAnimation& getFightAnimation();

	//dice
	void setDiceColor() override;
	

private:
	//Animation
	Animation animation;
	sf::Texture enemyTexture;
	//Fight Animation
	FAnimation fight;
	sf::Texture enemyFightingTexture;
	sf::Texture enemyTurnFightingTexture;
	int CA;

	//LPAnimation
	sf::Texture lpBubbleTexture;
	sf::Sprite lpBubbleSprite;
	sf::Text lptext;
}; 

#endif 