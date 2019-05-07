#pragma once
#include <SFML/Graphics.hpp>


#include <iostream>
#include <SFML/Network.hpp>
#include <string>
#include <string.h>
extern "C" {
#include "Juego76.h"
}

class Sfmlcon
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

	int n;
	std::string s = " ";



	const unsigned short PORT = 2620;
	const std::string IPADDRESS="25.68.58.155";//change to suit your needs

	std::string msgSend;

	sf::TcpSocket socket;
	sf::Mutex globalMutex;
	bool quit = false;


public:

	Sfmlcon();
	void changeTurn();
	void paintBoard();
	void Server();
	bool Client();
	void GetInput(void);
	void DoStuff();





};