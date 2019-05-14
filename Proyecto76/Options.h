
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string.h>
#include <string>
#include "BD.h"

//#include "MainMenu.h"

#include <windows.h>

#pragma once

class Options
{
public:
	Options();
	virtual ~Options();

	sf::RenderWindow window;

	sf::Text optionsTitle;
	sf::Text musicText;
	sf::Text leaderboardText;
	sf::Text playText;
	sf::Text t2;

	sf::Font font;
	std::string songPath;

	sf::Music musicOptions;

	OPENFILENAME ofn;       // common dialog box structure
	char szFile[260];       // buffer for file name
	HWND hwnd;              // owner window
	HANDLE hf;              // file handle

	int selectedOptionsItem;
	int mode;

	void initOptions();
	void update();

	void openFolder();

	void openFolder2();

	
};

