#include "WeaponMenuState.h"
#include "PlayingState.h"

WeaponMenuState::WeaponMenuState(PlayingState& playingState): GameState(), play(playingState) {
	//bakcground
	setBackground();
	//Weapons
	initWeaponText();
	w = (short)WEAPON::ARCH;
	weapon[0].setString("Arch");
	//control
	this->canBuy = true;
	//view
	setView();
}

void WeaponMenuState::render(sf::RenderTarget* target) {
	target->draw(sprite);
	target->draw(title);
	target->draw(coins);
	target->draw(weapon[this->w]);
	target->draw(leftArrow);
	target->draw(rightArrow);
	target->draw(weaponSprite);
	target->setView(getView());
}

GameState* WeaponMenuState::handleInput(sf::Event evnt) {
	if (evnt.type == evnt.KeyPressed) {
		if (evnt.key.code == sf::Keyboard::Right) {
			w += 1;
			w = w % 4;
		}
		if (evnt.key.code == sf::Keyboard::Left) {
			w -= 1;
			if (w == -1)
				w = 3;
		}
		
		if (evnt.key.code == sf::Keyboard::Enter) {
			if (this->canBuy == true) {
				chooseWeapon();
				this->play.getHero()->setTypeOfWeapon(wType);
				return new ArmorMenuState(this->play);
			}
			else {
				return this;
			}
		}
	}
	return this;
}

void WeaponMenuState::initWeaponText() {
	for (int i = 0; i < NUMBER_OF_WEAPONS; i++) {
		weapon[i] = sf::Text(" ", font, 80);
		GameState::setTextFeatures(this->weapon[i]);
		weapon[i].setPosition(150.f, 300.f);
	}
}

void WeaponMenuState::setSprite() {
	weaponSprite = sf::Sprite(weaponTexture);
	this->weaponSprite.setScale(4.f, 4.f);
	this->weaponSprite.setPosition(550.f, 230.f);
}

void WeaponMenuState::update() {
	switch (this->w) {
	case 0:
	{
		weapon[w].setString("Arch");
		if (play.getHero()->getGoldCoins() < 50) {
			weapon[w].setColor(sf::Color::Red);
			canBuy = false;
		}
		if (!weaponTexture.loadFromFile("../images/other/arch.png"))
			std::cout << "ERROR::WEAPON_MENU_STATE::CAN'T LOAD ARCH TEXTURE";
		break;
	}
	case 1:
	{
		this->weapon[w].setString("Ax");
		if (play.getHero()->getGoldCoins() < 10) {
			this->weapon[w].setColor(sf::Color::Red);
			this->canBuy = false;
		}
		if (!weaponTexture.loadFromFile("../images/other/ax.png"))
			std::cout << "ERROR::WEAPON_MENU_STATE::CAN'T LOAD AX TEXTURE";
		break;
	}
	case 2:
	{
		this->weapon[w].setString("Crossbow");
		if (play.getHero()->getGoldCoins() < 75) {
			this->weapon[w].setColor(sf::Color::Red);
			this->canBuy = false;
		}
		if (!weaponTexture.loadFromFile("../images/other/crossbow.png"))
			std::cout << "ERROR::WEAPON_MENU_STATE::CAN'T LOAD CROSSBOW TEXTURE";
		break;
	}
	case 3:
	{
		this->weapon[w].setString("Sword");
		if (play.getHero()->getGoldCoins() < 15) {
			this->weapon[w].setColor(sf::Color::Red);
			this->canBuy = false;
		}
		if (!weaponTexture.loadFromFile("../images/other/sword.png"))
			std::cout << "ERROR::WEAPON_MENU_STATE::CAN'T LOAD SWORD TEXTURE";
		break;
	}
	}
	setSprite();
}

void WeaponMenuState::chooseWeapon() {
	switch (w) {
	case 0 :
	{
		wType = "Arch";
		play.getHero()->setGoldCoins(play.getHero()->getGoldCoins() - 50);
		break;
	}
	case 1:
	{
		wType = "Ax";
		play.getHero()->setGoldCoins(play.getHero()->getGoldCoins() - 10);
		break;
	}
	case 2:
	{
		wType = "Crossbow";
		play.getHero()->setGoldCoins(play.getHero()->getGoldCoins() - 75);
		break;
	}
	case 3:
	{
		wType = "Sword";
		play.getHero()->setGoldCoins(play.getHero()->getGoldCoins() - 15);
		break;
	}
	}
}

void WeaponMenuState::setBackground() {
	//background
	if (!texture.loadFromFile("../images/other/menu.png"))
		std::cout << "ERROR::WEAPON_MENU_STATE::CAN'T LOAD MENU TEXTURE";
	sprite = sf::Sprite(texture);
	sprite.setScale(0.7f, 0.7f);
	//right
	if (!right.loadFromFile("../images/other/rightarrow.png"))
		std::cout << "ERROR::WEAPON_MENU_STATE::CAN'T LOAD RIGHT_ARROW TEXTURE";
	rightArrow = sf::Sprite(right);
	rightArrow.setPosition(950.f, 350.f);
	//left
	if (!left.loadFromFile("../images/other/leftarrow.png"))
		std::cout << "ERROR::WEAPON_MENU_STATE::CAN'T LOAD LEFT_ARROW TEXTURE";
	leftArrow = sf::Sprite(left);
	leftArrow.setPosition(5.f, 350.f);
	//title
	title = sf::Text("Choose your weapon", font, 80);
	GameState::setTextFeatures(this->title);
	title.setPosition(80.f, 30.f);
	//gold coins
	coins = sf::Text("Gold coins: " + std::to_string(play.getHero()->getGoldCoins()), font, 50);
	GameState::setTextFeatures(this->coins);
	coins.setPosition(80.f, 130.f);
}