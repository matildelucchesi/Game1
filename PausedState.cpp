#include "PausedState.h"
#include "PlayingState.h"
#include "FirstLevelState.h"

PausedState::PausedState(GameState& pre_State, std::shared_ptr<Hero> hero){
	preState = &pre_State;
	//hero
	h = hero;
	//Background
	setBackground();
	//View
	setView();
	//potion
	for (int w = 0; w < MAX_POTION; w++) {
		potion[w] = h->getPotion(w);
	}
	index = 0;
}

void PausedState::setBackground(){ 
	if (!texture.loadFromFile("../images/other/inventory.png"))
		std::cout << "ERROR::PAUSEDSTATE::CAN'T LOAD THE BACKGROUND TEXTURE";
	sprite = sf::Sprite(texture);
	//rect
	sf::Vector2f size;
	size.x = 150.f;
	size.y = 150.f;
	sf::Vector2f pos;
	pos.x = 50.f;
	pos.y = 84.f;
	for (int i = 0; i < MAX_POTION; i++) {
		grid[i] = sf::RectangleShape(size);
		grid[i].setPosition(pos);
		pos.x += size.x + 16.f;
			if (pos.x == ((size.x + 16) * 3.f) + 50.f) {
				pos.x = 50.f;
				pos.y += size.y + 16.f;
			}
		grid[i].setFillColor(sf::Color(49, 47, 48, opacity));
		grid[i].setOutlineColor(sf::Color(155, 152, 152, opacity));
		grid[i].setOutlineThickness(8.f);
	}

	//text
	text = sf::Text("Pause", font, 100);
	GameState::setTextFeatures(this->text);
	text.setPosition(825.f - (text.getGlobalBounds().width / 2.f), 50.f);

	//strenght
	strength = sf::Text("Strength: " + std::to_string(this->h->getStrength()), font, gameTextSize);
	GameState::setTextFeatures(this->strength);
	strength.setPosition(825.f - (text.getGlobalBounds().width / 2.f), 200.f);
	//dexterity
	dexterity = sf::Text("Dexterity: " + std::to_string(this->h->getDexterity()), font, gameTextSize);
	GameState::setTextFeatures(this->dexterity);
	dexterity.setPosition(825.f - (text.getGlobalBounds().width / 2.f), 250.f);
	//intelligence
	intelligence = sf::Text("Intelligence: " + std::to_string(this->h->getIntelligence()), font, gameTextSize);
	GameState::setTextFeatures(this->intelligence);
	intelligence.setPosition(825.f - (text.getGlobalBounds().width / 2.f), 300.f);
	//charisma
	charisma = sf::Text("Charisma: " + std::to_string(this->h->getCharisma()), font, gameTextSize);
	GameState::setTextFeatures(this->charisma);
	charisma.setPosition(825.f - (text.getGlobalBounds().width / 2.f), 350.f);
	//constitution
	constitution = sf::Text("Constitution: " + std::to_string(this->h->getConstitution()), font, gameTextSize);
	GameState::setTextFeatures(this->constitution);
	constitution.setPosition(825.f - (text.getGlobalBounds().width / 2.f), 400.f);
	//wisdom
	wisdom = sf::Text("Wisdom: " + std::to_string(this->h->getWisdom()), font, gameTextSize);
	GameState::setTextFeatures(this->wisdom);
	wisdom.setPosition(825.f - (text.getGlobalBounds().width / 2.f), 450.f);
	//potion value
	value = sf::Text(" ", font, gameTextSize);
	GameState::setTextFeatures(this->value);
	value.setPosition(825.f - (text.getGlobalBounds().width / 2.f), 500.f);
}

GameState* PausedState::handleInput(sf::Event evnt){
	if (evnt.type == evnt.KeyPressed)
		if(evnt.key.code == sf::Keyboard::BackSpace)
			return this->preState;
	if (evnt.type == evnt.KeyPressed) {
		if (evnt.key.code == sf::Keyboard::Right) {
			index += 1;
			index = index % MAX_POTION;
		}
		if (evnt.key.code == sf::Keyboard::Left) {
			index -= 1;
			if (index == -1)
				index = MAX_POTION - 1;
		}
		if (evnt.key.code == sf::Keyboard::Down) {
			index += 3;
			if (index >= MAX_POTION)
				index = index % 3;
		}
		if (evnt.key.code == sf::Keyboard::Up) {
			index -= 3;
			if (index < 0)
				index = index + MAX_POTION ;
		}
		if (evnt.key.code == sf::Keyboard::Enter && potion[index] != NULL) {
			h->usePotion(index);
		}
	}

	return this;
}

void PausedState::render(sf::RenderTarget* target) {
	target->setView(getView());
	target->draw(sprite);
	target->draw(grid[index]);

	for (int j = 0; j < MAX_POTION; j++) {
		if (j == index)
			target->draw(grid[index]);
		else
			target->draw(grid[j]);

		if(potion[j] != NULL)
			target->draw(potion[j]->getSprite());
	}

	target->draw(text);
	target->draw(strength);
	target->draw(dexterity);
	target->draw(intelligence);
	target->draw(charisma);
	target->draw(constitution);
	target->draw(wisdom);
	if (potion[index] != NULL) {
		target->draw(value);
	}
}

void PausedState::update() {
	int w = 0;
	while(w != MAX_POTION){
		potion[w] = h->getPotion(w);
		if (potion[w] != NULL) {
			this->potion[w]->getSprite().setPosition(grid[w].getGlobalBounds().left + (grid[w].getGlobalBounds().width / 2.f) - (potion[w]->getSprite().getGlobalBounds().width / 2.f), grid[w].getGlobalBounds().top + (grid[w].getGlobalBounds().height / 2.f) - (potion[w]->getSprite().getGlobalBounds().height / 2.f));
			w++;
		}
		else
			w++;
	}

	for (int i = 0; i < MAX_POTION; i++) {
		grid[i].setOutlineColor(sf::Color(155, 152, 152, opacity));
	}
	this->grid[index].setOutlineColor(sf::Color(37, 255, 3, opacity));

	if (potion[index] != NULL)
		value.setString("Potion's value: " + std::to_string(potion[index]->getPotionValue()));
}

void PausedState::reinitialized(GameState& pre_State, std::shared_ptr<Hero> hero) {
	setView();
	this->preState = &pre_State;
	this->h = hero;
}