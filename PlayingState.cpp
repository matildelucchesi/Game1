#include "PlayingState.h"
#include "WeaponMenuState.h"
#include "ArmorMenuState.h"
#include "PausedState.h"


PlayingState::PlayingState(short race, short cl) : GameState() {
	//tile map
	setBackground();
	//background object bounding box
	objectBB.resize(map->getNumberOfObjectLayer());
	objectBB = map->getBackgoundObjectBoundingBox();
	//Hero
	Playable::setHeroRace(race);
	Playable::setHeroClass(cl);
	Playable::setHero();
	//View
	position.x = getHero()->getPosX();
	position.y = getHero()->getPosY();
	setView(position);
	//LP Bubble
	getHero()->getAnimation().setLPBubble(getView(), getHero()->getLP());
	//messsage bubble
	str = "Hey! You're the hero of this story!\nThe mindflayer Ronkahudroth has kidnapped the princess Metalyn,\nand took her inside his castle! Now you have to save her!\n...But, first of all, you have to choose an armor and a weapon to\nface the pitfalls that you will find in front of you, so let's press W!";
	setMessageBubble(getView(), str);
	//control
	stop = true;
	isOpen = false;
	//Paused State
	pause = new PausedState(*this, this->getHero());
	//clock
	this->timer.restart();
}

GameState* PlayingState::handleInput(sf::Event evnt) {
	if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::W) {
		return new WeaponMenuState(*this);
	}

	if(getHero()->getAnimation().getBoundingBox().intersects(*map->getSpecifiedObjectBoundingBox("castle")) && evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A){
		getHero()->setPosX(heroNewLevelPosX);
		getHero()->setPosY(heroNewLevelPosY);
		getHero()->getAnimation().getSprite().setPosition(heroNewLevelPosX, heroNewLevelPosY);
		map->clear();
		return new FirstLevelState(*this, *this->pause);
	}

	if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A) {
		map->clear();
		str.clear();
		return new FirstLevelState(*this, *this->pause);
	}



	if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::Enter)
		return this->pause;

	return this;
}
void PlayingState::render(sf::RenderTarget* target) {
	target->setView(getView());
	map->render(target);
	target->draw(getHero()->getAnimation().getSprite());
	target->draw(getHero()->getAnimation().getLPBubble());
	target->draw(getHero()->getAnimation().getLPText());
	
	if (stop == true) {
		target->draw(getMessageBubble());
		target->draw(getText());
	}
}

void PlayingState::update() {
	if (gameTimer.getElapsedTime() > sf::seconds(1) && stop == false) {
		getHero()->updateMovement();
		getHero()->getAnimation().updateAnimation(getHero()->getMovementState());
		getHero()->getAnimation().updateBoundingBox();
		updateCollision(getHero(), this->map, this->objectBB);
	}
	getHero()->getAnimation().updateLPBubble(getView(), getHero()->getLP());
	updateView(getHero(), this->map);

	textAnimation();
	if (stop == false) {
		if (getHero()->getPosX() >= this->map->getSpecifiedObjectBoundingBox("castle")->left + 10.f && getHero()->getPosX() <= this->map->getSpecifiedObjectBoundingBox("castle")->left + this->map->getSpecifiedObjectBoundingBox("castle")->width && getHero()->getPosY() <= this->map->getSpecifiedObjectBoundingBox("castle")->top + this->map->getSpecifiedObjectBoundingBox("castle")->height + getHero()->getAnimation().getBoundingBox().height) {
			{
				openCastleMessage();
			}
		}
	}
}

void PlayingState::setRace(short race) {
	hr = race;
}

void PlayingState::setClass(short cl) {
	c = cl;
}


void PlayingState::setStop(bool s) {
	this->stop = s;
}

void PlayingState::setBackground() {
	map = new TileMap("../mapXML/PLMap.xml");
}


void PlayingState::openCastleMessage() {
	str.clear();
	str = "You have now arrived at the castle entrance! Press A to enter!";
	updateMessageBubble(getView(), str);
	stop = true;
}
