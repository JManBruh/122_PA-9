#include "draw.hpp"

void batch::add(const char* in, IntRect size, int num)
{
	if (num >= arraySize)
	{
		arraySize = num + 1;
		textures.resize(arraySize);
		positions.resize(arraySize);
		origins.resize(arraySize);
		scales.resize(arraySize);
		angles.resize(arraySize);
		sizes.resize(arraySize);
	}
	Texture texture(Image(in), false, size);
	textures[num] = texture;
	sizes[num] = size;
}

void batch::setOrg(Vector2f in, int num)
{
	origins[num] = in;
}

void batch::setPos(Vector2f in, int num)
{
	positions[num] = in;
}

void batch::setRot(Angle in, int num)
{
	angles[num] = in;
}

void batch::setScl(Vector2f in, int num)
{
	scales[num] = in;
}

void batch::draw(RenderWindow& window)
{
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<Event::Closed>())
			window.close();
	}
	Sprite sprite(textures[0]);
	window.clear();
	for (int i = 0; i < arraySize; i++)
	{
		sprite.setTextureRect(sizes[i]);
		sprite.setTexture(textures[i]);
		sprite.setOrigin(origins[i]);
		sprite.setScale(scales[i]);
		sprite.setPosition(positions[i]);
		sprite.setRotation(angles[i]);
		window.draw(sprite);
	}
	window.display();

}
