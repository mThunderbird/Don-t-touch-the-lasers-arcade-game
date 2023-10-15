#pragma once
#include "Defines.h"
#include <memory>
#include <vector>

class SoundPlayer
{
public:
	SoundPlayer();
	~SoundPlayer();

	static void playMusic(std::string fileName);
	static void playSound(sf::SoundBuffer sound);

private:

	static std::vector<std::shared_ptr<sf::Music>> activeMusic;
	static std::vector<std::shared_ptr<sf::Sound>> activeSound;
};