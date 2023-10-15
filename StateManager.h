#pragma once
#include "Enumerators.h"
#include "State.h"
#include <memory>

class StateManager
{
public:

	static StateManager* get();

	void switchState(STATE newState);

	std::shared_ptr<State> currentState;

private:


	StateManager();
	~StateManager();

	static StateManager* instance;
	

};

