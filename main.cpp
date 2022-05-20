#include <SFML/Graphics.hpp>
#include "constvars.hpp"
#include "snake.hpp"
#include "fruit.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "SNAKE SFML");
	window.setFramerateLimit(FRAMERATE);
	Snake snake;
	snake.grow();//tail
	Direction snakeDirection = NO_DIRECTION;

	Fruit fruit;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::KeyPressed )
			{
				switch(event.key.code)
				{
					case sf::Keyboard::Up :
						snakeDirection = Up;
						break;
					case sf::Keyboard::Down :
						snakeDirection = Down;
						break;
					case sf::Keyboard::Left :
						snakeDirection = Left;
						break;
					case sf::Keyboard::Right :
						snakeDirection = Right;
						break;
					default:
						break;
				}
			}
		}

		//Screen border collision

		if(snake.getPosition().x > WIN_WIDTH
				|| snake.getPosition().x < 0
				|| snake.getPosition().y > WIN_HEIGHT
				|| snake.getPosition().y < 0)
		{
			snake.reset();
			fruit.reset();
			snakeDirection = NO_DIRECTION;
		}

		snake.move(snakeDirection);

		if(snake.isSelfColliding()
				&& snakeDirection != NO_DIRECTION )
		{
			snake.reset();
			fruit.reset();
			snakeDirection = NO_DIRECTION;
		}

		if(snake.getPosition() == fruit.getPosition())
		{
			snake.grow();
			fruit.reset();
		}

		window.clear();

		snake.draw(window);
		fruit.draw(window);

		window.display();
	}

	return 0;
}
