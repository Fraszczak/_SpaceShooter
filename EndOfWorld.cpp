#include "pch.h"
#include "EndOfWorld.h"

EndOfWorld::EndOfWorld(Animation &animation, float x, float y) : Entity::Entity(animation, x, y)
{
	this->name ="EndOfMap";
}

void EndOfWorld::update(sf::Time &t)
{
	int						laser_speed = 1;

	if (y > 50) { this->x += laser_speed; }
	if (y < 50) { this->x -= laser_speed; }

	if (this->x > 1200)	{ this->x = 0; }
	if (this->x < 0)	{ this->x = 1200; }
}

 