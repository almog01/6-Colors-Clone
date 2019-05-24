#include "Button.h"

const float OUTLINE_THICKNESS = 4.f;

Button::Button(const Vector2f & size, const Vector2f & pos, const Color & color)
	: m_button(size), m_isSelected(false)
{	
	// initialize button
	m_button.setPosition(pos);
	m_button.setFillColor(color);
	m_button.setOutlineColor(Color::Black);
}

Button::~Button()
{
}

bool Button::isClicked(const Vector2f & pos) const
{
	if (m_button.getGlobalBounds().contains(pos))
		return true;
	return false;
}

bool Button::isClicked(const Vector2f & pos, Color & color) const
{
	if (m_button.getGlobalBounds().contains(pos))
	{
		color = m_button.getFillColor();
		return true;
	}
	return false;
}

void Button::select()
{
	m_isSelected = true;
	m_button.setOutlineThickness(-OUTLINE_THICKNESS);
}

void Button::deselect()
{
	m_isSelected = false;
	m_button.setOutlineThickness(0.f);
}
