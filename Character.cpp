#include "Character.h"

//Destructor
Character::~Character() {

}

void Character::setStrength(int strength) {
	this->strength = strength;
}

int Character::getStrength() const {
	return this->strength;
}

int Character::getStrengthModifier() const {
	return this->strengthModifier;
}

void Character::setDexterity(int dexterity) {
	this->dexterity = dexterity;
}

int Character::getDexterity() const {
	return this->dexterity;
}

int Character::getDexterityModifier() const {
	return this->dexterityModifier;
}

void Character::setIntelligence(int intelligence) {
	this->intelligence = intelligence;
}

int Character::getIntelligence() const {
	return this->intelligence;
}

int Character::getIntelligenceModifier()  const {
	return this->intelligenceModifier;
}

void Character::setCharisma(int charisma) {
	this->charisma = charisma;
}

int Character::getCharisma() const {
	return this->charisma;
}

int Character::getCharismaModifier() const {
	return this->charismaModifier;
}

void Character::setConstitution(int constitution) {
	this->constitution = constitution;
}

int Character::getConstitution() const {
	return this->constitution;
}


int Character::getConstitutionModifier() const {
	return this->constitutionModifier;
}

void Character::setWisdom(int wisdom) {
	this->wisdom = wisdom;
}

int Character::getWisdom() const {
	return this->wisdom;
}

int Character::getWisdomModifier() const {
	return this->wisdomModifier;
}

void Character::setFeatures(int s, int d, int i, int ch, int c, int w) {
	strength = s;
	dexterity = d;
	intelligence = i;
	charisma = ch;
	constitution = c;
	wisdom = w;


	//modifier
	strengthModifier = (s - 10) / 2;
	dexterityModifier = (d - 10) / 2;
	intelligenceModifier = (i - 10) / 2;
	charismaModifier = (ch - 10) / 2;
	constitutionModifier = (c - 10) / 2;
	wisdomModifier = (w - 10) / 2;
}
void Character::setLP(int lp) {
	LP = lp;
}

int Character::getLP() const {
	return LP;
}

void Character::setLevel(int level) {
	this->level = level;
}

int Character::getLevel() const {
	return this->level;
}

void Character::setInitiative() {
	initiative = dice->use(20) + getDexterityModifier();
}

int Character::getInitiative() const {
	return initiative;
}

void Character::setPosX(float x) {
	this->posX = x;
}

float Character::getPosX() const {
	return this->posX;
}

void Character::setPosY(float y) {
	this->posY = y;
}

float Character::getPosY() const {
	return this->posY;
}

std::string Character::getTypeOfWeapon() const {
	return this->wp.getType();
}

std::string Character::getTypeOfArmor() const {
	return this->ar.getType();
}

void Character::setDice() {
	this->dice = std::shared_ptr<Dice>(new Dice());
}

std::shared_ptr<Dice> Character::getDice() {
	return this->dice;
}

int Character::throwDiceFight() {
	return dice->use(20);
}

void Character::setRace(short r) {
	this->race = r;
}

short Character::getRace() {
	return this->race;
}

ConcreteArmor Character::getArmor() {
	return this->ar;
}

ConcreteWeapon Character::getWeapon() {
	return this->wp;
}