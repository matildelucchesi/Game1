#pragma once

#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum class MOVEMENT_STATE{IDLE = 5, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN};

using namespace std;

class Animation {
public:
	//Constructor
	Animation() = default;
	Animation(sf::Texture& texture);
	Animation(sf::Texture& texture, sf::IntRect& currentFrame, float movementSpeed, float x, float y);
	//Destructor
	~Animation() = default;
	//Update
	void update(sf::IntRect& currentFrame);
	void updateAnimation(short movingState);
	//Render stuff
	sf::Sprite& getSprite();
	//Movement stuff
	void setMovementSpeed(float m);
	float getMovementSpeed() const;
	//Text stuff
	void setFont();
	void setText(sf::Text& text);
	//LP Bubble stuff
	void setLPBubble(sf::View& v, int LP);
	void updateLPBubble(sf::View& v, int LP);
	sf::Sprite& getLPBubble();
	sf::Text& getLPText();
	//Clock
	sf::Clock getAnimationTimer();
	//bounding box
	sf::FloatRect getBoundingBox();
	void updateBoundingBox();
	//Collision
	void collision(sf::FloatRect* bBox);
	void boundCollision(sf::FloatRect* bBBox);

	sf::Font font;
	sf::Sprite sprite;

private:
	sf::Clock animationTimer;
	sf::Texture texture;
	sf::IntRect currentFrame;
	float movementSpeed;
	sf::Text LPText;
	sf::Sprite LPBubbleSprite;
	sf::Texture LPBubbleTexture;
	int LP;
	//bounding box
	sf::FloatRect boundingBox;
};



#endif 
