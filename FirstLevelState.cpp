#include "FirstLevelState.h"
#include "PausedState.h"

FirstLevelState::FirstLevelState(PlayingState& playingState, PausedState& pausedState) : playingState_(playingState){
	//tile map
	setBackground();
	//background object bounding box
	this->objectBB.resize(m->getNumberOfObjectLayer());
	this->objectBB = m->getBackgoundObjectBoundingBox();
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
	for (int i = 0; i < m->getInteractiveObjectNumber(); i++)
		this->m->getInteractiveObject()[i]->setAchievement(getAchievements());
	//enemy
	setEnemy(2, 50, 1, enemyPosX, enemyPosY);
	//message bubble
	string_ = " ";
	setMessageBubble(string_);
	setMex(false);
	//paused state
	p = &pausedState;
	p->reinitialized(*this, getHero());
}

GameState* FirstLevelState::handleInput(sf::Event evnt) {

	for (int k = 0; k < m->getInteractiveObjectNumber(); k++) {
		if(m->getInteractiveObject()[k]->getIsVisited() == false && getHero()->getAnimation().getBoundingBox().intersects(*m->getInteractiveObject()[k]->getBoundingBox())){
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

	if (getLive() == true && getHero()->getAnimation().getBoundingBox().left >= m->getSpecifiedObjectBoundingBox("wall5")->left && getHero()->getPosY() <= getEnemy()->getAnimation().getBoundingBox().top + getEnemy()->getAnimation().getBoundingBox().height + getHero()->getAnimation().getBoundingBox().height && getHero()->getPosY() >= getEnemy()->getAnimation().getBoundingBox().top) {
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

	if (getHero()->getAnimation().getBoundingBox().intersects(*m->getSpecifiedObjectBoundingBox("stair"))) {
		setType(5);
		setMex(true);
		setCanMove(false);
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A) {
			getHero()->setPosX(heroSecondLevelPosX);
			getHero()->setPosY(heroSecondLevelPosY);
			getHero()->getAnimation().getSprite().setPosition(heroSecondLevelPosX, heroSecondLevelPosY);
			m->clear();
			objectBB.clear();
			return new SecondLevelState(*this, *p);
		}
	}

	if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::F) {
		getHero()->setPosX(heroSecondLevelPosX);
		getHero()->setPosY(heroSecondLevelPosY);
		getHero()->getAnimation().getSprite().setPosition(heroSecondLevelPosX, heroSecondLevelPosY);
		m->clear();
		objectBB.clear();
		return new SecondLevelState(*this, *p);
	}
	
	return this;

}

void FirstLevelState::render(sf::RenderTarget* target) {
	this->m->render(target);
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
		if (this->e != nullptr)
			updateCollision(getHero(), this->e, this->m, this->objectBB);
		else
			updateCollision(getHero(), this->m, this->objectBB);
		updateView(getHero(), this->m);
	}
	
	if (getMex() == true) {
			updateMessage(getView());
	}

	if (a->getAchieve() == true) {
		a->update(getView());
	}
}

void FirstLevelState::setBackground() {
	m = new TileMap("../mapXML/FLMap.xml");
}

/*Achievements* FirstLevelState::getAchievements() {
	return this->a;
}*/