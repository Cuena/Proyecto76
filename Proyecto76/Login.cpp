#include "Login.h"
#include "MainMenu.h"
#include "BD.h"
#include <iostream>
#include <fstream>
#include <vector>



Login::Login()
{
	window.create(sf::VideoMode(700, 800), "Login", sf::Style::Close);


	if (!font.loadFromFile("Pixeled.ttf"))
	{
		std::cout << "Failed to load resources.\n\n";
		
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


				}
				else if (event.text.unicode < 128)
				{
					if (selectedLoginItem == 0 && userString.getSize()<10) {
						userString += event.text.unicode;
						inputUserText.setString(userString);
					}

				}
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code) {

				case sf::Keyboard::Enter:
				

					
					if (isPlayer(inputUserText.getString())) {
						printf("Inicio de sesion con cuenta ya existente\n");
						window.close();
						MainMenu(inputUserText.getString());
						
					}
					else {
						printf("Nueva cuenta creada\n");
						insert(inputUserText.getString());
						writePlayer(inputUserText.getString());
						window.close();
						MainMenu(inputUserText.getString());
						
					}


					window.close();

					

					break;

				}
			default:
				break;
			}



		}

		if (selectedLoginItem == 0) {

			userText.setOutlineColor(sf::Color(24, 140, 124));
			userText.setOutlineThickness(5);
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
	loginTitle.setCharacterSize(60);
	loginTitle.setPosition(window.getSize().x / 2.0f - loginTitle.getLocalBounds().width / 2.0f - 5, 100);

	userText.setFont(font);
	userText.setString("USERNAME: ");
	userText.setCharacterSize(25);
	userText.setPosition(window.getSize().x / 2.0f - 30 - 200, window.getSize().y / 2.0f - 100);

	inputUserText.setFont(font);
	inputUserText.setString(" ");
	inputUserText.setCharacterSize(25);
	inputUserText.setPosition(window.getSize().x / 2.0f - 30 + 50, window.getSize().y / 2.0f - 100);

	inputPasswordText.setFont(font);
	inputPasswordText.setString(" ");
	inputPasswordText.setCharacterSize(25);
	inputPasswordText.setPosition(window.getSize().x / 2.0f - 30 + 50, window.getSize().y / 2.0f);



}

void Login::update() {

	
	window.draw(loginTitle);
	window.draw(userText);
	window.draw(inputUserText);

}



bool Login::isPlayer(std::string s)
{

	ifstream file;
	string line;
	file.open("players.txt");
	while (getline(file, line)) {
		if (line == s) { 

			
			return true; 
		}
	}
	return false;
}

void Login::writePlayer(std::string p)
{
	ofstream newFile("players.txt", std::ios_base::app);

	newFile << p << "\n";
}


