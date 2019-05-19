#include "Options.h"




Options::Options()
{
	window.create(sf::VideoMode(700, 800), "Music	", sf::Style::Close);
	selectedOptionsItem = 0;
	mode = 0;
	
	if (!font.loadFromFile("Pixeled.ttf"))
	{
		std::cout << "Failed to load resources.\n\n";
		//window.close;
	}
	
	initOptions();
	

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
					if (selectedOptionsItem > 0) {
						selectedOptionsItem--;
					}
					break;
				case sf::Keyboard::Enter:
					//login
					if (selectedOptionsItem == 0) {
						openFolder2();
					}
					
					else if (selectedOptionsItem == 1) {
					
						try {
							std::cout << "path: " << songPath;
							(!musicOptions.openFromFile(songPath));
						}
						catch (int e) {}

						musicOptions.setVolume(50);
						musicOptions.setLoop(true);
						musicOptions.play();
					}
					
					

					break;
				case sf::Keyboard::Down:
					if (selectedOptionsItem < 1) {

						selectedOptionsItem++;

					}
					break;
				default:
					break;
				}
			default:
				break;
			}



			
		}

		if (selectedOptionsItem == 0) {

			musicText.setOutlineColor(sf::Color(24, 140, 124));
			musicText.setOutlineThickness(5);
			playText.setOutlineThickness(0);
		}else if (selectedOptionsItem == 1) {
			playText.setOutlineColor(sf::Color(24, 140, 124));
			playText.setOutlineThickness(5);
			musicText.setOutlineThickness(0);
		}

		window.clear();
		update();
		window.display();
	}

	
}



Options::~Options()
{
}



void Options::initOptions()
{
	optionsTitle.setFont(font);
	optionsTitle.setString("MUSIC");
	optionsTitle.setCharacterSize(60);
	optionsTitle.setPosition(window.getSize().x / 2.0f - optionsTitle.getLocalBounds().width / 2.0f - 5, 100);

	musicText.setFont(font);
	musicText.setString("Select music");
	musicText.setCharacterSize(25);
	musicText.setPosition(window.getSize().x / 2.0f - 30 - 100, window.getSize().y / 2.0f - 100);


	playText.setFont(font);
	playText.setString("Play song");
	playText.setCharacterSize(25);
	playText.setPosition(window.getSize().x / 2.0f - 30 - 100, window.getSize().y / 2.0f);



}

void Options::update()
{
	window.draw(optionsTitle);
	window.draw(musicText);
	window.draw(playText);
}



void Options::openFolder2()
{

	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	//ofn.hwndOwner = hwnd;
	ofn.lpstrFile = szFile;
	// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	// use the contents of szFile to initialize itself.
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "Sound\0 * .WAV\0All\0 * .*\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_NOCHANGEDIR | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	//Display the Open dialog box. 
	if (GetOpenFileName(&ofn) == TRUE) {
		
		
		songPath = ofn.lpstrFile;

		
	}

}
