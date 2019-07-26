#pragma once
#include "Entity.h"
class EndOfWorld :
	public Entity
{
public:
	EndOfWorld(Animation &animation, float x, float y);

	virtual void update(sf::Time &time);
};
 