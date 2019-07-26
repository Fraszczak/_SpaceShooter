#include "pch.h"
#include "Windows.h"


Animation::Animation(sf::Texture &anime_texture, int x, int y, int w, int h, int count, float speed)
{
	actuall_frame = 0;
	time_step = speed;

	for (int i = 0; i < count; i++)
		frames.push_back(sf::IntRect(x + i * w, y, w, h));

	animation_sprite.setOrigin(w / 2, h / 2);
	animation_sprite.setTexture(anime_texture);
	animation_sprite.setTextureRect(frames[0]);
}
void Animation::update()
{
	actuall_frame += time_step;
	int n = frames.size();
	if (actuall_frame >= n) actuall_frame -= n;
	if (n > 0) animation_sprite.setTextureRect(frames[int(actuall_frame)]);
}
bool Animation::isEnd()
{
	return actuall_frame + time_step >= frames.size();
}
