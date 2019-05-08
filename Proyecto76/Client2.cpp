#include "Client2.h"





Client2::Client2()
{
	int contador = 0;
	connectServer();

	int pri = 1;
	auto f = [](SOCKET sock, char buf[4096], char* jugador, bool* toca) {

		int pri = 1;
		
		while (true) {

			int bytesRecieved = recv(sock, buf, 4096, 0);

			if (bytesRecieved > 0) {

				//Echo response to console
				if (pri == 1) {
					std::cout << "SERVER> " << std::string(buf, 0, bytesRecieved) << "\n" << std::endl;
					char a = std::string(buf, 0, bytesRecieved).at(0);
					jugador = &a;
					if (*jugador == '1') {
					
						*toca=true;
					}
					pri = 0;
				}

				else {
					std::cout << std::string(buf, 0, bytesRecieved).at(0) << "\n" << std::endl;
				
					if (*jugador == '1'&&*toca) {
						meterFicha2("", player1char, std::string(buf, 0, bytesRecieved).at(0) - '0', 0);
						*toca = false;

						
					}
					else if (*jugador =='2' &&!*toca){
						meterFicha2("", player1char, std::string(buf, 0, bytesRecieved).at(0) - '0', 0);
						*toca = true;
					}
					else if (*jugador == '2' && *toca) {
						meterFicha2("", player2char, std::string(buf, 0, bytesRecieved).at(0) - '0', 0);
						*toca = false;
					}
					else if (*jugador == '1' && !*toca) {
						meterFicha2("", player2char, std::string(buf, 0, bytesRecieved).at(0) - '0', 0);
						*toca = true;
					}
					pintar2();

					if (winCheckMapa(1) == 1) {

						printf("HA GANADO EL JUGADOR 1");
						system("pause");
						exit(0);
					}

					if (winCheckMapa(2) == 2) {

						printf("HA GANADO EL JUGADOR 2");
						system("pause");
						
						exit(0);
					}

				}


			}
		}

	};


	


	std::thread t{ f,sock,buf,jugador,toca };
	//int bytesRecieved = recv(sock, buf, 4096, 0);

	crearMapa();
	pintar2();

	//if (bytesRecieved > 0) {

	//	//Echo response to console

	//	std::cout << "SERVER> " << std::string(buf, 0, bytesRecieved) << std::endl;

	//}
	

	do {




	

		getline(std::cin, userInput);
		if(*toca)
		int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
			
		
		
		
		//if (sendResult != SOCKET_ERROR) {
		//	//wait for response
		//	ZeroMemory(buf, 4096);
		//	int bytesRecieved = recv(sock, buf, 4096, 0);

		//	if (bytesRecieved > 0) {

		//		//Echo response to console
		//		
		//		std::cout << "SERVER> " << std::string(buf, 0, bytesRecieved) << std::endl;
		//		
		//	}

		//}

	} while (userInput.size() > 0);

	//gracefully cole down everything
	closesocket(sock);
	WSACleanup();

}





void Client2::winSockInit()
{
	ver = MAKEWORD(2, 2);

	int wsResult = WSAStartup(ver, &data);

	if (wsResult != 0) {
		printf("no muy skere");

	}


}


void Client2::connectServer()
{
	winSockInit();

	//create the socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {

		printf("no skerea");
		WSACleanup();
		return;
	}

	//fill in a hint structure

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));

	if (connResult == SOCKET_ERROR) {
		printf("mierda");
		closesocket(sock);
		WSACleanup();
		return;
	}


}


Client2::~Client2()
{
}