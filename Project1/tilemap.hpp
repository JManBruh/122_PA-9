#include "draw.hpp"

class tilemap : public batch
{
public:
	void addTilemap(const char* in, int num);
	void setMultiPos(vector<Vector2f> in, int num);
	void drawTilemap(RenderWindow& window);
private:
	vector<Texture>tiletexts;
	vector<vector<Vector2f>> tilePositions;
};