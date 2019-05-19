#include "onlineGUI.h"
#include "Client2.h"



onlineGUI::onlineGUI()
{
	window.create(sf::VideoMode(800, 800), "Connect 4", sf::Style::Close);
	circle.setRadius(38);
	circle.setPointCount(300);
	circle.setOutlineThickness(-3);
	circle.setOutlineColor(sf::Color::Black);
	rect.setSize( sf::Vector2f(800, 800));
	rect.setFillColor(sf::Color(54, 86, 124));


	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();
		window.draw(rect);
		pintalo();
		window.display();
	}
}


onlineGUI::~onlineGUI()
{
	
}

void  onlineGUI::pintalo() {

	mapaxd[7][7] = pintar3(mapaxd);

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++) {

			
			circle.setPosition(800 / 7 * i + 20, 800 / 6 * j + 20 );
			if (mapaxd[j + 1][i] == '1')
				circle.setFillColor(sf::Color::Blue);
			else if (mapaxd[j + 1][i] == '2')
				circle.setFillColor(sf::Color::Yellow);
			else
				circle.setFillColor(sf::Color(138, 138, 138));
			window.draw(circle);
		}

	}
}