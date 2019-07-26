#include "pch.h"
#include "Windows.h"
#include "EntityList.h"
#include <list>
#include <thread>
#include <chrono>

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

int Play::run(sf::RenderWindow &app)
{
	int meteors_number_per_sec = 0;
	bool running = true;
	sf::Clock clock;
	sf::Event event;
	std::list <Entity*> entity_list;
	lifes_counter = 1;

	//skorzystaj z <random>
	srand(time(NULL));

	//------------------Animation----------------
	Animation	
		laser_explosion(laser_explosion_texture, 0, 0, 256, 256, 48, 0.5),
		ship_animation(player_texture, 40, 0, 40, 40, 1, 0),
		big_meteor(big_meteor_texture, 0, 0, 64, 64, 16, 0.2),
		small_meteor(small_meteor_texture, 0, 0, 64, 64, 16, 0.2),
		blue_laser(laser_texture, 0, 0, 32, 64, 16, 0.8),
		ship_explosion(ship_explosion_texture, 0, 0, 192, 192, 64, 0.5),
		end_map_line_animation(end_map_line_texture, 0, 0, 64, 64, 16, 0.2);
	//---------------Load files------------------------------
	loadFiles(PLAY);

	//------------------------end of map-----------------------------
	for (int i = 0; i <= 4; i++)
	{
		if (i == 0)
		{
			EndOfWorld *endOfMapLaser = new EndOfWorld(end_map_line_animation, 0, 49);
			entity_list.push_back(endOfMapLaser);
			EndOfWorld *endOfMapLaser2 = new EndOfWorld(end_map_line_animation, 0, 51);
			entity_list.push_back(endOfMapLaser2);
		}

		else if (i == 1)
		{
			EndOfWorld *endOfMapLaser = new EndOfWorld(end_map_line_animation, 300, 51);
			entity_list.push_back(endOfMapLaser);
			EndOfWorld *endOfMapLaser2 = new EndOfWorld(end_map_line_animation, 0, 49);
			entity_list.push_back(endOfMapLaser2);
		}
		else if (i == 2)
		{
			EndOfWorld *endOfMapLaser = new EndOfWorld(end_map_line_animation, 600, 49);
			entity_list.push_back(endOfMapLaser);
			EndOfWorld *endOfMapLaser2 = new EndOfWorld(end_map_line_animation, 0, 51);
			entity_list.push_back(endOfMapLaser2);
		}
		else if (i == 3)
		{
			EndOfWorld *endOfMapLaser = new EndOfWorld(end_map_line_animation, 900, 51);
			entity_list.push_back(endOfMapLaser);
			EndOfWorld *endOfMapLaser2 = new EndOfWorld(end_map_line_animation, 0, 49);
			entity_list.push_back(endOfMapLaser2);
		}
		else if (i == 4)
		{
			EndOfWorld *endOfMapLaser = new EndOfWorld(end_map_line_animation, 1200, 49);
			entity_list.push_back(endOfMapLaser);
			EndOfWorld *endOfMapLaser2 = new EndOfWorld(end_map_line_animation, 0, 51);
			entity_list.push_back(endOfMapLaser2);
		}


	}

	//------------------------Player----------------------------
	Player *player = new Player(ship_animation, 500, 500);
	entity_list.push_back(player);

	while (running)
	{

		//--------------------------elapsed time-------------------------------------
		sf::Time elapsed = clock.restart();

		//-------------------------------statistic---------------------------------
		statistic(lifes_counter, shots_counter, meteors_counter);

		//---------------------------Meteors---------------------------
		meteors_number_per_sec++;
		while (meteors_number_per_sec % 500 == 0)
		{
			Meteors *meteor = new Meteors(big_meteor, (rand() % 1200 + 0.f), 0);
			entity_list.push_back(meteor);

			meteors_counter++;
			meteors_number_per_sec++;

			if (meteors_number_per_sec > 10000)
				meteors_number_per_sec = -9999;
		}

		//---------------------colision----------------------------------
		for (auto first_object : entity_list)
		{
			for (auto second_object : entity_list)
			{
				if ((first_object->getName() == "Meteor" || first_object->getName() == "SmallMeteor") && (second_object->getName() == "Player"))
				{
					if (areColided(first_object, second_object))
					{
						first_object->kill();
						second_object->kill();
						lifes_counter = 0;

						Explosion *explosion = new Explosion(ship_explosion, first_object->getX(), first_object->getY());
						entity_list.push_back(explosion);


					}
				}
				else if (first_object->getName() == "Laser" && (second_object->getName() == "Meteor" || second_object->getName() == "SmallMeteor"))
				{
					if (areColided(first_object, second_object))
					{
						first_object->kill();
						second_object->kill();
						points++;


						Explosion *explosion = new Explosion(ship_explosion, second_object->getX(), second_object->getY());
						entity_list.push_back(explosion);

						if (second_object->getName() == "SmallMeteor")
						{
							continue;
						}
						for (short i = 0; i < 2; i++)
						{
							Meteors *meteor = new Meteors(small_meteor, second_object->getX() + rand() % 50, second_object->getY() + rand() % 50);
							meteor->setName("SmallMeteor");
							entity_list.push_back(meteor);
						}


					}
				}
				else if (first_object->getName() == "Player" && (second_object->getName() == "EndOfMap" && meteors_counter >= 1))
					if (areColided(first_object, second_object))
					{
						{
							first_object->kill();
							second_object->kill();
							lifes_counter = 0;

							Explosion *explosion = new Explosion(ship_explosion, first_object->getX(), first_object->getY());
							entity_list.push_back(explosion);
						}
					}
			}
		}
		//-----------------ProcessEvents----------------------------
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return (-1);

			if (event.type == sf::Event::KeyPressed)
				switch (event.key.code)
				{
				case sf::Keyboard::Down: player->moving(player->down);break;
				case sf::Keyboard::Up: player->moving(player->up);break;
				case sf::Keyboard::Right: player->moving(player->right);break;
				case sf::Keyboard::Left: player->moving(player->left);break;
				case sf::Keyboard::Escape: meteors_counter = 0; return 0; break;
				case sf::Keyboard::Space:
				{
					if (lifes_counter > 0)
					{
						//---------------------------------shoots--------------------------------------------
						Laser *laser = new Laser(blue_laser, player->getX(), player->getY());
						entity_list.push_back(laser);

						shots_counter++;
					}
				}
				default:
					break;
				}
		}

		for (auto e : entity_list)
			if (e->getName() == "Explosion")
				if (e->animationIsEnd())
					e->kill();


		for (auto i = entity_list.begin(); i != entity_list.end(); )
		{
			Entity *e = *i;
			e->update(elapsed);
			e->animationUpdate();

			if (e->isKilled())
			{
				i = entity_list.erase(i);
				delete e;
			}
			else i++;
		}

		//--------------------app drawing----------------------
		app.clear();
		app.draw(*sBackground);
		app.draw(player_life);
		app.draw(meteors_counter_text);
		app.draw(shots_counter_text);
		app.draw(points_text);

		for (auto i : entity_list)
		{
			i->update(elapsed);
			i->draw(app);
		}

		if ((lifes_counter == 0) && ((time_to_game_over += elapsed.asSeconds()) > 2))
		{
			Explosion *explosion = new Explosion(ship_explosion, player->getX(), player->getY());
			entity_list.push_back(explosion);

			shots_counter = 0;
			meteors_counter = 0;
			points = 0;

			app.clear();
			app.draw(game_over);
			app.display();

			sleep_for(3s);

			return 3;
		}
		app.display();
	}
	return (-1);
}
bool Play::areColided(Entity *first_object, Entity *second_object)
{
	if (first_object->getAnimation().animation_sprite.getGlobalBounds().intersects(second_object->getAnimation().animation_sprite.getGlobalBounds()))
	{
		return true;
	}
	else return false;
}
void Play::statistic(short life_number, short shots_counter, short meteors_counter)
{
	//player life
	player_life.setFont(statistic_font);
	player_life.setString("Player life: " + std::to_string(life_number) + "\n");
	player_life.setPosition(0, 0);
	player_life.setFillColor(sf::Color(255, 0, 0, 255));
	//meteors
	meteors_counter_text.setFont(statistic_font);
	meteors_counter_text.setString("Meteors: " + std::to_string(meteors_counter) + "\n");
	meteors_counter_text.setPosition(300, 0);
	meteors_counter_text.setFillColor(sf::Color(255, 0, 0, 255));
	//shoots
	shots_counter_text.setFont(statistic_font);
	shots_counter_text.setString("Shots: " + std::to_string(shots_counter) + "\n");
	shots_counter_text.setPosition(600, 0);
	shots_counter_text.setFillColor(sf::Color(255, 0, 0, 255));
	//score
	points_text.setFont(statistic_font);
	points_text.setString("Score: " + std::to_string(points) + "\n");
	points_text.setPosition(800, 0);
	points_text.setFillColor(sf::Color(255, 0, 0, 255));
	//Game over
	game_over.setFont(statistic_font);
	game_over.setString("G A M E  O V E R \n\n\n	   @ @ @");
	game_over.setCharacterSize(50);
	game_over.setLetterSpacing(5);
	game_over.setPosition(300, 350);
	game_over.setFillColor(sf::Color(255, 100, 100, 255));
}