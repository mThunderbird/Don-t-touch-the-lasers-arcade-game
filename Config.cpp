#include "Config.h"

Config* Config::instance;

Config::Config()
{
}

Config::~Config()
{
}

Config* Config::get()
{
	if (instance == nullptr)
	{
		instance = new Config();
	}

	return instance;
}

void Config::load()
{
	nonestateC.load();
	loadScreenC.load();
	menuC.load();
	padC.load();
	gameplayC.load();
	endScreenC.load();
	meow.loadFromFile("img\\meow.wav");
}
