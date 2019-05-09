#pragma once
#include <SFML/Graphics.hpp>


#include <iostream>
#include <string>
#include <string.h>
extern "C" {
#include "Juego76.h"
}

class IaGUI
{
protected:

	int WIDTH = 800;
	int HEIGHT = 800;
	char turn = '1';
	bool added;
	bool go;
	char mapaxd[7][7];
	enum Tile { NONE, BLUE, YELLOW };
	sf::CircleShape circle, turnCircle;
	sf::ContextSettings settings;
	sf::RenderWindow window;
	sf::RectangleShape board, scoreboard, panel, rectWin,restart;
	sf::Font font;
	sf::Text text, turnText, text2, score1, score2, ggText, restartText, p1Text, p2Text, columnsText;

	sf::Texture texture;
	sf::Sprite sprite;
	

	sf::String player1,player2;

	int n;
	std::string s = " ";
	

public: 

	IaGUI(bool mode);
	void changeTurn();
	void paintBoard();
	void updateGUI();
	void initGUI();





};