#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include "Game.h"

int main()
{
    
    Game game;

    game.init();

    game.run();

    game.dispose();

    return 0;
}