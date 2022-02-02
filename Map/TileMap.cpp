#include "TileMap.h"

void TileMap::clear() {

	for (int i = 0; i < mapSize.x; i++) {
		for (int j = 0; j < mapSize.y; j++) {
			for (int w = 0; w < z; w++) {
				if(map[i][j][w] != nullptr)
					delete map[i][j][w];
			}
			map[i][j].clear();
		}
		map[i].clear();
	}

	map.clear();
	oBoundingBox.clear();
}

TileMap::TileMap(const char* xmlfile) {

	doc.LoadFile(xmlfile);
	if (doc.FirstChild() == nullptr)
		std::cout << "ERROR::TILEDMAP::ERROR_IN_LOADING_XML_FILE";

	//load tile size
	root = doc.FirstChildElement("map");
	root1 = doc.FirstChildElement("map");
	element = root->FirstChildElement("tileset");
	size.x = std::stoi(element->Attribute("tilewidth"));
	size.y = std::stoi(element->Attribute("tileheight"));

	//load texture source & set tile's texture
	element = element->FirstChildElement("image");
	textureSource = element->Attribute("source");
	if (!texture.loadFromFile(textureSource))
		std::cout << "ERROR::TILEDMAP::CAN'T_LOAD_TILE'S_TEXTURE_FROM_XML_FILE";

	//map
	element = root->FirstChildElement("layer");
	mapSize.x = std::stoi(element->Attribute("width"));
	mapSize.y = std::stoi(element->Attribute("height"));
	
	//map real size: multiply mapSize for the size of the tile because mapSize is in number of tiles
	mapRealSize.x = mapSize.x * size.x;
	mapRealSize.y = mapSize.y * size.y;

	//create the map
	//count how many layers and found what is the first layer of objects
	objectlayer = 0;
	z = 0;
	root = root->FirstChildElement("layer");

	tinyxml2::XMLElement* object = root->NextSiblingElement("objectgroup");
	
	while (root != nullptr) {
		z += 1;
		
		if (root->NextSibling() != nullptr && root->NextSibling() == root->NextSiblingElement("objectgroup")) {
			objectlayer++;	
		}
		root = root->NextSibling();

	}

	//boundingbox of background
	bBoundingBox = new sf::FloatRect(0.f, 0.f, mapRealSize.x, mapRealSize.y);
	//background's tiles instance
	int p = 0;

	root1 = root1->FirstChildElement("layer");
	element = root1->FirstChildElement("data");
	element = element->FirstChildElement("tile");

	map.resize(mapSize.x, std::vector< std::vector< Tile* > >());

	int l = 0;
	int x, y;
	
	while (root1 != nullptr) {

		x = -size.x;
		y = 0;
			for (int i = 0; i < mapSize.x; i++) {
				map[i].resize(mapSize.y, std::vector< Tile* >());

				for (int j = 0; j < mapSize.y; j++) {

					map[i][j].resize(z, NULL);
					x += size.x;
					if (x == mapSize.x * size.x) {
						x = 0.f;
						y += size.y;
					}
					
					map[i][j][l] = new Tile(size, this->texture, x, y, std::stoi(element->Attribute("gid")));
		
					if (element->NextSiblingElement("tile") != nullptr) {
						element = element->NextSiblingElement("tile");
					}
					else {
						l += 1 ;
						if (root1->NextSibling() == root1->NextSiblingElement("objectgroup")) {
							l++;
							root1 = root1->NextSibling();
						}
						root1 = root1->NextSiblingElement("layer");
						if (root1 != nullptr) {
							element = root1->FirstChildElement("data");
							element = element->FirstChildElement("tile");
						}
						else
							break;
					}
		
				}
			}
	}

	//object's tiles instance
	l = 0;
	root1 = object;
	element = root1->FirstChildElement("object");
	
	int s, c=0;

	oBoundingBox.resize(objectlayer);

	while (root1 != nullptr) {
		int maxX = 0;
		int maxY = 0;
		int minX = mapRealSize.x;
		int minY = mapRealSize.y;

		s = 0;
		for (int i = 0; i < mapSize.x; i++) {
			map[i].resize(mapSize.y, std::vector< Tile* >());

			for (int j = 0; j < mapSize.y; j++) {
				if (map[i][j][l] == nullptr) {
					map[i][j].resize(z);
					s++;
					if (s == std::stoi(element->Attribute("id"))) {
						map[i][j][l] = new Tile(size, this->texture, std::stoi(element->Attribute("x")), std::stoi(element->Attribute("y")) - size.y, std::stoi(element->Attribute("gid")));

						if (minX > std::stoi(element->Attribute("x")))
							minX = std::stoi(element->Attribute("x"));
						if (minY > std::stoi(element->Attribute("y")))
							minY = std::stoi(element->Attribute("y"));

						if (maxX < std::stoi(element->Attribute("x")))
							maxX = std::stoi(element->Attribute("x"));
						if (maxY < std::stoi(element->Attribute("y")))
							maxY = std::stoi(element->Attribute("y"));

						if(element->NextSibling() == element->NextSiblingElement("layer") && element->FirstChildElement("object") != nullptr) {
							root1 = root1->NextSibling();
							element = root1->NextSiblingElement("objectgroup");

							if (element->FirstChildElement("properties") != nullptr) {
								element = element->FirstChildElement("properties");
								element = element->NextSiblingElement("object");
							}
							else {
								element = element->FirstChildElement("object");
							}
						}

						if (element->NextSiblingElement("object") != nullptr) {
							element = element->NextSiblingElement("object");
						}
					}
				}
				else {
					l++;
				}

			}
		}
		
		oBoundingBox[c] =  new sf::FloatRect(minX, minY - size.y, (maxX + size.x) - minX , maxY - (minY - size.y));
		c++;


		if (root1->NextSiblingElement("objectgroup") != nullptr) {
			root1 = root1->NextSiblingElement("objectgroup");
			element = root1->FirstChildElement("object");
			l++;
		}
		else {
			break;
		}

	}
	
	//count the number of interactive objects
	numInteractiveOb = 0;
	root2 = doc.FirstChildElement("map");
	element = root2->FirstChildElement("objectgroup");
	root2 = root2->FirstChildElement("objectgroup");

	std::string treasure = "treasure";
	std::string statue = "statue";

	while (root2 != nullptr) {
		
		if (element->Attribute("name") == treasure || element->Attribute("name") == statue) {
			numInteractiveOb++;
		}

		root2 = root2->NextSibling();
		if (root2->NextSibling() != nullptr) {
			element = root2->NextSiblingElement("objectgroup");
		}
		else
			break;
	}

	//if the number of interactive objects isn't 0, add objects in interactiveOb
	int m = 0, q = -1, r = 0;

	if (numInteractiveOb != 0) {
		interactiveOb.resize(numInteractiveOb);

		root2 = doc.FirstChildElement("map");
		element = root2->FirstChildElement("layer");
		root2 = root2->FirstChildElement("layer");

		while (root2 != nullptr) {
			if (element->Attribute("name") == treasure) {
				element = element->FirstChildElement("properties");
				element = element->FirstChildElement("property");
				if (std::strcmp(element->Attribute("value"), "true") == 0)
					interactiveOb[m] = new InteractiveObject(this, treasure, true, size, oBoundingBox[q], r);
				else
					interactiveOb[m] = new InteractiveObject(this, treasure, false, size, oBoundingBox[q], r);
				
				m++;
			}
			if (element->Attribute("name") == statue) {
				element = element->FirstChildElement("properties");
				element = element->FirstChildElement("property");
				
				if (std::strcmp(element->Attribute("value"), "true") == 0)
					interactiveOb[m] = new InteractiveObject(this, statue, true, size, oBoundingBox[q], r);
				else
					interactiveOb[m] = new InteractiveObject(this, statue, false, size, oBoundingBox[q], r);
				
				m++;
			}

			if (root2->NextSibling() != nullptr) {
				if (root2->NextSibling() == root2->NextSiblingElement("layer")) {
					r++;
					element = root2->NextSiblingElement("layer");
					root2 = root2->NextSibling();
				}
				if (root2->NextSibling() == root2->NextSiblingElement("objectgroup")) {
					r++;
					element = root2->NextSiblingElement("objectgroup");
					root2 = root2->NextSibling();
					q++;
				}
			}
			else
				break;
		}
	}
	
}

