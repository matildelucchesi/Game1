#include "FirstLevelState.h"
#include "PausedState.h"

FirstLevelState::FirstLevelState(PlayingState& playingState, PausedState& pausedState) : playingState_(playingState){
	//tile map
	setBackground();
	//background object's bounding box
	setObjectBoundingBox();
	//hero
	Playable::hero = playingState_.getHero();
	getHero()->getAnimation().update(sf::IntRect(64, 0, 64, 64));
	setCanMove(true);
	//View
	pos.x = getHero()->getPosX();
	pos.y = getHero()->getPosY();
	setView(pos);
	//Achievements
	setAchievements();
	for (int i = 0; i < getMap()->getInteractiveObjectNumber(); i++)
		this->getMap()->getInteractiveObject()[i]->setAchievement(getAchievements());
	//enemy
	setEnemy(2, 30, 1, enemyPosX, enemyPosY);
	//message bubble
	string_ = " ";
	setMessageBubble(string_);
	setMex(false);
	//paused state
	p = &pausedState;
	p->reinitialized(*this, getHero());
}

GameState* FirstLevelState::handleInput(sf::Event evnt) {

	for (int k = 0; k < getMap()->getInteractiveObjectNumber(); k++) {
		if(getMap()->getInteractiveObject()[k]->getIsVisited() == false && getHero()->getAnimation().getBoundingBox().intersects(*getMap()->getInteractiveObject()[k]->getBoundingBox())){
			if (getMap()->getInteractiveObject()[k]->getName() == "statue")
				setType(0);
			else
				setType(1);

			setCanMove(false);

			setMex(true);
			if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A) {
				getMap()->getInteractiveObject()[k]->open();
			}
			if (getMap()->getInteractiveObject()[k]->getIsOpen() == true) {
				if (getMap()->getInteractiveObject()[k]->getIsEmpty() == false) {
					setType(2);
					if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::S) {
						getHero()->takePotion(getMap()->getInteractiveObject()[k]);
						setMex(false);
						setCanMove(true);
						getMap()->getInteractiveObject()[k]->setIsVisited(true);
					}
				}
				else {
					setType(3);
					if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::S) {
						setMex(false);
						setCanMove(true);
						getMap()->getInteractiveObject()[k]->setIsVisited(true);
					}
				}
			}
		}
	}

	if (getLive() == true && getHero()->getAnimation().getBoundingBox().left >= getMap()->getSpecifiedObjectBoundingBox("wall5")->left && getHero()->getPosY() <= getEnemy()->getAnimation().getBoundingBox().top + getEnemy()->getAnimation().getBoundingBox().height + getHero()->getAnimation().getBoundingBox().height && getHero()->getPosY() >= getEnemy()->getAnimation().getBoundingBox().top) {
		setMex(true);
		setCanMove(false);
		setType(4);
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A)
			return new FightState(*this);
	}
	
	if (getAchievements()->getAchieve() == true && evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::Z)
		getAchievements()->setAchieve(false);

	if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::Enter)
		return this->p;

	if (getHero()->getAnimation().getBoundingBox().intersects(*getMap()->getSpecifiedObjectBoundingBox("stair"))) {
		setType(5);
		setMex(true);
		setCanMove(false);
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A) {
			getHero()->setPosX(heroSecondLevelPosX);
			getHero()->setPosY(heroSecondLevelPosY);
			getHero()->getAnimation().getSprite().setPosition(heroSecondLevelPosX, heroSecondLevelPosY);
			getMap()->clear();
			getObjectBoundingBox().clear();
			return new SecondLevelState(*this, *p);
		}
	}
	
	return this;

}

void FirstLevelState::render(sf::RenderTarget* target) {
	this->getMap()->render(target);
	if (getLive() == true)
		target->draw(getEnemy()->getAnimation().getSprite());
	target->draw(getHero()->getAnimation().getSprite());
	target->draw(getHero()->getAnimation().getLPBubble());
	target->draw(getHero()->getAnimation().getLPText());
	target->setView(getView());

	if (getMex() == true) {
		target->draw(getMessageBubble());
		target->draw(getText());
	}
	if (getAchievements()->getAchieve() == true) {
		getAchievements()->render(target);
	}

}

void FirstLevelState::update() {
	if (getCanMove() == true) {
		getHero()->updateMovement();
		getHero()->getAnimation().updateAnimation(getHero()->getMovementState());
		getHero()->getAnimation().updateBoundingBox();
		getHero()->getAnimation().updateLPBubble(getView(), getHero()->getLP());
		if (getEnemy() != nullptr)
			updateCollision(getHero(), getEnemy(), getMap(), getObjectBoundingBox());
		else
			updateCollision(getHero(), getMap(), getObjectBoundingBox());
		updateView(getHero(), getMap());
	}
	
	if (getMex() == true) {
			updateMessage(getView());
	}

	if (a->getAchieve() == true) {
		a->update(getView());
	}
}

void FirstLevelState::setBackground() {
	Playable::map = new TileMap("../mapXML/FLMap.xml");
}
