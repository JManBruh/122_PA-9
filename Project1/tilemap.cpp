#include "tilemap.hpp"

void tilemap::addTilemap(const char* in, int num)
{
	if (num >= tiletexts.size())
	{
		tiletexts.resize(num + 1);
		int i = 0;
		if (tilePositions.size() == 0)
		{
			tilePositions.resize(1);
		}
		for (; i < tilePositions.size(); i++)
		{
			tilePositions[i].resize(num + 1);
		}
		tilePositions.resize(i + 1);
	}
	Texture texture(Image(in), false);
	tiletexts[num] = texture;
}

void tilemap::setMultiPos(vector<Vector2f> in, int num)
{
	if (in.size() > tilePositions[num].size())
	{
		tilePositions[num].resize(in.size() + 1);
	}
	for (int i = 0; i < in.size(); i++)
	{
		tilePositions[num][i] = in[i];
	}
}

void tilemap::drawTilemap(RenderWindow& window)
{
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<Event::Closed>())
			window.close();
	}
	Sprite sprite(tiletexts[0]);
	window.clear();
	for (int x = 0; x < tilePositions.size(); x++)
	{
		for (int y = 0; y < tilePositions[x].size(); y++)
		{
			sprite.setPosition(tilePositions[x][y]);
			window.draw(sprite);
		}
		sprite.setTexture(tiletexts[x]);
	}
	window.display();
}