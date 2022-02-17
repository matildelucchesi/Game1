#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
	virtual ~Observer() {};
	virtual void updateTreasure() = 0;
	virtual void updateStatue() = 0;
};

#endif
