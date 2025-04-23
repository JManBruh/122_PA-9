#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>

using namespace sf;
using std::vector;

class batch {
public:
	void add(const char* in, int num);
	void setOrg(Vector2f in, int num);
	void setPos(Vector2f in, int num);
	void setRot(Angle in, int num);
	void draw(RenderWindow& window);

private:
	int arraySize;
	vector<Texture> textures;
	vector<Vector2f> positions;
	vector<Vector2f> origins;
	vector<Vector2f> scales;
	vector<Angle> angles;
	RenderWindow window;
};

void batch::add(const char* in, int num) 
{
	if (num >= arraySize)
	{
		arraySize = num + 1;
		textures.resize(arraySize);
		positions.resize(arraySize);
		origins.resize(arraySize);
		scales.resize(arraySize);
		angles.resize(arraySize);
	}
	Texture texture(Image(in), false);
	textures[num] = texture;
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
	window.clear();
	for(int i = 0; i < textures.size(); i++) 
	{
		Sprite sprite(textures[i]);
		sprite.setOrigin(origins[i]);
		sprite.setPosition(positions[i]);
		sprite.setRotation(angles[i]);
		window.draw(sprite);
	}
	window.display();

}

