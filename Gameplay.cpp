#include "Gameplay.h"
#include "Game.h"

Gameplay::Gameplay()
{
}

Gameplay::~Gameplay()
{
}

void Gameplay::spawnCandy()
{
	int x = candySpawn.left + rand() % int(candySpawn.width - activeCandy.getGlobalBounds().width);
	int y = candySpawn.top + rand() % int(candySpawn.height - activeCandy.getGlobalBounds().height);

	isCandyPickedUp = false;
	activeCandy.setPosition(x, y);
}

void Gameplay::load()
{
}

void Gameplay::init()
{
	spaceInfo.setTexture(Config::get()->gameplayC.spaceInfo);
	spaceInfo.setPosition(1495, 40);	
	
	upInfo.setTexture(Config::get()->gameplayC.upInfo);
	upInfo.setPosition(1540, 1000);


	leftLine.x = 300;
	leftLine.isActive = false;
	rightLine.x = 1100;
	rightLine.isActive = false;

	pad.init();

	int startSpike = rand() % PAD_SIZE;
	pad.leftSpikes[startSpike].isActive = true;
	startSpike = rand() % PAD_SIZE;
	pad.rightSpikes[startSpike].isActive = true;

	if (Game::gameState.mode == 1)
	{
		Game::gameState.end = 1;
		Player player1;
		player1.direction = 1;
		player1.setTexture(Config::get()->gameplayC.player1);
		player1.setPosition(spawnPoint1);
		player1.jumpKey = sf::Keyboard::Space;
		players.push_back(player1);
	}

	if (Game::gameState.mode == 2)
	{
		Player player1;
		player1.direction = 1;
		player1.setTexture(Config::get()->gameplayC.player1);
		player1.setPosition(spawnPoint1);
		player1.jumpKey = sf::Keyboard::Space;
		players.push_back(player1);

		Player player2;
		player2.direction = -1;
		player2.setTexture(Config::get()->gameplayC.player2);
		player2.setPosition(spawnPoint2);
		player2.jumpKey = sf::Keyboard::Up;
		players.push_back(player2);
	}

	levelHolder.setTexture(Config::get()->gameplayC.levelHolder);
	levelHolder.setPosition(1490, 480);
	levelText.setFont(Config::get()->gameplayC.font);
	levelText.setString("0");
	levelText.setPosition(1650, 490);
	levelText.setCharacterSize(64);

	player1ScoreHolder.setTexture(Config::get()->gameplayC.player1ScoreHolder);
	player1ScoreHolder.setPosition(1490, 110);

	player1ScoreText.setFont(Config::get()->gameplayC.font);
	player1ScoreText.setString("0");
	player1ScoreText.setPosition(1660, 345);
	player1ScoreText.setCharacterSize(64);

	player2ScoreHolder.setTexture(Config::get()->gameplayC.player2ScoreHolder);
	player2ScoreHolder.setPosition(1490, 585);
	
	player2ScoreText.setFont(Config::get()->gameplayC.font);
	player2ScoreText.setString("0");
	player2ScoreText.setPosition(1660, 830);
	player2ScoreText.setCharacterSize(64);


	activeCandy.setTexture(Config::get()->gameplayC.candyTxt);
	spawnCandy();

}

void Gameplay::update()
{
	if (isGameOver == false)
	{

		for (int i = 0; i < players.size(); i++)
		{
			players[i].update();

			if (players[i].getGlobalBounds().left + players[i].getGlobalBounds().width >
				pad.border.getGlobalBounds().left + pad.border.getGlobalBounds().width) // way to right
			{
				players[i].direction *= -1;
				players[i].setPosition(pad.border.getGlobalBounds().left + pad.border.getGlobalBounds().width - players[i].getGlobalBounds().width, players[i].getPosition().y);
				rightLine.isActive = true;
				if (i == 0)
				{
					level++;
					levelText.setString(std::to_string(level));
					spawnCandy();
				}
			}
			if (players[i].getGlobalBounds().left <
				pad.border.getGlobalBounds().left)
			{
				players[i].direction *= -1;
				players[i].setPosition(pad.border.getGlobalBounds().left, players[i].getPosition().y);
				leftLine.isActive = true;
				if (i == 0)
				{
					level++;
					levelText.setString(std::to_string(level));
					spawnCandy();
				}
			}

			if (players[i].collRect.intersects(pad.collisionRectBot)
				|| players[i].collRect.intersects(pad.collisionRectTop))
			{
				isGameOver = true;
				Game::gameState.end = 2 - i;
			}
		
		
			if (leftLine.isActive && 
				players[i].collRect.left <= leftLine.x 
				&& players[i].collRect.left + players[i].collRect.width >= leftLine.x)
			{

				std::vector<int> active = pad.generateSpikes(level);
				for (int i = 0; i < PAD_SIZE; i++)
				{
					pad.rightSpikes[i].isActive = false;
				}

				for (int i = 0; i < active.size(); i++)
				{
					pad.rightSpikes[active[i]].isActive = true;
				}

				leftLine.isActive = false;
			}

			if (rightLine.isActive &&
				players[i].collRect.left <= rightLine.x
				&& players[i].collRect.left + players[i].collRect.width >= rightLine.x)
			{

				std::vector<int> active = pad.generateSpikes(level);

				for (int i = 0; i < PAD_SIZE; i++)
				{
					pad.leftSpikes[i].isActive = false;
				}

				for (int i = 0; i < active.size(); i++)
				{
					pad.leftSpikes[active[i]].isActive = true;
				}

				rightLine.isActive = false;
			}
		
		
			for (int j = 0; j < PAD_SIZE; j++)
			{
				if (players[i].collRect.intersects(pad.leftSpikes[j].getGlobalBounds())
					&& pad.leftSpikes[j].isActive)
				{
					isGameOver = true;
					Game::gameState.end = 2 - i;
					break;
				}
				if (players[i].collRect.intersects(pad.rightSpikes[j].getGlobalBounds())
					&& pad.rightSpikes[j].isActive)
				{
					isGameOver = true;
					Game::gameState.end = 2 - i;
					break;
				}

			}

			if (activeCandy.getGlobalBounds().intersects(players[i].getGlobalBounds())
				&& isCandyPickedUp == false)
			{
				isCandyPickedUp = true;
				players[i].score += 1;

			}
		}

		player1ScoreText.setString(std::to_string(players[0].score));
		if (Game::gameState.mode == 2)
		{
			player2ScoreText.setString(std::to_string(players[1].score));
		}

	}
	else
	{
		StateManager::get()->switchState(STATE::END_SCREEN);
	}
}

void Gameplay::draw()
{
	pad.draw();
	for (int i = 0; i < players.size(); i++)
	{
		players[i].draw();
	}

	if (Game::gameState.mode == 1)
	{
		Game::window->draw(levelHolder);
		Game::window->draw(levelText);
		Game::window->draw(player1ScoreHolder);
		Game::window->draw(player1ScoreText);
		Game::window->draw(spaceInfo);
	}

	if (Game::gameState.mode == 2)
	{
		Game::window->draw(levelHolder);
		Game::window->draw(levelText);
		Game::window->draw(player1ScoreHolder);
		Game::window->draw(player1ScoreText);
		Game::window->draw(player2ScoreHolder);
		Game::window->draw(player2ScoreText);
		Game::window->draw(spaceInfo);
		Game::window->draw(upInfo);
	}

	if (isCandyPickedUp == false)
	{
		Game::window->draw(activeCandy);
	}
}

void Gameplay::dispose()
{
}
