#include "Menu.h"
#include "Config.h"
#include "Game.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::load()
{
}

void Menu::init()
{
	background.setTexture(Config::get()->menuC.background);
	background.setPosition(0, 0);

	play1Btn.texture = &Config::get()->menuC.play1Btn;
	play1Btn.mask = &Config::get()->menuC.play1BtnMask;
	play1Btn.setTexture(*play1Btn.texture);
	play1Btn.setOnClick([]() {
		Game::gameState.mode = 1;
		StateManager::get()->switchState(STATE::GAMEPLAY); 
		});
	play1Btn.setPosition(400, 850 );

	play2Btn.texture = &Config::get()->menuC.play2Btn;
	play2Btn.mask = &Config::get()->menuC.play2BtnMask;
	play2Btn.setTexture(*play2Btn.texture);
	play2Btn.setOnClick([]() { 
		Game::gameState.mode = 2;
		StateManager::get()->switchState(STATE::GAMEPLAY); 
		});
	play2Btn.setPosition(1120, 850);

	Game::gameState.mode = 1;
}

void Menu::update()
{
	play1Btn.update();
	play2Btn.update();
}

void Menu::draw()
{
	Game::window->draw(background);
	play1Btn.draw();
	play2Btn.draw();
}

void Menu::dispose()
{
}
