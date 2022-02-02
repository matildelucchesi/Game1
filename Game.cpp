#include "Game.h"
//Constructor & Destructor
Game::Game(){
	initVariables();
	initWindow();
}

Game::~Game() {
	delete this->window;
}

//Game
void Game::initVariables() {
	this->currentState = new StartState();
	this->endGame = false;
	this->window = nullptr;
}
void Game::initWindow() {
	this->window = new sf::RenderWindow(sf::VideoMode(1100, 620), "Game", sf::Style::Close);
	this->window->setFramerateLimit(144);
}

const bool Game::running() const {
	return this->window->isOpen();
}
void Game::pollEvents() {
	while (this->window->pollEvent(this->evnt)) {
		handleInput(evnt);
	}
}
void Game::update() {
	this->pollEvents();
	this->currentState->update();
}

//Render
void Game::render() {
	this->window->clear();
	this->currentState->render(this->window);
	this->window->display();
}

sf::RenderWindow* Game::getTarget() {
	return this->window;
}

void Game::handleInput(sf::Event evnt) {
	this->currentState = currentState->handleInput(evnt);
}



