#pragma once
#include "BaseShape.h"
#include "Colorbar.h"
#include "ColorGen.h"
#include <SFML/Graphics.hpp>

using sf::Color;

class Player
{
public:
	Player(Colorbar & colorbar);
	virtual ~Player();

	// Sets the starting shape of the player
	virtual void setStartingShape(BaseShape & shape);

	// Initializes the player with a starting color and a starting shape
	virtual void initializePlayer(const Color & forbidden);

	// Conquers the possible area with the given color
	virtual void conquerArea(const Color & color);

	// Returns the currently selected color of the player
	virtual Color getCurrColor() const { return m_currColor; }

	// Returns the area currently controlled by the player
	virtual float getArea() const { return m_area; }

	// Restarts all the player data
	virtual void restart();

protected:
	// Selects the color button in the colorbar
	virtual void pickColor(const Color & color);

	vector<BaseShape*> m_conqueredShapes;	// shapes currently controlled by the player
	float m_area;			// area currently controlled by the player
	Color m_currColor;		// currently selected color
	Colorbar & m_colorbar;	// reference to the colorbar
};

