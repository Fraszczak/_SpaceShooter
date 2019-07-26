#pragma once
#include "Entity.h"

class Laser :
	public Entity
{
public:
	Laser(Animation &animation, float x, float y);

	virtual void	update(sf::Time &time);
};

