//
// Created by Иван Кушнаренко on 22.11.2019.
//

#ifndef ARTEM_SHAPES_H
#define ARTEM_SHAPES_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Network/Packet.hpp>

class Rectangle: public sf::RectangleShape
{
public:
	explicit Rectangle(const sf::Vector2f &size);
	Rectangle(float width, float height);
	void move(size_t windowWidth, size_t windowHeight) noexcept;
private:
	const float velocity = 1;
};

class Ball: public sf::CircleShape
{
public:
	explicit Ball(float radius);
	bool move(size_t windowWidth, size_t windowHeight) noexcept;
	const sf::Vector2f& getSpeed() const noexcept;
	void setSpeed(const sf::Vector2f &new_speed) noexcept;
	void setRandomSpeed() noexcept;
	bool touchLeft(const Rectangle &rectangle) const noexcept;
	bool touchRight(const Rectangle &rectangle) const noexcept;
	void bounce() noexcept;
private:
	sf::Vector2f speed;
	const float velocity = 1;

};

#endif //ARTEM_SHAPES_H
