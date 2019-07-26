#pragma once
#include "WindowControl.h"
#include "WindowsSettings.h"
#include "Entity.h"
class Play :
	public WindowControl,
	protected WindowsSettings
{
public:
	Play() {};
	~Play() {};

	int run	(sf::RenderWindow &app) override;
	bool areColided(Entity *first_object, Entity *second_object);
	void statistic(short, short, short);




};


