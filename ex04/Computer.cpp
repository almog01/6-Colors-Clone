#include "Computer.h"

const int NUM_OF_COLORS = 6;

void Computer::playTurn()
{
	calcNextColor();
	conquerArea(m_nextColor);
}

float Computer::calcAreaGain(const Color & color)
{
	float areaGain = 0.f;
	for (auto shape : m_conqueredShapes)	// send each conquered shape to calculate how much area will be added with the given color
		areaGain += shape->conquerNeighbors(color, m_conqueredShapes, false);
	return areaGain;	// return the total area
}

void Computer::calcNextColor()
{
	float maxArea = 0.f;	// the color which gives max area
	for (int i = 0; i < NUM_OF_COLORS; i++)
	{
		if (!m_colorbar.isColorSelected(ColorGen::toColor(i)))	// check only unselected colors
		{
			float area = calcAreaGain(ColorGen::toColor(i));	// area gain by the color
			if (area >= maxArea)
			{
				maxArea = area;
				m_nextColor = ColorGen::toColor(i);
			}
		}
	}
}

Computer::Computer(Colorbar & colorbar) : Player(colorbar)
{
}


Computer & Computer::instance(Colorbar & colorbar)
{
	static Computer inst(colorbar);
	return inst;
}

Computer::~Computer()
{
}
