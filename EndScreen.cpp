#include "EndScreen.h"
#include "Game.h"

EndScreen::EndScreen()
{
}

EndScreen::~EndScreen()
{
}

void EndScreen::load()
{
}

void EndScreen::init()
{
	if (Game::gameState.mode == 1)
	{
		background.setTexture(Config::get()->endScreenC.onePlayerEnd);
	}
	else if(Game::gameState.end == 1)
	{
		background.setTexture(Config::get()->endScreenC.player1Wins);
	}
	else
	{
		background.setTexture(Config::get()->endScreenC.player2Wins);
	}

	background.setPosition(0, 0);
	menuBtn.setPosition(760, 820);
	menuBtn.texture = &Config::get()->endScreenC.menuBtn;
	menuBtn.mask = &Config::get()->endScreenC.menuBtnMask;
	menuBtn.setOnClick([]() { StateManager::get()->switchState(STATE::MENU); });
	menuBtn.setTexture(*menuBtn.texture);
}

void EndScreen::update()
{
	menuBtn.update();
}

void EndScreen::draw()
{
	Game::window->draw(background);
	menuBtn.draw();
}

void EndScreen::dispose()
{
}
