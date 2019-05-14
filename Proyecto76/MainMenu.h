#pragma once
using namespace std;
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "onlineGUI.h"
#include "Client2.h"
#include <thread>
#include <iostream>
#include <cstdlib>

#include "Options.h"

class MainMenu
{
public:
	MainMenu();
	virtual ~MainMenu();

	int selectedMenuItem = 0;
	int col = 0;
	sf::CircleShape menuCircle;

	sf::RenderWindow window;

	sf::Music music;

	sf::Text menuTitle;
	sf::Text menuPlayText;
	sf::Text menuPlayIAText;
	sf::Text menuPlayOnlineText;
	sf::Text menuOptionsText;
	sf::Text menuQuitText;

	sf::Texture backTexture;
	sf::Sprite backSprite;

	std::string songPath;
	



	void drawMenuItems();

	
};
