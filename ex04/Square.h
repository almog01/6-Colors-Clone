#pragma once
#include "BaseShape.h"

class Square : public BaseShape
{
public:
	Square(const Vector2f & pos, float rotation = 0);
	~Square() {};

	// Return square's size
	static float size() { return m_size; };
	// Return square's area
	static float area() { return m_area; };

	// Inherited via BaseShape
	virtual float getRadius() const override;

	// Inherited via BaseShape
	virtual Vector2f getCenter() const override;

	// Inherited via BaseShape
	virtual float getArea() const override;

private:
	static float m_size;	// square's size
	static float m_area;	// square's area
};

