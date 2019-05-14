#pragma once
using namespace std;
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "onlineGUI.h"
#include "Client2.h"
//#include "Options.h"
#include <thread>
#include <iostream>
#include <cstdlib>




class MainMenu
{
public:
	MainMenu(std::string s);
	virtual ~MainMenu();

	int selectedMenuItem = 0;
	int col = 0;

	 std::string playerName;
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

	sf::Vertex line[2];

	sf::Vertex line2[2];

	sf::Font font;

	sf::Font getFont();


	void drawMenuItems();
	void update();

	
};
