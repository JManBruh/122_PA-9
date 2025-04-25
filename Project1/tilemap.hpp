/*
FIXES BY TAYLOR:

Removed window.clear(), window.display(), and event polling from drawTilemap(); now only draws. 
Fixed sprite.setTexture() order to avoid flickering when drawing multiple tile types.
Fixed a float truncation.
*/ 


#include "draw.hpp"
#include "character.hpp"

void game();

class tilemap : private batch
{
public:
	void addTilemap(const char* in, int num);
	void setMultiPos(vector<Vector2f> in, int num);
	void drawTilemap(RenderWindow& window);
private:
	vector<Texture> tiletexts;
	vector<vector<Vector2f>> tilePositions;
};

void tilemap::addTilemap(const char* in, int num)
{
	if (num >= tiletexts.size())
	{
		tiletexts.resize(num + 1);
		int i = 0;
		if (tilePositions.size() == 0)
			tilePositions.resize(1);

		for (; i < tilePositions.size(); i++)
			tilePositions[i].resize(num + 1);

		tilePositions.resize(i + 1);
	}
	Texture texture(Image(in), false);
	tiletexts[num] = texture;
}

void tilemap::setMultiPos(vector<Vector2f> in, int num)
{
	if (num >= tilePositions.size()) {
		tilePositions.resize(num + 1);
	}
	tilePositions[num].resize(in.size()); //fixed memory bounds issue -Taylor

	for (int i = 0; i < in.size(); i++) {
		tilePositions[num][i] = in[i];
	}
}

void tilemap::drawTilemap(RenderWindow& window)
{
	Sprite sprite(tiletexts[0]);
	for (int x = 0; x < tilePositions.size(); x++)
	{
		for (int y = 0; y < tilePositions[x].size(); y++)
		{
			sprite.setPosition(tilePositions[x][y]);
			sprite.setTexture(tiletexts[x]);
			window.draw(sprite);
		}
	}
}

void game()
{
	Music track("mp3/FishGame.mp3");
	batch load;
	tilemap map;
	Character player; 

	IntRect asize({ 0, 0 }, { 512, 512 }), bsize({ 0, 0 }, { 1200, 675 });
	vector<Vector2f> mapPos = { {0,-600}, {-100, -600}, {-200, -600}, {-300, -600} };

	load.add("img/mtrainierbg.png", bsize, 0);
	load.setOrg({ 0, 0 }, 0);
	load.setOrg({ 0,-800 }, 1);

	map.addTilemap("img/grass.png", 0);
	map.setMultiPos(mapPos, 0);

	player.init("img/fisherman.png", asize, { 400.f, 500.f });

	track.play();
	float x = 0.0;

	RenderWindow window(VideoMode({ 1600, 900 }), "GET FISH");
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
				window.close();
		}

		player.update();

		window.clear();
		load.draw(window);
		map.drawTilemap(window);

		player.draw(window);

		window.display();

		x += 0.1f;
	}
}
