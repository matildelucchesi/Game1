#include "SecondLevelState.h"

SecondLevelState::SecondLevelState(FirstLevelState& firstState, PausedState& pause) : first(firstState){
	//hero
	Playable::hero = first.getHero();
	getHero()->getAnimation().update(sf::IntRect(64, 0, 64, 64));
	setCanMove(true);
	//paused state
	p = &pause;
	p->reinitialized(*this, getHero());
	//tile map
	setBackground();
	//background object bounding box
	setObjectBoundingBox();
	//message bubble
	setMessageBubble(str);
	setMex(false);
	//Achievements
	Playable::a = first.getAchievements();
	for (int i = 0; i < getMap()->getInteractiveObjectNumber(); i++) {
		getMap()->getInteractiveObject()[i]->setAchievement(getAchievements());
	}
	//enemy
	setEnemy(1, 50, 1, enemyPosX, enemyPosY);
	//View
	pos.x = getHero()->getPosX();
	pos.y = getHero()->getPosY();
	setView(pos);
}

//tile map

void SecondLevelState::setBackground() {
	Playable::map = new TileMap("../mapXML/SLMap.xml");
}

//Game State

GameState* SecondLevelState::handleInput(sf::Event evnt) {
	for (int k = 0; k < getMap()->getInteractiveObjectNumber(); k++) {
		if (getMap()->getInteractiveObject()[k]->getIsVisited() == false && getHero()->getAnimation().getBoundingBox().intersects(*getMap()->getInteractiveObject()[k]->getBoundingBox())) {
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

	//paused state
	if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::Enter)
		return this->p;

	//Achievements
	if (getAchievements()->getAchieve() == true && evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::Z)
		getAchievements()->setAchieve(false);

	//fight
	if (getLive() == true && getHero()->getAnimation().getBoundingBox().top >= getMap()->getSpecifiedObjectBoundingBox("wall7")->top + getMap()->getSpecifiedObjectBoundingBox("wall7")->height && getHero()->getAnimation().getBoundingBox().top + getHero()->getAnimation().getBoundingBox().height <= getMap()->getSpecifiedObjectBoundingBox("wall5")->top && getHero()->getPosX() <= getEnemy()->getAnimation().getBoundingBox().left + getEnemy()->getAnimation().getBoundingBox().width && getHero()->getPosX() >= getMap()->getSpecifiedObjectBoundingBox("wall6")->left) {
		setMex(true);
		setCanMove(false);
		setType(4);
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A)
			return new FightState(*this);
	}

	//third level state
	if (getHero()->getAnimation().getBoundingBox().intersects(*getMap()->getSpecifiedObjectBoundingBox("stair"))) {
		setType(5);
		setMex(true);
		setCanMove(false);
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A) {
			getHero()->setPosX(TposX);
			getHero()->setPosY(TposY);
			getHero()->getAnimation().getSprite().setPosition(TposX, TposY);
			getMap()->clear();
			getObjectBoundingBox().clear();
			return new ThirdLevelState(*this, *p);
		}
	}

	return this;
}

void SecondLevelState::render(sf::RenderTarget* target) {
	getMap()->render(target);
	//enemy
	if (getLive() == true)
		target->draw(getEnemy()->getAnimation().getSprite());
	//hero
	target->draw(getHero()->getAnimation().getSprite());
	target->draw(getHero()->getAnimation().getLPBubble());
	target->draw(getHero()->getAnimation().getLPText());
	target->setView(getView());
	//message
	if (getMex() == true) {
		target->draw(getMessageBubble());
		target->draw(getText());
	}
	//achievements message
	if (getAchievements()->getAchieve() == true) {
		getAchievements()->render(target);
	}
}

void SecondLevelState::update() {
	if (getCanMove() == true) {
		getHero()->updateMovement();
		getHero()->getAnimation().updateAnimation(getHero()->getMovementState());
		getHero()->getAnimation().updateBoundingBox();
		getHero()->getAnimation().updateLPBubble(getView(), getHero()->getLP());
		updateCollision(getHero(), getMap(), getObjectBoundingBox());
		if (getEnemy() != nullptr)
			updateCollision(getHero(), getEnemy(), getMap(), getObjectBoundingBox());
		else
			updateCollision(getHero(), getMap(), getObjectBoundingBox());

		updateView(getHero(), getMap());
	}

	if (getMex() == true) {
		updateMessage(getView());
	}

	if (getAchievements()->getAchieve() == true) {
		getAchievements()->update(getView());
	}
}
