#pragma once
#ifndef PLAYABLE_H
#define PLAYABLE_H

#include <iostream>
#include <string.h>
#include <sstream>
#include <memory>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Hero.h"
#include "Enemy.h"
#include "Achievements.h"

using namespace std;

class Playable {
public:
	Playable();
	virtual ~Playable() = 0;
	//messageBubble
	void textAnimation();
	void setMessageBubble(sf::String& s);
	void setMessageBubble(sf::View v, sf::String& s);
	void updateText(sf::View v, sf::String& s);
	sf::Sprite& getMessageBubble();
	sf::Text& getText();
	void updateMessageBubble(sf::View v, sf::String& s);
	void updateMessage(sf::View v);
	void setType(short t);
	short getType() const; 
	void setMex(bool m);
	bool getMex() const;
	//hero
	void setHeroRace(short hr);
	void setHeroClass(short cl);
	void setHero();
	virtual std::shared_ptr<Hero> getHero();
	//collision
	void updateCollision(std::shared_ptr<Hero> h, TileMap* m, std::vector<sf::FloatRect*> oBB);
	void updateCollision(std::shared_ptr<Hero> h, std::shared_ptr<Enemy> e, TileMap* m, std::vector<sf::FloatRect*> oBB);
	//hero
	std::shared_ptr<Hero> hero;
	bool canMove;
	void setCanMove(bool cM);
	bool getCanMove();
	//enemy
	std::shared_ptr<Enemy> enemy;
	void setEnemy(short race, int lp, int level, float posX, float posY);
	std::shared_ptr<Enemy> getEnemy();
	void destroyEnemy();
	void setLive(bool l);
	bool getLive();
	//Achievements
	void setAchievements();
	Achievements* getAchievements();
	Achievements* a;
	void setInteractiveObjectAchievements();
	//map
	TileMap* map;
	TileMap* getMap();
	//object's bounding box
	std::vector<sf::FloatRect*> objectBB;
	std::vector<sf::FloatRect*> getObjectBoundingBox();
	void setObjectBoundingBox();
	//interaction
	void objectInteraction(sf::Event e);

	
private:
	//message bubble
	sf::Texture message;
	sf::Sprite messageBubble;
	sf::Font f;
	sf::Text text;
	sf::String str;
	short type;
	bool mex;
	//hero
	short heroRace;
	short heroClass;
	//enemy
	bool live;
	
};

#endif 
