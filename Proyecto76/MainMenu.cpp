#include "MainMenu.h"
#include "IaGUI.h"

void runOnlineGUI()
{
	onlineGUI();
}

void runOnlineCMD()
{
	Client2();
}


MainMenu::MainMenu()
{

	window.create(sf::VideoMode(1200, 1000), "Connect 4", sf::Style::Close);



	
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

	menuCircle.setPosition(window.getSize().x / 2 - 80 - 100, window.getSize().y / 2 - 85);
	//menuCircle.setPosition(screenWidth / 2 - getSize().x / 2, screenHeight / 2 - getSize().y / 2);
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

						t1.join();
						t2.join();
					}
					else if (selectedMenuItem == 3) {
						Options();
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

		drawMenuItems();

		window.display();
	}
}



MainMenu::~MainMenu()
{
}

void MainMenu::drawMenuItems()
{
	sf::Font font;
	if (!font.loadFromFile("SaucerBB.ttf"))
	{
		std::cout << "Failed to load resources.\n\n";
		//window.close;
	}
	menuTitle.setFont(font);
	menuTitle.setString("PROJECT 76");
	menuTitle.setCharacterSize(70);
	menuTitle.setPosition(window.getSize().x / 2.0f - menuTitle.getLocalBounds().width / 2.0f - 5, 100);

	menuPlayText.setFont(font);
	menuPlayText.setString("play vs player");
	menuPlayText.setCharacterSize(40);
	menuPlayText.setPosition(window.getSize().x / 2.0f - 10 - 100, window.getSize().y / 2.0f - 100);

	menuPlayIAText.setFont(font);
	menuPlayIAText.setString("play vs IA");
	menuPlayIAText.setCharacterSize(40);
	menuPlayIAText.setPosition(window.getSize().x / 2.0f - 10 - 100, window.getSize().y / 2.0f);

	menuPlayOnlineText.setFont(font);
	menuPlayOnlineText.setString("play online");
	menuPlayOnlineText.setCharacterSize(40);
	menuPlayOnlineText.setPosition(window.getSize().x / 2.0f - 10 - 100, window.getSize().y / 2.0f + 100);

	menuOptionsText.setFont(font);
	menuOptionsText.setString("options");
	menuOptionsText.setCharacterSize(40);
	menuOptionsText.setPosition(window.getSize().x / 2.0f - 10 - 100, window.getSize().y / 2.0f + 200);

	menuQuitText.setFont(font);
	menuQuitText.setString("quit");
	menuQuitText.setCharacterSize(40);
	menuQuitText.setPosition(window.getSize().x / 2.0f - 10 - 100, window.getSize().y / 2.0f + 300);


	if (!backTexture.loadFromFile("background.jpg"))
	{
		// error...
	}
	backTexture.setSmooth(true);
	backSprite.setTexture(backTexture);
	backSprite.setPosition(0,0);
	//backSprite.setScale(sf::Vector2f(2.f, 2.f));

	window.draw(backSprite);
	window.draw(menuTitle);
	window.draw(menuPlayText);
	window.draw(menuOptionsText);
	window.draw(menuPlayIAText);
	window.draw(menuPlayOnlineText);
	window.draw(menuQuitText);
	window.draw(menuCircle);
}



