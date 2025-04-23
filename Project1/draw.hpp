#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>

//My constituent teammates may claim all the credit they want, but all of the below was coded by Jordan!

using namespace sf;
using std::vector;
using std::string;

class batch {
public:
	void add(const char* in, IntRect size, int num);
	void setOrg(Vector2f in, int num);
	void setPos(Vector2f in, int num);
	void setRot(Angle in, int num);
	void draw(RenderWindow& window);

protected:
	int arraySize;
	vector<Texture> textures;
	vector<Vector2f> positions;
	vector<Vector2f> origins;
	vector<Vector2f> scales;
	vector<Angle> angles;
	vector<IntRect> sizes;
	RenderWindow window;
};

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

void batch::draw(RenderWindow& window) 
{
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<Event::Closed>())
			window.close();
	}
	Sprite sprite(textures[0]);
	window.clear();
	for(int i = 0; i < arraySize; i++) 
	{
		sprite.setTextureRect(sizes[i]);
		sprite.setTexture(textures[i]);
		sprite.setOrigin(origins[i]);
		sprite.setPosition(positions[i]);
		sprite.setRotation(angles[i]);
		window.draw(sprite);
	}
	window.display();

}

