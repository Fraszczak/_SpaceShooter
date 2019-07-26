#include "pch.h"
#include <iostream>

#include "Windows.h"

int main(int argc, char** argv)
{
	std::vector<WindowControl *> windows_controler;
	int window = 0;

	//Window creation
	sf::RenderWindow app(sf::VideoMode(window_width, window_height, 32), "SpaceShooter");

	try
	{
		//Object creation
		Menu window_menu;
		windows_controler.push_back(&window_menu);
		Options window_options;
		windows_controler.push_back(&window_options);
		Play window_play;
		windows_controler.push_back(&window_play);
			Display window_display;
			windows_controler.push_back(&window_display);
			Audio window_audio;
			windows_controler.push_back(&window_audio);
		
		//Main loop
		while (window >= 0)
		{
			window = windows_controler[window]->run(app);
		}
	}
	catch (XBoundary ex)
	{
		std::cout << ex.getException();
	}

}
