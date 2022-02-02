
#ifndef OBJECTANIMATION_H
#define OBJECTANIMATION_H

#include <iostream>
#include <list>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Map/Tile.h"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;

class ObjectAnimation {
public:
	//Constructor & Destructor
	ObjectAnimation() = default;
	ObjectAnimation(bool empty, sf::Vector2f tilesize, sf::Texture& isEmpty, sf::Texture& notEmpty, sf::FloatRect* bBox, int layerNumber);
	~ObjectAnimation() = default;

	std::vector<Tile*> getTile();
	void update();
	sf::FloatRect getBoundingBox();
	void setIsEmpty(bool empty);
	bool getIsEmpty();
	void updateTexture();

private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Texture emptyT;
	sf::Texture notEmptyT;
	sf::Vector2f size;
	sf::Vector2f tileSize;
	
	//tile
	std::vector<Tile*> tile;
	sf::FloatRect boundingBox;
	
	int numberOfTile;
	int lNumber;
	std::string n;

	bool e;
	//tile map

};

#endif OBJECTANIMATION_H