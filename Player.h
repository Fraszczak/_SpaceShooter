#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player(Animation &animation, float X, float Y);

	virtual void	update(sf::Time &time);
	enum direction  { down, up, right, left };
	void			moving(int);
	sf::Vector2f	getPossition();
private:
	sf::Vector2f	movement{ 0,0 };
	sf::Vector2f	possition{ 0,0 };
};

