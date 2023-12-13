#include <SFML/Graphics.hpp>

#include "Config.h"
#include "Calculator.h"

Calculator::Calculator()
	:window(WINDOW_SIZE, "Calculator")
{

	if (!font.loadFromFile("ariblk.ttf"))
	{
		//error
	}
	text.setFont(font);
	text.setString("+");
	
	text.setCharacterSize(24); 
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(10, 10));
	
	
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			sf::RectangleShape btn(buttonSize);
			if (i > 1 && j == 3) {
				btn.setFillColor(colorFillOrangeButton);
				btn.setOutlineColor(colorOutlineOrangeButton);
				btn.setOutlineThickness(tricknessSize/2);
			}
			else {
				btn.setFillColor(colorFillButton);
				btn.setOutlineColor(colorOutlineButton);
				btn.setOutlineThickness(tricknessSize);
			}
			
			btn.setPosition(sf::Vector2f(j * (buttonSize.x+ tricknessSize), 
										i * (buttonSize.y + tricknessSize)));
			keyboard.push_back(btn);
		}
	}
}

void Calculator::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Calculator::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Calculator::update()
{
}

void Calculator::render()
{
	window.clear(colorOutlineButton);
	for (auto i : keyboard) {
		window.draw(i);
	}
	window.draw(text);
	window.display();
}
