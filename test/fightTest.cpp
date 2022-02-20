#include <gtest/gtest.h>
#include "../Hero.h"
#include "../Enemy.h"

Hero* hero = new Hero(1, 2);
Enemy* enemy = new Enemy(0, 100, 0, 200.f, 300.f);

TEST(FightState, hero_Attack) {
	hero->setTypeOfArmor("Half Armor");
	hero->getFightAnimation().setTurn(true);
	enemy->getFightAnimation().setTurn(false);
	ASSERT_EQ(true, hero->getFightAnimation().getTurn());
	ASSERT_EQ(false, enemy->getFightAnimation().getTurn());
	int heroResult = hero->throwDiceFight();
	int enemyLP = enemy->getLP();
	if (heroResult >= enemy->getArmor().getCA()) {
		enemy->setLP(enemy->getLP() - heroResult);
		ASSERT_EQ(enemyLP - heroResult, enemy->getLP());
	}
	else
		ASSERT_EQ(enemyLP, enemy->getLP());
}

TEST(FightState, enemy_Attack) {
	enemy->getFightAnimation().setTurn(true);
	hero->getFightAnimation().setTurn(false);
	ASSERT_EQ(true, enemy->getFightAnimation().getTurn());
	ASSERT_EQ(false, hero->getFightAnimation().getTurn());
	int enemyResult = enemy->throwDiceFight();
	int heroLP = hero->getLP();
	if (enemyResult >= hero->getArmor().getCA()) {
		hero->setLP(hero->getLP() - enemyResult);
		ASSERT_EQ(heroLP - enemyResult, hero->getLP());
	}
	else
		ASSERT_EQ(heroLP, hero->getLP());
}