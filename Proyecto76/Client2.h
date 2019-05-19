#pragma once
#include "onlineGUI.h"
#include "MainMenu.h"
#include <WS2tcpip.h>

#include <thread>
extern "C" {
#include "Juego76.h"
}
#include <string>
#include <iostream>
#include <sstream>

#include "BD.h"



#pragma comment (lib, "ws2_32.lib")

class Client2
{
private:
	std::string ipAddress = "25.68.58.155";
	int port = 2620;
	WSAData data;
	WORD ver;
	SOCKET sock;
	sockaddr_in hint;
	char buf[4096];
	std::string userInput;
	char* jugador;
	bool toca2=false;
	bool* toca=&toca2;
	bool fin2 = true;
	bool* fin = &fin2;

	
	

public:
	string playerNameC;
	
	Client2(string s);
	Client2();
	void winSockInit();
	void connectServer();
	void update();
	

	~Client2();
};

