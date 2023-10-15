#include "StateManager.h"
#include "NoneState.h"
#include "LoadScreen.h"
#include "Menu.h"
#include "Gameplay.h"
#include "EndScreen.h"
#include <iostream>

StateManager* StateManager::instance;

StateManager::StateManager()
{
	currentState = std::make_shared<LoadScreen>();
	currentState->init();
}


StateManager* StateManager::get()
{
	if (instance == nullptr)
	{
		instance = new StateManager();
	}
	return instance;
}

void StateManager::switchState(STATE newState)
{

	currentState->dispose();

	switch (newState)
	{
	case STATE::NONE:
		currentState = std::make_shared<NoneState>();
		std::cout << "Switched state to None\n";
		break;
	case STATE::LOAD_SCREEN:
		currentState = std::make_shared<LoadScreen>();
		std::cout << "Switched state to LoadScreen\n";
		break;
	case STATE::MENU:
		currentState = std::make_shared<Menu>();
		break;
	case STATE::GAMEPLAY:
		currentState = std::make_shared<Gameplay>();
		break;
	case STATE::END_SCREEN:
		currentState = std::make_shared<EndScreen>();
		break;
	default:
		break;
	}

	currentState->init();
}
