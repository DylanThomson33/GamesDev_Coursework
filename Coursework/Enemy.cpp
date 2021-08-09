<<<<<<< Updated upstream
=======
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

Enemy::Enemy()
    : _speed(200.0f), Entity(make_unique<sf::Sprite>()) {
    _sprite->setTexture(spritesheet);
    _sprite->setTextureRect(sf::IntRect(32, 0, 32, 32));
    _sprite->setOrigin(Vector2f(25.f, 25.f));
}

void Enemy::Update(double dt) {

    //need to add random movement
    srand(time(NULL));


    //"random" movement ai for enemy
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

    Enemy::move(Vector2f(rand_x * _speed * dt, rand_y * _speed * dt));

    //if touching right wall
    if (_position.x > 800)
    {
        Enemy::move(Vector2f(-12.5, 0));
    }
    //if touching left wall
    if (_position.x < 0)
    {
        Enemy::move(Vector2f(12.5, 0));
    }
    //if touching top wall
    if (_position.y > 600)
    {
        Enemy::move(Vector2f(0, -12.5));
    }
    //if touching bottom wall 
    if (_position.y < 0)
    {
        Enemy::move(Vector2f(0, 12.5));
    }

    Entity::Update(dt);
}

void Enemy::Render() {
    Renderer::queue(_sprite.get());
}
>>>>>>> Stashed changes
