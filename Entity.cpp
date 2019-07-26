#include "pch.h"
#include "Entity.h"
#include "Animation.h"


Entity::Entity(Animation &animation, float x, float y)
{
	this->animation = animation;
	this->x = x;
	this->y = y;

	this->life = true;
	
}

void Entity::draw(sf::RenderWindow &app)
{
	animation.animation_sprite.setPosition(x, y);
	app.draw(animation.animation_sprite);
}

bool Entity::getLife()
{
	return this->life;
}

void Entity::setLife(bool life)
{
	this->life = life;
}

void Entity::kill()
{
	this->life = false;
}

bool Entity::isKilled()
{
	if (this->life == true)
		return false;

	return true;
}

std::string Entity::getName()
{
	return this->name;
}

void Entity::setName(std::string name)
{
	this->name = name;
}

float Entity::getX()
{
	return this->x;
}

float Entity::getY()
{
	return this->y;
}

void Entity::animationUpdate()
{
	animation.update();
}

bool Entity::animationIsEnd()
{
	return animation.isEnd();
}

Animation Entity::getAnimation()
{
	return this->animation;
}
