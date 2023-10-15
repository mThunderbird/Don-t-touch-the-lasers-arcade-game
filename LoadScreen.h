#pragma once

#pragma once
#include "State.h"
#include "Defines.h"

class LoadScreen : public State
{
public:
	LoadScreen();
	~LoadScreen();

private:

	sf::Sprite background;
	sf::Sprite pressKeyText;
	int opacity;
	int opacityStep;

	// Inherited via State
	void load() override;

	void init() override;

	void update() override;

	void draw() override;

	void dispose() override;

};