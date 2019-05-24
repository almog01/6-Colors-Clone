#include "ColorGen.h"

enum Colors_t
{
	RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE
};

const int NUM_OF_COLORS = 6;

Color ColorGen::randColor()
{
	int randNum = rand() % NUM_OF_COLORS;
	switch (randNum)
	{
	case RED:
		return Color::Red;
	case ORANGE:
		return Color(255, 153, 0);	// RGB of orange
	case YELLOW:
		return Color::Yellow;
	case GREEN:
		return Color::Green;
	case BLUE:
		return Color::Blue;
	case PURPLE:
		return Color::Magenta;
	default:
		return Color::Red;
	}
}

int ColorGen::toInt(const Color & color)
{
	if (color == Color::Red)
		return RED;
	else if (color == Color(255, 153, 0))	// RGB of orange
		return ORANGE;
	else if (color == Color::Yellow)
		return YELLOW;
	else if (color == Color::Green)
		return GREEN;
	else if (color == Color::Blue)
		return BLUE;
	else if (color == Color::Magenta)
		return PURPLE;
	else
		return 0;
}

Color ColorGen::toColor(int i)
{
	switch (i)
	{
	case RED:
		return Color::Red;
	case ORANGE:
		return Color(255, 153, 0);
	case YELLOW:
		return Color::Yellow;
	case GREEN:
		return Color::Green;
	case BLUE:
		return Color::Blue;
	case PURPLE:
		return Color::Magenta;
	default:
		return Color::Transparent;
	}
}
