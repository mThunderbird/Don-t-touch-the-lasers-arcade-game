#include "LoadScreen.h"

#include "LoadScreen.h"
#include "Config.h"
#include "Game.h"

LoadScreen::LoadScreen()
{
}

LoadScreen::~LoadScreen()
{
}

void LoadScreen::load()
{
}

void LoadScreen::init()
{
	background.setTexture(Config::get()->loadScreenC.background);
	background.setOrigin(background.getLocalBounds().getSize() / 2.0f);
	background.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

	pressKeyText.setTexture(Config::get()->loadScreenC.pressKey);
	pressKeyText.setOrigin(pressKeyText.getLocalBounds().getSize() / 2.0f);
	pressKeyText.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100);
	pressKeyText.setColor(sf::Color{ 255,255,255,255 });

	opacityStep = -2;
	opacity = 255;
}

void LoadScreen::update()
{
	opacity += opacityStep;

	if (opacity <= 50)
	{
		opacityStep = -opacityStep;
		opacity = 50;
	}
	else if (opacity >= 255)
	{
		opacityStep = -opacityStep;
		opacity = 255;
	}

	pressKeyText.setColor(sf::Color{ 255,255,255, sf::Uint8(opacity) });

	if (Input::isAnyKeyPressed())
	{
		StateManager::get()->switchState(STATE::MENU);
	}
}

void LoadScreen::draw()
{
	Game::window->draw(background);
	Game::window->draw(pressKeyText);
}

void LoadScreen::dispose()
{
}
