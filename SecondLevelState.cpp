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
	this->objectBB.resize(m->getNumberOfObjectLayer());
	this->objectBB = m->getBackgoundObjectBoundingBox();
	//message bubble
	setMessageBubble(str);
	setMex(false);
	//Achievements
	Playable::a = first.getAchievements();
	for (int i = 0; i < m->getInteractiveObjectNumber(); i++) {
		this->m->getInteractiveObject()[i]->setAchievement(getAchievements());
	}
	//enemy
	setEnemy(1, 60, 1, enemyPosX, enemyPosY);
	//View
	pos.x = getHero()->getPosX();
	pos.y = getHero()->getPosY();
	setView(pos);
}

//tile map

void SecondLevelState::setBackground() {
	this->m = new TileMap("../mapXML/SLMap.xml");
}

//Game State

GameState* SecondLevelState::handleInput(sf::Event evnt) {
	for (int k = 0; k < m->getInteractiveObjectNumber(); k++) {
		if (m->getInteractiveObject()[k]->getIsVisited() == false && getHero()->getAnimation().getBoundingBox().intersects(*m->getInteractiveObject()[k]->getBoundingBox())) {
			if (m->getInteractiveObject()[k]->getName() == "statue")
				setType(0);
			else
				setType(1);

			setCanMove(false);
			setMex(true);
			if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A) {
				m->getInteractiveObject()[k]->open();
			}
			if (m->getInteractiveObject()[k]->getIsOpen() == true) {
				if (m->getInteractiveObject()[k]->getIsEmpty() == false) {
					setType(2);
					if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::S) {
						getHero()->takePotion(m->getInteractiveObject()[k]);
						setMex(false);
						setCanMove(true);
						m->getInteractiveObject()[k]->setIsVisited(true);
					}
				}
				else {
					setType(3);
					if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::S) {
						setMex(false);
						setCanMove(true);
						m->getInteractiveObject()[k]->setIsVisited(true);
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
	if (getLive() == true && getHero()->getAnimation().getBoundingBox().top >= m->getSpecifiedObjectBoundingBox("wall7")->top + m->getSpecifiedObjectBoundingBox("wall7")->height && getHero()->getAnimation().getBoundingBox().top + getHero()->getAnimation().getBoundingBox().height <= m->getSpecifiedObjectBoundingBox("wall5")->top && getHero()->getPosX() <= getEnemy()->getAnimation().getBoundingBox().left + getEnemy()->getAnimation().getBoundingBox().width && getHero()->getPosX() >= m->getSpecifiedObjectBoundingBox("wall6")->left) {
		setMex(true);
		setCanMove(false);
		setType(4);
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A)
			return new FightState(*this);
	}

	//third level state
	if (getHero()->getAnimation().getBoundingBox().intersects(*m->getSpecifiedObjectBoundingBox("stair"))) {
		setType(5);
		setMex(true);
		setCanMove(false);
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::O) {
			getHero()->setPosX(1000.f);
			getHero()->setPosY(2000.f);
			getHero()->getAnimation().getSprite().setPosition(1000.f, 2000.f);
			m->clear();
			objectBB.clear();
			return new ThirdLevelState(*this, *p);
		}
	}

	if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::O) {
		getHero()->setPosX(1000.f);
		getHero()->setPosY(2000.f);
		getHero()->getAnimation().getSprite().setPosition(1000.f, 2000.f);
		m->clear();
		objectBB.clear();
		return new ThirdLevelState(*this, *p);
	}

	return this;
}

void SecondLevelState::render(sf::RenderTarget* target) {
	this->m->render(target);
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
		updateCollision(getHero(), this->m, this->objectBB);
		if (getEnemy() != nullptr)
			updateCollision(getHero(), getEnemy(), this->m, this->objectBB);
		else
			updateCollision(getHero(), this->m, this->objectBB);

		updateView(getHero(), this->m);
	}

	if (getMex() == true) {
		updateMessage(getView());
	}

	if (getAchievements()->getAchieve() == true) {
		getAchievements()->update(getView());
	}
}
