#include "StartState.h"

StartState::StartState() : GameState() {
	//background
	setBackground();
	//view
	setView(sf::Vector2f(texture.getSize().x / 2.f, texture.getSize().y / 2.f));
	//title
	setTitle();
	//text
	text = sf::Text("Press Enter to Start the Game", font, 70);
	GameState::setTextFeatures(this->text);
	text.setPosition(100.f, 450.f);

}

GameState* StartState::handleInput(sf::Event evnt) {
	if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::Enter) {
			return new RaceMenuState();
	}else
		return this;
}

void StartState::render(sf::RenderTarget* target) {
	target->draw(sprite);
	target->draw(title);
	target->draw(text);
	target->setView(getView());
}

void StartState::setTitle() {
	title = sf::Text("Castle", font, 200);
	GameState::setTextFeatures(this->title);
	title.setPosition(410.f, 10.f);
}

void StartState::update() {

}

void StartState::setBackground() {
	if (!texture.loadFromFile("../images/other/start.png"))
		std::cout << "ERROR::STARTSTATE::CANT'LOAD TEXTURE";
	sprite = sf::Sprite(texture);
}

