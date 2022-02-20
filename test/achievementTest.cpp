#include <gtest/gtest.h>
#include "../Achievements.h"
#include "../InteractiveObject.h"
#include "../Hero.h"

//statues

InteractiveObject* s1 = new InteractiveObject("statue", true);
InteractiveObject* s2 = new InteractiveObject("statue", false);
InteractiveObject* s3 = new InteractiveObject("statue", true);
InteractiveObject* s4 = new InteractiveObject("statue", true);
Achievements* a = new Achievements();

TEST(Achievements, open_one_statue) {
	s1->setAchievement(a);
	s1->setIsOpen(true);
	s1->setIsVisited(true);
	ASSERT_EQ(false, a->getAchieve());
	ASSERT_EQ(1, a->getCountS());
}

TEST(Achievements, open_two_statues) {
	s2->setAchievement(a);
	s2->setIsOpen(true);
	s2->setIsVisited(true);
	ASSERT_EQ(false, a->getAchieve());
	ASSERT_EQ(2, a->getCountS());
}

TEST(Achievements, open_four_statues_and_achieve) {
	s3->setAchievement(a);
	s3->setIsOpen(true);
	s3->setIsVisited(true);
	s4->setAchievement(a);
	s4->setIsOpen(true);
	s4->setIsVisited(true);
	ASSERT_EQ(4, a->getCountS());
	ASSERT_EQ(true, a->getAchieve());
}

//treasures

InteractiveObject* t1 = new InteractiveObject("treasure", true);
InteractiveObject* t2 = new InteractiveObject("treasure", false);
InteractiveObject* t3 = new InteractiveObject("treasure", true);

TEST(Achievements, open_one_treasure) {
	a->setAchieve(false);
	t1->setAchievement(a);
	t1->setIsOpen(true);
	t1->setIsVisited(true);
	ASSERT_EQ(false, a->getAchieve());
	ASSERT_EQ(1, a->getCountT());
}

TEST(Achievements, open_two_treasures) {
	t2->setAchievement(a);
	t2->setIsOpen(true);
	t2->setIsVisited(true);
	ASSERT_EQ(false, a->getAchieve());
	ASSERT_EQ(2, a->getCountT());
}


TEST(Achievements, open_three_treasures_and_achieve) {
	t3->setAchievement(a);
	t3->setIsOpen(true);
	t3->setIsVisited(true);
	ASSERT_EQ(3, a->getCountT());
	ASSERT_EQ(true, a->getAchieve());
}
