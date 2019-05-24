#pragma once
#include "Panel.h"
#include "ResourceManager.h"
#include "Button.h"
#include <unordered_map>
#include <memory>

using std::unordered_map;
using std::unique_ptr;
using sf::Color;
using sf::Text;

class Colorbar : public Panel
{
public:
	Colorbar(const ResourceManager & rm);
	~Colorbar();

	// Inherited via Panel
	virtual void draw(RenderWindow & window) override;

	// Returns if any button in the colorbar was clicked
	bool isBtnClicked(const Vector2f & pos, Color & color) const;

	// Sets color button as selected
	void selectColor(const Color & color);
	// Sets color button as deselected
	void deselectColor(const Color & color);

	// Update the user and computer scores
	void updateScore(float user, float computer);

	// Returns if the given color button is selected
	bool isColorSelected(const Color & color) const;

private:
	// Creates the color button
	void createColorButtons();

	// Creates the area texts
	void createAreaText();

	const ResourceManager & m_rm;	// resource manager reference
	unordered_map<int, unique_ptr<Button>> m_colorBtns;	// map for the color buttons
	Text m_userScore;		// user score text
	Text m_computerScore;	// computer score text
};

