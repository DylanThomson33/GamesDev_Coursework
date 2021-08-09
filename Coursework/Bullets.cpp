#include "Bullets.h";
#include "Global_Values.h";
#include "Render.h";
#include <iostream>
#include <time.h>
#include <random>

using namespace sf;
using namespace std;

float bulletAngle;
float vulletVelocity;
float bulletScalarX;
float bulletScalarY;

Bullets::Bullets()
    : _speed(200.0f), Entity(make_unique<sf::Sprite>()) {
    _shape->setTexture(spritesheet);
    _shape->setTextureRect(sf::IntRect(0, 0, 32, 32));
    _shape->setOrigin(Vector2f(25.f, 25.f));
}

void Bullets::Fire(float x, float y, float angle, int type)
{

}



void Bullets::Update(double dt) {

    
    Bullets::move(Vector2f(bulletScalarX * _speed * dt, bulletScalarY * _speed * dt));

    Entity::Update(dt);
}

void Bullets::Render() {
    Renderer::queue(_shape.get());
}
