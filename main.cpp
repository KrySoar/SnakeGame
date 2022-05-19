#include <SFML/Graphics.hpp>
#include "constvars.hpp"
#include "snake.hpp"
#include "fruit.hpp"

#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "SNAKE SFML");
	window.setFramerateLimit(FRAMERATE);
	Snake snake;
	snake++;//tail
	char snakeDirection = 0;

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
						snakeDirection = 'U';
						break;
					case sf::Keyboard::Down :
						snakeDirection = 'D';
						break;
					case sf::Keyboard::Left :
						snakeDirection = 'L';
						break;
					case sf::Keyboard::Right :
						snakeDirection = 'R';
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
		}
	    
		/*////////EASY MODE/////NO SCREEN BORDER///////////////  
		// 
		if(snake.getPosition().x > WIN_WIDTH)
			snake.setPosition(sf::Vector2f(0,snake.getPosition().y));
		if(snake.getPosition().x < 0)
			snake.setPosition(sf::Vector2f(WIN_WIDTH,snake.getPosition().y));
		if(snake.getPosition().y > WIN_HEIGHT)
			snake.setPosition(sf::Vector2f(snake.getPosition().x,0));
		if(snake.getPosition().y < 0)
			snake.setPosition(sf::Vector2f(snake.getPosition().x,WIN_HEIGHT));
	    *//////////////////////////////////////////////////////

		snake.move(snakeDirection);

		if(snake.isSelfColliding() && snakeDirection != 0)
		{
			snake.reset();
			fruit.reset();
		}

		if(snake.getPosition() == fruit.getPosition())
		{
			snake++;
			fruit.reset();
		}

        window.clear();

		snake.draw(&window);
		fruit.draw(&window);

        window.display();
    }

    return 0;
}
