#include "FightState.h"

FightState::FightState(Playable& state) : state_(state){
	//Hero
	this->h = this->state_.getHero();
	h->getFightAnimation().setFightLPAnimation(h->getLP());
	h->getFightAnimation().setTurn(false);
	heroResult = h->throwDiceFight();
	//Enemy
	e = state_.getEnemy();
	e->getFightAnimation().setFightLPAnimation(e->getLP());
	e->getFightAnimation().setTurn(false);
	enemyResult = e->throwDiceFight();
	//View
	setView();
	//Background
	setBackground();
	start = true;
	//clock
	s = 0;
	type = 4;
}

void FightState::setBackground() {
	if (!background.loadFromFile("../images/fight/background.png"))
		std::cout << "ERROR::FIGHT_STATE::CAN'T LOAD BACKGROUND_TEXTURE";
	backgroundS = sf::Sprite(background);

	//text
	messageT = sf::Text(" ", font, 80);
	GameState::setTextFeatures(this->messageT);

	//hero
	heroCAText = sf::Text("CA: " + std::to_string(this->h->getArmor().getCA()), font, 50);
	GameState::setTextFeatures(this->heroCAText);
	heroCAText.setPosition(viewX / 2.f - 387.f, viewY / 2.f + 150.f);
		
	heroInitiative = sf::Text(to_string(h->getInitiative()), font, 80);
	heroInitiative.setFillColor(sf::Color::Black);
	heroInitiative.setPosition(viewX / 2.f - 95.f - heroInitiative.getGlobalBounds().width, viewY / 2.f - 30.f);
	
	//enemy
	enemyCAText = sf::Text("CA: "+ std::to_string(e->getArmor().getCA()), font, 50);
	GameState::setTextFeatures(this->enemyCAText);
	enemyCAText.setPosition(viewX / 2.f + 313.f, viewY / 2.f + 150.f);

	enemyInitiative = sf::Text(std::to_string(e->getInitiative()), font, 80);
	enemyInitiative.setFillColor(sf::Color::Black);
	enemyInitiative.setPosition(viewX / 2.f + 100.f, viewY / 2.f - 30.f);

	//numbers
	number = sf::Text(" ", font, 60);
	GameState::setTextFeatures(this->number);
	number.setPosition(viewX / 2.f - 20.f, viewY / 2.f - 10.f);

	heroNumber = sf::Text(std::to_string(heroResult), font, 60);
	GameState::setTextFeatures(this->heroNumber);
	heroNumber.setPosition(viewX / 2.f - (heroNumber.getGlobalBounds().width / 2.f), viewY / 2.f - 10.f);

	enemyNumber = sf::Text(std::to_string(enemyResult), font, 60);
	GameState::setTextFeatures(this->enemyNumber);
	enemyNumber.setPosition(viewX / 2.f - (enemyNumber.getGlobalBounds().width / 2.f), viewY / 2.f - 10.f);

	//initiative stuff
	if (!rect.loadFromFile("../images/fight/rect.png"))
		std::cout << "ERROR::FIGHT_STATE::CAN'T LOAD RECT_TEXTURE";
	rectS = sf::Sprite(rect);
	rectS.setPosition(viewX / 2.f - (rectS.getGlobalBounds().width / 2.f) , viewY / 2.f - 35.f);

	mm = sf::Text(" ", font, 80);
	mm.setFillColor(sf::Color::Black);
	mm.setPosition(viewX / 2.f - (mm.getGlobalBounds().width / 2.f), viewY / 2.f - 45.f);


}

