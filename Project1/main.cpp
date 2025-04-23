#include "draw.hpp"

int main()
{
    SFMLDraw render;

    render.add("img/grass.png");
    render.add("img/fisherman.png");
    render.draw();
    
}