#pragma once

#include "bodypart.hpp"
#include <vector>

class Snake
{
	private:
		BodyPart snakeHead;
		std::vector<BodyPart*> snakeBody;
		

	public:
		Snake();

		void move(char direction);//(U)p (D)own (L)eft (R)ight

		void draw(sf::RenderWindow *win);

		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f newPos);

		bool isSelfColliding();

		void operator++(int);
		void reset();
};
