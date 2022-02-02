#include "Playable.h"

Playable::Playable() {
	if (!this->f.loadFromFile("../Font/TaylorGothic.otf"))
		std::cout << "ERROR::PLAYABLE::CAN'T LOAD THE FONT";
}

Playable::~Playable() {

}

void Playable::textAnimation() {
	
	if (str.getSize() > 0) {
		sf::sleep(sf::milliseconds(10));
		text.setString(text.getString() + str[0]);
		str = str.toAnsiString().substr(1);
	}
}

void Playable::setMessageBubble(sf::String& s) {
	if (!message.loadFromFile("../images/other/message bubble.png"))
		std::cout << "ERROR::PLAYABLE::CAN'T LOAD MESSAGE_BUBBLE_TEXTURE";
	messageBubble = sf::Sprite(message);
	messageBubble.setScale(0.9f, 0.9f);
	//text;
	this->str = s;
	text = sf::Text(this->str, f, 30);
	text.setColor(sf::Color::Black);
}

void Playable::setMessageBubble(sf::View v, sf::String& s) {
	if (!message.loadFromFile("../images/other/message bubble.png"))
		std::cout << "ERROR::PLAYABLE::CAN'T LOAD MESSAGE_BUBBLE_TEXTURE";
	messageBubble = sf::Sprite(message);
	messageBubble.setScale(0.9f, 0.9f);
	messageBubble.setPosition(v.getCenter().x - 450, v.getCenter().y + 80);
	//text
	this->str = s;
	text = sf::Text(" ", f, 30);
	text.setColor(sf::Color::Black);
	text.setPosition(v.getCenter().x - 430, v.getCenter().y + 100);
}

void Playable::updateMessageBubble(sf::View v, sf::String& s) {
	messageBubble.setPosition(v.getCenter().x - 450, v.getCenter().y + 80);
	//text
	this->str = s;
	text.setString(" ");
	text.setPosition(v.getCenter().x - 430, v.getCenter().y + 100);
}

void Playable::updateCollision(std::shared_ptr<Hero> h, TileMap* m, std::vector<sf::FloatRect*> oBB) {
	h->getAnimation().boundCollision(m->getBackgroundBoundingBox());
	for (int i = 0; i < m->getNumberOfObjectLayer(); i++) {
		h->getAnimation().collision(oBB[i]);
	}
}

void Playable::updateCollision(std::shared_ptr<Hero> h, std::shared_ptr<Enemy> e, TileMap* m, std::vector<sf::FloatRect*> oBB) {
	h->getAnimation().boundCollision(m->getBackgroundBoundingBox());
	h->getAnimation().boundCollision(&e->getAnimation().getBoundingBox());
	for (int i = 0; i < m->getNumberOfObjectLayer(); i++) {
		h->getAnimation().collision(oBB[i]);
	}
}

sf::Sprite& Playable::getMessageBubble() {
	return this->messageBubble;
}

sf::Text& Playable::getText() {
	return this->text;
}

void Playable::updateText(sf::View v, sf::String& s) {
	messageBubble.setPosition(v.getCenter().x - 450, v.getCenter().y + 80);
	text.setString(s);
	text.setPosition(v.getCenter().x - 430, v.getCenter().y + 100);
}

void Playable::updateMessage(sf::View v) {
	switch (type) {
	case 0:
	{
		text.setString("Press A to smash the statue");
		break;
	}
	case 1:
	{
		text.setString("Press A to open the treasure");
		break;
	}
	case 2:
	{
		text.setString("Oh! You found a potion! Press S to get it");
		break;
	}
	case 3:
	{
		text.setString("On no! It's empty! Press S to continue");
		break;
	}
	case 4:
	{
		text.setString("Oh no! You can't go on!\nAn enemy wants to fight with you!\nPress A to fight");
		break;
	}
	case 5:
	{
		text.setString("Press A to go upstairs");
		break;
	}
	}

	messageBubble.setPosition(v.getCenter().x - 450, v.getCenter().y + 80);
	text.setPosition(v.getCenter().x - 430, v.getCenter().y + 100);
}

void Playable::setType(short t) {
	this->type = t;
}

short Playable::getType() const {
	return this->type;
}

void Playable::setMex(bool m) {
	this->mex = m;
}

bool Playable::getMex() const {
	return this->mex;
}

//hero
void Playable::setHeroClass(short cl) {
	this->heroClass = cl;
}

void Playable::setHeroRace(short hr) {
	this->heroRace = hr;
}

void Playable::setHero() {
	this->hero = std::shared_ptr<Hero>(new Hero(heroRace, heroClass));
}

std::shared_ptr<Hero> Playable::getHero() {
	return this->hero;
}

void Playable::setCanMove(bool cM) {
	this->canMove = cM;
}

bool Playable::getCanMove() {
	return this->canMove;
}

//enemy

void Playable::setEnemy(short race, int lp, int level, float posX, float posY) {
	this->enemy = std::shared_ptr<Enemy>(new Enemy(race, lp, level, posX, posY));
	this->live = true;
}

std::shared_ptr<Enemy> Playable::getEnemy() {
	return this->enemy;
}

void Playable::destroyEnemy() {
	this->canMove = true;
	this->live = false;
	this->mex = false;
	this->enemy.reset();
}

void Playable::setLive(bool l) {
	this->live = l;
}

bool Playable::getLive() {
	return this->live;
}

//Achievements

void Playable::setAchievements() {
	this->a = new Achievements();
}

Achievements* Playable::getAchievements() {
	return this->a;
}