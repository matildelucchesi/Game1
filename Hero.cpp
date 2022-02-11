#include "Hero.h"

Hero::Hero(short race, short hClass) {
	setRace(race);
	heroClass = hClass;
	//setFeatures
	setFeatureValue();
	Character::setInitiative();
	Character::setLP(100);
	Character::setLevel(0);
	//position
	setPosX(600);
	setPosY(900);
	//gold coins
	calculateGoldCoins();
	//animation
	movingState = 5;
	setAnimation();
	//fight animation
	setFightAnimation();
	setFightTurnAnimation();
	fight = FAnimation(fightingTexture, fightingTurnTexture);
	fight.getSprite().setPosition(150.f, 250.f);
	//dice
	Character::setDice();
	setDiceColor();
	//count potion
	for (int i = 0; i < MAX_POTION; i++) {
		POTION[i] = NULL;
	}
	numPotion = 0;
	ppx = 0;
	ppy = 0;
}

Hero::~Hero() {
	Character::~Character();
}

void Hero::setClass(short hClass) {
	this->heroClass = hClass;
}

short Hero::getClass() const {
	return heroClass;
}

const int Hero::getXP() {
	return XP;
}

void Hero::setXP(int xp) {
	XP = xp;
}

void Hero::increaseXP(int xp) {
	XP += xp;
}

void Hero::calculateGoldCoins() {
	switch(this->heroClass) {
	case 0:
	{
		goldCoins = 3 * dice->use(6) * 100;
		break;
	}
	case 1:
	{
		goldCoins = 2 * dice->use(6) * 100;
		break;
	}
	case 2:
	{
		goldCoins = 5 * dice->use(6) * 100;
		break;
	}
	case 3:
	{
		goldCoins = 2 * dice->use(6) * 100;
		break;
	}
	}
	
}

int Hero::getGoldCoins() const {
	return goldCoins;
}

void Hero::increaseLevel(int xp) {
	if (xp == 1000) {
		Character::setLevel(Character::getLevel() + 1);
		setXP(0);
	}
}

void Hero::setGoldCoins(int gc){
	goldCoins = gc;
}

void Hero::setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR type) {
	this->ar = armorFactory.createArmor(type);
	if (getGoldCoins() >= this->ar.getCost()) {
		setGoldCoins(getGoldCoins() - this->ar.getCost());
	}
}

void Hero::setTypeOfArmor(std::string type) {
	if (type == "Full Armor")
		setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::FULL_ARMOR);
	if (type == "Half Armor")
		setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::HALF_ARMOR);
	if (type == "Padded Armor")
		setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::PADDED_ARMOR);
	if (type == "None")
		setArmor(ConcreteArmorCreator::TYPE_OF_ARMOR::NONE);
}

void Hero::setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON type) {
	this->wp = weaponFactory.createWeapon(type);
	if (getGoldCoins() >= this->wp.getCost()) {
		setGoldCoins(getGoldCoins() - this->wp.getCost());
	}
}

void Hero::setTypeOfWeapon(std::string type) {
	if (type == "Ax") {
		setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::AX);
	}
	else if (type == "Sword") {
		setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::SWORD);
	}
	else if (type == "Crossbow") {
		setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::CROSSBOW);
	}
	else if (type == "Arch") {
		setWeapon(ConcreteWeaponCreator::TYPE_OF_WEAPON::ARCH);
	}
}

void Hero::setFeatureValue(){
	switch (getRace()) {
	case 0 :
	{
		setFeatures(getValue(1), getValue(1), getValue(1), getValue(1), getValue(1), getValue(1));
		break;
	}
	case 1:
	{
		setFeatures(getValue(2), getValue(0), getValue(0), getValue(1), getValue(0), getValue(0));
		break;
	}
	case 2:
	{
		setFeatures(getValue(0), getValue(0), getValue(0), getValue(2), getValue(1), getValue(1));
		break;
	}
	case 3:
	{
		setFeatures(getValue(0), getValue(2), getValue(1), getValue(1), getValue(0), getValue(1));
		break;
	}
	case 4:
	{
		setFeatures(getValue(2), getValue(0), getValue(1), getValue(0), getValue(0), getValue(1));
		break;
	}
	}
}

int Hero::getValue(int sum) {
	result = dice->use(20) * 2 + 2 + sum;
	if (result > 18)
		result = 18;
	return result;
}

//Animation

