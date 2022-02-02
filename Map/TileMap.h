#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include "tinyxml2.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include "../InteractiveObject.h"

using namespace tinyxml2;
using namespace std;

class InteractiveObject;
class ObjectAnimation;

class TileMap {
public:
	TileMap(const char* xmlfile);
	~TileMap();
	void render(sf::RenderTarget* target);
	void clear();
	sf::Vector2f getSize();
	sf::Vector2f getTileSize();
	sf::FloatRect* getBackgroundBoundingBox();
	std::vector <sf::FloatRect*> getBackgoundObjectBoundingBox();
	int getNumberOfObjectLayer();
	sf::FloatRect* getSpecifiedObjectBoundingBox(std::string layerName);
	void changeTile(int layerNumber, std::vector<Tile*> tile);

	//object
	std::vector<InteractiveObject*> getInteractiveObject();
	int getInteractiveObjectNumber();
	
private:
	float gridSizeF;
	unsigned gridSizeU;
	unsigned layer;
	std::string source;
	sf::Texture tileSheet;
	//map
	std::vector< std::vector < std::vector< Tile* > > > map;
	int z;
	int objectlayer;
	//file xml
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* element;
	tinyxml2::XMLNode* root;
	tinyxml2::XMLNode* root1;
	tinyxml2::XMLNode* root2;

	//size
	sf::Vector2f size;
	std::string textureSource;
	sf::Texture texture;
	sf::Vector2f mapSize;
	sf::Vector2f mapRealSize;

	//background bounding box
	sf::FloatRect* bBoundingBox;
	//background object bounding box
	std::vector <sf::FloatRect*> oBoundingBox;

	//interactive objects
	int numInteractiveOb;
	std::vector <InteractiveObject*> interactiveOb;


};


#endif TILEMAP_H