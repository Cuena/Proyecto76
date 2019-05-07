
#include "Sfmlcon.h"
//int WIDTH = 800;
//int HEIGHT = 800;
//char turn = '1';
//bool added;
//bool go;





void Sfmlcon::changeTurn() {

	if (turn == '1') { turn = '2'; }
	else if (turn == '2') { turn = '1'; }


}

void Sfmlcon::paintBoard() {
	mapaxd[7][7] = pintar3(mapaxd);

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++) {

			//circle.setPosition(7 + 90 * (i % 7), 7 + 90 * (i / 7));
			circle.setPosition(800 / 7 * i + 20, 800 / 6 * j + 20 + 200);
			if (mapaxd[j + 1][i] == '1')
				circle.setFillColor(sf::Color::Blue);
			else if (mapaxd[j + 1][i] == '2')
				circle.setFillColor(sf::Color::Yellow);
			else
				circle.setFillColor(sf::Color(138, 138, 138));
			window.draw(circle);
		}

	}
	if (turn == '1')
		turnCircle.setFillColor(sf::Color::Yellow);
	else
		turnCircle.setFillColor(sf::Color::Blue);



}


void Sfmlcon::DoStuff(void)
{
	static std::string oldMsg;
	while (!quit)
	{
		sf::Packet packetSend;
		globalMutex.lock();
		packetSend << msgSend;
		globalMutex.unlock();

		socket.send(packetSend);

		std::string msg;
		sf::Packet packetReceive;

		socket.receive(packetReceive);
		if ((packetReceive >> msg) && oldMsg != msg && !msg.empty())
		{
			std::cout << msg << std::endl;
			oldMsg = msg;
		}
	}
}

void Sfmlcon::Server(void)
{
	sf::TcpListener listener;
	listener.listen(PORT);
	listener.accept(socket);
	std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
}

