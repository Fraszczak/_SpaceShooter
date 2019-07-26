#include "pch.h"
#include "Meteors.h"

Meteors::Meteors(Animation &animation, float x, float y) : Entity::Entity(animation, x, y)
{
	this->name = "Meteor";
}

void Meteors::update(sf::Time &t)
{
	srand(time(NULL));
	float speed = rand() % 30 + 15;
	
	y += (speed * t.asSeconds());
	
	if (x > 800 || x < 0 || y > 1200 || y < 0)
	{
		life = false;
	}
	
}