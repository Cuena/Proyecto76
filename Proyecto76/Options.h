
#include<SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <string>

//#include "MainMenu.h"

#include <windows.h>
#include <SFML/Audio.hpp>
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

	int selectedOptionsItem;
	int mode;

	void initOptions();
	void update();

	void openFolder();


	
};

