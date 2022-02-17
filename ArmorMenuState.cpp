#include "ArmorMenuState.h"
#include "PlayingState.h"

ArmorMenuState::ArmorMenuState(PlayingState& playingState): GameState(), play(playingState) {
	//Background
	setBackground();
	//Armor
	initArmorText();
	a = 0;
	armor[0].setString("Padded Armor");
	//control
	this->canBuy = true;
	//CA text
	initCAText();
	//view
	setView();

}

void ArmorMenuState::update() {
	switch (this->a) {
	case 0:
	{
		armor[a].setString("Padded Armor");
		ca.setString("CA: "+ std::to_string(11));
		if (this->play.getHero()->getGoldCoins() < 50) {
			armor[a].setColor(sf::Color::Red);
			canBuy = false;
		}
		else
			this->canBuy = true;
		break;
	}
	case 1:
	{
		this->armor[a].setString("Half Armor");
		ca.setString("CA: " + std::to_string(15));
		if (this->play.getHero()->getGoldCoins() < 750) {
			armor[a].setColor(sf::Color::Red);
			canBuy = false;
		}
		else
			canBuy = true;

		break;
	}
	case 2:
	{
		this->armor[a].setString("Full Armor");
		ca.setString("CA: " + std::to_string(18));
		if (this->play.getHero()->getGoldCoins() < 1500) {
			armor[a].setColor(sf::Color::Red);
			canBuy = false;
		}
		else
			canBuy = true;
		break;
	}
	case 3:
	{
		this->armor[a].setString("None");
		ca.setString("CA: " + std::to_string(10));
		this->canBuy = true;
		break;
	}
	}
}

void ArmorMenuState::render(sf::RenderTarget* target) {
	target->setView(getView());
	target->draw(sprite);
	target->draw(titleA);
	target->draw(coinsA);
	target->draw(rightArrow);
	target->draw(leftArrow);
	target->draw(armor[a]);
	target->draw(ca);
}

GameState* ArmorMenuState::handleInput(sf::Event evnt) {
	if (evnt.type == evnt.KeyPressed) {
		if (evnt.key.code == sf::Keyboard::Right) {
			a += 1;
			a = a % 4;
		}
		if (evnt.key.code == sf::Keyboard::Left) {
			a -= 1;
			if (a == -1)
				a = 3;
		}

		if (evnt.key.code == sf::Keyboard::Enter) {
			if (this->canBuy == true) {
				chooseArmor();
				this->play.getHero()->setTypeOfArmor(aType);
				play.setCanMove(true);
				return &this->play;
			}
			else {
				return this;
			}
		}
	}
	return this;
}

void ArmorMenuState::initArmorText() {
	for (int i = 0; i < NUMBER_OF_ARMOR; i++) {
		armor[i] = sf::Text(" ", font, 80);
		GameState::setTextFeatures(this->armor[i]);
		this->armor[i].setPosition(150.f, 300.f);
	}
}


void ArmorMenuState::chooseArmor() {
	switch (a) {
	case 0:
	{
		this->aType = "Padded Armor";
		this->play.getHero()->setGoldCoins(this->play.getHero()->getGoldCoins() - 50);
		break;
	}
	case 1:
	{
		this->aType = "Half Armor";
		this->play.getHero()->setGoldCoins(this->play.getHero()->getGoldCoins() - 750);
		break;
	}
	case 2:
	{
		this->aType = "Full Armor";
		this->play.getHero()->setGoldCoins(this->play.getHero()->getGoldCoins() - 1500);
		break;
	}
	case 3:
	{
		this->aType = "None";
		break;
	}
	}
}

void ArmorMenuState::initCAText() {
	ca = sf::Text(" ", font, 80);
	GameState::setTextFeatures(this->ca);
	ca.setPosition(680.f, 300.f);
}

void ArmorMenuState::setBackground() {
	//background
	if (!texture.loadFromFile("../images/other/menu.png"))
		std::cout << "ERROR::ARMOR_MENU_STATE::CAN'T LOAD MENU TEXTURE";
	sprite = sf::Sprite(texture);
	sprite.setScale(0.7f, 0.7f);
	//right arrow
	if (!right.loadFromFile("../images/other/rightarrow.png"))
		std::cout << "ERROR::ARMOR_MENU_STATE::CAN'T LOAD RIGHT_ARROW TEXTURE";
	rightArrow = sf::Sprite(right);
	rightArrow.setPosition(950.f, 350.f);
	//left arrow
	if (!left.loadFromFile("../images/other/leftarrow.png"))
		std::cout << "ERROR::ARMOR_MENU_STATE::CAN'T LOAD LEFT_ARROW TEXTURE";
	leftArrow = sf::Sprite(left);
	leftArrow.setPosition(5.f, 350.f);
	//gold coins
	coinsA = sf::Text("Gold coins: " + std::to_string(play.getHero()->getGoldCoins()), font, 50);
	GameState::setTextFeatures(this->coinsA);
	this->coinsA.setPosition(80.f, 130.f);
	//title
	titleA = sf::Text("Choose your armor", font, 80);
	GameState::setTextFeatures(this->titleA);
	titleA.setPosition(80.f, 30.f);
}