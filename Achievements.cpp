#include "Achievements.h"

Achievements::Achievements() {
	//animation
	setAnimation();
	//count
	countT = 0;
	countS = 0;
	achieve = false;
}

void Achievements::updateTreasure() {
	countT += 1;
	if (countT == 3) {
		achieve = true;
		text.setString("Congratulation: you open 3 treasures!\nPress Z to continue");
	}
}

void Achievements::updateStatue() {
	countS += 1;
	if (countS == 4) {
		achieve = true;
		text.setString("Congratulation: you open 4 statues\nPress Z to continue");
	}
}

void Achievements::setAnimation() {
	if (!messageBubble.loadFromFile("../images/other/message bubble.png"))
		std::cout << "ERROR::ACHIEVEMENTS::CAN'T LOAD MESSAGE_BUBBLE_TEXTURE";
	messageBubbleS = sf::Sprite(messageBubble);
	messageBubbleS.setScale(0.9f, 0.9f);
	//font
	if (!font.loadFromFile("../Font/TaylorGothic.otf"))
		std::cout << "ERROR::ACHIEVEMENTS::CAN'T LOAD THE FONT";
	text = sf::Text(" ", font, 30);
	text.setFillColor(sf::Color::Blue);
}

void Achievements::render(sf::RenderTarget* target) {
	target->draw(messageBubbleS);
	target->draw(text);
}

void Achievements::update(sf::View v) {
	messageBubbleS.setPosition(v.getCenter().x - 450.f, v.getCenter().y + 80.f);
	text.setPosition(v.getCenter().x - 430.f, v.getCenter().y + 100.f);
}

bool Achievements::getAchieve() const{
	return this->achieve;
}

void Achievements::setAchieve(bool a){
	this->achieve = a;
}

//Count

int Achievements::getCountS() const {
	return this->countS;
}

int Achievements::getCountT() const {
	return this->countT;
}