#pragma once
#include "State.h"
#include "Button.h"

class Menu : public State
{
public:

	Menu();
	~Menu();

	sf::Sprite background;
	Button play1Btn;
	Button play2Btn;

private:


	// Inherited via State
	void load() override;

	void init() override;

	void update() override;

	void draw() override;

	void dispose() override;

};