TileMap::~TileMap() {
	clear();
}

void TileMap::render(sf::RenderTarget* target) {
	for (int w = 0; w < z; w++) {
		for (int i = 0; i < mapSize.x; i++) {
			for (int j = 0; j < mapSize.y; j++) {
				if (map[i][j][w] != nullptr) {
					map[i][j][w]->render(target);
				}
				
			}
		}
	}
}

sf::Vector2f TileMap::getSize(){
	return this->mapRealSize;
}

sf::Vector2f TileMap::getTileSize() {
	return this->size;
}

sf::FloatRect* TileMap::getBackgroundBoundingBox() {
	return this->bBoundingBox;
}

std::vector<sf::FloatRect*> TileMap::getBackgoundObjectBoundingBox() {
	return this->oBoundingBox;
}

int TileMap::getNumberOfObjectLayer() {
	return this->objectlayer;
}

sf::FloatRect* TileMap::getSpecifiedObjectBoundingBox(std::string layerName) {
	tinyxml2::XMLNode* r = doc.FirstChildElement("map");
	tinyxml2::XMLElement* e = r->FirstChildElement("objectgroup");
	r = r->FirstChildElement("objectgroup");
	
	int c = 0;

	while (r != nullptr) {

		if (layerName == e->Attribute("name")) {
			return oBoundingBox[c];
		}
		else {
			if (e->NextSibling() != e->NextSiblingElement("layer")) {
				e = r->NextSiblingElement("objectgroup");
				r = r->NextSiblingElement("objectgroup");
				c++;
			}
			else {
				r = r->NextSibling();
				e = r->NextSiblingElement("objectgroup");
			}
		}
	}
	
}

void TileMap::changeTile(int layerNumber, std::vector<Tile*> tile) {
	int s = 0;

	for (int i = 0; i < mapSize.x; i++) {
		for (int j = 0; j < mapSize.y; j++) {
			
			if (map[i][j][layerNumber] != nullptr) {
				map[i][j][layerNumber]->update(tile[s]);
				s++;
			}
		}
	}

}


std::vector<InteractiveObject*> TileMap::getInteractiveObject() {
	return this->interactiveOb;
}

int TileMap::getInteractiveObjectNumber() {
	return this->numInteractiveOb;
}