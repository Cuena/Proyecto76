#include "Login.h"
#include "MainMenu.h"
#include "BD.h"



Login::Login()
{
	window.create(sf::VideoMode(700, 800), "Connect 4", sf::Style::Close);


	if (!font.loadFromFile("SaucerBB.ttf"))
	{
		std::cout << "Failed to load resources.\n\n";
		//window.close;
	}

	drawLoginItems();

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::TextEntered:

				if (event.text.unicode == '\b') {
					if (selectedLoginItem == 0 && userString.getSize() > 0) {

						try {
							userString.erase(userString.getSize() - 1, 1);
							inputUserText.setString(userString);
						}
						catch (int e) {}

					}
					else if (selectedLoginItem == 1 && passwordString.getSize() > 0) {

						try {
							passwordString.erase(passwordString.getSize() - 1, 1);
							inputPasswordText.setString(passwordString);
						}
						catch (int e) {}

					}

				}
				else if (event.text.unicode < 128)
				{
					if (selectedLoginItem == 0 && userString.getSize()<10) {
						userString += event.text.unicode;
						inputUserText.setString(userString);
					}
					else if (selectedLoginItem == 1 && passwordString.getSize()<10) {
						passwordString += event.text.unicode;
						inputPasswordText.setString(passwordString);
					}
				}
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					if (selectedLoginItem > 0) {
						passwordText.setOutlineColor(sf::Color::Blue);
						selectedLoginItem--;
					}
					break;
				case sf::Keyboard::Enter:
					//login

					window.close();
					MainMenu();

					break;
				case sf::Keyboard::Down:
					if (selectedLoginItem < 1) {

						selectedLoginItem++;

					}
					break;
				default:
					break;
				}
			default:
				break;
			}



		}

		if (selectedLoginItem == 0) {

			userText.setOutlineColor(sf::Color(24, 140, 124));
			userText.setOutlineThickness(5);
			passwordText.setOutlineThickness(0);
		}
		else if (selectedLoginItem == 1) {
			passwordText.setOutlineColor(sf::Color(24, 140, 124));
			passwordText.setOutlineThickness(5);
			userText.setOutlineThickness(0);
		}

		window.clear();

		update();

		window.display();
	}
}


Login::~Login()
{
}

void Login::drawLoginItems()
{
	loginTitle.setFont(font);
	loginTitle.setString("LOGIN");
	loginTitle.setCharacterSize(70);
	loginTitle.setPosition(window.getSize().x / 2.0f - loginTitle.getLocalBounds().width / 2.0f - 5, 100);

	userText.setFont(font);
	userText.setString("Username: ");
	userText.setCharacterSize(40);
	userText.setPosition(window.getSize().x / 2.0f - 10 - 200, window.getSize().y / 2.0f - 100);

	passwordText.setFont(font);
	passwordText.setString("Password: ");
	passwordText.setCharacterSize(40);
	passwordText.setPosition(window.getSize().x / 2.0f - 10 - 200, window.getSize().y / 2.0f);

	inputUserText.setFont(font);
	inputUserText.setString(" ");
	inputUserText.setCharacterSize(40);
	inputUserText.setPosition(window.getSize().x / 2.0f - 10 + 50, window.getSize().y / 2.0f - 100);

	inputPasswordText.setFont(font);
	inputPasswordText.setString(" ");
	inputPasswordText.setCharacterSize(40);
	inputPasswordText.setPosition(window.getSize().x / 2.0f - 10 + 50, window.getSize().y / 2.0f);



}

void Login::update() {


	window.draw(loginTitle);
	window.draw(userText);
	window.draw(passwordText);
	window.draw(inputUserText);
	window.draw(inputPasswordText);

}

