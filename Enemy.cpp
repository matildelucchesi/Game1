#include "Enemy.h"

Enemy::Enemy(short race, int lp, int level, float x, float y){
	//features
	setRace(race);
	setGameFeatures();
	Character::setLP(lp);
	Character::setLevel(level);
	Character::setInitiative();
	//position
	Character::setPosX(x);
	Character::setPosY(y);
	//Animation
	setAnimationTexture();
	this->animation = Animation::Animation(enemyTexture);
	this->animation.getSprite().setScale(1.7f, 1.7f);
	this->animation.getSprite().setPosition(x, y);
	this->animation.updateBoundingBox();
	//Fight Animation
	setFightAnimation();
	setFightTurnAnimation();
	fight = FAnimation(enemyFightingTexture, enemyTurnFightingTexture);
	fight.getSprite().setPosition(850.f, 250.f);
	//dice
	Character::setDice();
	setDiceColor();
}

void Enemy::setGameFeatures() {
	switch (getRace()) {
	case 0:
		{
			setFeatures(11, 12, 12, 19, 17, 17);
			this->setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::HALF_ARMOR);
			this->setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::SWORD);
			break;
		}
	case 1:
		{
			setFeatures(12, 11, 13, 10, 16, 12);
			this->setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::NONE);
			this->setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::ARCH);
			break;
		}
	case 2:
		{
			setFeatures(12, 14, 15, 6, 8, 6);
			this->setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::PADDED_ARMOR);
			this->setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::AX);
			break;
		}
	}
}

void Enemy::setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR type) {
	ar = armorFactory.createArmor(type);
}

void Enemy::setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON type) {
	wp = weaponFactory.createWeapon(type);
}

//Animation
void Enemy::setAnimationTexture() {
	switch (getRace()) {
	case 0:
	{
		if (!enemyTexture.loadFromFile("../images/enemy/mindflayer.png"))
			std::cout << "ERROR::ENEMY::CAN'T LOAD MINDFLAYER_TEXTURE";
		break;
	}
	case 1:
	{
		if (!enemyTexture.loadFromFile("../images/enemy/darkpriest.png"))
			std::cout << "ERROR::ENEMY::CAN'T LOAD DARKPRIEST_TEXTURE";
		break;
	}
	case 2:
	{
		if (!enemyTexture.loadFromFile("../images/enemy/skeleton.png"))
			std::cout << "ERROR::ENEMY::CAN'T LOAD SKELETON_TEXTURE";
		break;
	}
	}
}

Animation& Enemy::getAnimation() {
	return this->animation;
}

//fight animation
void Enemy::setFightAnimation() {
	switch (getRace()) {
	case 0:
	{
		if (!enemyFightingTexture.loadFromFile("../images/fight/fightingMindflayer.png"))
			std::cout << "ERROR::ENEMY::CAN'T LOAD FIGHTING_MINDFLAYER_TEXTURE";
		break;
	}
	case 1:
	{
		if (!enemyFightingTexture.loadFromFile("../images/fight/fightingDarkPriest.png"))
			std::cout << "ERROR::ENEMY::CAN'T LOAD FIGHTING_DARK_PRIEST_TEXTURE";
		break;
	}
	case 2:
	{
		if (!enemyFightingTexture.loadFromFile("../images/fight/fightingSkeleton.png"))
			std::cout << "ERROR::ENEMY::CAN'T LOAD FIGHTING_SKELETON_TEXTURE";
		break;
	}
	}
}

void Enemy::setFightTurnAnimation() {
	switch (getRace()) {
	case 0:
	{
		if (!enemyTurnFightingTexture.loadFromFile("../images/fight/mindflayerTurn.png"))
			std::cout << "ERROR::ENEMY::CAN'T LOAD FIGHTING_MINDFLAYER_TURN_TEXTURE";
		break;
	}
	case 1:
	{
		if (!enemyTurnFightingTexture.loadFromFile("../images/fight/darkPriestTurn.png"))
			std::cout << "ERROR::ENEMY::CAN'T LOAD FIGHTING_DARK_PRIEST_TURN_TEXTURE";
		break;
	}
	case 2:
	{
		if (!enemyTurnFightingTexture.loadFromFile("../images/fight/skeletonTurn.png"))
			std::cout << "ERROR::ENEMY::CAN'T LOAD FIGHTING_SKELETON_TURN_TEXTURE";
		break;
	}
	}
}

FAnimation& Enemy::getFightAnimation() {
	return this->fight;
}

//dice

void Enemy::setDiceColor() {
	switch (getRace()) {
	case 0:
	{
		dice->setColor(sf::Color(213, 0, 255, 255));
		break;
	}
	case 1:
	{
		dice->setColor(sf::Color(206, 206, 206, 255));
		break;
	}
	case 2:
	{
		dice->setColor(sf::Color(255, 255, 255, 255));
		break;
	}
	}
}