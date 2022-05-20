#include "snake.hpp"

Snake::Snake()
{
	BodyPart snakeHead;
	snakeHead.setPosition(sf::Vector2f(WIN_WIDTH/2.0f,WIN_HEIGHT/2.0f));
	snakeHead.setColor(sf::Color(50,200,50));

	snakeBody.push_back(snakeHead);
}

void Snake::move(Direction dir)
{

	switch(dir)
	{
		case Up:
			snakeBody.front().move(Up);
			break;

		case Down:
			snakeBody.front().move(Down);
			break;

		case Left:
			snakeBody.front().move(Left);
			break;

		case Right:
			snakeBody.front().move(Right);
			break;
	
		default:
			break;
	}
	//for each frame,set the new bodypart position
	//to the last position of the bodypart ahead
	//i = 1 to exclude the head
	for(int i = 1;i<snakeBody.size();i++)
		snakeBody[i].setPosition(snakeBody[i-1].getLastPosition());
}


void Snake::draw(sf::RenderWindow *win)
{
	for(BodyPart bp : snakeBody)
		bp.draw(win);
}

sf::Vector2f Snake::getPosition()
{
	return snakeBody[0].getPosition();
}

void Snake::setPosition(sf::Vector2f newPos)
{
	snakeBody[0].setPosition(newPos);
}

bool Snake::isSelfColliding()
{
	//i = 1 to exclude the head
	for(int i = 1;i < snakeBody.size();i++ )
		if(snakeBody[i].getPosition() == snakeBody[0].getPosition())
			return true;
	return false;
}

void Snake::grow()
{
	BodyPart newBodyPart(snakeBody.back().getLastPosition());
	snakeBody.push_back(newBodyPart); 
}

void Snake::reset()
{
	this->setPosition(sf::Vector2f(WIN_WIDTH/2.0f,WIN_HEIGHT/2.0f));

	//only keep the head and tail
	snakeBody.erase(snakeBody.begin()+2,snakeBody.end());
}
