#include "Animation.h"
Animation::Animation(sf::Texture& texture) {
	this->animationTimer.restart();
	sprite = sf::Sprite(texture, sf::IntRect(64, 0, 64, 64));
	boundingBox = sprite.getGlobalBounds();
	setFont();
	movementSpeed = 0;
}

Animation::Animation(sf::Texture& texture, sf::IntRect& currentFrame, float movementSpeed, float x, float y) {
	this->animationTimer.restart();
	sprite = sf::Sprite(texture, currentFrame);
	sprite.setPosition(x, y);
	boundingBox = sprite.getGlobalBounds();
	this->movementSpeed = movementSpeed;
	setFont();
}

void Animation::update(sf::IntRect& currentFrame) {
	sprite.setTextureRect(currentFrame);
}

sf::Sprite& Animation::getSprite() {
	return this->sprite;
}

void Animation::setMovementSpeed(float m) {
	this->movementSpeed = m;
}

float Animation::getMovementSpeed() const {
	return this->movementSpeed;
}

void Animation::setFont() {
	if (!font.loadFromFile("../Font/TaylorGothic.otf"))
		std::cout << "ERROR::ANIMATION::CAN'T LOAD FONT FILE";
}

void Animation::setText(sf::Text& text) {
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color(75, 75, 75, 255));
	text.setOutlineThickness(2);
}

sf::Clock Animation::getAnimationTimer() {
	return this->animationTimer;
}

void Animation::updateAnimation(short movingState) {
	switch (movingState) {
	case 5:
	{
		currentFrame = sf::IntRect(64, 0, 64, 64);
		break;
	}
	case 6:
	{
		if (animationTimer.getElapsedTime().asSeconds() >= 0.1f) {
			this->currentFrame.top = 64;
			this->currentFrame.left += 64;
			if (this->currentFrame.left >= 192) {
				this->currentFrame.left = 0;
			}
			animationTimer.restart();
			sprite.setTextureRect(this->currentFrame);
		}
		break;
	}
	case 7:
	{
		if (animationTimer.getElapsedTime().asSeconds() >= 0.1f) {
			this->currentFrame.top = 128;
			this->currentFrame.left += 64;
			if (this->currentFrame.left >= 192) {
				this->currentFrame.left = 0;
			}
			animationTimer.restart();
			sprite.setTextureRect(this->currentFrame);
		}
		break;
	}
	case 8:
	{
		if (animationTimer.getElapsedTime().asSeconds() >= 0.1f) {
			this->currentFrame.top = 192;
			this->currentFrame.left += 64;
			if (this->currentFrame.left >= 192) {
				this->currentFrame.left = 0;
			}
			animationTimer.restart();
			sprite.setTextureRect(this->currentFrame);
		}
		break;
	}
	case 9:
	{
		if (animationTimer.getElapsedTime().asSeconds() >= 0.1f) {
			this->currentFrame.top = 0;
			this->currentFrame.left += 64;
			if (this->currentFrame.left >= 192) {
				this->currentFrame.left = 0;
			}
			animationTimer.restart();
			sprite.setTextureRect(this->currentFrame);
		}
		break;
	}
	}
}

//LP bubble

void Animation::setLPBubble(sf::View& v, int LP) {
	if (!this->LPBubbleTexture.loadFromFile("../images/other/greenlpbubble.png"))
		std::cout << "ERROR::ANIMATION::CAN'T LOAD GREEN_LP_BUBBLE_TEXTURE_FILE";
	LPBubbleSprite = sf::Sprite(this->LPBubbleTexture);
	LPBubbleSprite.setScale(1.3f, 1.3f);
	LPBubbleSprite.setPosition(v.getCenter().x + 335.f , v.getCenter().y - 280.f);
	//text
	LPText = sf::Text(std::to_string(LP), font, 30);
	LPText.setFillColor(sf::Color::White);
	LPText.setOutlineColor(sf::Color(75, 75, 75, 255));
	LPText.setOutlineThickness(2);
	LPText.setPosition(v.getCenter().x + 335.f + (LPBubbleSprite.getGlobalBounds().width / 2.f) - (LPText.getGlobalBounds().width / 2.f), v.getCenter().y - 280.f);
}

