#include "Toolbar.h"

const unsigned TEXT_SIZE = 20U;	// size of the texts

Toolbar::Toolbar(const ResourceManager & rm)
	: m_rm(rm), 
	m_restartBtn(Vector2f(67.f, 20.f), Vector2f(155.f, 5.f), Color::Cyan),	// initialize restart button
	m_exitBtn(Vector2f(47.f, 20.f), Vector2f(350.f, 5.f), Color::Cyan)		// initialize exit button
{
	createTexts();	// create the texts inside the buttons
}


Toolbar::~Toolbar()
{
}

void Toolbar::draw(RenderWindow & window)
{
	// draw buttons
	m_restartBtn.draw(window);
	m_exitBtn.draw(window);
	// draw texts
	window.draw(m_restartTxt);
	window.draw(m_exitTxt);
}

bool Toolbar::isBtnClicked(const Vector2f & pos, string & cmd) const
{
	if (m_restartBtn.isClicked(pos))	// if the restart button was clicked
	{
		cmd = "Restart";
		return true;
	}
	else if (m_exitBtn.isClicked(pos))	// if the exit button was clicked
	{
		cmd = "Exit";
		return true;
	}
	return false;
}

void Toolbar::createTexts()
{
	// initialize restart text
	m_restartTxt.setFont(m_rm.getFont());
	m_restartTxt.setCharacterSize(TEXT_SIZE);
	m_restartTxt.setFillColor(Color::Black);
	m_restartTxt.setPosition(Vector2f(160.f, 2.f));
	m_restartTxt.setString("Restart");

	// initialize exit text
	m_exitTxt.setFont(m_rm.getFont());
	m_exitTxt.setCharacterSize(TEXT_SIZE);
	m_exitTxt.setFillColor(Color::Black);
	m_exitTxt.setPosition(Vector2f(360.f, 2.f));
	m_exitTxt.setString("Exit");
}
