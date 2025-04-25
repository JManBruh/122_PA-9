#include "draw.hpp"

class tilemap : public batch
{
public:
	//initialization is important!
	tilemap();

	void setMultiPos(vector<Vector2f> in, int num);
	void drawTilemap(RenderWindow& window);
private:
	vector<vector<Vector2f>> tilePositions;
};