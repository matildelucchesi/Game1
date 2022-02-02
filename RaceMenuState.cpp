#include "RaceMenuState.h"

RaceMenuState::RaceMenuState() : GameState() {
	//Background
	setBackground();
	//hero
	initHeroSprite();
	//title
	text = sf::Text("Choose the race of the hero", font, 80);
	GameState::setTextFeatures(this->text);
	text.setPosition(80.f, 30.f);
	//Race
	initRaceText();
	this->r = (int) RACE::HUMAN;
	//view
	setView();
}

GameState* RaceMenuState::handleInput(sf::Event evnt) {
	if (evnt.type == evnt.KeyPressed) {
		if (evnt.key.code == sf::Keyboard::Right) {
			r += 1;
			r = r % NUMBER_OF_RACE;
		}
		if (evnt.key.code == sf::Keyboard::Left) {
			r -= 1;
			if (r == -1)
				r = NUMBER_OF_RACE - 1;
		}
		if (evnt.key.code == sf::Keyboard::Enter) {
			return new ClassMenuState(r);
		}
	}
	return this;
}

void RaceMenuState::render(sf::RenderTarget* target) {
	target->setView(getView());
	target->draw(this->sprite);
	target->draw(this->text);
	target->draw(this->race);
	target->draw(this->heroImage);
	target->draw(this->rightArrow);
	target->draw(this->leftArrow);
}

void RaceMenuState::initRaceText() {
	race = sf::Text("Human", font, 100);
	GameState::setTextFeatures(this->race);
	race.setPosition(150.f, 300.f);
}

void RaceMenuState::initHeroSprite() {
	heroImage = sf::Sprite(heroTexture);
	heroImage.setTextureRect(sf::IntRect(64, 0, 64, 64));
	heroImage.setScale(5.f, 5.f);
	heroImage.setPosition(600.f, 200.f);
}

void RaceMenuState::setBackground() {
	if (!texture.loadFromFile("../images/other/menu.png"))
		std::cout << "ERRROR::RACE_MENU_STATE::CAN'T LOAD MENU TEXTURE";
	sprite = sf::Sprite(texture);
	sprite.setScale(0.7f, 0.7f);
	//right arrow
	if (!this->right.loadFromFile("../images/other/rightarrow.png"))
		std::cout << "ERROR::RACE_MENU_STATE::CAN'T LOAD RIGHT_ARROW_TEXTURE";
	rightArrow = sf::Sprite(right);
	rightArrow.setPosition(950.f, 350.f);
	//left arrow
	if (!this->left.loadFromFile("../images/other/leftarrow.png"))
		std::cout << "ERROR::RACE_MENU_STATE::CAN'T LOAD LEFT_ARROW_TEXTURE";
	leftArrow = sf::Sprite(left);
	leftArrow.setPosition(5.f, 350.f);
}

void RaceMenuState::update() {
	switch (this->r) {
	case 0:
	{
		race.setString("Human");
		heroTexture.loadFromFile("../images/hero/human.png");
		break;
	}
	case 1:
	{
		race.setString("Dragonborn");
		heroTexture.loadFromFile("../images/hero/dragonborn.png");
		break;
	}
	case 2:
	{
		race.setString("Tiefling");
		heroTexture.loadFromFile("../images/hero/tiefling.png");
		break;
	}
	case 3:
	{
		race.setString("Elf");
		heroTexture.loadFromFile("../images/hero/elf.png");
		break;
	}
	case 4:
	{
		race.setString("Dwarf");
		heroTexture.loadFromFile("../images/hero/dwarf.png");
		break;
	}
	}
}