bool Sfmlcon::Client(void)
{
	if (socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
	{
		std::cout << "Connected\n";
		return true;
	}
	return false;
}

void Sfmlcon::GetInput(void)
{
	std::string s;
	std::cout << "\nEnter \"exit\" to quit or message to send: ";
	getline(std::cin, s);
	if (s == "exit")
		quit = true;
	globalMutex.lock();
	msgSend = s;
	globalMutex.unlock();
}






Sfmlcon::Sfmlcon()
{

	//sf::Thread* thread = 0;

	char who;
	std::cout << "Do you want to be a server (s) or a client (c) ? ";
	std::cin >> who;
	if (who == 's')
		Server();
	else
		Client();

	/*sf::Thread thread(&DoStuff);
	thread.launch();*/


	window.create(sf::VideoMode(1200, 1000), "Connect 4", sf::Style::Close, settings);

	//for (int i = 1; i < 8; ++i)
	//{
	//	for (int j = 0; j < 7; j++)
	//	{
	//		mapaxd[i][j] = '0';
	//	}
	//}



	int moveCount = 0;

	char str[3];
	char player[] = "player";

	onescore = 0;
	twoscore = 0;


	settings.antialiasingLevel = 8;




	//sf::RectangleShape background(sf::Vector2f(800, 800));
	//background.setFillColor(sf::Color(238, 38, 38));

	sf::Font font;
	if (!font.loadFromFile("SaucerBB.ttf"))
	{
		std::cout << "Failed to load resources.\n\n";
		//window.close;
	}


	sf::RectangleShape board(sf::Vector2f(800, 800));
	board.setFillColor(sf::Color(150, 150, 255));
	board.setOutlineColor(sf::Color::Black);
	board.setOutlineThickness(5);
	board.setPosition(0, 200);

	sf::RectangleShape scoreboard(sf::Vector2f(1000, 200));
	scoreboard.setFillColor(sf::Color(54, 86, 124));
	scoreboard.setOutlineColor(sf::Color::Black);
	scoreboard.setOutlineThickness(5);
	scoreboard.setPosition(0, 0);


	sf::RectangleShape panel(sf::Vector2f(400, 1000));
	panel.setFillColor(sf::Color(54, 86, 124));
	panel.setOutlineColor(sf::Color::Black);
	panel.setOutlineThickness(5);
	panel.setPosition(800, 000);

	sf::Text text;
	text.setFont(font);
	text.setString("NUMERO DE COLUMNA");
	text.setCharacterSize(18); // in pixels, not points!
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setPosition(882, 600);

	sf::Text turnText;
	turnText.setFont(font);
	turnText.setString("TURNO");
	turnText.setCharacterSize(18); // in pixels, not points!
	turnText.setFillColor(sf::Color::White);
	turnText.setStyle(sf::Text::Bold);
	turnText.setPosition(950, 350);

	sf::Text text2;
	text2.setFont(font);
	text2.setString(" ");
	text2.setCharacterSize(30); // in pixels, not points!
	text2.setFillColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setPosition(1000, 650);

	sf::Text score1;
	score1.setFont(font);
	score1.setString(" ");
	score1.setCharacterSize(50); // in pixels, not points!
	score1.setFillColor(sf::Color::Blue);
	score1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	score1.setPosition(350, 100);
	score1.setString(std::to_string(twoscore));

	sf::Text score2;
	score2.setFont(font);
	score2.setString(" ");
	score2.setCharacterSize(50); // in pixels, not points!
	score2.setFillColor(sf::Color::Yellow);
	score2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	score2.setPosition(450, 100);
	score2.setString(std::to_string(onescore));


	circle.setRadius(38);
	circle.setPointCount(300);
	circle.setOutlineThickness(-3);
	circle.setOutlineColor(sf::Color::Black);


	turnCircle.setRadius(38);
	turnCircle.setPointCount(300);
	turnCircle.setOutlineThickness(-3);
	turnCircle.setOutlineColor(sf::Color::Black);
	turnCircle.setPosition(950, 400);

	sf::RectangleShape restart(sf::Vector2f(175, 50));
	restart.setFillColor(sf::Color(255, 150, 0));
	restart.setPosition(920, 850);
	restart.setOutlineColor(sf::Color::Black);
	restart.setOutlineThickness(1);
	sf::Text restartText;
	restartText.setFont(font);
	restartText.setString("Restart");
	restartText.setCharacterSize(35);
	//restartText.setColor(sf::Color::Black);
	restartText.setPosition(940, 850);


	//	/*sf::RectangleShape overlay(sf::Vector2f(630, 630));
	//	overlay.setFillColor(sf::Color(150, 150, 150, 150));
	//*/
	sf::Text ggText;
	ggText.setFont(font);
	ggText.setCharacterSize(100);
	ggText.setFillColor(sf::Color::Black);

	//char grid[7][6];//SFML //SFML



	crearMapa();
	win = 0;
	added = false;
	go = true;


	/*bool tileDropped = false, currentRed = true;
	int column = 0, newTile = 0, hoverTile = 0, moveCounter = 0;
	Tile winner = NONE;*/

	window.setKeyRepeatEnabled(false);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();






			if (win == 0 && turn == '1' && go) {


				int prueba = AIManager();
				//printf("La prueba ha decidido que se meta en: %i", prueba);
				meterFicha2("", player2char, prueba, 0);
				//pintar2();



				if (winCheckMapa(2) == 2) {
					//printf("No eres un reto \n");
					win = 2;
				}

				go = false;

			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Enter)
				{

					try
					{
						s = text2.getString();
						n -= 1;
						n = stoi(s);
					}
					catch (const std::exception&)
					{

					}

					//meterFicha2("Player 2: ", player2char);
					if (win == 0 && turn == '1' && n > 0 && n < 8 && go && llena(n) == 0)
					{

						meterFicha2("Player 1: ", player2char, n, 0);

						//pintar2();


						if (winCheckMapa(2) == 2) {
							//printf("Has tenido suerte \n");
							win = 2;
						}
						//paintBoard();
						/*paintBoard();

						changeTurn();*/
						go = false;
					}

					if (win == 0 && turn == '2' && n > 0 && n < 8 && go && llena(n) == 0)
					{

						meterFicha2("Player 1: ", player1char, n, 0);

						//pintar2();

						if (winCheckMapa(1) == 1) {
							//printf("Has tenido suerte \n");
							win = 1;
						}
						//paintBoard();
						/*paintBoard();

						changeTurn();*/
						go = false;
					}


				}
			}
			if (restart.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				crearMapa();
				ggText.setString("");
				win = 0;
				/*moveCounter = 0;
				winner = NONE;*/
				added = false;
				Sfmlcon::changeTurn();

			}
			if (event.type == sf::Event::TextEntered)
			{

				if (event.text.unicode < 128)
					//std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
					text2.setString(event.text.unicode);

			}

		}


		if (win != 0)
		{
			if (!added) {
				if (win == 1)
				{

					//overlay.setFillColor(sf::Color(255, 0, 0, 150));
					ggText.setString("Blue Wins!");
					ggText.setPosition(90, 0);
					onescore++;
					score1.setString(std::to_string(onescore));
					//std::cout << onescore << "\n";
					added = true;
					Sfmlcon::changeTurn();


				}
				else if (win == 2)
				{

					//overlay.setFillColor(sf::Color(255, 255, 0, 150));
					ggText.setString("Yellow Wins!");
					ggText.setPosition(90, 0);
					twoscore++;
					score2.setString(std::to_string(twoscore));
					added = true;
					Sfmlcon::changeTurn();


				}
				else
				{
					//overlay.setFillColor(sf::Color(150, 150, 150, 150));
					ggText.setString("Draw!");
					ggText.setPosition(180, 260);
					added = true;
					Sfmlcon::changeTurn();


				}
				//window.draw(overlay);

			}
		}

		//}
		//paintBoard();
		if (!go) {
			Sfmlcon::changeTurn();
			go = true;
		}

		window.clear();
		window.draw(scoreboard);
		window.draw(panel);
		//window.draw(background);
		window.draw(board);

		window.draw(text);
		window.draw(text2);
		//window.draw(overlay);
		window.draw(ggText);

		window.draw(score1);
		window.draw(score2);
		window.draw(restart);
		window.draw(restartText);
		window.draw(ggText);
		window.draw(turnText);
		window.draw(turnCircle);


		Sfmlcon::paintBoard();



		window.display();

	}


	//return 0;
}


