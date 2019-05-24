#pragma once
#include <SFML/Graphics.hpp>

using sf::Vector2f;
using sf::Color;
using sf::RenderWindow;
using sf::RectangleShape;

class Button
{
public:
	Button(const Vector2f & size, const Vector2f & pos, const Color & color);
	~Button();

	// Draws the button on the given panel
	virtual void draw(RenderWindow & window) { window.draw(m_button); };

	// Returns if the given position is clicked on the button
	bool isClicked(const Vector2f & pos) const;
	// Returns if the given position is clicked on the button, while also setting the color of the button
	bool isClicked(const Vector2f & pos, Color & color) const;

	// Set button as selected
	void select();
	// Set button as deselected
	void deselect();

	// Returns if the button is selected
	bool isSelected() const { return m_isSelected; }

private:
	RectangleShape m_button;	// the button
	bool m_isSelected;			// boolean if the button is selected
};

