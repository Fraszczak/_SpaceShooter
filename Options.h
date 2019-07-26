#pragma once
#include "WindowControl.h"
#include "WindowsSettings.h"
class Options :
	public WindowControl,
	protected WindowsSettings
{
public:
	Options() {};
	~Options() {};

	int run(sf::RenderWindow &app) override;

};

