//
// Created by Иван Кушнаренко on 22.11.2019.
//

#include "Shapes.h"
#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;
using namespace std;

Ball::Ball(float radius): CircleShape(radius)
{
	setOrigin(radius, radius);
	setRandomSpeed();
}


bool Ball::move(size_t windowWidth, size_t windowHeight) noexcept
{
//	if (getPosition().x <= getRadius() || getPosition().x >= windowWidth - getRadius())
//		speed.x *= -1;
	if (CircleShape::getPosition().x <= -getRadius() || CircleShape::getPosition().x >= windowWidth + getRadius())
	{
		setPosition(windowWidth / 2, windowHeight / 2);
		setRandomSpeed();
		return true;
	}
	if (CircleShape::getPosition().y <= getRadius() || CircleShape::getPosition().y >= windowHeight - getRadius())
		speed.y *= -1;
	setPosition(CircleShape::getPosition() + speed);
	return false;
}

const sf::Vector2f& Ball::getSpeed() const noexcept
{
	return speed;
}

void Ball::setSpeed(const sf::Vector2f &new_speed) noexcept
{
	speed = new_speed;
}

void Ball::setRandomSpeed() noexcept
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, M_2_PI);
	float angle = dis(gen);
	setSpeed(velocity * sf::Vector2f(cos(angle), sin(angle)));
}

bool Ball::touchLeft(const Rectangle &rectangle) const noexcept
{
	return (getPosition().x - getRadius() <= rectangle.getPosition().x + rectangle.getSize().x / 2) &&
			(getPosition().y >= rectangle.getPosition().y - rectangle.getSize().y / 2) &&
			(getPosition().y <= rectangle.getPosition().y + rectangle.getSize().y / 2);
}

bool Ball::touchRight(const Rectangle &rectangle) const noexcept
{
	return (getPosition().x + getRadius() >= rectangle.getPosition().x - rectangle.getSize().x / 2) &&
		   (getPosition().y >= rectangle.getPosition().y - rectangle.getSize().y / 2) &&
		   (getPosition().y <= rectangle.getPosition().y + rectangle.getSize().y / 2);
}

void Ball::bounce() noexcept
{
	speed.x *= -1;
}

Rectangle::Rectangle(const sf::Vector2f &size): RectangleShape(size)
{
	setOrigin(size.x / 2, size.y / 2);
}

Rectangle::Rectangle(float width, float height):Rectangle(sf::Vector2f(width, height))
{}

void Rectangle::move(size_t windowWidth, size_t windowHeight) noexcept
{
	float y = getPosition().y;
	if (Keyboard::isKeyPressed(Keyboard::Down))
		y += velocity;
	if (Keyboard::isKeyPressed(Keyboard::Up))
		y -= velocity;

	float halfHeight = getSize().y / 2;
	if (y <= halfHeight)
		y = halfHeight;
	else if (y > (windowHeight - halfHeight))
		y = windowHeight - halfHeight;

	setPosition(getPosition().x, y);
}


