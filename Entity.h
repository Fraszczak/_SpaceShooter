#pragma once
#include "pch.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	Entity(Animation &animation, float x, float y);
	virtual ~Entity() { };

	virtual void	update(sf::Time &t) {};
	void			draw(sf::RenderWindow &app);
	bool			getLife();
	void			setLife(bool);
	void			kill();
	bool			isKilled();
	std::string		getName();
	void			setName(std::string);
	float			getX();
	float			getY();
	void			animationUpdate();
	bool			animationIsEnd();
	Animation		getAnimation();


protected:
	bool life;
	std::string	name;
	float x, y;
	Animation animation;

};

