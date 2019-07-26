#include "pch.h"
#include "Explosion.h"


Explosion::Explosion(Animation &animation, float x, float y) : Entity::Entity(animation, x, y)
{
	this->name = "Explosion";
};
