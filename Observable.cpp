#include "Observable.h"

void Observable::addObserver(Achievements* observer) {
	observerList.push_back(observer);
}

void Observable::removeObserver(Achievements* observer) {
	observerList.remove(observer);
}

Observable::~Observable() {

}