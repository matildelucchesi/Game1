#include "EndState.h"

EndState::EndState() {
	setView();
	setBackground();
}

GameState* EndState::handleInput(sf::Event evnt) {
	return this;
}

void EndState::render(sf::RenderTarget* target) {
	target->setView(getView());
	target->draw(backgroundS);
	target->draw(endMessage);
}

void EndState::update() {

}

void EndState::setBackground() {
	if (!background.loadFromFile("../images/other/menu.png"))
		std::cout << "ERROR::ENDASTATE::CAN'T LOAD BACKGROUND_TEXTURE	";
	backgroundS = sf::Sprite(background);

	endMessage = sf::Text("The End", font, 200);
	GameState::setTextFeatures(this->endMessage);
	endMessage.setPosition(550.f - (endMessage.getGlobalBounds().width / 2.f), 310.f - (endMessage.getGlobalBounds().height/2.f));

}