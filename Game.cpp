#include "Game.h"
#include "SoundPlayer.h"

std::shared_ptr<sf::RenderWindow> Game::window;
GameState Game::gameState;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "SFML engine", sf::Style::Fullscreen);
    window->setFramerateLimit(60);
    Config::get()->load();
    Input::init();   
    SoundPlayer::playMusic("img\\backgroundMusic.wav");
}

void Game::run()
{

    while (window->isOpen())
    {
        Input::poll();
        

        if (Input::isKeyPressed(sf::Keyboard::Escape))
        {
            window->close();
            return;
        }

        StateManager::get()->currentState->update();
        StateManager::get()->currentState->draw();

        window->display();
        window->clear(sf::Color::Black); // Color background
    }
}

void Game::dispose()
{

}

