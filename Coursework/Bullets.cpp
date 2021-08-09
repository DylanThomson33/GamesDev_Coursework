<<<<<<< Updated upstream
=======
//bullet.cpp
#include "Bullets.h"
#include "Global_Values.h"
#include "Render.h";
using namespace sf;
using namespace std;

int projectileType;
float scalarAngle;

Bullets::Bullets()
{

};

Bullets::Bullets(const sf::Vector2f& pos, const int firedBy, float angle)
{
    //TODO - Constructor (set pos, speed / angle)
    Bullets::setPosition(pos.x, pos.y);
    projectileType = firedBy;
    scalarAngle = angle;
}


void Bullets::Update(const float& dt) {
    if (projectileType == 0)
    {
        //TODO - check collisions

        //TODO - Interact with gravity

        //SPEED AND ANGLE CALCULATIONS
        move(0, dt * 200.0f);
    }
}

>>>>>>> Stashed changes