void Animation::updateLPBubble(sf::View& v, int LP) {
	LPText.setString(std::to_string(LP));
	if (LP > 25) {
		if (!LPBubbleTexture.loadFromFile("../images/other/greenlpbubble.png"))
			std::cout << "ERROR::ANIMATION::CAN'T LOAD GREEN_LP_BUBBLE_TEXTURE_FILE";
	}
	if (LP <= 25) {
		if (!LPBubbleTexture.loadFromFile("../images/other/orangelpbubble.png"))
			std::cout << "ERROR::ANIMATION::CAN'T LOAD ORANGE_LP_BUBBLE_TEXTURE_FILE";
	}
	if (LP <= 10) {
		if (!LPBubbleTexture.loadFromFile("../images/other/redlpbubble.png"))
			std::cout << "ERROR::ANIMATION::CAN'T LOAD RED_LP_BUBBLE_TEXTURE_FILE";
	}
	LPBubbleSprite.setPosition(v.getCenter().x + 335.f, v.getCenter().y - 280.f);
	LPText.setPosition(v.getCenter().x + 335.f + (LPBubbleSprite.getGlobalBounds().width / 2.f) - (LPText.getGlobalBounds().width / 2.f), v.getCenter().y - 280.f);
}

sf::Sprite& Animation::getLPBubble() {
	return this->LPBubbleSprite;
}

sf::Text& Animation::getLPText() {
	return this->LPText;
}

sf::FloatRect Animation::getBoundingBox() {
	return this->boundingBox;
}

void Animation::collision(sf::FloatRect* bBox) {
	sf::FloatRect nextPos = this->boundingBox;
	nextPos.left += 0.1f;
	nextPos.top += 0.1f;

	if (bBox->intersects(nextPos)) {
		//Top
		if (boundingBox.top < bBox->top && boundingBox.top + boundingBox.height < bBox->top + bBox->height && boundingBox.left < bBox->left + bBox->width && boundingBox.left + boundingBox.width > bBox->left) {
			this->sprite.setPosition(boundingBox.left, bBox->top - boundingBox.height);
		}
		//Bottom
		if (boundingBox.top > bBox->top && boundingBox.top + boundingBox.height > bBox->top + bBox->height && boundingBox.left < bBox->left + bBox->width && boundingBox.left + boundingBox.width > bBox->left) {
			this->sprite.setPosition(boundingBox.left, bBox->top + bBox->height);
		}
		//Right
		if (boundingBox.left < bBox->left && boundingBox.left + boundingBox.width < bBox->left + bBox->width && boundingBox.top < bBox->top + bBox->height && boundingBox.top + boundingBox.height > bBox->top) {
			this->sprite.setPosition(bBox->left - boundingBox.width, boundingBox.top);
		}
		//Left
		if (boundingBox.left > bBox->left && boundingBox.left + boundingBox.width > bBox->left + bBox->width && boundingBox.top < bBox->top + bBox->height && boundingBox.top + boundingBox.height > bBox->top) {
			this->sprite.setPosition(bBox->left + bBox->width, boundingBox.top);
		}
	}
}

void Animation::updateBoundingBox() {
	this->boundingBox = this->sprite.getGlobalBounds();
}

void Animation::boundCollision(sf::FloatRect* bBBox) {
	sf::FloatRect nextPos = this->boundingBox;
	nextPos.left += 0.1f;
	nextPos.top += 0.1f;

	if (bBBox->intersects(nextPos)) {
		//Top
		if (boundingBox.top < bBBox->top)
			sprite.setPosition(sprite.getPosition().x, bBBox->top);
		//Bottom
		if (boundingBox.top + boundingBox.height > bBBox->top + bBBox->height)
			sprite.setPosition(sprite.getPosition().x, bBBox->top + bBBox->height - boundingBox.height);
		//Right
		if (boundingBox.left < bBBox->left)
			sprite.setPosition(bBBox->left, sprite.getPosition().y);
		//Left
		if (boundingBox.left + boundingBox.width > bBBox->left + bBBox->width)
			sprite.setPosition(bBBox->left + bBBox->width - boundingBox.width, sprite.getPosition().y);
	}
}