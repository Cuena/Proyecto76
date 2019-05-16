#include "Options.h"




Options::Options()
{
	window.create(sf::VideoMode(700, 800), "Options", sf::Style::Close);
	selectedOptionsItem = 0;
	mode = 0;
	

	if (!font.loadFromFile("SaucerBB.ttf"))
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
			//leaderboardText.setOutlineThickness(0);
			playText.setOutlineThickness(0);
		}
		else if (selectedOptionsItem == 45345) {
			//leaderboardText.setOutlineColor(sf::Color(24, 140, 124));
			//leaderboardText.setOutlineThickness(5);
			musicText.setOutlineThickness(0);
			playText.setOutlineThickness(0);
		}

		else if (selectedOptionsItem == 1) {
			playText.setOutlineColor(sf::Color(24, 140, 124));
			playText.setOutlineThickness(5);
			musicText.setOutlineThickness(0);
			//leaderboardText.setOutlineThickness(0);
		}

		window.clear();
		update();
		window.display();
	}

	
}
//
//Options::Options()
//{
//	printf("me cago en dios");
//}


Options::~Options()
{
}



void Options::initOptions()
{
	optionsTitle.setFont(font);
	optionsTitle.setString("OPTIONS");
	optionsTitle.setCharacterSize(70);
	optionsTitle.setPosition(window.getSize().x / 2.0f - optionsTitle.getLocalBounds().width / 2.0f - 5, 100);

	musicText.setFont(font);
	musicText.setString("Select music");
	musicText.setCharacterSize(40);
	musicText.setPosition(window.getSize().x / 2.0f - 10 - 100, window.getSize().y / 2.0f - 100);

	/*leaderboardText.setFont(font);
	leaderboardText.setString("Leaderboard");
	leaderboardText.setCharacterSize(40);
	leaderboardText.setPosition(window.getSize().x / 2.0f - 10 - 100, window.getSize().y / 2.0f);
*/
	playText.setFont(font);
	playText.setString("Play song");
	playText.setCharacterSize(40);
	playText.setPosition(window.getSize().x / 2.0f - 10 - 100, window.getSize().y / 2.0f);



}

void Options::update()
{
	window.draw(optionsTitle);
	window.draw(musicText);
	//window.draw(leaderboardText);
	window.draw(playText);
}

void Options::openFolder()
{
	char filename[MAX_PATH];
	

	//OPENFILENAME ofn;
	ZeroMemory(&filename, sizeof(filename));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
	//ofn.lpstrFilter = "Text Files\0*.txt\0Any File\0*.*\0";
	ofn.lpstrFilter = "Sound\0 * .WAV\0All\0 * .*\0";
	ofn.lpstrFile = filename;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "Select a File, yo!";
	ofn.Flags = OFN_NOCHANGEDIR | OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST ;

	if (GetOpenFileNameA(&ofn))
	{
		songPath = filename;
		std::cout << "You chose the file \"" << filename << "\"\n";
	
	}
	else
	{
		// All this stuff below is to tell you exactly how you messed up above. 
		// Once you've got that fixed, you can often (not always!) reduce it to a 'user cancelled' assumption.
		switch (CommDlgExtendedError())
		{
		case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
		case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
		case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
		case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
		case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
		case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
		case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
		case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
		case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
		case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
		case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
		case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
		case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
		case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
		case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
		default: std::cout << "You cancelled.\n";
		}
	}

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

	// Display the Open dialog box. 

	if (GetOpenFileName(&ofn) == TRUE) {
		
		//std::cout << "path: " << ofn.lpstrFileTitle;
		songPath = ofn.lpstrFile;

		
	}

}
