#include "Player.h";
#include "Global_Values.h";
#include "Render.h";
<<<<<<< Updated upstream
#include <stdlib.h>

using namespace sf;
using namespace std;

float direction;


float scalarY = 0.0f;

float scalarX = 0.0f;




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
=======
>>>>>>> Stashed changes

float getDirection()
{

    direction = calculateDirection(scalarX, scalarY);
    //now, following that calculate bit you might be wondering why i chose to return the variable through this get
    //its because i live to spite god and couldnt for the life of me get this function to work. i dont know if it was a ghost o 
    // -Fio
    return direction;
}

Player::Player()
//only way to contruct is through entity constructor which takes an sf:sprite----------------
    : _speed(200.0f), Entity(make_unique<sf::Sprite>()) {
    //instead of set colour we are going to set rect----------------------
    _shape->setTexture(spritesheet);
    _shape->setTextureRect(IntRect(160, 32, 32, 32));
    _shape->setOrigin(Vector2f(25.f, 25.f));
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
    


    Player::move(Vector2f(scalarX * _acceleration * dt, scalarY * _acceleration * dt));


    Entity::Update(dt);
}

<<<<<<< Updated upstream
Player::Player()
    : _acceleration(0.2f), Entity(make_unique<CircleShape>(25.f)) {
    _shape->setFillColor(Color::Yellow);
    _shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::Render(sf::RenderWindow& window) const {

    //window.draw(*_shape);
=======
void Player::Render() 
{
>>>>>>> Stashed changes
    Renderer::queue(_shape.get());
}