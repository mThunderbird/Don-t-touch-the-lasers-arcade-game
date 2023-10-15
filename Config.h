#pragma once
#include "Defines.h"


struct NoneStateConfig
{
	sf::Texture noneStateBg;

	void load()
	{
		noneStateBg.loadFromFile("img\\noneState.png");
	}

};

struct LoadScreenConfig
{
	sf::Texture background;
	sf::Texture pressKey;

	void load()
	{
		background.loadFromFile("img\\loadBackground.png");
		pressKey.loadFromFile("img\\pressAny.png");
	}
};

struct MenuConfig
{
	sf::Texture play1Btn;
	sf::Texture play1BtnMask;
	sf::Texture play2Btn;
	sf::Texture play2BtnMask;
	sf::Texture background;

	void load()
	{
		play1Btn.loadFromFile("img\\1PlayerBtn.png");
		play1BtnMask.loadFromFile("img\\1PlayerBtnMask.png");
		play2Btn.loadFromFile("img\\2PlayerBtn.png");
		play2BtnMask.loadFromFile("img\\2PlayerBtnMask.png");
		background.loadFromFile("img\\menuBackground.png");
	}
};

struct PadConfig
{
	sf::Texture background;
	sf::Texture leftSpike;
	sf::Texture rightSpike;

	void load()
	{
		background.loadFromFile("img\\padBorder.png");
		leftSpike.loadFromFile("img\\leftSpike.png");
		rightSpike.loadFromFile("img\\rightSpike.png");
	}

};

struct GameplayConfig
{
	sf::Texture spaceInfo;
	sf::Texture upInfo;
	sf::Texture player1;
	sf::Texture player2;
	sf::Texture levelHolder;
	sf::Texture player1ScoreHolder;
	sf::Texture player2ScoreHolder;
	sf::Font font;
	sf::Texture candyTxt;

	void load()
	{
		spaceInfo.loadFromFile("img\\spaceInfo.png");
		upInfo.loadFromFile("img\\upInfo.png");
		player1.loadFromFile("img\\player1.png");
		player2.loadFromFile("img\\player2.png");
		levelHolder.loadFromFile("img\\levelHolder.png");
		player1ScoreHolder.loadFromFile("img\\player1ScoreHolder.png");
		player2ScoreHolder.loadFromFile("img\\player2ScoreHolder.png");
		font.loadFromFile("img\\myFont.ttf");
		candyTxt.loadFromFile("img\\candy.png");
	}

};

struct EndScreenConfig
{
	sf::Texture onePlayerEnd;
	sf::Texture player1Wins;
	sf::Texture player2Wins;
	sf::Texture menuBtn;
	sf::Texture menuBtnMask;

	void load()
	{
		onePlayerEnd.loadFromFile("img\\onePlayerEnd.png");
		player1Wins.loadFromFile("img\\player1Wins.png");
		player2Wins.loadFromFile("img\\player2Wins.png");
		menuBtn.loadFromFile("img\\menuBtn.png");
		menuBtnMask.loadFromFile("img\\menuBtnMask.png");
	}

};


class Config
{
public:

	~Config();

	static Config* get();

	void load();

	NoneStateConfig nonestateC;
	LoadScreenConfig loadScreenC;
	MenuConfig menuC;
	PadConfig padC;
	GameplayConfig gameplayC;
	EndScreenConfig endScreenC;
	sf::SoundBuffer meow;

private:

	Config();

	static Config* instance;

};
