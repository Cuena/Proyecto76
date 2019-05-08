#include "MainMenu.h"
#include "IaGUI.h"



MainMenu::MainMenu()
{

	window.create(sf::VideoMode(1200, 1000), "Connect 4", sf::Style::Close);


	sf::Music music;
	try {

		(!music.openFromFile("plastic love.wav"));
	}
	catch (int e) {}
		
	music.setVolume(50);
	music.play();
	
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

					break;

				case sf::Keyboard::Down:
					if (selectedMenuItem < 3) {
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

	menuOptionsText.setFont(font);
	menuOptionsText.setString("options");
	menuOptionsText.setCharacterSize(40);
	menuOptionsText.setPosition(window.getSize().x / 2.0f - 10 - 100, window.getSize().y / 2.0f + 100);

	menuQuitText.setFont(font);
	menuQuitText.setString("quit");
	menuQuitText.setCharacterSize(40);
	menuQuitText.setPosition(window.getSize().x / 2.0f - 10 - 100, window.getSize().y / 2.0f + 200);

	window.draw(menuTitle);
	window.draw(menuPlayText);
	window.draw(menuOptionsText);
	window.draw(menuPlayIAText);
	window.draw(menuQuitText);
	window.draw(menuCircle);
}


