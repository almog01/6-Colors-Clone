#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <experimental/vector>

using std::unique_ptr;
using std::vector;
using sf::RenderTexture;
using sf::ConvexShape;
using sf::Color;
using sf::Vector2f;

class BaseShape
{
public:
	BaseShape(const Vector2f & pos, float rotation = 0);
	virtual ~BaseShape() {};

	// Draws the shape on the given panel
	virtual void draw(RenderTexture & panel) { panel.draw(*m_shape); }

	// Returns if the shape is intersects with other shape
	bool intersects(const BaseShape & other) const;

	// Add other shape as a neighbor
	void addNeighbor(BaseShape & other);

	// Recursive function to conquer my own neighbors with the given color, and thier neighbors
	float conquerNeighbors(const Color & color, vector<BaseShape*> & conquered, bool toConquer);

	// Returns if the shape is conquered or not
	bool isConquered() const { return m_isConquered; }

	// Conquers the shape
	void conquer(const Color & color);

	// Returns the color of the shape
	Color getColor() const { return m_shape->getFillColor(); }

	// Returns the radius of the shape
	virtual float getRadius() const = 0;

	// Returns the center point of the shape
	virtual Vector2f getCenter() const = 0;

	// Returns the area of the shape
	virtual float getArea() const = 0;

	// Sets the shape as the first shape of a player
	void setAsFirst();

protected:
	unique_ptr<ConvexShape> m_shape;	// the shape
	vector<BaseShape*> m_neighbors;		// vector of the neighbors
	bool m_isConquered;					// boolean if the shape is conquered

private:
	// Returns the distance between 2 points
	float distance(const Vector2f & p1, const Vector2f & p2) const;
};

