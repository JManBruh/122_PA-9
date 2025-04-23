#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>

using namespace sf;
//using sf::Texture;
using std::vector;
using std::string;

class SFMLDraw {
public:
	void add(string img);
	void remove();
	void draw();
private:
	vector<Sprite> images;
	int index = 0;
};

void SFMLDraw::add(string img)
{

	const char* c = img.c_str();
	Texture textimg(c, false, sf::IntRect({ 10, 10 }, { 32, 32 }));
	Sprite sprimg(textimg);

	sprimg.rotate(degrees(14));
	sprimg.setPosition({ 10.f, 50.f });
	sprimg.setScale({ 0.5f, 2.f });


	images.push_back(sprimg);
	index++;
};

void SFMLDraw::remove() 
{
	images.erase(images.begin() + index);
	index--;
};

void SFMLDraw::draw() 
{
	RenderWindow window(sf::VideoMode({ 1600, 900 }), "PA 9: FISHING");
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
				window.close();
		}
		for(Sprite image : images) 
		{
			window.clear();
			window.draw(image);
			window.display();
		}
	}
}



