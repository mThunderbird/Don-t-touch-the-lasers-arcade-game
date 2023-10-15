#pragma once
#include "State.h"
#include "Pad.h"
#include "Player.h"

struct activatorLine
{
	float x;
	bool isActive = false;
};


class Gameplay : public State
{
public:
	Gameplay();
	~Gameplay();


private:

	Pad pad;
	std::vector<Player> players;
	sf::Sprite activeCandy;
	bool isCandyPickedUp = false;

	sf::Sprite spaceInfo;
	sf::Sprite upInfo;
	sf::Sprite levelHolder;
	sf::Text levelText;
	sf::Sprite player1ScoreHolder;
	sf::Sprite player2ScoreHolder;
	sf::Text player1ScoreText;
	sf::Text player2ScoreText;

	sf::Vector2f spawnPoint1 = { 200, 500 };
	sf::Vector2f spawnPoint2 = { 1200, 500 };
	sf::FloatRect candySpawn = { 260, 150, 980, 780 };

	bool isGameOver = false;

	int level = 0;
	activatorLine leftLine;
	activatorLine rightLine;

	void spawnCandy();

	// Inherited via State
	void load() override;

	void init() override;

	void update() override;

	void draw() override;

	void dispose() override;

};