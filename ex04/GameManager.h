#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "Toolbar.h"
#include "Board.h"
#include "Colorbar.h"
#include "User.h"
#include "Computer.h"

using sf::RenderWindow;
using sf::Event;

class GameManager
{
public:
	GameManager();
	~GameManager();

	// Runs the game
	void play();

private:
	// Creates a window.
	void createWindow();

	// Draws the whole game objects on the window, and than displays it
	void draw();

	// Handles the events of the user
	void handleEvents();

	// Handles the events of any mouse button pressed
	void mouseButtonPressedHandler(const Event & event);

	// Displays a message box which announces the user if he won or lost
	void announceWinner(const Player & player);

	// Restarts the game
	void restartGame();

	// Members:
	RenderWindow m_window;	// Main window
	ResourceManager m_rm;	// Resource manager to load the needed files
	Toolbar m_toolbar;		// Toolbar (for buttons at the top of the window)
	Colorbar m_colorbar;	// Colorbar (for stats and color buttons at the bottom of the window)
	User& m_user;			// The user player
	Computer& m_computer;	// The computer player
	Board m_board;			// Board
};

