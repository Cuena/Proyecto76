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
	//copia del mapa original (mapa[7][7]) para poder trabajar con el en esta clase
	char mapaxd[7][7];

	void pintalo();
};

