#include "Entity.h";
#include "Global_Values.h";
#include "Render.h";
/*
//constructors 
Entity::Entity() {};
Entity::Entity(sf::IntRect ir) : Sprite() {
	_sprite = ir;

	setTexture(spritesheet);
	setTextureRect(_sprite);
};

//deconstructor
Entity::~Entity() = default;

//update function
void Entity::Update(const float& dt) {}
*/

using namespace std;
using namespace sf;

const Vector2f Entity::getPosition() { return _position; }

void Entity::setPosition(const Vector2f& pos) { _position = pos; }

void Entity::move(const Vector2f& pos) { _position += pos; }

void Entity::Update(const double dt) {
    _shape->setPosition(_position);
}

Entity::Entity(unique_ptr<Shape> s) : _shape(std::move(s)) {}

void EntityManager::update(const double dt)
{
    for (std::shared_ptr<Entity>& e : list)
    {
        e->Update(dt);
    }
}

void EntityManager::render(sf::RenderWindow& window)
{
    for (std::shared_ptr<Entity>& e : list)
    {
        e->Render(window);
    }
}
