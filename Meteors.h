#pragma once
#include "Entity.h"
class Meteors :
	public Entity
{
public:
	Meteors(Animation &animation, float x, float y);

	virtual void	update(sf::Time &time);
};

