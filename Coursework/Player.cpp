#include "Player.h";
#include "Global_Values.h";
#include "Render.h";
/*
//player constructor
using namespace sf;
Player::Player() : Entity(sf::IntRect(160, 32, 32, 32)) {
    setPosition({ gameHeight * .5f, gameHeight - 32.f });
}

//controls
const Keyboard::Key controls[2] = {
    Keyboard::A,   // Player1 left
    Keyboard::D,   // Player1 right
};


//this is where handle player movement, etc
void Player::Update(const float& dt)
{
    float directionY = 0.0f;
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        directionY++;
    }
    //Move Right
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        directionY--;
    }

    //move left
    float directionX = 0.0f;
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        directionX--;
    }
    //move right
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        directionX++;
    }

    Player::move(Vector2f(directionX * _speed * dt, directionY * _speed * dt));

    Entity::Update(dt);
   


    //checking if fired
   // if (Keyboard::isKeyPressed(Keyboard::W))
   // {
        //if key is pressed, then bullet it fired
    //    Bullet::Fire(Player::getPosition(), true);
    //}
}
*/

using namespace sf;
using namespace std;

void Player::Update(double dt) {
    //Move in four directions based on keys
    //when direction = 0 speed will not be applied to that axis
    //when direction is positive- speed will be that direction
    //Move left
    float directionY = 0.0f;
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        directionY++;
    }
    //Move Right
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        directionY--;
    }

    //move left
    float directionX = 0.0f;
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        directionX--;
    }
    //move right
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        directionX++;
    }

    Player::move(Vector2f(directionX * _speed * dt, directionY * _speed * dt));

    Entity::Update(dt);
}

Player::Player()
    : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
    _shape->setFillColor(Color::Yellow);
    _shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::Render() 
{
    Renderer::queue(_shape.get());
}