#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "ConcreteArmorCreator.h"
#include "ConcreteWeaponCreator.h"
#include "Dice.h"
#include <memory>
#include <iostream>

using namespace std;

class Character {
public:
	//Virtual Destructor
	virtual ~Character() = 0;
	//Character Features: setter and getter
	void setStrength(int strength);
	int getStrength() const;
	int getStrengthModifier() const;

	void setDexterity(int dexterity);
	int getDexterity() const;
	int getDexterityModifier() const;

	void setIntelligence(int intelligence);
	int getIntelligence() const;
	int getIntelligenceModifier() const;

	void setCharisma(int charisma);
	int getCharisma() const;
	int getCharismaModifier() const;

	void setConstitution(int constitution);
	int getConstitution() const;
	int getConstitutionModifier() const;

	void setWisdom(int wisdom);
	int getWisdom() const;
	int getWisdomModifier() const;
	//set character features
	void setFeatures(int strength, int dexterity, int intelligence, int charisma, int constitution, int wisdom);

	void setLP(int lp);
	int getLP() const;

	void setLevel(int l);
	int getLevel() const;

	void setPosX(float x);
	float getPosX() const;
	void setPosY(float y);
	float getPosY() const;

	void setInitiative();
	int getInitiative() const;

	virtual void setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR type) = 0;
	std::string getTypeOfArmor() const;

	virtual void setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON type) = 0;
	std::string getTypeOfWeapon() const;

	void setRace(short r);
	short getRace();

	//Armor & Weapon
	ConcreteArmor ar;
	ConcreteArmor getArmor();
	ConcreteArmorCreator armorFactory;
	ConcreteWeapon wp;
	ConcreteWeaponCreator weaponFactory;

	//dice
	std::shared_ptr<Dice> dice;
	void setDice();
	std::shared_ptr<Dice> getDice();
	int throwDiceFight();
	virtual void setDiceColor() = 0;

private:
	int strength;
	int strengthModifier;
	int dexterity;
	int dexterityModifier;
	int intelligence;
	int intelligenceModifier;
	int constitution;
	int constitutionModifier;
	int charisma;
	int charismaModifier;
	int wisdom;
	int wisdomModifier;
	int LP;
	int level;
	int initiative;
	float posX;
	float posY;
	short race;
	
};

#endif