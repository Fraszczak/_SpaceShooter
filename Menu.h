#pragma once
#include "WindowControl.h"
#include "WindowsSettings.h"
class Menu :
	public WindowControl,
	protected WindowsSettings
{
public:
	Menu() {};
	~Menu() {};
	int run(sf::RenderWindow &app) override;
};

