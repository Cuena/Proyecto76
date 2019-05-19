#include "Client2.h"
#include "MainMenu.h"




//metodo al cual llama el hilo para recibir datos del servidor
void hola(SOCKET sock, char buf[4096], char* jugador, bool* toca, bool* fin, string name) {

	int pri = 1;




	while (*fin == true) {


		int bytesRecieved = recv(sock, buf, 4096, 0);

		if (bytesRecieved > 0) {

			//Echo response to console
			if (pri == 1) {
				std::cout << "Eres el jugador> " << std::string(buf, 0, bytesRecieved) << "\n" << std::endl;
				char a = std::string(buf, 0, bytesRecieved).at(0);
				jugador = &a;
				if (*jugador == '1') {

					*toca = true;
				}
				pri = 0;
			}

			else {
				std::cout << std::string(buf, 0, bytesRecieved).at(0) << "\n" << std::endl;

				if (*jugador == '1'&&*toca) {
					meterFicha2("", player1char, std::string(buf, 0, bytesRecieved).at(0) - '0', 0);
					if (winCheckMapa(1) == 1) {

						printf("HA GANADO 1\n");
						const char* result2 = "";
						std::string str;

						str = "UPDATE PLAYER SET WINSONLINE = WINSONLINE + 1 WHERE NAME = '";
						str += name;
						str += "';";
						result2 = str.c_str();

						updateBD(result2);
						*fin = false;
					}
					*toca = false;
				}
				else if (*jugador == '2' && !*toca) {
					meterFicha2("", player1char, std::string(buf, 0, bytesRecieved).at(0) - '0', 0);
					*toca = true;
					if (winCheckMapa(1) == 1) {

						printf("HA GANADO 1\n");
						const char* result2 = "";
						std::string str;

						str = "UPDATE PLAYER SET LOSESONLINE = LOSESONLINE + 1 WHERE NAME = '";
						str += name;
						str += "';";
						result2 = str.c_str();

						updateBD(result2);

						*fin = false;
					}
				}
				else if (*jugador == '2' && *toca) {
					meterFicha2("", player2char, std::string(buf, 0, bytesRecieved).at(0) - '0', 0);
					if (winCheckMapa(2) == 2) {

						printf("HA GANADO 2\n");

						const char* result2 = "";
						std::string str;

						str = "UPDATE PLAYER SET WINSONLINE = WINSONLINE + 1 WHERE NAME = '";
						str += name;
						str += "';";
						result2 = str.c_str();

						updateBD(result2);
						*fin = false;
					}
					*toca = false;
				}
				else if (*jugador == '1' && !*toca) {
					meterFicha2("", player2char, std::string(buf, 0, bytesRecieved).at(0) - '0', 0);

					*toca = true;
					if (winCheckMapa(2) == 2) {

						printf("HA GANADO 2\n");

						const char* result2 = "";
						std::string str;

						str = "UPDATE PLAYER SET LOSESONLINE = LOSESONLINE + 1 WHERE NAME = '";
						str += name;
						str += "';";
						result2 = str.c_str();

						updateBD(result2);



						*fin = false;
					}
				}
				pintar2();
				printf("%c\n", *jugador);

			}

		}


	}
}


Client2::Client2(string s)
{
	int contador = 0;
	playerNameC = s;
	connectServer();
	int pri = 1;
	thread t1(hola, sock, buf, jugador, toca, fin, playerNameC);
	t1.detach();
	crearMapa();

	do {


		if (*fin == false) {
			t1.~thread();
			break;
		}

		getline(std::cin, userInput);
		if (userInput == "Exit") {
			*fin = false;
			t1.~thread();
			break;
		}
		//enviar el dato introducido si y solo si es un número del 1 al 8
		if (*toca&&userInput != "" && (userInput.at(0) - '0') < 8 && (userInput.at(0) - '0') > 0) {
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
		}
	} while (true);
	//print que indica que se ha desconectado el cliente del servidor
	printf("Se acabo\n");
	//limpieza de sockets
	closesocket(sock);
	WSACleanup();

}




//Inicializar la libreria winSock
void Client2::winSockInit()
{
	ver = MAKEWORD(2, 2);

	int wsResult = WSAStartup(ver, &data);

	if (wsResult != 0) {
		printf("no muy skere");

	}


}

//crear el socket y "bindearlo" a un puerto y una ip
void Client2::connectServer()
{
	winSockInit();

	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {

		printf("Error al crear el Socket");
		WSACleanup();
		return;
	}

	//"Bindear" el socket

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));

	if (connResult == SOCKET_ERROR) {
		printf("No se ha podido establecer la conexión");
		*fin = false;
		closesocket(sock);
		WSACleanup();
		return;
	}


}


Client2::~Client2()
{
}
