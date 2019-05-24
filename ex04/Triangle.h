#pragma once
#include "BaseShape.h"

class Triangle : public BaseShape
{
public:
	Triangle(const Vector2f & pos, float rotation = 0);
	~Triangle();

	// Return triangle's width
	static float width() { return m_width; };
	// Return triangle's height
	static float height() { return m_height; };
	// Return triangle's area
	static float area() { return m_area; };

	// Inherited via BaseShape
	virtual float getRadius() const override;

	// Inherited via BaseShape
	virtual Vector2f getCenter() const override;

	// Inherited via BaseShape
	virtual float getArea() const override;

private:
	static float m_width;	// triangle's width
	static float m_height;	// triangle's height
	static float m_area;	// triangle's area
};

