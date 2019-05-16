#include "MainMenu.h"
#include "IaGUI.h"
#include "Options.h"
#include "BD.h"

void runOnlineGUI()
{
	onlineGUI();
}

void runOnlineCMD()
{
	Client2();
}
void runOptions() {

	Options();
}

MainMenu::MainMenu(std::string s)
{

	window.create(sf::VideoMode(1200, 1000), "Connect 4", sf::Style::Close);
	
	playerName = s;
	cout << s << endl;
	
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

	menuCircle.setRadius(15);
	//menuCircle.setPointCount(300);
	menuCircle.setOutlineThickness(-3);
	menuCircle.setOutlineColor(sf::Color::Black);

	menuCircle.setPosition(window.getSize().x / 2 - 110 - 100, window.getSize().y / 2 - 100);
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
						IaGUI(false);
					}
					else if (selectedMenuItem == 1) {
						IaGUI(true);
					}
					else if (selectedMenuItem == 2) {
						
						thread t1(runOnlineCMD);
						thread t2(runOnlineGUI);
						t1.detach();
						t2.detach();
						
					}
					else if (selectedMenuItem == 3) {

						thread t3(runOptions);
						t3.detach();
						
					}
					else if (selectedMenuItem == 4) {

						exit(0);

					}

					break;

				case sf::Keyboard::Down:
					if (selectedMenuItem < 4) {
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
	
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f((window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5), 75)),
		sf::Vertex(sf::Vector2f((window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5)+560, 75))
	};

	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f((window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5), 180)),
		sf::Vertex(sf::Vector2f((window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5) + 560, 180))
	};


	menuTitle.setFont(font);
	menuTitle.setString("PROJECT 76");
	menuTitle.setCharacterSize(60);
	menuTitle.setPosition((window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5), 100);

	menuPlayText.setFont(font);
	menuPlayText.setString("PLAY VS PLAYER");
	menuPlayText.setCharacterSize(30);
	menuPlayText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f - 100);

	menuPlayIAText.setFont(font);
	menuPlayIAText.setString("PLAY VS IA");
	menuPlayIAText.setCharacterSize(30);
	menuPlayIAText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f);

	menuPlayOnlineText.setFont(font);
	menuPlayOnlineText.setString("PLAY ONLINE");
	menuPlayOnlineText.setCharacterSize(30);
	menuPlayOnlineText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f + 100);

	menuOptionsText.setFont(font);
	menuOptionsText.setString("OPTIONS");
	menuOptionsText.setCharacterSize(30);
	menuOptionsText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f + 200);

	menuQuitText.setFont(font);
	menuQuitText.setString("QUIT");
	menuQuitText.setCharacterSize(30);
	menuQuitText.setPosition(window.getSize().x / 2.0f - 60 - 100, window.getSize().y / 2.0f + 300);


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
	window.draw(backSprite);
	window.draw(line, 2, sf::Lines);
	window.draw(line2, 2, sf::Lines);
	window.draw(menuTitle);
	window.draw(menuPlayText);
	window.draw(menuOptionsText);
	window.draw(menuPlayIAText);
	window.draw(menuPlayOnlineText);
	window.draw(menuQuitText);
	window.draw(menuCircle);
}



