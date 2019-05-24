#include "Colorbar.h"
#include "ColorGen.h"
#include "ResourceManager.h"

using std::make_unique;

const unsigned TEXT_SIZE = 20U;	// size of the texts
const float OUTLINE_THICKNESS = 2.f;	// outline thickness size

Colorbar::Colorbar(const ResourceManager & rm) : m_rm(rm)
{
	createColorButtons();	// create the color buttons
	createAreaText();		// create the areas covered texts
}


Colorbar::~Colorbar()
{
}

void Colorbar::draw(RenderWindow & window)
{
	for (auto& btn : m_colorBtns)	// draw each button
		btn.second->draw(window);
	window.draw(m_userScore);		// draw user score
	window.draw(m_computerScore);	// draw computer score
}

void Colorbar::createColorButtons()
{
	// red button
	auto redBtn = make_unique<Button>(Vector2f(25.f, 25.f), Vector2f(170.f, 585.f), Color::Red);
	m_colorBtns[ColorGen::toInt(Color::Red)] = std::move(redBtn);

	// orange button
	auto orangeBtn = make_unique<Button>(Vector2f(25.f, 25.f), Vector2f(210.f, 585.f), Color(255, 153, 0));
	m_colorBtns[ColorGen::toInt(Color(255, 153, 0))] = std::move(orangeBtn);

	// yellow button
	auto yellowBtn = make_unique<Button>(Vector2f(25.f, 25.f), Vector2f(250.f, 585.f), Color::Yellow);
	m_colorBtns[ColorGen::toInt(Color::Yellow)] = std::move(yellowBtn);

	// green button
	auto greenBtn = make_unique<Button>(Vector2f(25.f, 25.f), Vector2f(290.f, 585.f), Color::Green);
	m_colorBtns[ColorGen::toInt(Color::Green)] = std::move(greenBtn);

	// blue button
	auto blueBtn = make_unique<Button>(Vector2f(25.f, 25.f), Vector2f(330.f, 585.f), Color::Blue);
	m_colorBtns[ColorGen::toInt(Color::Blue)] = std::move(blueBtn);

	// purple button
	auto purpleBtn = make_unique<Button>(Vector2f(25.f, 25.f), Vector2f(370.f, 585.f), Color::Magenta);
	m_colorBtns[ColorGen::toInt(Color::Magenta)] = std::move(purpleBtn);
}

void Colorbar::createAreaText()
{
	// initialize user score text
	m_userScore.setFont(m_rm.getFont());
	m_userScore.setCharacterSize(TEXT_SIZE);
	m_userScore.setFillColor(Color::White);
	m_userScore.setPosition(Vector2f(60.f, 585.f));
	m_userScore.setOutlineColor(Color::Black);
	m_userScore.setOutlineThickness(OUTLINE_THICKNESS);
	m_userScore.setString(std::to_string(0.f) + "%");

	// initialize computer score text
	m_computerScore.setFont(m_rm.getFont());
	m_computerScore.setCharacterSize(TEXT_SIZE);
	m_computerScore.setFillColor(Color::White);
	m_computerScore.setPosition(Vector2f(450.f, 585.f));
	m_computerScore.setOutlineColor(Color::Black);
	m_computerScore.setOutlineThickness(OUTLINE_THICKNESS);
	m_computerScore.setString(std::to_string(0.f) + "%");
}

bool Colorbar::isBtnClicked(const Vector2f & pos, Color & color) const
{
	for (auto& btn : m_colorBtns)	// check if any of the color buttons was clicked
		if (btn.second->isClicked(pos, color))
			return true;
	return false;
}

void Colorbar::selectColor(const Color & color)
{
	m_colorBtns[ColorGen::toInt(color)]->select();	// set color button as selected
}

void Colorbar::deselectColor(const Color & color)
{
	m_colorBtns[ColorGen::toInt(color)]->deselect();	// set color button as deselected
}

void Colorbar::updateScore(float user, float computer)
{
	// update scores
	m_userScore.setString(std::to_string(user) + "%");
	m_computerScore.setString(std::to_string(computer) + "%");
}

bool Colorbar::isColorSelected(const Color & color) const
{
	return m_colorBtns.at(ColorGen::toInt(color))->isSelected();	// return if the color button is selected
}
