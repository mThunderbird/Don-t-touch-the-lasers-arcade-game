#pragma once

#pragma once
#include "Defines.h"
#include <map>

class Input
{
public:
	Input();
	~Input();

	static sf::Event event;

	static void init();
	static void poll();

	static bool isKeyPressed(sf::Keyboard::Key key);
	static bool isKeyReleased(sf::Keyboard::Key key);
	static bool isAnyKeyPressed();
	static bool leftClick();
	static sf::Vector2f getMouseCoord();
	static bool spriteClicked(sf::Sprite& sprite);

private:

	static std::map<sf::Keyboard::Key, bool> keyPressed;
	static std::map<sf::Keyboard::Key, bool> keyReleased;
	static bool anyPressed;
};