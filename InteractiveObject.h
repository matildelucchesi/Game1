
#ifndef INTERACTIVEOBJECT_H
#define INTERACTIVEOBJECT_H

#include <iostream>
#include "Achievements.h"
#include "Observable.h"
#include "Potion.h"
#include "Map/TileMap.h"
#include "ObjectAnimation.h"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace std;

class TileMap;

class InteractiveObject : public Observable {
public:
	//constructor & destructor
	InteractiveObject(TileMap* map, std::string name, bool empty, sf::Vector2f tilesize, sf::FloatRect* bBox, int layerNumber);
	~InteractiveObject() = default;

	//setter & getter
	void setIsVisited(bool isVisited_);
	bool getIsVisited() const;
	void setIsOpen(bool isOpen_);
	bool getIsOpen() const;
	void setIsEmpty(bool isEmpty_);
	bool getIsEmpty() const;
	void setPosX(int posX_);
	int getPosX() const;
	void setPosY(int posY_);
	int getPosY() const;
	void setAchievement(Achievements* a);
	Achievements* getAchievement() const;
	std::string getName();

	//bounding box
	sf::FloatRect* getBoundingBox();

	//interaction
	void open();
	void notify() override;
	std::shared_ptr<Potion> getPotion();
	void takePotion();

	//Animation
	ObjectAnimation getAnimation();

private:
	bool isVisited;
	bool isOpen;
	bool isEmpty;
	sf::Texture emptyT;
	sf::Texture notEmptyT;
	int posX;
	int posY;
	std::string n;
	sf::FloatRect* boundingBox;

	//animation
	ObjectAnimation animation;
	int l;

	//potion
	std::shared_ptr<Potion> potion;

	//achievements
	Achievements* achievement;

	//tile map
	TileMap* m;
};

#endif INTERACTIVEOBJECT_H