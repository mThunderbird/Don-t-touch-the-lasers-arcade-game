#include "Pad.h"
#include "Game.h"
#include "Defines.h"

Pad::Pad()
{
}

Pad::~Pad()
{
}

void Pad::init()
{
	border.setPosition(50, 50);
	border.setTexture(Config::get()->padC.background);

	for (int i = 0; i < PAD_SIZE; i++)
	{
		Spike leftSpike;
		leftSpike.setPosition(sf::Vector2f{ 50.0f, 150.0f + i*50.0f });
		leftSpike.setTexture(Config::get()->padC.leftSpike);
		leftSpikes.push_back(leftSpike);

		Spike rightSpike;
		rightSpike.setPosition(sf::Vector2f{ 1450.0f - 80.0f, 150.0f + i * 50.0f });
		rightSpike.setTexture(Config::get()->padC.rightSpike);
		rightSpikes.push_back(rightSpike);
	}

}

void Pad::draw()
{

	for (int i = 0; i < 16; i++)
	{	
		if (leftSpikes[i].isActive)
		{
			Game::window->draw(leftSpikes[i]);
		}
		if (rightSpikes[i].isActive)
		{
			Game::window->draw(rightSpikes[i]);
		}
	}

	Game::window->draw(border);
}

std::vector<int> Pad::generateSpikes(int level)
{
	int maxSpikes = 2 + ((level / 5)) * 2;
	int numberOfSpikes = 1 + rand() % (maxSpikes - 1);
	
	if (numberOfSpikes == 0) numberOfSpikes = 1;
	if (numberOfSpikes > 10) numberOfSpikes = 10;

	bool isValid = true;

	std::vector<int> result;
	std::vector<int> slots;
	for (int i = 0; i < PAD_SIZE; i++)
	{
		slots.push_back(i);
	}

	do
	{
		isValid = false;

		for (int i = 0; i < numberOfSpikes; i++)
		{
			int chosen = rand() % slots.size();
			result.push_back(slots[chosen]);
			slots.erase(slots.begin() + chosen);
		}

		for (int i = 0; i < slots.size() - 2; i++)
		{
			if (slots[i] + 1 == slots[i + 1] && slots[i + 1] + 1 == slots[i+2])
			{
				isValid = true;
				break;
			}
		}

	} while (!isValid);

	return result;
}


