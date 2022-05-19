#pragma once

#include <SFML/Graphics.hpp>
class Fruit
{
	private:
		sf::RectangleShape fruitShape;

	public:
		Fruit();
		void reset();
		sf::Vector2f getPosition();
		void draw(sf::RenderWindow*);
};
