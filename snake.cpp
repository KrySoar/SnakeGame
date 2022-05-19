#include "snake.hpp"
#include "constvars.hpp"

Snake::Snake()
{
	snakeHead.setPosition(sf::Vector2f(WIN_WIDTH/2.0f,WIN_HEIGHT/2.0f));
	snakeHead.setColor(sf::Color(50,200,50));

	snakeBody.push_back(&snakeHead);
}

void Snake::move(char direction)//(U)p (D)own (L)eft (R)ight
{

	switch(direction)
	{
		case 'U':
			snakeHead.move('U');
			break;

		case 'D':
			snakeHead.move('D');
			break;

		case 'L':
			snakeHead.move('L');
			break;

		case 'R':
			snakeHead.move('R');
			break;
	
		default:
			break;
	}
	//for each frame,set the new bodypart position
	//to the last position of the bodypart ahead
	for(int i = 0;i<snakeBody.size();i++)
		if(i != 0)//exclude the head
			snakeBody[i]->setPosition(snakeBody[i-1]->getLastPosition());

}

void Snake::draw(sf::RenderWindow *win)
{
	for(BodyPart *bp : snakeBody)
		bp->draw(win);
}

sf::Vector2f Snake::getPosition()
{
	return snakeHead.getPosition();
}

void Snake::setPosition(sf::Vector2f newPos)
{
	return snakeHead.setPosition(newPos);
}

bool Snake::isSelfColliding()
{
	for(BodyPart* bp : snakeBody )
		if(bp != &snakeHead)
			if(bp->getPosition() == snakeHead.getPosition())
				return true;
	return false;
}

void Snake::operator++(int)
{
	snakeBody.push_back(new BodyPart(snakeBody.back()->getLastPosition()));
}

void Snake::reset()
{
	this->setPosition(sf::Vector2f(WIN_WIDTH/2.0f,WIN_HEIGHT/2.0f));
	//only keep the head and tail
	snakeBody.erase(snakeBody.begin()+2,snakeBody.end());
}
