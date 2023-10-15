#include "Input.h"
#include "Game.h"

sf::Event Input::event;
std::map<sf::Keyboard::Key, bool> Input::keyPressed;
std::map<sf::Keyboard::Key, bool> Input::keyReleased;
bool Input::anyPressed = false;

Input::Input()
{
}

Input::~Input()
{
}

void Input::init()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		keyPressed.insert(std::make_pair(sf::Keyboard::Key(i), false));
		keyReleased.insert(std::make_pair(sf::Keyboard::Key(i), false));
	}
}

void Input::poll()
{
	anyPressed = false;

	for (auto& itr : keyReleased) // reset Key released in every frame
	{
		itr.second = false;
	}

	for (auto& itr : keyPressed)	// check for Key releases => if it WAS pressed and NOW it is not => released
	{
		if (itr.second == true && sf::Keyboard::isKeyPressed(itr.first) == false)
		{
			keyReleased.at(itr.first) = true;
		}

		if (sf::Keyboard::isKeyPressed(itr.first) == true)
		{
			anyPressed = true;
			std::cout << "Pressed " << sf::Keyboard::Key(itr.first) << "\n";
		}

		itr.second = sf::Keyboard::isKeyPressed(itr.first);	// set current state of key
	}
}

bool Input::isKeyPressed(sf::Keyboard::Key key)
{
	return keyPressed.at(key);
}

bool Input::isKeyReleased(sf::Keyboard::Key key)
{
	return keyReleased.at(key);
}

bool Input::isAnyKeyPressed()
{
	return anyPressed;
}

bool Input::leftClick()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

sf::Vector2f Input::getMouseCoord()
{
	return sf::Vector2f{ sf::Mouse::getPosition(*Game::window) };
}

bool Input::spriteClicked(sf::Sprite& sprite)
{
	return sprite.getGlobalBounds().contains(getMouseCoord()) && leftClick();
}
