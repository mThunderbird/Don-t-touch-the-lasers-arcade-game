#pragma once
#include "Defines.h"
#include <functional>

class Button : public sf::Sprite
{
public:

	Button();
	Button(std::function<void()> _onClick);
	~Button();

	sf::Texture* texture;
	sf::Texture* mask;

	void update();
	void draw();

	void setOnClick(std::function<void()> _onClick);

private:

	bool drawMask = false;
	std::function<void()> onClick;
};