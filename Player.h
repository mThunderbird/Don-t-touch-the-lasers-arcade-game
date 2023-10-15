#pragma once
#include "Defines.h"

class Player : public sf::Sprite
{
public:
	Player();
	~Player();

	void update();
	void draw();

	int direction = 1;
	int target = 0;
	int score = 0;

	sf::FloatRect collRect;

	sf::Keyboard::Key jumpKey = sf::Keyboard::Space;

private:


	const static int speed = 5;
	const static int gravity = 3;
	const static int jumpSpeed = 10;
	const static int jump = 120;

	static float lerp(float v0, float v1, float t) {
		return (1 - t) * v0 + t * v1;
	}
};