#pragma once
using namespace std;
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MainMenu
{
public:
	MainMenu();
	virtual ~MainMenu();

	int selectedMenuItem = 0;

	sf::CircleShape menuCircle;

	sf::RenderWindow window;

	sf::Text menuTitle;
	sf::Text menuPlayText;
	sf::Text menuPlayIAText;
	sf::Text menuOptionsText;
	sf::Text menuQuitText;

	void drawMenuItems();

};

class MainMenu
{
public:
	MainMenu();
	~MainMenu();
};

