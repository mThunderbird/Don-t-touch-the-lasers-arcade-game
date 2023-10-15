#pragma once
#include "State.h"
#include "Defines.h"
#include "Button.h"

class EndScreen : public State
{
public:

	EndScreen();
	~EndScreen();

	sf::Sprite background;
	Button menuBtn;

private:


	// Inherited via State
	void load() override;

	void init() override;

	void update() override;

	void draw() override;

	void dispose() override;

};