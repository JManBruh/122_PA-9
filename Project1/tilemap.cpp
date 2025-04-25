#include "tilemap.hpp"

tilemap::tilemap() 
{
	tilePositions.resize(1);
	tilePositions[0].resize(1);
	tilePositions[0][0] = {0,0};


}

void tilemap::setMultiPos(vector<Vector2f> in, int num)
{
	tilePositions.resize(num + 1);
	for (int i = 0; i < in.size(); i++)
	{
		tilePositions[num].push_back(in[i]);
	}
}

void tilemap::drawTilemap(RenderWindow& window)
{
	Vector2f unint;
	//there was simply no other way
	Sprite sprite(textures[0]);
	window.clear();
	for (int i = 0; i < arraySize; i++)
	{
		sprite.setTextureRect(sizes[i]);
		sprite.setTexture(textures[i]);
		sprite.setOrigin(origins[i]);
		sprite.setScale(scales[i]);
		sprite.setRotation(angles[i]);
		sprite.setPosition(positions[i]);
		if (tilePositions.size() > i && tilePositions[i][0] != unint)
		{
			for (int y = 0; y < tilePositions[i].size(); y++)
			{
				sprite.setOrigin(tilePositions[i][y]);
				window.draw(sprite);
			}
		} else 
		{
			window.draw(sprite);
		}
	}
	window.display();
}