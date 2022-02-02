#include "ClassMenuState.h"

ClassMenuState::ClassMenuState(short race) : GameState() {
	//background
	setBackground();
	//title
	this->text = sf::Text("Choose the class of the hero", font, 80);
	GameState::setTextFeatures(this->text);
	this->text.setPosition(80.f, 30.f);
	//classes
	this->cl = (int) CLASSES::BARBARIAN;
	initClassText();
	this->classes[0].setString("Barbarian");
	this->classes[0].setPosition(100.f, 200.f);
	this->classes[1].setString("Druid");
	this->classes[1].setPosition(100.f, 300.f);
	this->classes[2].setString("Warrior");
	this->classes[2].setPosition(100.f, 400.f);
	this->classes[3].setString("Wizard");
	this->classes[3].setPosition(100.f, 500.f);
	this->r = race;
	//view
	setView();
}

GameState* ClassMenuState::handleInput(sf::Event evnt) {
	if (evnt.type == evnt.KeyPressed) {
		if (evnt.key.code == sf::Keyboard::Down) {
			cl += 1;
			cl = cl % NUMBER_OF_CLASSES;
		}
		if (evnt.key.code == sf::Keyboard::Up) {
			cl -= 1;
			if (cl == -1)
				cl = NUMBER_OF_CLASSES - 1;
		}
		if (evnt.key.code == sf::Keyboard::Enter) {
			return new PlayingState(r, cl);
		}
	}
	return this;
}

void ClassMenuState::render(sf::RenderTarget* target) {
	target->setView(getView());
	target->draw(this->sprite);
	target->draw(this->text);
	for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
		target->draw(this->classes[i]);
	}
}

void ClassMenuState::initClassText() {
	for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
		classes[i] = sf::Text(" ", font, 80);
		GameState::setTextFeatures(classes[i]);
	}
}

void ClassMenuState::update() {
		this->classes[0].setOutlineColor(sf::Color(75, 75, 75, 255));
		this->classes[1].setOutlineColor(sf::Color(75, 75, 75, 255));
		this->classes[2].setOutlineColor(sf::Color(75, 75, 75, 255));
		this->classes[3].setOutlineColor(sf::Color(75, 75, 75, 255));
		this->classes[cl].setOutlineColor(sf::Color(0, 0, 0, 255));
}

void ClassMenuState::setBackground() {
	if (!texture.loadFromFile("../images/other/menu.png"))
		std::cout << "ERROR::CLASS_MENU_STATE::CAN'T LOAD MENU TEXTURE";
	sprite = sf::Sprite(texture);
	sprite.setScale(0.7f, 0.7f);
}