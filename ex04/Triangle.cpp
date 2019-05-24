#include "Triangle.h"

const size_t VERTICES = 3;

float Triangle::m_width = 34.f;
float Triangle::m_height = 17.f;
float Triangle::m_area = 0.5f;

Triangle::Triangle(const Vector2f & pos, float rotation)
	: BaseShape(pos, rotation)
{
	// draw the 3 vertices of the triangle
	m_shape->setPointCount(VERTICES);
	m_shape->setPoint(0, Vector2f(0, 0));
	m_shape->setPoint(1, Vector2f(m_width / 2, m_height));
	m_shape->setPoint(2, Vector2f(m_width, 0));
}

Triangle::~Triangle()
{
}

float Triangle::getRadius() const
{
	return (m_width + 1.f) / 4.f;
}

Vector2f Triangle::getCenter() const
{
	auto bounds = m_shape->getGlobalBounds();	// global bounds of the triangle
	return Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);	// center of the bounds
}

float Triangle::getArea() const
{
	return m_area;
}
