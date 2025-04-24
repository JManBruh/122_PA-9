#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>

using namespace sf;
using std::vector;
using std::string;

class batch {
public:
	void add(const char* in, IntRect size, int num);
	void setOrg(Vector2f in, int num);
	void setPos(Vector2f in, int num);
	void setScl(Vector2f in, int num);
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
