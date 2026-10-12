#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <cstdlib>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;

class Tile {
public:
	//Constructor & Destructor
	Tile(sf::Vector2f size, sf::Texture& texture, float gridX, float gridY, int gid);
	~Tile() = default;
	//render
	void render(sf::RenderTarget* target);
	void update(Tile* tile);
	void update(sf::Texture& texture);
	sf::Sprite getSprite();
	

private:
	sf::Vector2f size;
	sf::Vector2f rect;
	sf::Sprite tile;

};


#endif TILE_H