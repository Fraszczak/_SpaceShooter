#include "pch.h"
#include "Options.h"

int Options::run(sf::RenderWindow &app)
{
	loadFiles(OPTIONS);
	while (is_running)
	{
		text(OPTIONS);
		app.clear();
		app.draw(*sBackground);
		app.draw(display);
		app.draw(audio);
		app.draw(get_back);
		app.draw(still_in_progress);
		app.display();
		switch (processEvent(app, OPTIONS))
		{
		case DISPLAY: return 3; break;
		case AUDIO: return 4; break;
		case GET_BACK: return 0; break;
		}
	}
	return -1;
}
