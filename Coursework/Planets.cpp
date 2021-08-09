#include "Planets.h"
#include <iostream>
#include <time.h>
#include <random>

#include "Enemy.h";
#include "Global_Values.h";
#include "Render.h";
#include <iostream>
#include <time.h>
#include <random>

using namespace sf;
using namespace std;

Planet::Planet()
    : Entity(make_unique<sf::Sprite>()) {
    _shape->setTexture(spritesheet);
    _shape->setTextureRect(sf::IntRect(48, 16, 16, 16));
    _shape->setPosition(sf::Vector2f(gameHeight/2, gameWidth/2));
    _radius = 200.0f;
}

bool Planet::searchRadius(sf::Vector2f& pos)
{
    //if spaceship is within the radius then apply gravity.
    if (sqrt(pow((pos.x - _shape->getPosition().x), 2) + pow((pos.y - _shape->getPosition().y), 2)) < _radius)
    {
        //returns true
        return true;
    }
    else {
        //returns false
        return false;
    }
}

void Planet::Update(double dt) {

    //need to add random movement
    srand(time(NULL));
    Entity::Update(dt);
}

void Planet::Render() {
    Renderer::queue(_shape.get());
}