#pragma once
#include <SFML/Graphics.hpp>

using sf::Color;

class ColorGen
{
public:
	ColorGen() {};
	~ColorGen() {};

	static Color randColor();
	static int toInt(const Color & color);
	static Color toColor(int i);
};

