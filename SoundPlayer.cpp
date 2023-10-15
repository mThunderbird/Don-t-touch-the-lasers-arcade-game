#include "SoundPlayer.h"

std::vector<std::shared_ptr<sf::Music>> SoundPlayer::activeMusic;
std::vector<std::shared_ptr<sf::Sound>> SoundPlayer::activeSound;


SoundPlayer::SoundPlayer()
{
}

SoundPlayer::~SoundPlayer()
{
}


void SoundPlayer::playMusic(std::string fileName)
{
	std::shared_ptr<sf::Music> music = std::make_shared<sf::Music>();
	music->openFromFile(fileName);
	music->play();
	activeMusic.push_back(music);

}

void SoundPlayer::playSound(sf::SoundBuffer _sound)
{
	std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>();
	sound->setBuffer(_sound);
	sound->play();
	activeSound.push_back(sound);
}
