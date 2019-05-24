#include "Square.h"

const size_t VERTICES = 4;

float Square::m_size = 34.f;
float Square::m_area = 1.f;

Square::Square(const Vector2f & pos, float rotation)
	: BaseShape(pos, rotation)
{
	// draw the 4 vertices of the triangle
	m_shape->setPointCount(VERTICES);
	m_shape->setPoint(0, Vector2f(m_size / 2, 0));
	m_shape->setPoint(1, Vector2f(0, m_size / 2));
	m_shape->setPoint(2, Vector2f(m_size / 2, m_size));
	m_shape->setPoint(3, Vector2f(m_size, m_size / 2));
}

float Square::getRadius() const
{
	return (m_size + 15.f) / 4.f;
}

Vector2f Square::getCenter() const
{
	auto bounds = m_shape->getGlobalBounds();	// global bounds of the rectangle
	return Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);	// center of the bounds
}

float Square::getArea() const
{
	return m_area;
}
