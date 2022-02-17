#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Achievements.h"
#include <iostream>
#include <list>

using namespace std;

class Observable {
public:
	//Virtual Destructor
	virtual ~Observable() = 0;
	//Observer stuff
	void addObserver(Achievements* observer);
	void removeObserver(Achievements* observer);
	virtual void notify() = 0;

	std::list<Achievements*> observerList;
};


#endif