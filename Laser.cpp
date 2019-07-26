#include "pch.h"
#include "Laser.h"

Laser::Laser(Animation &animation, float x, float y) : Entity::Entity(animation, x, y)
{
	this->name = "Laser";
};

void Laser::update(sf::Time &t)
{
	int	laser_speed = 1;

	this->y -= laser_speed;

	if (this->y < 0)	{ this->life = false; }
}


