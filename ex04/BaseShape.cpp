#include "BaseShape.h"
#include "ColorGen.h"

const float OUTLINE_THICKNESS = 2.3f;

BaseShape::BaseShape(const Vector2f & pos, float rotation)
	: m_shape(std::make_unique<ConvexShape>()), m_isConquered(false)
{
	// initialize the shape with position, rotation, color and outline
	m_shape->setPosition(pos);
	m_shape->rotate(rotation);
	m_shape->setFillColor(ColorGen::randColor());
	m_shape->setOutlineColor(Color::Black);
}

bool BaseShape::intersects(const BaseShape & other) const
{
	const Vector2f myCenter = getCenter();	// center of myself
	float myRadius = getRadius();			// radius of myself
	const Vector2f otherCenter = other.getCenter();	// center of other shape
	float otherRadius = other.getRadius();	// radius of other shape
	// if the distance betweeen the 2 centers is less than both radius, it means they intersects
	return distance(myCenter, otherCenter) < ((myRadius + otherRadius));
}

void BaseShape::addNeighbor(BaseShape & other)
{
	m_neighbors.push_back(&other);	// add other to the neighbors vector
}

float BaseShape::conquerNeighbors(const Color & color, vector<BaseShape*> & conquered, bool toConquer)
{	// toConquer = boolean to state if to actually conquer the neighbors, or just to return the total area conquered
	if (toConquer)
		m_shape->setFillColor(color);	// firstly, change the shape's color
	float addedArea = 0.f;
	for (auto neighbor : m_neighbors)	// for each neighbor
		if (!neighbor->isConquered() && neighbor->m_shape->getFillColor() == color)
		{	// if his not conquered yet, and he has the color that we want to conquer
			if (toConquer)
			{
				conquered.push_back(neighbor);	// add neighbor to the conquered shapes
				neighbor->conquer(color);		// and conquer neighbor
			}
			else
				neighbor->m_isConquered = true;	// workaround to not pass twice on the same shape
			addedArea += neighbor->getArea();	// add the neighbor's area
			addedArea += neighbor->conquerNeighbors(color, conquered, toConquer);	// add the area conquered by the neighbor
			if (!toConquer)
				neighbor->m_isConquered = false;	// workaround to not pass twice on the same shape
		}
	return addedArea;	// return total area conquered
}

void BaseShape::conquer(const Color & color)
{
	m_shape->setOutlineThickness(-OUTLINE_THICKNESS);	// set outline
	m_isConquered = true;	// set boolean
	m_shape->setFillColor(color);	// set color
}

void BaseShape::setAsFirst()
{
	for (auto neighbor : m_neighbors)	// for each neighbor
		while (neighbor->getColor() == m_shape->getFillColor())	// change his color until the color is different than mine
			neighbor->m_shape->setFillColor(ColorGen::randColor());
}

float BaseShape::distance(const Vector2f & p1, const Vector2f & p2) const
{
	float distX = p1.x - p2.x;	// distance in x axis
	float distY = p1.y - p2.y;	// distance in y axis
	return sqrt(distX * distX + distY * distY);	// distance = square_root(x^2 + y^2)
}
