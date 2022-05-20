#include "fruit.hpp"
#include "constvars.hpp"
#include <SFML/System/Vector2.hpp>
#include <ctime>
#include <cstdlib>

Fruit::Fruit()
{
	fruitShape.setSize(sf::Vector2f(CELL_SIZE,CELL_SIZE));
	this->reset();
	fruitShape.setFillColor(sf::Color::Red);
}

void Fruit::reset()
{
	std::srand(std::time(nullptr));
	float newPosX = std::rand()%(int)(WIN_WIDTH/CELL_SIZE)*CELL_SIZE;
	float newPosY = std::rand()%(int)(WIN_HEIGHT/CELL_SIZE)*CELL_SIZE;
	fruitShape.setPosition(sf::Vector2f(newPosX,newPosY));
	//fruitShape.setPosition(sf::Vector2f(15.0f,15.0f));
}

sf::Vector2f Fruit::getPosition()
{
	return fruitShape.getPosition();
}

void Fruit::draw(sf::RenderWindow &win)
{
	win.draw(fruitShape);
}
