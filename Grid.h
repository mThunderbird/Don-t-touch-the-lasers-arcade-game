#pragma once
#include "Defines.h"
#include "Button.h"

class Grid
{
public:

	Grid();
	Grid(sf::Vector2f _dimensions);
	~Grid();

	void createMatrix(sf::Vector2f _dimensions);

	void update();
	void draw();

private:

	const int maximumTileSize = 100;
	const int maximumGridWidth = 1000;
	const int maximumGridHeight = 800;
	int tileSize;
	sf::Vector2f dimensions;
	sf::Vector2f position;

	std::vector<std::vector<Button>> matrix;

};

