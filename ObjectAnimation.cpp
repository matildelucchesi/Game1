#include "ObjectAnimation.h"

ObjectAnimation::ObjectAnimation(bool empty, sf::Vector2f tilesize, sf::Texture& isEmpty, sf::Texture& notEmpty, sf::FloatRect* bBox, int layerNumber) {
	
	emptyT = isEmpty;
	notEmptyT = notEmpty;
	lNumber = layerNumber;
	this->boundingBox = *bBox;
	this->tileSize = tilesize;
	
	e = empty;
	
}

void ObjectAnimation::update(){
	if (e == true)
		texture = emptyT;
	else
		texture = notEmptyT;
	
	size.x = texture.getSize().x / tileSize.x;
	size.y = texture.getSize().y / tileSize.y;
	
	int s = 0;
	float posX = boundingBox.left;
	float posY = boundingBox.top;

	numberOfTile = (int)(size.x * size.y);
	
	tile.resize(numberOfTile);

	for (int i = 0; i < size.y; i++) {
		for (int j = 0; j < size.x; j++) {
			tile[s] = new Tile(tileSize, texture, posX, posY, s + 1);
			s++;
			posX += tileSize.x;
			if (posX == boundingBox.left + boundingBox.width) {
				posX = boundingBox.left;
				posY += tileSize.y;
			}
		}
	}
	
	
}

std::vector<Tile*> ObjectAnimation::getTile() {
	return this->tile;
}

sf::FloatRect ObjectAnimation::getBoundingBox() {
	return this->boundingBox;
}

void ObjectAnimation::setIsEmpty(bool empty) {
	this->e = empty;
}

void ObjectAnimation::updateTexture() {
	if (e == true)
		texture = emptyT;
	else
		texture = notEmptyT;
}

bool ObjectAnimation::getIsEmpty() {
	return this->e;
}