#include "GameState.h"

GameState::GameState() {
	initFont();
}

GameState::~GameState() {

}

void GameState::initFont() {
	if (!this->font.loadFromFile("../Font/TaylorGothic.otf"))
		std::cout << "ERROR::GAMESTATE::CAN'T LOAD THE FONT";
}

void GameState::setTextFeatures(sf::Text &t) {
	t.setFillColor(sf::Color::White);
	t.setOutlineColor(sf::Color(75, 75, 75, opacity));
	t.setOutlineThickness(3);
}

void GameState::setView() {
	view.reset(sf::FloatRect(0.f, 0.f, viewX, viewY));
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
}

void GameState::setView(sf::Vector2f center) {
	view.reset(sf::FloatRect(0.f, 0.f, viewX, viewY));
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	view.setCenter(center);
}

sf::View GameState::getView() {
	return this->view;
}

void GameState::updateView(std::shared_ptr<Hero> hero, TileMap* map) {
	sf::Vector2f c;
	c.x = hero->getPosX();
	c.y = hero->getPosY();

	if (hero->getPosX() + 1 >= viewX / 2.f) {
		if (hero->getPosX() + viewX / 2.f >= map->getSize().x)
			c.x = map->getSize().x - viewX / 2.f;
		else
			c.x = hero->getPosX() + 1;
	}

	if (hero->getPosX() + 1 < viewX / 2.f) {
		if (hero->getPosX() - viewX / 2.f <= 0.f)
			c.x = viewX / 2.f;
		else
			c.x = hero->getPosX() - 1;
	}

	if (hero->getPosY() + 1 >= viewY / 2.f) {
		if (hero->getPosY() + viewY / 2.f >= map->getSize().y)
			c.y = map->getSize().y - viewY / 2.f;
		else
			c.y = hero->getPosY() + 1;
	}

	if (hero->getPosY() + 1 < viewY / 2.f) {
		if (hero->getPosY() - viewY / 2.f <= 0.f)
			c.y = viewY / 2.f;
		else
			c.y = hero->getPosY() - 1;
	}

	view.setCenter(c);
}