GameState* FightState::handleInput(sf::Event evnt) {
	if (s == 0 && type == 4 && evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A) {
		if (h->getInitiative() >= e->getInitiative()) {
			mm.setString(">");
			h->getFightAnimation().setTurn(true);
			s = 2;
		}
		else {
			mm.setString("<");
			e->getFightAnimation().setTurn(true);
			s = 1;
		}
		type = 4;
	}
	
	if (s == 1 && e->getLP() != 0 && h->getLP() != 0) {
		e->getFightAnimation().setTurn(true);

		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::D) {
			start = false;
			enemyAttack();
			h->getFightAnimation().setTurn(true);
			s = 3;
		}
	}

	if (s == 2 && h->getLP() != 0 && e->getLP() != 0) {
		e->getFightAnimation().setTurn(false);

		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::S) {
			start = false;
			heroAttack();
			h->getFightAnimation().setTurn(false);
			s = 3;
		}
	}

	if (s == 3) {
		if (e->getFightAnimation().getTurn() == true)
			s = 2;
		else
			s = 1;
	}

	if (h->getLP() == 0) {
		type = 10;
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A) {
			return new EndState();
		}
	}

	if (e->getLP() == 0) {
		type = 9;
		if (evnt.type == evnt.KeyPressed && evnt.key.code == sf::Keyboard::A){
			state_.destroyEnemy();
			return dynamic_cast<GameState*>(&state_);
			}
	}

	return this;
}

void FightState::update() {
	//Update Message
	updateUpperMessage();
	//Update Hero
	h->getFightAnimation().updateFightAnimation();
	//Update Enemy
	e->getFightAnimation().updateFightAnimation();
}

void FightState::render(sf::RenderTarget* target) {
	//View
	target->setView(getView());
	//Background
	target->draw(backgroundS);
	//Render Hero
	target->draw(h->getFightAnimation().getSprite());
	target->draw(h->getFightAnimation().getLPBubble());
	target->draw(h->getFightAnimation().getLPText());
	target->draw(heroCAText);
	//Render Enemy
	target->draw(e->getFightAnimation().getSprite());
	target->draw(e->getFightAnimation().getLPBubble());
	target->draw(e->getFightAnimation().getLPText());
	target->draw(enemyCAText);
	//Rrender Dice
	if (s == 1 && start == false) {
		h->getDice()->render(target);
		target->draw(heroNumber);
	}
	if (s == 2 && start == false) {
		e->getDice()->render(target);
		target->draw(enemyNumber);
	}
	//Render Messages
	target->draw(messageT);
	//Render initial stuff
	if (start == true) {
		target->draw(rectS);
		target->draw(heroInitiative);
		target->draw(enemyInitiative);
		target->draw(mm);
	}
}

void FightState::updateUpperMessage() {
	switch(type) {
	case 4 :
	{
		message = "Who starts the turn?";
		break;
	}
	case 5:
	{
		message = "You hit the enemy!";
		break;
	}
	case 6:
	{
		message = "You miss the enemy!";
		break;
	}
	case 7:
	{
		message = "The enemy hit you!";
		break;
	}
	case 8:
	{
		message = "The enemy miss you!";
		break;
	}
	case 9:
	{
		message = "Enemy is dead";
		break;
	}
	case 10:
	{
		message = "You are dead";
		break;
	}
	}

	messageT.setString(message);
	messageT.setPosition(viewX / 2.f - (messageT.getGlobalBounds().width / 2.f), 10.f);
}

void FightState::heroAttack() {
	heroResult = h->throwDiceFight();
	heroNumber.setString(std::to_string(heroResult));
	heroNumber.setPosition(viewX / 2.f - (heroNumber.getGlobalBounds().width / 2.f), viewY / 2.f - 10.f);
	if (heroResult >= e->getArmor().getCA()) {
		type = 5;
		e->setLP(e->getLP() - heroResult);
		if (e->getLP() < 0)
			e->setLP(0);
		e->getFightAnimation().updateFightLPAnimation(e->getLP());
	}
	else {
		type = 6;
	}
}

void FightState::enemyAttack() {
	enemyResult = e->throwDiceFight();
	enemyNumber.setString(std::to_string(enemyResult));
	enemyNumber.setPosition(viewX / 2.f - (enemyNumber.getGlobalBounds().width / 2.f), viewY / 2.f - 10.f);
	if (enemyResult >= h->getArmor().getCA()) {
		type = 7;
		h->setLP(h->getLP() - enemyResult);
		if (h->getLP() < 0)
			h->setLP(0);
		h->getFightAnimation().updateFightLPAnimation(h->getLP());
	}
	else {
		type = 8;
	}
}