#include "Tile.h"


Tile::Tile(sf::Vector2f size, sf::Texture& texture, float gridX, float gridY, int gid) {
	//set tile
	this->tile.setTexture(texture);
	int id = 1;
	rect.x = 0.f;
	rect.y = 0.f;

	while (id != gid) {
		rect.x += size.x;
		if (rect.x == texture.getSize().x) {
			rect.x = 0.f;
			rect.y += size.y;
		}
	
		id += 1;
	}

	tile.setTextureRect(sf::IntRect(rect.x, rect.y, size.x, size.y));
	tile.setPosition(gridX, gridY);
}

void Tile::render(sf::RenderTarget* target) {
	target->draw(this->tile);
}

void Tile::update(Tile* tile) {
	this->tile = tile->getSprite();
}

void Tile::update(sf::Texture& texture) {
	tile.setTexture(texture);
}

sf::Sprite Tile::getSprite() {
	return this->tile;
}