void Hero::setAnimation() {
	switch (getRace()) {
	case 0:
	{
		if (!heroTexture.loadFromFile("../images/hero/human.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD THE TEXTURE FILE";
		break;
	}
	case 1:
	{
		if (!heroTexture.loadFromFile("../images/hero/dragonborn.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD THE TEXTURE FILE";
		break;
	}
	case 2:
	{
		if (!heroTexture.loadFromFile("../images/hero/tiefling.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD THE TEXTURE FILE";
		break;
	}
	case 3:
	{
		if (!heroTexture.loadFromFile("../images/hero/elf.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD THE TEXTURE FILE";
		break;
	}
	case 4:
	{
		if (!heroTexture.loadFromFile("../images/hero/dwarf.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD THE TEXTURE FILE";
		break;
	}

	}

	animation = Animation::Animation(this->heroTexture, sf::IntRect(64, 0, 64, 64), 2.f, getPosX(), getPosY());
}

void Hero::updateMovement() {
	movingState = 5;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		animation.getSprite().move(-animation.getMovementSpeed(), 0.f);
		movingState = 6;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		animation.getSprite().move(animation.getMovementSpeed(), 0.f);
		movingState = 7;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		animation.getSprite().move(0.f, -animation.getMovementSpeed());
		movingState = 8;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		animation.getSprite().move(0.f, animation.getMovementSpeed());
		movingState = 9;
	}
	
	setPosX(animation.getSprite().getPosition().x);
	setPosY(animation.getSprite().getPosition().y);

}

Animation& Hero::getAnimation() {
	return this->animation;
}

//fight

void Hero::setFightAnimation() {
	switch (getRace()) {
	case 0:
	{
		if (!fightingTexture.loadFromFile("../images/fight/fightinghuman.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD FIGHTING_HUMAN_TEXTURE";
		break;
	}
	case 1:
	{
		if (!fightingTexture.loadFromFile("../images/fight/fightingdragonborn.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD FIGHTING_DRAGONBORN_TEXTURE";
		break;
	}
	case 2:
	{
		if (!fightingTexture.loadFromFile("../images/fight/fightingtiefling.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD FIGHTING_TIEFLING_TEXTURE";
		break;
	}
	case 3:
	{
		if (!fightingTexture.loadFromFile("../images/fight/fightingelf.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD FIGHTING_ELF_TEXTURE";
		break;
	}
	case 4:
	{
		if (!fightingTexture.loadFromFile("../images/fight/fightingdwarf.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD FIGHTING_DWARF_TEXTURE";
		break;
	}
	}
}

void Hero::setFightTurnAnimation() {
	switch (getRace()) {
	case 0:
	{
		if (!fightingTurnTexture.loadFromFile("../images/fight/humanTurn.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD THE HUMAN_TURN_TEXTURE_FILE";
		break;
	}
	case 1:
	{
		if (!fightingTurnTexture.loadFromFile("../images/fight/dragonbornTurn.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD THE DRAGONBORN_TURN_TEXTURE_FILE";
		break;
	}
	case 2:
	{
		if (!fightingTurnTexture.loadFromFile("../images/fight/tieflingTurn.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD THE TIEFLING_TURN_TEXTURE_FILE";
		break;
	}
	case 3:
	{
		if (!fightingTurnTexture.loadFromFile("../images/fight/elfTurn.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD THE ELF_TURN_TEXTURE_FILE";
		break;
	}
	case 4:
	{
		if (!fightingTurnTexture.loadFromFile("../images/fight/dwarfTurn.png"))
			std::cout << "ERROR::HERO::CAN'T LOAD THE DWARF_TURN_TEXTURE_FILE";
		break;
	}
	}
}

FAnimation& Hero::getFightAnimation() {
	return this->fight;
}

//potion

void Hero::takePotion(InteractiveObject* obj) {
	if (numPotion == MAX_POTION)
		std::cout << "You can't take this";
	else {
		obj->takePotion();
		numPotion += 1;
		int e = 0;
		while (e != numPotion){
			if (POTION[e] == NULL)
				POTION[e] = obj->getPotion();
			
			e++;
		}
	}

}

void Hero::usePotion(short i) {
	setLP(getLP() + POTION[i]->getPotionValue());
	if (getLP() > 100)
		setLP(100);
	POTION[i] = NULL;
	numPotion -= 1;
}

std::shared_ptr<Potion> Hero::getPotion(int i) {
		return this->POTION[i];
}

int Hero::getMaxPotion() {
	return MAX_POTION;
}


//dice

void Hero::setDiceColor() {
	switch (getRace()) {
	case 0:
	{
		dice->setColor(sf::Color(230, 255, 0, 255));
		break;
	}
	case 1:
	{
		dice->setColor(sf::Color(255, 0, 42, 255));
		break;
	}
	case 2:
	{
		dice->setColor(sf::Color(149, 0, 255, 255));
		break;
	}
	case 3:
	{
		dice->setColor(sf::Color(0, 255, 13, 255));
		break;
	}
	case 4:
	{
		dice->setColor(sf::Color(255, 149, 0, 255));
		break;
	}
	}
}


short Hero::getMovementState() {
	return this->movingState;
}