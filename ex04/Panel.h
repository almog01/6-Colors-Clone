#pragma once
#include <SFML/Graphics.hpp>

using sf::RenderWindow;

class Panel
{
public:
	Panel();
	virtual ~Panel();

	// Draws the objects inside the panel
	virtual void draw(RenderWindow & window) = 0;
};

