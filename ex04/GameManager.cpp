#include "GameManager.h"
#include <string>
#include "Square.h"
#include "BaseShape.h"
#include <memory>
#include <Windows.h>

using std::string;
using sf::VideoMode;
using sf::Color;

const string GAME_NAME = "6 Colors";	// game title
const unsigned WINDOW_WIDTH = 578;		// main window width
const unsigned WINDOW_HEIGHT = 619;		// main window height
const unsigned TOOLBAR_HEIGHT = 30;		// Toolbar height
const unsigned BOARD_HEIGHT = 544;		// Board height
const unsigned COLORBAR_HEIGHT = 45;	// Colorbar height
const float WINNING_AREA = 50;			// Colorbar height

GameManager::GameManager()
	: m_user(User::instance(m_colorbar)), m_computer(Computer::instance(m_colorbar)), 
	m_board(m_user, m_computer), m_colorbar(m_rm), m_toolbar(m_rm)
{
}


GameManager::~GameManager()
{
}

void GameManager::play()
{
	createWindow();	// create the main window

	while (m_window.isOpen())	// main window loop
	{
		// each iteration:
		draw();				// clear, draw and display each object on the main window
		handleEvents();		// handle each events
	}
}

void GameManager::createWindow()
{
	m_window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);	// create main window
	m_board.createTexture(Vector2f(0, TOOLBAR_HEIGHT), m_window.getSize().x, BOARD_HEIGHT);	// create board texture
}

void GameManager::draw()
{
	m_window.clear(Color(102, 153, 153));	// clear the main window

	m_toolbar.draw(m_window);	// draw Toolbar
	m_board.draw(m_window);		// draw Board
	m_colorbar.draw(m_window);	// draw Colorbar

	m_window.display();	// display the main window after all has been drawn
}

void GameManager::handleEvents()
{
	Event event;
	while (m_window.pollEvent(event))	// wait event loop
	{
		switch (event.type)
		{
		case Event::Closed:		// event of windows closed
			m_window.close();
			break;
		case Event::MouseButtonPressed:	// event of mouse button pressed
			mouseButtonPressedHandler(event);
			break;
		}
	}
}

void GameManager::mouseButtonPressedHandler(const Event & event)
{
	if (event.mouseButton.button == sf::Mouse::Button::Left)	// at left mouse button press
	{
		// Save the position of the mouse click:
		const Vector2f mousePos = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
		
		Color pickedColor;
		if (m_colorbar.isBtnClicked(mousePos, pickedColor))	// check if a button in the colorbar was clicked
			if (pickedColor != m_user.getCurrColor() && pickedColor != m_computer.getCurrColor())	// check that the clicked color is not picked already
			{
				float total = m_board.getTotalArea();
				m_user.conquerArea(pickedColor);	// send the user to conquer the area with the picked color
				float userArea = (m_user.getArea() / total) * 100.f;	// calculate user conquered area
				if (userArea >= WINNING_AREA)	// if the user conquered more than 50% of the board
				{
					announceWinner(m_user);	// announce that the user won
					return;
				}
				m_computer.playTurn();	// play computer turn
				float computerArea = (m_computer.getArea() / total) * 100.f;	// calculate computer conquered area
				if (computerArea >= WINNING_AREA)	// if the computer conquered more than 50% of the board
				{
					announceWinner(m_computer);	// announce that the computer won
					return;
				}
				m_colorbar.updateScore(userArea, computerArea);	// update score in the end
			}

		string cmd;
		if (m_toolbar.isBtnClicked(mousePos, cmd))	// check if a button in the toolbar was clicked
		{
			if (cmd == "Restart")	// if the restart button was clicked
				restartGame();		// restart game
			else if (cmd == "Exit")	// if the exit button was clicked
				exit(EXIT_SUCCESS);	// end game
		}
	}
}

void GameManager::announceWinner(const Player & player)
{
	if (typeid(player) == typeid(m_user))	// if the user won
	{
		MessageBoxA(NULL, "You win!", "Game over", MB_OK);	// print message
	}
	else if (typeid(player) == typeid(m_computer))	// if the computer won
	{
		MessageBoxA(NULL, "You lose!", "Game over", MB_OK);	// print message
	}
	restartGame();	// restart game
}

void GameManager::restartGame()
{
	m_user.restart();		// restart the user
	m_computer.restart();	// restart the computer
	m_board.restart();		// restart board
	m_colorbar.updateScore(0.f, 0.f);	// restart score to 0
}
