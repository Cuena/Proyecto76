#include "MainMenu.h"
#include "IaGUI.h"
#include "Options.h"


void runOnlineGUI()
{
	onlineGUI();
}

void runOnlineCMD(string s)
{
	Client2 client(s);//cuidao
}
void runOptions() {

	Options();
}

MainMenu::MainMenu(std::string s)
{

	window.create(sf::VideoMode(1200, 1000), "Main Menu", sf::Style::Close);
	
	
	playerName = s;
	//printf("MENU: %s\n", playerName);
	
	if (!font.loadFromFile("Pixeled.ttf"))
	{
		std::cout << "Failed to load resources.\n\n";
		//window.close;
	}
	
	//try {

	//	(!music.openFromFile("plastic love.wav"));
	//}
	//catch (int e) {}
	//	
	//music.setVolume(50);
	////music.play();

	menuCircle.setRadius(10);
	//menuCircle.setPointCount(300);
	menuCircle.setOutlineThickness(6);
	menuCircle.setOutlineColor(sf::Color(24, 140, 124));

	menuCircle.setPosition(window.getSize().x / 2 - 110 - 100, window.getSize().y / 2 - 100 -50);
	//menuCircle.setPosition(screenWidth / 2 - getSize().x / 2, screenHeight / 2 - getSize().y / 2);
	drawMenuItems();
	
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					if (selectedMenuItem > 0) {
						selectedMenuItem--;
						menuCircle.setPosition(menuCircle.getPosition().x, menuCircle.getPosition().y - 100);
					}

					break;

				case sf::Keyboard::Enter:
					if (selectedMenuItem == 0) {
						IaGUI(false,playerName);
					}
					else if (selectedMenuItem == 1) {
						IaGUI(true,playerName);
					}
					else if (selectedMenuItem == 2) {
						
						thread t1(runOnlineCMD,playerName);
						thread t2(runOnlineGUI);
						t1.detach();
						t2.detach();
						
					}
					else if (selectedMenuItem == 3) {

						

						select(playerName);
						
					}
					else if (selectedMenuItem == 4) {

						thread t3(runOptions);
						t3.detach();
					}
					else if (selectedMenuItem == 4) {

						exit(0);

					}

					break;

				case sf::Keyboard::Down:
					if (selectedMenuItem < 5) {
						selectedMenuItem++;
						menuCircle.setPosition(menuCircle.getPosition().x, menuCircle.getPosition().y + 100);
					}

					break;

				

				default:
					break;
				}

			default:
				break;
			}
		}

		window.clear();

		update();

		window.display();
	}
}



MainMenu::~MainMenu()
{
}

 sf::Font MainMenu::getFont()
{
	 
	return font;
}

void MainMenu::drawMenuItems()
{
	col = rand() % 4 -4;
	



	menuTitle.setFont(font);
	menuTitle.setString("PROJECT 76");
	menuTitle.setCharacterSize(60);
	menuTitle.setPosition((window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5), 100);
	menuTitle.setOutlineColor(sf::Color(24, 140, 124));
	menuTitle.setOutlineThickness(3);

	menuPlayText.setFont(font);
	menuPlayText.setString("PLAY VS PLAYER");
	menuPlayText.setCharacterSize(30);
	menuPlayText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f - 100 - 50);

	menuPlayIAText.setFont(font);
	menuPlayIAText.setString("PLAY VS IA");
	menuPlayIAText.setCharacterSize(30);
	menuPlayIAText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f -50);

	menuPlayOnlineText.setFont(font);
	menuPlayOnlineText.setString("PLAY ONLINE");
	menuPlayOnlineText.setCharacterSize(30);
	menuPlayOnlineText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f + 100 -50);

	statsText.setFont(font);
	statsText.setString("STATS");
	statsText.setCharacterSize(30);
	statsText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f + 200 -50);

	menuOptionsText.setFont(font);
	menuOptionsText.setString("MUSIC");
	menuOptionsText.setCharacterSize(30);
	menuOptionsText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f + 300 -50);

	menuQuitText.setFont(font);
	menuQuitText.setString("QUIT");
	menuQuitText.setCharacterSize(30);
	menuQuitText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f + 400- 50);


	if (!backTexture.loadFromFile("Black.jpg"))
	{
		// error...
	}
	backTexture.setSmooth(true);
	backSprite.setTexture(backTexture);
	backSprite.setPosition(0,0);
	//backSprite.setScale(sf::Vector2f(2.f, 2.f));
	
	
}

void MainMenu::update()
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f((window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5), 75)),
		sf::Vertex(sf::Vector2f((window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5) + 560, 75))
	};

	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f((window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5), 180)),
		sf::Vertex(sf::Vector2f((window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5) + 560, 180))
	};

	window.draw(backSprite);
	window.draw(line, 2, sf::Lines);
	window.draw(line2, 2, sf::Lines);
	window.draw(menuTitle);
	window.draw(menuPlayText);
	window.draw(menuOptionsText);
	window.draw(menuPlayIAText);
	window.draw(menuPlayOnlineText);
	window.draw(statsText);
	window.draw(menuQuitText);
	window.draw(menuCircle);
}



