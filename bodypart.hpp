#pragma once
#include <SFML/Graphics.hpp>
#include "constvars.hpp"

class BodyPart
{
	private:
		sf::RectangleShape partShape;
		sf::Vector2f lastPosition;

	public:
		BodyPart();
		BodyPart(sf::Vector2f position);

		void move(Direction);
		void draw(sf::RenderWindow *win);

		sf::Vector2f getPosition();
		sf::Vector2f getLastPosition();
		void setPosition(sf::Vector2f newPos);
		void setColor(sf::Color);
};
