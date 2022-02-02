
#include "Game.h"

int main() {

	//Initialize random seed
	srand(static_cast<unsigned>(time(0)));

	//Initialize the game
	Game game;


	//Game loop

	while (game.running()) {
		game.pollEvents();

		game.update();

		game.render();
	}

}