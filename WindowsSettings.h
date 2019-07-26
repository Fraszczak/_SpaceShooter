#pragma once
#include <SFML/Graphics.hpp>
class WindowsSettings 
{
public:
	WindowsSettings() {}
	~WindowsSettings() {}

	int processEvent(sf::RenderWindow &app, int for_what_screen);
	void loadFiles(int for_what_window);
	void text(int for_what_window);

	
protected:
	int selected;
	bool is_running = true;
	int boundary_min = 0, boundary_max = 2;

	//enum boundary { SELECTED_PLAY, SELECTED_OPTIONS, SLEECTED_EXIT };
	enum menu_windows_enum { MENU, OPTIONS, PLAY, EXIT = (-1), GET_BACK = 7 };
	enum options_windows_enum {DISPLAY = 3, AUDIO = 4};
	sf::Event event;

	sf::Text Play, Continue, Options, Exit, title, title_shadow;
	sf::Texture *tBackground = new sf::Texture();
	sf::Sprite *sBackground = new sf::Sprite();
	sf::Font title_font, text_font;

	//Options
protected:
	sf::Text display, audio, get_back, still_in_progress;
//Play
protected:
	sf::Texture	backgroud_texture, player_texture,
		big_meteor_texture, small_meteor_texture,
		laser_texture, laser_explosion_texture,
		ship_explosion_texture, end_map_line_texture;

	sf::Sprite background_sprite;

	sf::Text player_life, meteors_counter_text,
		shots_counter_text, points_text, game_over;


	sf::Font player_death_font, statistic_font, game_over_font;

protected:
	short shots_counter, meteors_counter, points;

	float time_to_game_over = 0.f;
};
