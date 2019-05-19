
#include "IaGUI.h"
#include "MainMenu.h"
#include "BD.h"
//int WIDTH = 800;
//int HEIGHT = 800;
//char turn = '1';
//bool added;
//bool go;


	


void IaGUI::changeTurn() {

	if (turn == '1') { turn = '2'; }
	else if (turn == '2') { turn = '1'; }


}

void IaGUI::paintBoard() {
	mapaxd[7][7]= pintar3(mapaxd);

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++) {
			circle.setTexture(&circleText);
			
			//circle.setPosition(7 + 90 * (i % 7), 7 + 90 * (i / 7));
			circle.setPosition(800 / 7 * i + 20, 800 / 6 * j + 20 + 200);
			if (mapaxd[j + 1][i] == '1') {
				circle.setFillColor(sf::Color::Blue);//blue
				
			}
			else if (mapaxd[j + 1][i] == '2')
				circle.setFillColor(sf::Color::Yellow);//yellow
			else
				circle.setFillColor(sf::Color(138, 138, 138));
			window.draw(circle);
		}

	}
	if (turn == '1')
		turnCircle.setFillColor(cYellow);
	else
		turnCircle.setFillColor(cBlue);

	
	
}

void IaGUI::updateGUI()
{

}

void IaGUI::initGUI()
{
	//sf::RectangleShape board(sf::Vector2f(800, 800));
	board.setSize(sf::Vector2f(800, 800));
	board.setFillColor(sf::Color(61, 68, 86));
	board.setOutlineColor(sf::Color::Black);
	board.setOutlineThickness(5);
	board.setPosition(0, 200);

	//sf::RectangleShape scoreboard(sf::Vector2f(1000, 200));
	scoreboard.setSize(sf::Vector2f(800, 200));
	scoreboard.setFillColor(sf::Color(3, 26, 61));
	scoreboard.setOutlineColor(sf::Color::Black);
	scoreboard.setOutlineThickness(5);
	scoreboard.setPosition(0, 0);


	//sf::RectangleShape panel(sf::Vector2f(400, 1000));
	panel.setSize(sf::Vector2f(400, 1000));
	//panel.setFillColor(sf::Color(3, 26, 61));
	panel.setOutlineColor(sf::Color::Black);
	panel.setOutlineThickness(5);
	panel.setPosition(800, 000);
	panel.setTexture(&backgroundTexture);



	//sf::Text text;
	text.setFont(font);
	text.setString("NUMERO DE COLUMNA");
	text.setCharacterSize(18); // in pixels, not points!
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setPosition(820, 600);

	//sf::Text turnText;
	turnText.setFont(font);
	turnText.setString("TURNO");
	turnText.setCharacterSize(18); // in pixels, not points!
	turnText.setFillColor(sf::Color::White);
	turnText.setStyle(sf::Text::Bold);
	turnText.setPosition(900, 350);

	//sf::Text text2;
	text2.setFont(font);
	text2.setString(" ");
	text2.setCharacterSize(30); // in pixels, not points!
	text2.setFillColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setPosition(925, 650);

	//sf::Text score1;
	score1.setFont(font);
	score1.setString(" ");
	score1.setCharacterSize(50); // in pixels, not points!
	score1.setFillColor(cBlue);
	score1.setOutlineThickness(2);

	score1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	score1.setPosition(330, 60);
	score1.setString(std::to_string(twoscore));
	score1.setOutlineColor(sf::Color::White);

	//sf::Text score2;
	score2.setFont(font);
	score2.setString(" ");
	score2.setCharacterSize(50); // in pixels, not points!
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

	//sf::RectangleShape restart(sf::Vector2f(175, 50));
	restart.setSize(sf::Vector2f(175, 50));
	restart.setFillColor(sf::Color(255, 150, 0));
	restart.setPosition(855, 850);
	restart.setOutlineColor(sf::Color::Black);
	restart.setOutlineThickness(1);

	//sf::Text restartText;
	restartText.setFont(font);
	restartText.setString("Restart");
	restartText.setCharacterSize(35);
	//restartText.setColor(sf::Color::Black);
	restartText.setPosition(875, 850);


	//	/*sf::RectangleShape overlay(sf::Vector2f(630, 630));
	//	overlay.setFillColor(sf::Color(150, 150, 150, 150));
	//*/
	//sf::Text ggText;
	ggText.setFont(font);
	ggText.setCharacterSize(150);
	ggText.setOutlineColor(sf::Color::Magenta);
	ggText.setOutlineThickness(10);
	ggText.setFillColor(sf::Color::Black);

	/*rectWin.setSize(sf::Vector2f(700, 200));
	rectWin.setFillColor(sf::Color(54, 86, 124));
	rectWin.setOutlineColor(sf::Color::Black);
	rectWin.setOutlineThickness(5);
	rectWin.setPosition(200, 000);*/
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

	if (!texture.loadFromFile("Mob0.png"))
	{
		// error...
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
	//for (int i = 1; i < 8; ++i)
	//{
	//	for (int j = 0; j < 7; j++)
	//	{
	//		mapaxd[i][j] = '0';
	//	}
	//}
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
		player2 = "player 2";
	}


	if (!circleText.loadFromFile("sirculo.png"))
	{
		printf("image error");
	}
	circleText.setSmooth(true);


	if (!backgroundTexture.loadFromFile("gradient2.jpg"))
	{
		printf("image error");
	}
	

	
	player1 = playerName;
	//player2 = "PLAYER 2";
	int moveCount = 0;

	char str[3];
	char player[] = "player";
	
	onescore = 0;
	twoscore = 0;

	
	
	settings.antialiasingLevel = 8;
	

	

	//sf::RectangleShape background(sf::Vector2f(800, 800));
	//background.setFillColor(sf::Color(238, 38, 38));
	//font = m->getFont;
	
	if (!font.loadFromFile("SaucerBB.ttf"))
	{
		std::cout << "Failed to load resources.\n\n";
		//window.close;
	}

	
	
	initGUI();

	//char grid[7][6];//SFML //SFML



	crearMapa();
	win = 0;
	added = false;
	go = true;
	moveCount = 0;
	

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
			
			
			//if (moveCount == 42) win = 3;
			if (!movres()) win = 3;
			
			

			if (win == 0 && turn == '1' && go  && mode) {

				
					int prueba = AIManager();
					printf("La prueba ha decidido que se meta en: %i \n", prueba);
					if (prueba != 0) {
						meterFicha2("", player2char, prueba, 0);
					}
					else {
						do { prueba = rand() % 7 + 1; } while (llena(prueba)!=0);
						meterFicha2("", player2char, prueba, 0);
					
					}
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
					if (win == 0 && turn == '1' && n >= 0 && n < 8 && go && !mode && llena(n) == 0)
					{

						/*meterFicha2("Player 1: ", player2char, n, 0);
						moveCount++;*/
						if (n == 0 ) {
							
							if (habPlayer) {
								borrarColumna(rand() % 6);
								habPlayer = false;
								habText2.setOutlineColor(sf::Color::Red);
							}
							else {
								break;
							}
						}
						else {

							meterFicha2("Player 1: ", player2char, n, 0);
							moveCount++;

							//pintar2();
						}

							if (winCheckMapa(2) == 2) {
								//printf("Has tenido suerte \n");
								win = 2;
							}
							//paintBoard();
							/*paintBoard();

							changeTurn();*/
							go = false;
						
					}
					
					if (win == 0 && turn == '2' && n >= 0 && n < 8 && go && llena(n) == 0)
					{

						/*meterFicha2("Player 1: ", player1char, n, 0);
						moveCount++;*/

						if (n == 0) {

							if (habOtro) {
								borrarColumna(rand() % 7 + 1);
								habOtro = false;
								habText1.setOutlineColor(sf::Color::Red);

							}
							else {
								break;
							}
						}
						else {

							meterFicha2("Player 1: ", player1char, n, 0);
							moveCount++;

						}

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
				IaGUI::changeTurn();
				moveCount = 0;

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
					//std::cout << onescore << "\n";
					added = true;
					IaGUI::changeTurn();


				}
				else if (win == 2)
				{
					
					//overlay.setFillColor(sf::Color(255, 255, 0, 150));
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
					//overlay.setFillColor(sf::Color(150, 150, 150, 150));
					ggText.setString("Draw!");
					ggText.setPosition(180, 260);
					added = true;
					IaGUI::changeTurn();


				}
				//window.draw(overlay);

			}
			}

		//}
		//paintBoard();
		if (!go) {
			IaGUI::changeTurn();
			go = true;
		}

	
		window.clear();
		
		window.draw(panel);
		//window.draw(background);
		window.draw(board);
		window.draw(scoreboard);
		window.draw(text);
		window.draw(text2);
		//window.draw(overlay);
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


		IaGUI::paintBoard();
		window.draw(ggText);

		window.draw(p1Text);
		window.draw(p2Text);

		window.draw(sprite);
		window.display();
	
	}


	//return 0;
}


