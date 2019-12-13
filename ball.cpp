//
// Created by Иван Кушнаренко on 24.11.2019.
//

#include "Shapes.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>

using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Ball");

	Ball ball(20);
	ball.setPosition(sf::Vector2f(400, 300));

	Rectangle r(10, 100);
	r.setPosition(5, 300);

	Rectangle r1(10, 600);
	r1.setPosition(795, 300);

	while (window.isOpen())
	{
		sf::Event event{};

		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();
		ball.move(window.getSize().x, window.getSize().y);
		r.move(window.getSize().x, window.getSize().y);

		if (ball.touchLeft(r) ||  ball.touchRight(r1))
			ball.bounce();


		window.clear();
		window.draw(ball);
		window.draw(r);
		window.draw(r1);
		window.display();
	}
	return 0;
}


