#include "Player.h";
#include "Global_Values.h";
#include "Render.h";
#include "Bullets.h"
#include <stdlib.h>

using namespace sf;
using namespace std;

float direction = 0.0f;


float velocity = 0.0f;
float scalarY = 0.0f;
float scalarX = 0.0f;

//bullet pool


Player::Player()

    : _acceleration(1.5f), Entity(make_unique<sf::Sprite>()) {
    _shape->setTexture(spritesheet);
    _shape->setTextureRect(IntRect(160, 32, 32, 32));
    _shape->setOrigin(Vector2f(16.0f, 16.0f));
    _position = Vector2f(500.0f, 500.0f);
}

float calculateDirection(float x, float y)
{
    //Hey Dylan, ready to see some cool maths that made me cry at 4:27am this morning?

    //temp variables for your viewing pleasure
    float dot;
    float det;
    float angle;
    //calculating dot product
    dot = (0.0f * x) + (-1.0f * y);

    //determinant 
    det = (0.0f * x) - (-1.0f * y);

    //(0.0f, -1.0f) is north, btw. Angles are clockwise from north.
    //anyway heres wonderwall
    angle = atan2(det, dot);

    return angle;
}

float getPrograde()
{
    //now, following that calculate bit you might be wondering why i chose to return the variable through this get
    //its because i live to spite god and couldnt for the life of me get this function to work. i dont know if it was a ghost o 
    // -Fio
    return calculateDirection(scalarX, scalarY);;
}

void Player::Update(double dt) {

    // Move in four directions based on keys
        //when direction = 0 speed will not be applied to that axis
        //when direction is positive- speed will be that direction
        //Move left

    if (Keyboard::isKeyPressed(Keyboard::S)) {
        scalarY++;
    }
    //Move Right
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        scalarY--;
    }
    //move left
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        scalarX--;
    }
    //move right
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        scalarX++;
    }
    if (Keyboard::isKeyPressed(Keyboard::Q))
    {
        direction--;
        _shape.get()->setRotation(direction);
    }
    //move right
    if (Keyboard::isKeyPressed(Keyboard::E))
    {
        direction++;
        _shape.get()->setRotation(direction);
    }


    //shoot weapons
    if (Keyboard::isKeyPressed(Keyboard::Space)) {

        vector<Bullets> bulletpool;

        bulletpool.push_back(Bullets().Fire(_position.x, _position.y, direction, 0);
    }

    

    Player::move(Vector2f(scalarX * _acceleration * dt, scalarY * _acceleration * dt));
    Entity::Update(dt);
}

void Player::Render() 
{
    Renderer::queue(_shape.get());
}