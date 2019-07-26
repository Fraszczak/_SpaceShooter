#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation() {};
	Animation(sf::Texture &animation_texture, int x, int y, int w, int h, int count, float speed);
	~Animation() {};

	void		update();
	bool		isEnd();

public:
	sf::Sprite	animation_sprite;

protected:
	sf::Clock	animation_frame_time,
		loop_clock;

	std::vector<sf::IntRect> frames;

	float		actuall_frame,
		time_step;
};