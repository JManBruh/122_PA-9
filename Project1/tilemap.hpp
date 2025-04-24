#include "draw.hpp"

void game();

class tilemap : private batch
{
public:
	void addTilemap(const char* in, int num);
	void setMultiPos(vector<Vector2f> in, int num);
	void drawTilemap(RenderWindow& window);
private:
	vector<Texture>tiletexts;
	vector<vector<Vector2f>> tilePositions;
};

void tilemap::addTilemap(const char* in, int num) 
{
	if(num >= tiletexts.size()) 
	{
		tiletexts.resize(num + 1);
		int i = 0;
		if(tilePositions.size() == 0) 
		{
			tilePositions.resize(1);
		}
		for(; i < tilePositions.size(); i++) 
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
	if(in.size() > tilePositions[num].size())
	{ 
		tilePositions[num].resize(in.size() + 1);
	}
	for(int i = 0; i < in.size(); i++) 
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

void game() 
{
	Music destroy("mp3/Fish Game.wav");
	batch load;
	tilemap map;

	IntRect asize({ 0, 0 }, { 512, 512 }), bsize({ 0, 0 }, { 1200, 675 });
	vector<Vector2f> mapPos = { {0,-600}, {-100, -600}, {-200, -600}, {-300, -600} };

	load.add("img/mtrainierbg.png", bsize, 0);
	load.add("img/fisherman.png", asize, 2);
	load.setOrg({ 0, 0 }, 0);
	load.setOrg({ 0,-800 }, 1);
	load.setOrg({ 0, -400 }, 2);

	map.addTilemap("img/grass.png", 0);
	map.setMultiPos(mapPos, 0);


	destroy.play();
	float x = 0.0;
	//main game loop
	RenderWindow window(VideoMode({ 1600, 900 }), "GET FISH");
	while (window.isOpen())
	{
		load.draw(window);
		load.setPos({ x, 0 }, 2);
		x += 0.1;
	}
}