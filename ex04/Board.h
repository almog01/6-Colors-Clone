#pragma once
#include "Panel.h"
#include "BaseShape.h"
#include "User.h"
#include "Computer.h"
#include <memory>
#include <experimental/vector>

using sf::RenderTexture;
using sf::Sprite;
using sf::Vector2f;
using std::vector;
using std::unique_ptr;

class Board : public Panel
{
public:
	Board(User& user, Computer& computer);
	~Board();

	// Inherited via Panel
	virtual void draw(RenderWindow & window) override;

	// Returns total area of the board
	float getTotalArea() const { return m_totalArea; }

	// Creates the texture with will be used as the board
	void createTexture(const Vector2f & pos, unsigned width, unsigned height);

	// Restarts the board data
	void restart();

private:
	// Creates all the shapes which builds the board
	void createBoard();

	// Sets for each shape of the board, who is his neighbors
	void setNeighbors();

	// Adds a random rectangle to the board: full, divided horizontally or divided vertically
	void randomRectangle(const Vector2f & pos);

	// Initialize the players after the board has been built
	void iniPlayers();

	RenderTexture m_texture;	// the board is built on a render texture
	Sprite m_sprite;		// in order to draw the texture on a window, it needs a sprite
	vector<unique_ptr<BaseShape>> m_board;	// the board itself
	float m_totalArea;		// total area of the board
	User& m_user;			// reference to user player
	Computer& m_computer;	// reference to computer player
};

