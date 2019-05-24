#pragma once
#include "Player.h"

using sf::Color;

class Computer : public Player
{
public:
	// Instance function to make the computer as singleton
	static Computer& instance(Colorbar & colorbar);
	~Computer();
	Computer(const Computer&) = delete;
	Computer& operator=(const Computer&) = delete;

	// Play the computer turn
	void playTurn();

private:
	Computer(Colorbar & colorbar);

	// Calculates the total area that will be gained if choosing the given color
	float calcAreaGain(const Color & color);

	// Calculates and mark the color which gives the max area for the computer 
	void calcNextColor();

	Color m_nextColor;	// next color to choose
};

