#pragma once
using namespace std;
#include <iostream>
#include <SFML/Graphics.hpp>

class Login
{
public:
	Login();
	virtual ~Login();

	int selectedLoginItem = 0;

	sf::RenderWindow window;

	sf::Text loginTitle;
	sf::Text userText;
	//sf::Text passwordText;
	sf::Text inputUserText;
	sf::Text inputPasswordText;

	sf::String userString, passwordString;

	sf::Font font;


	void drawLoginItems();
	void update();

	int readSize();
	bool isPlayer(std::string s);

	void incSize();
	void writePlayer(std::string p);

	

};

