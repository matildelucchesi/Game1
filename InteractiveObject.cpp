#include "InteractiveObject.h"

InteractiveObject::InteractiveObject(TileMap* map,std::string name, bool empty, sf::Vector2f tilesize, sf::FloatRect* bBox, int layerNumber) {
	isVisited = false;
	isOpen = false;
	isEmpty = empty;
	posX = (int)bBox->left;
	posY = (int)bBox->top;
	n = name;
	m = map;
	l = layerNumber;
	boundingBox = bBox;
	//animation
	if (n == "treasure") {
		if (!emptyT.loadFromFile("../images/mapTile/emptyTreasureTile.png"))
			std::cout << "ERROR::INTERACTIVE_OBJECT::CAN'T LOAD TREASURE TEXTURE FILE" << endl;
		if (!notEmptyT.loadFromFile("../images/mapTile/notEmptyTreasureTile.png"))
			std::cout << "ERROR::INTERACTIVE_OBJECT::CAN'T LOAD TREASURE TEXTURE FILE" << endl;
	}
	if (n == "statue") {
		if (!emptyT.loadFromFile("../images/mapTile/emptyStatueTileSet.png"))
			std::cout << "ERROR::INTERACTIVE_OBJECT::CAN'T LOAD STATUE TEXTURE FILE" << endl;
		if (!notEmptyT.loadFromFile("../images/mapTile/notEmptyStatueTileSet.png"))
			std::cout << "ERROR::INTERACTIVE_OBJECT::CAN'T LOAD STATUE TEXTURE FILE" << endl;

	}

	this->animation = ObjectAnimation::ObjectAnimation(this->isEmpty, tilesize, this->emptyT , this->notEmptyT, bBox, layerNumber);

	//potion
	if (isEmpty == false)
		this->potion = make_shared<Potion>();
	else
		this->potion = nullptr;

}

//setter & getter

void InteractiveObject::setIsVisited(bool isVisited_) {
	this->isVisited = isVisited_;
	if (isVisited_ == true)
		this->notify();
}

bool InteractiveObject::getIsVisited() const {
	return this->isVisited;
}

void InteractiveObject::setIsOpen(bool isOpen_) {
	this->isOpen = isOpen_;
}

bool InteractiveObject::getIsOpen() const {
	return this->isOpen;
}

void InteractiveObject::setIsEmpty(bool isEmpty_) {
	this->isEmpty = isEmpty_;
}

bool InteractiveObject::getIsEmpty() const {
	return this->isEmpty;
}

void InteractiveObject::setPosX(int posX_) {
	this->posX = posX_;
}

int InteractiveObject::getPosX() const {
	return this->posX;
}

void InteractiveObject::setPosY(int posY_) {
	this->posY = posY_;
}

int InteractiveObject::getPosY() const {
	return this->posY;
}

void InteractiveObject::setAchievement(Achievements* a) {
	achievement = a;
	Observable::addObserver(achievement);
}

std::string InteractiveObject::getName() {
	return this->n;
}

//interaction

void InteractiveObject::open() {
	isOpen = true;
	this->animation.update();
	m->changeTile(l, animation.getTile());
}

void InteractiveObject::notify() {
	for (auto s = std::begin(observerList); s != std::end(observerList); s++) {
		if (n == "statue") {
			(*s)->Achievements::updateStatue();
		}
		if (n == "treasure") {
			(*s)->Achievements::updateTreasure();
		}
	}
}

void InteractiveObject::takePotion() {
	isEmpty = true;
	animation.setIsEmpty(true);
	animation.update();
	m->changeTile(l, animation.getTile());
}

sf::FloatRect* InteractiveObject::getBoundingBox() {
	return this->boundingBox;
}

std::shared_ptr<Potion> InteractiveObject::getPotion() {
	return this->potion;
}

ObjectAnimation InteractiveObject::getAnimation() {
	return this->animation;
}