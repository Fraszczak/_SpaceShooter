#pragma once
#include "WindowControl.h"
#include "WindowsSettings.h"
class Display :
	public WindowControl,
	protected WindowsSettings
{
public:
	Display() {};
	~Display() {};

	int run(sf::RenderWindow &app) override;
};

