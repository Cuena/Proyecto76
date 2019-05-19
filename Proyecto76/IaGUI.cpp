
#include "IaGUI.h"
#include "MainMenu.h"
#include "BD.h"
#include <cctype>


//Con esta clase se gestionan los modos vs jugador y vs IA	



void IaGUI::changeTurn() {

	if (turn == '1') { turn = '2'; }
	else if (turn == '2') { turn = '1'; }


}

//pinta los circulos en el tablero
void IaGUI::paintBoard() {
	mapaxd[7][7]= pintar3(mapaxd);

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++) {
			circle.setTexture(&circleText);
			
			//circle.setPosition(7 + 90 * (i % 7), 7 + 90 * (i / 7));
			circle.setPosition(800 / 7 * i + 20, 800 / 6 * j + 20 + 200);
			if (mapaxd[j + 1][i] == '1') {
				circle.setFillColor(cBlue);//blue
				
			}
			else if (mapaxd[j + 1][i] == '2')
				circle.setFillColor(cYellow);//yellow
			else
				circle.setFillColor(sf::Color(104, 122, 130));
			window.draw(circle);
		}

	}
	if (turn == '1')
		turnCircle.setFillColor(cYellow);
	else
		turnCircle.setFillColor(cBlue);

	
	
}

//inicializacion de componentes
void IaGUI::initGUI()
{
	
	board.setSize(sf::Vector2f(800, 800));
	board.setFillColor(sf::Color(61, 68, 86));
	board.setOutlineColor(sf::Color::Black);
	board.setOutlineThickness(5);
	board.setPosition(0, 200);

	
	scoreboard.setSize(sf::Vector2f(800, 200));
	scoreboard.setFillColor(sf::Color(3, 26, 61));
	scoreboard.setOutlineColor(sf::Color::Black);
	scoreboard.setOutlineThickness(5);
	scoreboard.setPosition(0, 0);


	
	panel.setSize(sf::Vector2f(400, 1000));
	panel.setOutlineColor(sf::Color::Black);
	panel.setOutlineThickness(5);
	panel.setPosition(800, 000);
	panel.setTexture(&backgroundTexture);




	text.setFont(font);
	text.setString("NUMERO DE COLUMNA");
	text.setCharacterSize(18); 
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setPosition(820, 600);

	
	turnText.setFont(font);
	turnText.setString("TURNO");
	turnText.setCharacterSize(18);
	turnText.setFillColor(sf::Color::White);
	turnText.setStyle(sf::Text::Bold);
	turnText.setPosition(900, 350);

	
	text2.setFont(font);
	text2.setString(" ");
	text2.setCharacterSize(30); 
	text2.setFillColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setPosition(925, 650);

	
	score1.setFont(font);
	score1.setString(" ");
	score1.setCharacterSize(50); 
	score1.setFillColor(cBlue);
	score1.setOutlineThickness(2);
	score1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	score1.setPosition(330, 60);
	score1.setString(std::to_string(twoscore));
	score1.setOutlineColor(sf::Color::White);


	score2.setFont(font);
	score2.setString(" ");
	score2.setCharacterSize(50); 
	score2.setFillColor(cYellow);
	score2.setOutlineThickness(2);
	score2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	score2.setPosition(430, 60);
	score2.setString(std::to_string(onescore));
	score2.setOutlineColor(sf::Color::Black);


	circle.setRadius(38);
	circle.setPointCount(300);
	circle.setOutlineThickness(-3);
	circle.setOutlineColor(sf::Color::Black);


	turnCircle.setRadius(38);
	turnCircle.setPointCount(300);
	turnCircle.setOutlineThickness(-3);
	turnCircle.setOutlineColor(sf::Color::Black);
	turnCircle.setPosition(895, 400);

	
	restart.setSize(sf::Vector2f(175, 50));
	restart.setFillColor(sf::Color(255, 150, 0));
	restart.setPosition(855, 850);
	restart.setOutlineColor(sf::Color::Black);
	restart.setOutlineThickness(1);


	restartText.setFont(font);
	restartText.setString("Restart");
	restartText.setCharacterSize(35);
	restartText.setPosition(875, 850);



	ggText.setFont(font);
	ggText.setCharacterSize(150);
	ggText.setOutlineColor(sf::Color::Magenta);
	ggText.setOutlineThickness(10);
	ggText.setFillColor(sf::Color::Black);


	p1Text.setFont(font);
	p1Text.setString(player1);
	p1Text.setCharacterSize(32); 
	p1Text.setFillColor(sf::Color::White);
	p1Text.setStyle(sf::Text::Bold);
	p1Text.setPosition(145, 80);

	p2Text.setFont(font);
	p2Text.setString(player2);
	p2Text.setCharacterSize(32);
	p2Text.setFillColor(sf::Color::White);
	p2Text.setStyle(sf::Text::Bold);
	p2Text.setPosition(550, 80);

	habText1.setFont(font);
	habText1.setString("0: SKILL");
	habText1.setCharacterSize(18);
	habText1.setFillColor(sf::Color::White);
	habText1.setStyle(sf::Text::Bold);
	habText1.setPosition(140, 60);
	habText1.setOutlineColor(sf::Color::Green);
	habText1.setOutlineThickness(1);

	habText2.setFont(font);
	habText2.setString("0: SKILL");
	habText2.setCharacterSize(18);
	habText2.setFillColor(sf::Color::White);
	habText2.setStyle(sf::Text::Bold);
	habText2.setPosition(560, 60);
	habText2.setOutlineColor(sf::Color::Green);
	habText2.setOutlineThickness(1);


	columnsText.setFont(font);
	columnsText.setString("1          2           3           4          5           6          7");
	columnsText.setCharacterSize(32);
	columnsText.setFillColor(sf::Color::White);
	columnsText.setStyle(sf::Text::Bold);
	columnsText.setPosition(50, 155);

	colRect.setSize(sf::Vector2f(95,777));
	//colRect.setOutlineColor(sf::Color::Red);
	colRect.setOutlineThickness(2);
	colRect.setFillColor(sf::Color::Transparent);

	if (!texture.loadFromFile("Mob0.png"))
	{

		std::cout << "Error al cargar la textura" << std::endl;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setPosition(895, 90);
	sprite.setScale(sf::Vector2f(4.f, 4.f));

}


IaGUI::IaGUI(bool mode,std::string s)
{
	window.create(sf::VideoMode(1075, 1000), "Game", sf::Style::Close, settings);
	bool habPlayer = true;
	bool habOtro = true;
	playerName = s;

	cBlue.r = 37;
	cBlue.g = 91;
	cBlue.b = 178;

	cYellow.r = 214;
	cYellow.g = 209;
	cYellow.b = 7;

	if (mode) {
		player2 = "MOB0";
	}
	else {
		player2 = "Player 2";
	}


	/*if (!circleText.loadFromFile("sirculo2.png"))
	{
		printf("image error");
	}
	circleText.setSmooth(true);*/


	if (!backgroundTexture.loadFromFile("gradient2.jpg"))
	{
		printf("image error");
	}
	

	
	player1 = playerName;
	int moveCount = 0;

	char str[3];
	char player[] = "player";
	
	onescore = 0;
	twoscore = 0;

	
	
	settings.antialiasingLevel = 8;
	


	if (!font.loadFromFile("SaucerBB.ttf"))
	{
		std::cout << "Failed to load resources.\n\n";
	
	}

	
	
	initGUI();





	crearMapa();
	win = 0;
	added = false;
	go = true;
	moveCount = 0;
	



	window.setKeyRepeatEnabled(false);

	//hilo principal de la ventana que gestiona el juego y los eventos de SFML (click, intro, input de teclado)

	//usamos los metodos del modulo c para manejar el array 7x6
	//meter ficha, comprobar si la columna está llena, vaciar columna, mirar si hay 4 en raya

	//cuando termina una partida se guarda el resultado en la BD del jugador que ha iniciado sesion
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			
		
			if (!movres()) win = 3;
			
			if (habPlayer) habText1.setOutlineColor(sf::Color::Green);
			else habText1.setOutlineColor(sf::Color::Red);

			if (habOtro) habText2.setOutlineColor(sf::Color::Green);
			else habText2.setOutlineColor(sf::Color::Red);

			if (text2.getString() == "1") colRect.setPosition(10, 210);
			else if (text2.getString() == "2") colRect.setPosition(125, 210);
			else if (text2.getString() == "3") colRect.setPosition(240, 210);
			else if (text2.getString() == "4") colRect.setPosition(355, 210);
			else if (text2.getString() == "5") colRect.setPosition(466, 210);
			else if (text2.getString() == "6") colRect.setPosition(579, 210);
			else if (text2.getString() == "7") colRect.setPosition(694, 210);
			else colRect.setPosition(1000, 1100);

			 

			if (win == 0 && turn == '1' && go  && mode) {

					//llamada al algoritmo de la IA
					int prueba = AIManager();
					printf("La prueba ha decidido que se meta en: %i \n", prueba);
					if (prueba != 0) {
						meterFicha2("", player2char, prueba, 0);
					}
					else { //en caso de que suceda el bug de la ia se pone en una columna random
						do { prueba = rand() % 7 + 1; } while (llena(prueba)!=0);
						meterFicha2("", player2char, prueba, 0);
					
					}
				
					
			
			
				if (winCheckMapa(2) == 2) {
					
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
						//n -= 1;
						n = stoi(s);
					}
					catch (const std::exception&)
					{
						printf("columna invalida\n");
					}
				
				
					if (win == 0 && turn == '1' && n >= 0 && n < 8 && go && !mode && llena(n) == 0 && text2.getString() != " ")
					{

						
						if (n == 0 ) {
							
							if (habOtro) {
								borrarColumna(rand() % 6);
								habOtro = false;
								
							}
							else {
								break;
							}
						}
						else {

							meterFicha2("Player 1: ", player2char, n, 0);
							moveCount++;
							text2.setString(" ");
							

						
						}

							if (winCheckMapa(2) == 2) {
								
								win = 2;
							}

							go = false;
						
					}
					
					if (win == 0 && turn == '2' && n >= 0 && n < 8 && go && llena(n) == 0 && text2.getString() != " ")
					{

		
						if (n == 0) {

							if (habPlayer && !mode) {
								borrarColumna(rand() % 7 + 1);
								habPlayer = false;
								

							}
							else {
								break;
							}
						}
						else {

							meterFicha2("Player 1: ", player1char, n, 0);
							moveCount++;
							text2.setString(" ");
							

						}

						

							if (winCheckMapa(1) == 1) {
								
								win = 1;
							}

							go = false;
						
					}


				}
			}
			if (restart.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				crearMapa();
				ggText.setString("");
				win = 0;

				added = false;
				IaGUI::changeTurn();
				moveCount = 0;
				habPlayer = true;
				habOtro = true;

			}
			if (event.type == sf::Event::TextEntered)
			{

				if (std::isdigit(event.text.unicode))
					text2.setString(event.text.unicode);

			}
			
		}

	
		if (win != 0)
		{
			if (!added) {
				if (win == 1)
				{

				
					ggText.setString("Blue Wins!");
					ggText.setPosition(100,400 );
					onescore++;
					if (mode) {

						const char* result = "";
						std::string str;

						str = "UPDATE PLAYER SET WINSIA = WINSIA + 1 WHERE NAME = '";
						str += playerName;
						str += "';";
						result = str.c_str();

						updateBD(result);
					}
					else {
	
						const char* result = "";
						std::string str;

						str = "UPDATE PLAYER SET WINSPVP = WINSPVP + 1 WHERE NAME = '";
						
						str += playerName;
						str += "';";
						result = str.c_str();

						updateBD(result);
					}
					score1.setString(std::to_string(onescore));
				
					added = true;
					IaGUI::changeTurn();


				}
				else if (win == 2)
				{
					
					
					ggText.setString("Yellow Wins!");
					ggText.setPosition(100, 400);
					twoscore++;
					if (mode) {

						const char* result = "";
						std::string str;

						str = "UPDATE PLAYER SET LOSESIA = LOSESIA + 1 WHERE NAME = '";
						str += playerName;
						str += "';";
						result = str.c_str();

						updateBD(result);
					}
					else {

						const char* result = "";
						std::string str;

						str = "UPDATE PLAYER SET LOSESPVP = LOSESPVP + 1 WHERE NAME = '";
						str += playerName;
						str += "';";
						result = str.c_str();

						updateBD(result);
					}
					score2.setString(std::to_string(twoscore));
					added = true;
					IaGUI::changeTurn();


				}
				else
				{
					
					ggText.setString("Draw!");
					ggText.setPosition(180, 260);
					added = true;
					IaGUI::changeTurn();


				}
			

			}
			}

	
		if (!go) {
			IaGUI::changeTurn();
			go = true;
		}

		
		//actualizar ventana
		window.clear();
		
		window.draw(panel);
	
		window.draw(board);
		window.draw(scoreboard);
		window.draw(text);
		window.draw(text2);
		
		window.draw(ggText);

		window.draw(score1);
		window.draw(score2);
		if (!mode) {
			window.draw(habText2);
			window.draw(habText1);
		}
		window.draw(restart);
		window.draw(restartText);
		
		window.draw(turnText);
		window.draw(turnCircle);
		window.draw(columnsText);

		window.draw(colRect);
		IaGUI::paintBoard();
		window.draw(ggText);

		window.draw(p1Text);
		window.draw(p2Text);

		window.draw(sprite);
		window.display();
	
	}


	
}


