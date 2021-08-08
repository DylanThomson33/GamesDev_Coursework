//bullet.cpp
#include "Bullets.h"
#include "Global_Values.h"
using namespace sf;
using namespace std;

Bullets::Bullets()
{

};


void Bullets::Update(const float& dt) {
    if (firedBy == 0)
    {

        move(0, dt * 200.0f);
    }
}
