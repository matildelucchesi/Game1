#include "ThirdLevelState.h"

ThirdLevelState::ThirdLevelState(SecondLevelState& secondState, PausedState& pause) {
	//hero
	Playable::hero = secondState.getHero();
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
	Playable::a = secondState.getAchievements();
	for (int i = 0; i < getMap()->getInteractiveObjectNumber(); i++) {
		getMap()->getInteractiveObject()[i]->setAchievement(getAchievements());
	}
	//enemy
	setEnemy(0, 50, 2, ePosX, ePosY);
	//View
	pos.x = getHero()->getPosX();
	pos.y = getHero()->getPosY();
	setView(pos);
}

//tile map

void ThirdLevelState::setBackground() {
	Playable::map = new TileMap("../mapXML/TLMap.xml");
}

//Game State

GameState* ThirdLevelState::handleInput(sf::Event evnt) {
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
	if(getLive() == true && getHero()->getAnimation().getBoundingBox().intersects(getEnemy()->getAnimation().getBoundingBox())){
		setMex(true);
		setCanMove(false);
		setType(4);
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A)
			return new FightState(*this);
	}

	if (getLive() == false) {
		setType(6);
		setMex(true);
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A)
			return new EndState();
	}


	return this;
}

void ThirdLevelState::render(sf::RenderTarget* target) {
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
	if (a->getAchieve() == true) {
		a->render(target);
	}
}

void ThirdLevelState::update() {
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
