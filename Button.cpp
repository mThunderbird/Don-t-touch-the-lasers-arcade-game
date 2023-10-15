#include "Button.h"
#include "Game.h"
#include "Input.h"
#include "SoundPlayer.h"

Button::Button()
{
}

Button::Button(std::function<void()> _onClick)
{
	onClick = _onClick;
}

Button::~Button()
{
}

void Button::update()
{
	if (Input::spriteClicked(*this) && onClick != nullptr)
	{
		SoundPlayer::playSound(Config::get()->meow);
		onClick();
	}

	if (getGlobalBounds().contains(Input::getMouseCoord()))
	{
		drawMask = true;
	}
	else
	{
		drawMask = false;
	}
}

void Button::draw()
{
	Game::window->draw(*this);
	if (drawMask)
	{
		setTexture(*mask);
		Game::window->draw(*this);
		setTexture(*texture);
	}
}

void Button::setOnClick(std::function<void()> _onClick)
{
	onClick = _onClick;
}
