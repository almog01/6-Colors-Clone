#include "Board.h"
#include "Square.h"
#include "Triangle.h"

using std::make_unique;

const float BOARD_SIZE = 17;	// Board size

Board::Board(User& user, Computer& computer)
	: m_totalArea(0.f), m_user(user), m_computer(computer)
{
	createBoard();
	setNeighbors();
	iniPlayers();
}


Board::~Board()
{
}

void Board::draw(RenderWindow & window)
{
	m_texture.clear();	// clear board's texture
	for (auto& shape : m_board)	// draw all shapes on the board
		shape->draw(m_texture);
	window.draw(m_sprite);	// draw the sprite to the window
	m_texture.display();	// display
}

void Board::createTexture(const Vector2f & pos, unsigned width, unsigned height)
{
	m_texture.create(width, height);	// create the texture
	m_sprite.setPosition(pos);			// set the position of the board
	m_sprite.setTexture(m_texture.getTexture(), true);	// set board's sprite texture
}

void Board::restart()
{
	// restart board data
	m_totalArea = 0.f;
	m_board.clear();
	createBoard();
	setNeighbors();
	iniPlayers();
}

void Board::createBoard()
{
	// create the first triangle for the user at the bottom left corner
	auto userStart = make_unique<Triangle>
		(Vector2f(Triangle::width(), (BOARD_SIZE-1) * Triangle::width()), 180.f);
	m_user.setStartingShape(*userStart);
	m_board.push_back(std::move(userStart));
	m_totalArea += Triangle::area();

	// create the first triangle for the computer at the top right corner
	auto compStart = make_unique<Triangle>
		(Vector2f((BOARD_SIZE-1) * Triangle::width(), 0));
	m_computer.setStartingShape(*compStart);
	m_board.push_back(std::move(compStart));
	m_totalArea += Triangle::area();

	// -----------------Board frame-----------------
	// top row
	for (int i = 0; i < BOARD_SIZE - 1; ++i)
	{
		m_board.push_back(make_unique<Triangle>
			(Vector2f(i * Triangle::width(), 0.f)));
		m_totalArea += Triangle::area();
	}
	// left column
	for (int i = 1; i < BOARD_SIZE; ++i)
	{
		m_board.push_back(make_unique<Triangle>
			(Vector2f(0, i * Triangle::width()), 270.f));
		m_totalArea += Triangle::area();
	}
	// bottom row
	for (int i = 2; i < BOARD_SIZE + 1; ++i)
	{
		m_board.push_back(make_unique<Triangle>
			(Vector2f(i * Triangle::width(), (BOARD_SIZE - 1) * Triangle::width()), 180.f));
		m_totalArea += Triangle::area();
	}
	// right column
	for (int i = 0; i < BOARD_SIZE - 1; ++i)
	{
		m_board.push_back(make_unique<Triangle>
			(Vector2f(BOARD_SIZE * Triangle::width(), i * Triangle::width()), 90.f));
		m_totalArea += Triangle::area();
	}
	// ---------------------------------------------

	// -----------------Middle board-----------------
	for (int i = 0; i < BOARD_SIZE - 1; ++i)
		for (int j = 0; j < BOARD_SIZE - 1; ++j)
			randomRectangle(Vector2f((Triangle::width() / 2) + (i * Square::size()), (j * Square::size())));
	for (int i = 0; i < BOARD_SIZE; ++i)
		for (int j = 0; j < BOARD_SIZE - 2; ++j)
			randomRectangle(Vector2f((i * Square::size()), (Triangle::height()) + (j * Square::size())));
	// ----------------------------------------------
}

void Board::setNeighbors()
{
	for (auto shape1 = m_board.cbegin(); shape1 != m_board.cend(); ++shape1)	// for each shape of the board
	{
		for (auto shape2 = shape1 + 1; shape2 != m_board.cend(); ++shape2)	// check on the next shapes
		{
			if ((*shape1)->intersects(*(*shape2)))	// if 2 shapes intersects it means they are neighbors
			{
				(*shape1)->addNeighbor(*(*shape2));	// add neighbors in both directions
				(*shape2)->addNeighbor(*(*shape1));
			}
		}
	}
}

void Board::randomRectangle(const Vector2f & pos)
{
	int type = rand() % 3;	// get random between 3 rectangle types
	switch (type)
	{
	case 0:		// full rectangle
	{
		m_board.push_back(make_unique<Square>(pos));
		break;
	}
	case 1:		// divided horizontally rectangle: top and bottom (rotated by 180) triangles
	{
		const Vector2f topPos(pos.x, pos.y + Triangle::height());
		m_board.push_back(make_unique<Triangle>(topPos));
		const Vector2f botPos(topPos.x + Triangle::width(), topPos.y);
		m_board.push_back(make_unique<Triangle>(botPos, 180.f));
		break;
	}
	case 2:		// divided vertically rectangle:left (rotated by 90) and right (rotated by 270) triangles
	{
		const Vector2f leftPos(pos.x + (Triangle::width() / 2.f), pos.y);
		m_board.push_back(make_unique<Triangle>(leftPos, 90.f));
		const Vector2f rightPos(leftPos.x, leftPos.y + Triangle::width());
		m_board.push_back(make_unique<Triangle>(rightPos, 270.f));
		break;
	}
	default:
		return;
	}
	m_totalArea += Square::area();
	return;
}

void Board::iniPlayers()
{
	m_user.initializePlayer(Color::Transparent);	// initialize user
	m_computer.initializePlayer(m_user.getCurrColor());	// initialize computer
}
