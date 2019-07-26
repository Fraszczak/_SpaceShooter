#include "pch.h"

#include "Player.h"

Player::Player(Animation &animation, float x, float y) : Entity::Entity(animation, x, y)
{
	this->name = "Player";
}
void Player::update(sf::Time &t)
{
	
	if (movement.x > 100)
	{
		movement.x = 100;
	}
	else if (movement.x < (-100))
		movement.x = (-100);

	if (movement.y > 100)
	{
		movement.y = 100;
	}
	else if (movement.y < (-100))
		movement.y = (-100);

	x += movement.x*t.asSeconds();
	y += movement.y*t.asSeconds();
	
	
	if (Player::x >= 1200)
	{
		x = 0;
		if (movement.x > 0) movement.x -= movement.x*0.5;
		if (movement.x < 0) movement.x += movement.x*0.5;
	}
	else if (Player::x <= 0)
	{
		x = 1200;
		if (movement.x < 0) movement.x -= movement.x*0.5;
		if (movement.x > 0) movement.x += movement.x*0.5;
	}
	else if (Player::y >= 800)
	{
		y = 800; 
		if (movement.y > 0) movement.x -= movement.x*0.5;
		if (movement.y < 0) movement.x += movement.x*0.5;
	}
	else if (Player::y <= 5)
	{
		y = 5;
		if (movement.y > 0) movement.x -= movement.x*0.5;
		if (movement.y < 0) movement.x += movement.x*0.5;
	}

}
void Player::moving(int direction)
{
	if (direction == down)
	{
		movement.y += 50;
	}
	else if (direction == up)
	{
		movement.y -= 50;
	}
	else if (direction == right)
	{
		movement.x += 50;
	}  
	else if (direction == left)
	{
		movement.x -= 50;
	}
}
sf::Vector2f Player::getPossition()
{
	this->possition.x = this->x;
	this->possition.y = this->y;
	
	return possition;
}

