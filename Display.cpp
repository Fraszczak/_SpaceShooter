#include "pch.h"
#include "Display.h"


int Display::run(sf::RenderWindow &app)
{
	loadFiles(DISPLAY);
	while (is_running)
	{
		text(DISPLAY);

		app.clear();
		app.draw(*sBackground);
		app.draw(get_back);
		app.draw(still_in_progress);
		app.display();
		switch (processEvent(app, DISPLAY))
		{
		case GET_BACK: return 1; break;
		}
	}
	return 0;
}
