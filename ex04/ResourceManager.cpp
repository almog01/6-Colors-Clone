#include "ResourceManager.h"
#include <Windows.h>


ResourceManager::ResourceManager()
{
	loadFont(m_font, "BebasNeue-Regular.ttf");	// load the font file
}


ResourceManager::~ResourceManager()
{
}

void ResourceManager::loadFont(Font & font, string path)
{
	if (!font.loadFromFile(path))	// if font couldn't be loaded
	{
		MessageBoxA(NULL, "Error loading font!", "Error", MB_OK | MB_ICONEXCLAMATION);	// print error message
		exit(EXIT_FAILURE);
	}
}
