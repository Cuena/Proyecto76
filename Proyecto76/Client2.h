#pragma once
#include "onlineGUI.h"
#include <WS2tcpip.h>
#include <thread>
extern "C" {
#include "Juego76.h"
}
#include <string>
#include <iostream>
#include <sstream>



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



public:
	Client2();
	void winSockInit();
	void connectServer();
	
	

	~Client2();
};

