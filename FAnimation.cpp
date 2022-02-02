#include "FAnimation.h"

FAnimation::FAnimation(sf::Texture notYourTurnTexture, sf::Texture yourTurnTexture) {
	this->notYourTurnTexture = notYourTurnTexture;
	this->yourTurnTexture = yourTurnTexture;
	fightingSprite = sf::Sprite(this->notYourTurnTexture);
}

sf::Sprite& FAnimation::getSprite() {
	return this->fightingSprite;
}

//Turn Animation
void FAnimation::setTurn(bool yourTurn) {
	this->yourTurn = yourTurn;
}

bool FAnimation::getTurn() {
	return this->yourTurn;
}

void FAnimation::updateFightAnimation() {
	if (yourTurn == true)
		fightingSprite.setTexture(this->yourTurnTexture);
	else
		fightingSprite.setTexture(this->notYourTurnTexture);
}

//LP Animation
void FAnimation::setFightLPAnimation(int LP) {
	//LP Bubble
	if (!lpBubbleTextureF.loadFromFile("../images/other/greenlpbubble.png"))
		std::cout << "ERROR::FIGHT_ANIMATION::CAN'T LOAD THE GREEN_LP_BUBBLE_TEXTURE_FILE";
	lpBubbleSpriteF = sf::Sprite(lpBubbleTextureF);
	lpBubbleSpriteF.setScale(1.3f, 1.3f);
	lpBubbleSpriteF.setPosition(fightingSprite.getGlobalBounds().left + (fightingSprite.getGlobalBounds().width / 2.f) - (fightingSprite.getGlobalBounds().width / 2.f), 180.f);
	//Font
	if (!font.loadFromFile("../Font/TaylorGothic.otf"))
		std::cout << "ERROR::FIGHT_ANIMATION::CAN'T LOAD THE FONT FILE";
	//Lp Text
	LPText = sf::Text(std::to_string(LP), font, 40);
	LPText.setColor(sf::Color::White);
	LPText.setOutlineColor(sf::Color(75, 75, 75, 255));
	LPText.setOutlineThickness(2);
	LPText.setPosition(lpBubbleSpriteF.getGlobalBounds().left + (lpBubbleSpriteF.getGlobalBounds().width / 2.f) - (LPText.getGlobalBounds().width / 2.f), lpBubbleSpriteF.getGlobalBounds().top - (LPText.getGlobalBounds().height / 5.5f));
}

void FAnimation::updateFightLPAnimation(int LP) {
	LPText.setString(std::to_string(LP));
	LPText.setPosition(lpBubbleSpriteF.getGlobalBounds().left + (lpBubbleSpriteF.getGlobalBounds().width / 2.f) - (LPText.getGlobalBounds().width / 2.f), lpBubbleSpriteF.getGlobalBounds().top - (LPText.getGlobalBounds().height / 5.5f));
	if (LP <= 25) {
		if (!lpBubbleTextureF.loadFromFile("../images/other/orangelpbubble.png"))
			std::cout << "ERROR::FIGHT_ANIMATION::CAN'T LOAD THE ORANGE_LP_BUBBLE_TEXTURE_FILE";
	}
	if (LP <= 10) {
		if (!lpBubbleTextureF.loadFromFile("../images/other/redlpbubble.png"))
			std::cout << "ERROR::FIGHT_ANIMATION::CAN'T LOAD THE RED_LP_BUBBLE_TEXTURE_FILE";
	}

}

sf::Sprite& FAnimation::getLPBubble() {
	return this->lpBubbleSpriteF;
}

sf::Text& FAnimation::getLPText() {
	return this->LPText;
}