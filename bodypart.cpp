#include "bodypart.hpp"
#include "constvars.hpp"

BodyPart::BodyPart()
{
	partShape.setSize(sf::Vector2f(CELL_SIZE,CELL_SIZE));
	partShape.setPosition(sf::Vector2f(500.0f,500.0f));
	partShape.setFillColor(sf::Color(150,255,150));
}

BodyPart::BodyPart(sf::Vector2f position)
{
	partShape.setSize(sf::Vector2f(CELL_SIZE,CELL_SIZE));
	partShape.setPosition(position);
	partShape.setFillColor(sf::Color(150,255,150));
}

void BodyPart::move(char direction)//(U)p (D)own (L)eft (R)ight
{
	lastPosition = partShape.getPosition();
	switch(direction)
	{
		case 'U':
			partShape.move(0,-SNAKE_SPEED);
			
			break;
		case 'D':
			partShape.move(0,SNAKE_SPEED);
			break;

		case 'L':
			partShape.move(-SNAKE_SPEED,0);
			break;

		case 'R':
			partShape.move(SNAKE_SPEED,0);
			break;
	
		default:
			break;
	}
}

void BodyPart::draw(sf::RenderWindow *win)
{
	win->draw(partShape);
}

sf::Vector2f BodyPart::getPosition()
{
	return partShape.getPosition();
}

sf::Vector2f BodyPart::getLastPosition()
{
	return lastPosition;
}
void BodyPart::setPosition(sf::Vector2f newPos)
{
	lastPosition = partShape.getPosition();
	partShape.setPosition(newPos);
}

void BodyPart::setColor(sf::Color newColor)
{
	partShape.setFillColor(newColor);
}
