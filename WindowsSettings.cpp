#include "pch.h"
#include "Windows.h"

int WindowsSettings::processEvent(sf::RenderWindow &app, int for_what_screen)
{
	switch (for_what_screen)
	{
	case MENU:{
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return EXIT;
			}
			if (event.type == sf::Keyboard::Escape)
			{
				return GET_BACK;
				break;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				
				switch (event.key.code)
				{
				case sf::Keyboard::Down: {
					selected++;
					if (selected > boundary_max) selected = boundary_min;
					break;
				}
				case sf::Keyboard::Up: {
					selected--;
					if (selected < boundary_min) selected = boundary_max;
					break;
				}
				case sf::Keyboard::Enter: {
					switch (selected)
					{
					case 0: {
						return PLAY;
						break;
					}
					case 1: {
						return OPTIONS;
						break;
					}
					case 2: {
						return EXIT;
						break;
					}

					default: {
						break;
					}
					}
				}
				default: {
					break;
				}
				}
			}
		}
		break;
	}
	case OPTIONS: {
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return EXIT;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape: {
					return GET_BACK;
					break;
				}
				case sf::Keyboard::Down: {
					selected++;
					if (selected > boundary_max) selected = boundary_min;
					break;
				}
				case sf::Keyboard::Up: {
					selected--;
					if (selected < boundary_min) selected = boundary_max;
					break;
				}
				case sf::Keyboard::Enter: {
					switch (selected)
					{
					case 0: {
						return DISPLAY;
						break;
					}
					case 1: {
						return AUDIO;
						break;
					}
					case 2: {
						return GET_BACK;
						break;
					}

					default: {
						break;
					}
					}
				}
				default: {
					break;
				}
				}
			}
		}
		break;
	}
	case PLAY: {

		break;
	}
	case DISPLAY: {
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return EXIT;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape: {
					return GET_BACK;
					break;
				}
										   /*case sf::Keyboard::Down: {
											   selected++;
											   if (selected > boundary_max) selected = boundary_min;
											   break;
										   }
										   case sf::Keyboard::Up: {
											   selected--;
											   if (selected < boundary_min) selected = boundary_max;
											   break;
										   }*/
				case sf::Keyboard::Enter: {
					switch (selected)
					{
					case 0: {
						return GET_BACK;
						break;
					}
					default: {
						break;
					}
					}
				}
				default: {
					break;
				}
				}
			}
		}
		break;
	}
	case AUDIO: {
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return EXIT;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape: {
					return GET_BACK;
					break;
				}
				/*case sf::Keyboard::Down: {
					selected++;
					if (selected > boundary_max) selected = boundary_min;
					break;
				}
				case sf::Keyboard::Up: {
					selected--;
					if (selected < boundary_min) selected = boundary_max;
					break;
				}*/
				case sf::Keyboard::Enter: {
					switch (selected)
					{
					case 0: {
						return GET_BACK;
						break;
					}
					default: {
						break;
					}
					}
				}
				default: {
					break;
				}
				}
			}
		}
		break;
	}
	}
	
}
void WindowsSettings::loadFiles(int for_what_window)
{
	switch (for_what_window)
	{
	case MENU: {
		//Text for title and options
		if (!title_font.loadFromFile("Fonts/kenvector_future.ttf"))
			throw XBoundary("Cannot load title font file");
		if (!text_font.loadFromFile("Fonts/kenvector_future_thin.ttf"))
			throw XBoundary("Cannot load text font file");

		//Background files
		if (!tBackground->loadFromFile("Backgrounds/menu.png"))
			throw XBoundary("Cannot load background texture file");
		sBackground->setTexture(*tBackground);

		break;
	}
	case OPTIONS: {
		if (!tBackground->loadFromFile("Backgrounds/menu.png"))
			throw XBoundary("Cannot load background file");
		sBackground->setTexture(*tBackground);

		if (!text_font.loadFromFile("Fonts/kenvector_future_thin.ttf"))
			throw XBoundary("Cannot load font file");

		break;
	}
	case PLAY: {
		//background
		if (!tBackground->loadFromFile("Backgrounds/background.jpg"))
			throw XBoundary("Cannot load background file");
		sBackground->setTexture(*tBackground);
		tBackground->setSmooth(true);
		//fonts
		if (!player_death_font.loadFromFile("Fonts/kenvector_future.ttf"))
			throw XBoundary("Cannot load font file");
		if (!game_over_font.loadFromFile("Fonts/game_over.ttf"))
			throw XBoundary("Cannot load font file");
		if (!statistic_font.loadFromFile("Fonts/kenvector_future_thin.ttf"))
			throw XBoundary("Cannot load font file");
		//player
		if (!player_texture.loadFromFile("Animations/img/spaceship.png"))
			throw XBoundary("Cannot load background file");
		player_texture.setSmooth(true);
		//meteors
		if (!big_meteor_texture.loadFromFile("Animations/img/rock.png"))
			throw XBoundary("Cannot load background file");
		if (!small_meteor_texture.loadFromFile("Animations/img/rock_small.png"))
			throw XBoundary("Cannot load background file");
		//laser
		if (!laser_texture.loadFromFile("Animations/img/fire_blue.png"))
			throw XBoundary("Cannot load background file");
		//explosion
		if (!end_map_line_texture.loadFromFile("Animations/img/fire_red.png"))
			throw XBoundary("Cannot load background file");
		if (!ship_explosion_texture.loadFromFile("Animations/type_B.png"))
			throw XBoundary("Cannot load background file");
		if (!laser_explosion_texture.loadFromFile("Animations/type_C.png"))
			throw XBoundary("Cannot load background file");
		break;
	}
	case DISPLAY: {
		if (!tBackground->loadFromFile("Backgrounds/menu.png"))
			throw XBoundary("Cannot load background file");
		sBackground->setTexture(*tBackground);

		if (!text_font.loadFromFile("Fonts/kenvector_future_thin.ttf"))
			throw XBoundary("Cannot load font file");

		break;
	}
	case AUDIO: {
		if (!tBackground->loadFromFile("Backgrounds/menu.png"))
			throw XBoundary("Cannot load background file");
		sBackground->setTexture(*tBackground);

		if (!text_font.loadFromFile("Fonts/kenvector_future_thin.ttf"))
			throw XBoundary("Cannot load font file");

		break;
	}
	default: {
		throw XBoundary("Something wrong in WindowsStettings loadFiles function");
		break;
	}
	}
}
void WindowsSettings::text(int for_what_window)
{
	switch (for_what_window)
	{
	case MENU: {

		int alpha_play, alpha_continue;
		if (isPlaying == true)
		{
			alpha_play = 0;
			alpha_continue = 255;
		}
		else if (isPlaying == false)
		{
			alpha_play = 255;
			alpha_continue = 0;
		}
		if (selected == 0)
		{
			Play.setFillColor(sf::Color(255, 255, 0, alpha_play));
			Continue.setFillColor(sf::Color(255, 255, 0, alpha_continue));
			Options.setFillColor(sf::Color(255, 0, 0, 255));
			Exit.setFillColor(sf::Color(255, 0, 0, 255));
		}
		else if (selected == 1)
		{
			Play.setFillColor(sf::Color(255, 0, 0, alpha_play));
			Continue.setFillColor(sf::Color(255, 0, 0, alpha_continue));
			Options.setFillColor(sf::Color(255, 255, 0, 255));
			Exit.setFillColor(sf::Color(255, 0, 0, 255));
		}
		else if (selected == 2)
		{
			Play.setFillColor(sf::Color(255, 0, 0, alpha_play));
			Continue.setFillColor(sf::Color(255, 0, 0, alpha_continue));
			Options.setFillColor(sf::Color(255, 0, 0, 255));
			Exit.setFillColor(sf::Color(255, 255, 0, 255));
		}
		//title
		title.setFont(title_font);
		title.setString("SpaceShooter");
		title.setPosition(150, 100);
		title.setFillColor(sf::Color(255, 0, 0, 255));
		title.setLetterSpacing(20);
		title.setCharacterSize(33);
		//----------------
		title_shadow.setFont(title_font);
		title_shadow.setString("SpaceShooter");
		title_shadow.setPosition(95, 90);
		title_shadow.setFillColor(sf::Color(200, 0, 0, 155));
		title_shadow.setLetterSpacing(21);
		title_shadow.setCharacterSize(34);
		//play
		Play.setFont(text_font);
		Play.setString("Play");
		Play.setPosition(500, 350);
		Play.setLetterSpacing(5);
		//continue
		Continue.setFont(text_font);
		Continue.setString("Continue");
		Continue.setPosition(500, 350);
		//options
		Options.setFont(text_font);
		Options.setString("Options");
		Options.setPosition(500, 420);
		Options.setLetterSpacing(5);
		//exit
		Exit.setFont(text_font);
		Exit.setString("Exit");
		Exit.setPosition(500, 490);
		Exit.setLetterSpacing(5);

		break;
	}
	case OPTIONS: {
		if (selected == 0)
		{
			display.setFillColor(sf::Color(255, 255, 0, 255));
			audio.setFillColor(sf::Color(255, 0, 0, 255));
			get_back.setFillColor(sf::Color(255, 0, 0, 255));
		}
		else if (selected == 1)
		{
			display.setFillColor(sf::Color(255, 0, 0, 255));
			audio.setFillColor(sf::Color(255, 255, 0, 255));
			get_back.setFillColor(sf::Color(255, 0, 0, 255));
		}
		else if (selected == 2)
		{
			display.setFillColor(sf::Color(255, 0, 0, 255));
			audio.setFillColor(sf::Color(255, 0, 0, 255));
			get_back.setFillColor(sf::Color(255, 255, 0, 255));
		}
		//display
		display.setFont(text_font);
		display.setString("Display");
		display.setPosition(200, 450);
		//audio
		audio.setFont(text_font);
		audio.setString("Audio");
		audio.setPosition(200, 500);
		//get back
		get_back.setFont(text_font);
		get_back.setString("Get back");
		get_back.setPosition(200, 600);
		//still in progress
		still_in_progress.setFont(text_font);
		still_in_progress.setString("Still in progress");
		still_in_progress.setPosition(300, 350);
		still_in_progress.setCharacterSize(50);
		still_in_progress.setLetterSpacing(5);

		break;
	}
	case PLAY: {

		break;
	}
	case DISPLAY: {
		if (selected == 0)
		{
			get_back.setFillColor(sf::Color(255, 255, 0, 255));
		}
		//get back
		get_back.setFont(text_font);
		get_back.setString("Get back");
		get_back.setPosition(200, 550);
		//still in progress
		still_in_progress.setFont(text_font);
		still_in_progress.setString("Still in progress");
		still_in_progress.setPosition(300, 350);
		still_in_progress.setCharacterSize(50);
		still_in_progress.setLetterSpacing(5);
		break;
	}
	case AUDIO: {
		if (selected == 0)
		{
			get_back.setFillColor(sf::Color(255, 255, 0, 255));
		}
		//get back
		get_back.setFont(text_font);
		get_back.setString("Get back");
		get_back.setPosition(200, 550);
		//still in progress
		still_in_progress.setFont(text_font);
		still_in_progress.setString("Still in progress");
		still_in_progress.setPosition(300, 350);
		still_in_progress.setCharacterSize(50);
		still_in_progress.setLetterSpacing(5);
		break;
	}
	default: { 
		throw XBoundary("Something wrong in WindowsStettings text function"); 
		break;
			}	 
	}
}

