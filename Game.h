#pragma once
#include "Defines.h"
#include "StateManager.h"
#include "Input.h"
#include "Config.h"

struct GameState
{
	int mode; //1 for 1 player, 2 for 2 player
	int end; //1 for 1 player, 2 for player 1 wins , 3 for player 2 wins
};


class Game
{
public:

	Game();
	~Game();

	void init();
	void run();
	void dispose();


	static std::shared_ptr<sf::RenderWindow> window;

	static GameState gameState;

private:

};