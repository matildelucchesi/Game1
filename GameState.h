#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <memory.h>
#include "Hero.h"
#include "Map/TileMap.h"

using namespace std;

#define viewX 1100.f
#define viewY 620.f
#define opacity 255
#define gameTextSize 30
#define menuTextSize 80

class GameState {
public:
	//Constructor & Destructor
	GameState();
	virtual ~GameState() = 0;

	virtual GameState* handleInput(sf::Event evnt) = 0;
	virtual void render(sf::RenderTarget* target) = 0;
	virtual void update() = 0;
	virtual void setBackground() = 0;
	void initFont();
	void setTextFeatures(sf::Text &t);

	//view
	void setView();
	void setView(sf::Vector2f centre);
	sf::View getView();
	void updateView(std::shared_ptr<Hero> hero, TileMap* map);

	sf::Font font;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::View view;
};

#endif 
