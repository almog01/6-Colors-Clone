#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "Panel.h"
#include "Button.h"
#include <memory>

using sf::RenderWindow;
using sf::Text;
using std::string;

class Toolbar : public Panel
{
public:
	Toolbar(const ResourceManager & rm);
	~Toolbar();

	// Inherited via Panel
	virtual void draw(RenderWindow & window) override;

	// Returns if any button in the toolbar was clicked
	bool isBtnClicked(const Vector2f & pos, string & cmd) const;

private:
	// Creates the restart and exit texts
	void createTexts();

	const ResourceManager & m_rm;	// resource manager reference
	Button m_restartBtn;	// restart button
	Button m_exitBtn;		// exit button
	Text m_restartTxt;		// restart text
	Text m_exitTxt;			// exit text
};

