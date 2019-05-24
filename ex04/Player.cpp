#include "Player.h"



Player::Player(Colorbar & colorbar)
	: m_area(0.f), m_currColor(Color::Transparent), m_colorbar(colorbar)
{
}


Player::~Player()
{
}

void Player::setStartingShape(BaseShape & shape)
{
	m_conqueredShapes.push_back(&shape);	// add shape to the vector
}

void Player::initializePlayer(const Color & forbidden)
{
	Color color = ColorGen::randColor();	// generate a random color
	while (color == forbidden)	// continue getting colors until the color is not forbidden
		Color randColor = ColorGen::randColor();
	m_conqueredShapes[0]->conquer(color);	// conquer the starting shape with the generated color
	m_conqueredShapes[0]->setAsFirst();	// set the neighbors of the starting shape to be at different color than him
	m_currColor = color;	// save current color
	m_colorbar.selectColor(color);	// make the color button to be selected
	m_area += m_conqueredShapes[0]->getArea();	// add the starting shape area
}

void Player::conquerArea(const Color & color)
{
	pickColor(color);	// select the color button in the colorbar
	auto size = m_conqueredShapes.size();
	for (size_t i = 0; i < size; i++)	// for each conquered shape, send him to conquer his neighbors
		m_area += m_conqueredShapes[i]->conquerNeighbors(color, m_conqueredShapes, true);
}

void Player::restart()
{
	// restart all data
	m_area = 0.f;
	m_colorbar.deselectColor(m_currColor);
	m_currColor = Color::Transparent;
	m_conqueredShapes.clear();
}

void Player::pickColor(const Color & color)
{
	m_colorbar.deselectColor(m_currColor);	// deselect old color button
	m_currColor = color;					// set new color
	m_colorbar.selectColor(color);			// select new color button
}
