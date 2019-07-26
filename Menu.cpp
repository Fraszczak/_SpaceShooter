#include "pch.h"
#include "Windows.h"

int Menu::run(sf::RenderWindow &app)
{
	loadFiles(MENU);

	while (is_running)
	{
		text(MENU);

		app.clear();
		app.draw(*sBackground);
		app.draw(title);
		app.draw(title_shadow);
		if (isPlaying)
			app.draw(Continue);
		if (!isPlaying)
			app.draw(Play);
		app.draw(Options);
		app.draw(Exit);
		app.display();
		switch (processEvent(app, MENU))
		{
		case PLAY: return 2; break;
		case OPTIONS: return 1; break;
		case EXIT: return -1; break;
		}
	}
	return -1;

}
