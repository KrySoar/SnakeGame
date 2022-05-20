#pragma once

#include "bodypart.hpp"
#include <vector>

class Snake
{
	private:

		std::vector<BodyPart> snakeBody;
		

	public:
		Snake();

		void move(Direction);

		void draw(sf::RenderWindow *win);

		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f newPos);

		bool isSelfColliding();

		void grow();
		void reset();
};
