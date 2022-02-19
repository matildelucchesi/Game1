#pragma once
#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Animation.h"
#include "FAnimation.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include "ConcreteArmorCreator.h"
#include "ConcreteWeaponCreator.h"
#include "InteractiveObject.h"
#include "Potion.h"
#include <memory>


using namespace std;

enum class HERO_RACE{HUMAN = 0, DRAGONBORN, TIEFLING, ELF, DWARF};
enum class ANIMATION_STATES { IDLE = 5, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };
enum class HERO_CLASS { BARBARIAN = 0, DRUID, WARRIOR, WIZARD };

#define MAX_POTION 9

class Hero : public Character{
public:
	//Constructor & Destructor
	Hero() =  default;
	Hero(short race, short hClass);
	~Hero();

	void setClass(short hClass);
	short getClass() const;

	const int getXP();
	void setXP(int xp);
	void increaseXP(int xp);

	void setFeatureValue();
	int getValue(int sum);

	//gold coins
	void calculateGoldCoins();
	void setGoldCoins(int gc);
	int getGoldCoins() const;
	
	void increaseLevel(int xp);

	//Armor
	void setTypeOfArmor(std::string type);
	void setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR type) override;

	//Weapon
	void setTypeOfWeapon(std::string type);
	void setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON type) override;

	//Animation
	void setAnimation();
	void updateMovement();
	Animation& getAnimation();
	short getMovementState();

	//Fight Animation
	void setFightAnimation();
	void setFightTurnAnimation();
	FAnimation& getFightAnimation();

	//Collision
	void collision(sf::Sprite target);

	//Potion
	std::shared_ptr<Potion> POTION[MAX_POTION];
	void usePotion(short i);
	std::shared_ptr<Potion> getPotion(int i);
	int getMaxPotion();
	void addPotion();
	int ppx;
	int ppy;
	int getNumPotion() const;
	//take potion
	void takePotion(InteractiveObject* obj);

	//Dice
	void setDiceColor() override;

private:
	int goldCoins;
	int XP;
	short heroClass;
	short heroRace;

	//animation
	Animation animation;
	short movingState;
	sf::Texture heroTexture;
	sf::Sprite heroSprite;
	sf::FloatRect nextPos;
	sf::IntRect currentFrame;


	//fight animation
	FAnimation fight;
	sf::Texture fightingTexture;
	sf::Texture fightingTurnTexture;
	
	//LP animation
	sf::Texture lpBubbleTexture;
	sf::Sprite lpBubbleSprite;
	sf::Text lpText;
	sf::Texture lpBubbleTextureF;
	sf::Sprite lpBubbleSpriteF;
	sf::Text lpTextF;

	int result;
	int numPotion;
};


#endif