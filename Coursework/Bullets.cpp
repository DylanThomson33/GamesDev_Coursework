//bullet.cpp
#include "bullets.h"
#include "game.h"

using namespace sf;
using namespace std;

//Create definition for the constructor

Bullets::Bullets() 
{
    _mode = mode;
}

void Bullets::Fire(const sf::Vector2f& pos, const bool mode)
{
    bulletList[bulletPointer]._mode = mode;
}

void Bullets::Render(sf::RenderWindow& window)
{
    for (int i = 0; i < 256; i++)
    {
        window.draw(bulletList[i]);
    }
}


void Bullets::Update(const float& dt) {

    for (int i = 0; i < 256; i++) 
    {
        bulletList[i].move(0, dt * 200.0f * (bulletList[i]._mode ? 1.0f : -1.0f));
    }
}

void Bullets::_Update(const float& dt)
{

}