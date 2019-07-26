#pragma once
#include "WindowControl.h"
#include "WindowsSettings.h"
class Audio :
	public WindowControl,
	protected WindowsSettings
{
public:
	Audio() {};
	~Audio() {};
	int run(sf::RenderWindow &app) override;
};
