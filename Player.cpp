#include "Player.h"
#include "Game.h"
#include <cmath>

Player::Player()
{
}

Player::~Player()
{
}

void Player::update()
{

	move(direction * speed, 0);

	if (target != 0)
	{
		setPosition(getPosition().x, int(lerp(getPosition().y, target, 0.2f)));
		if (getPosition().y - target <= 5)
		{
			target = 0;
		}
	}
	else
	{
		move(0, gravity);
	}
	
	collRect = sf::FloatRect{ getPosition() + sf::Vector2f{25, 10}, sf::Vector2f{40,45} };

	if (Input::isKeyReleased(jumpKey))
	{
		target = getPosition().y - jump;
	}
}

void Player::draw()
{
	Game::window->draw(*this);
}
