#pragma once
#include <SFML/Graphics.hpp>
extern "C" {
#include "Juego76.h"
}
class onlineGUI
{
public:
	onlineGUI();
	virtual ~onlineGUI();

	sf::RenderWindow window;
	sf::RectangleShape rect;
	sf::CircleShape circle;
	char mapaxd[7][7];

	void pintalo();
};

