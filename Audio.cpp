#include "pch.h"
#include "Windows.h"

int Audio::run(sf::RenderWindow & app)
{
	loadFiles(AUDIO);

	while (is_running)
	{
		text(AUDIO);

		app.clear();
		app.draw(*sBackground);
		app.draw(get_back);
		app.draw(still_in_progress);
		app.display();
		switch (processEvent(app, AUDIO))
		{
		case GET_BACK: return 1; break;
		}
	}
	return -1;

}
