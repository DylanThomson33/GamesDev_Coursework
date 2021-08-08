#include "Enemy.h";
#include "Global_Values.h";
#include "Render.h";
#include <iostream>
#include <time.h>
#include <random>

using namespace sf;
using namespace std;

int rand_y;
int rand_x;

void Ghost::Update(double dt) {

    //need to add random movement
    srand(time(NULL));

    if (rand() % 2 - 1 == 0)
    {
        rand_x = -1;
    }
    else {
        rand_x = 1;
    }

    if (rand() % 2 - 1 == 0)
    {
        rand_y = -1;
    }
    else {
        rand_y = 1;
    }

    Ghost::move(Vector2f(rand_x * _speed * dt, rand_y * _speed * dt));

    //if touching right wall
    if (_position.x > 800)
    {
        Ghost::move(Vector2f(-12.5, 0));
    }
    //if touching left wall
    if (_position.x < 0)
    {
        Ghost::move(Vector2f(12.5, 0));
    }
    //if touching top wall
    if (_position.y > 600)
    {
        Ghost::move(Vector2f(0, -12.5));
    }
    //if touching bottom wall 
    if (_position.y < 0)
    {
        Ghost::move(Vector2f(0, 12.5));
    }

    Entity::Update(dt);
}

//creates ghost object and sets sprite to enemy ship
Ghost::Ghost()
    : _speed(200.0f), Entity(make_unique<sf::Sprite>()) {
    _shape->setTexture(spritesheet);
    _shape->setTextureRect(IntRect(0, 0, 32, 32));
    _shape->setOrigin(Vector2f(25.f, 25.f));
}

void Ghost::Render(sf::RenderWindow& window) const {
    //window.draw(*_shape);
    Renderer::queue(_shape.get());
}
