#pragma once
#include <SFML/Graphics.hpp>

using sf::Font;
using std::string;

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	// Returns the loaded font
	const Font & getFont() const { return m_font; }

private:
	// Loads a font. Prints error message if the loading failed
	void loadFont(Font & font, string path);

	Font m_font;	// the game font
};

