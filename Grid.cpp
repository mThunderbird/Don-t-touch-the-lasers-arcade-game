#include "Grid.h"
#include "Config.h"
#include "Game.h"

Grid::Grid()
{
}

Grid::Grid(sf::Vector2f _dimensions)
{

}

Grid::~Grid()
{
}

void Grid::createMatrix(sf::Vector2f _dimensions)
{
	dimensions = _dimensions;
	if (maximumTileSize * dimensions.y > maximumGridHeight)
	{
        tileSize = maximumGridHeight / dimensions.y;
        tileSize = (tileSize / 5) * 5;
        if (tileSize * dimensions.x > maximumGridWidth)
        {
            tileSize = maximumGridWidth / dimensions.x;
            tileSize = (tileSize / 5) * 5;
        }
	}
    else if (maximumTileSize * dimensions.x > maximumGridWidth)
    {
        tileSize = maximumGridWidth / dimensions.x;
        tileSize = (tileSize / 5) * 5;
        if (tileSize * dimensions.y > maximumGridHeight)
        {
            tileSize = maximumGridHeight / dimensions.y;
            tileSize = (tileSize / 5) * 5;
        }
    }
    else tileSize = maximumTileSize;

    position.x = WINDOW_WIDTH / 2 - dimensions.x * tileSize / 2;
    position.y = WINDOW_HEIGHT / 2 - dimensions.y * tileSize / 2;
    
    matrix.resize(dimensions.x);

    for (int i = 0; i < dimensions.x; i++)
    {
        matrix[i].resize(dimensions.y);

        for (int j = 0; j < dimensions.y; j++)
        {
            Button temp;
            temp.setPosition(position.x + i * tileSize, position.y + j * tileSize);
            temp.setScale( float(tileSize) / float(maximumTileSize), float(tileSize) / float(maximumTileSize));
            temp.texture = std::make_shared<sf::Texture>(Config::get()->gridC.gridSquare);
            temp.mask = std::make_shared<sf::Texture>(Config::get()->gridC.gridSquarehover);

            //temp.mPosition = new Vector2(position.X + j * tileSize, position.Y + i * tileSize);
            //temp.mDimensions = new Vector2(tileSize, tileSize);

            //temp.Texture = Config.Instance.gridTile1;

            matrix[i].push_back(temp);
        }
    }


}

void Grid::update()
{
    for (int i = 0; i < dimensions.x; i++)
    {
        for (int j = 0; j < dimensions.y; j++)
        {
            matrix[i][j].update();
        }
    }
}

void Grid::draw()
{
    for (int i = 0; i < dimensions.x; i++)
    {
        for (int j = 0; j < dimensions.y; j++)
        {
            Game::window->draw(matrix[i][j]);
        }
    }
}
