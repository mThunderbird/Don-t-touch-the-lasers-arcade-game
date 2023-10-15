#pragma once
#include "Defines.h"

class Spike : public sf::Sprite
{
public:
	Spike() {};
	~Spike() {};

	bool isActive = false;
	sf::FloatRect collisionRect;

private:

};


class Pad
{
public:
	Pad();
	~Pad();


	void init();
	void draw();

	sf::Sprite border;
	
	std::vector<Spike> leftSpikes;
	std::vector<Spike> rightSpikes;

	sf::FloatRect collisionRectTop = sf::FloatRect(100, 50, 1300, 80);
	sf::FloatRect collisionRectBot = sf::FloatRect{100, 970, 1300, 80};

	std::vector<int> generateSpikes(int level);

private:

};