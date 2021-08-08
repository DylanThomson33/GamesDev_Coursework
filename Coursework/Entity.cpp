#include "Entity.h";
#include "Global_Values.h";
#include "Render.h";

using namespace std;
using namespace sf;

const Vector2f Entity::getPosition() { return _position; }

void Entity::setPosition(const Vector2f& pos) { _position = pos; }

void Entity::move(const Vector2f& pos) { _position += pos; }

void Entity::Update(const double dt) {
    _shape->setPosition(_position);
}

<<<<<<< Updated upstream
Entity::Entity(unique_ptr<Shape> s) : _shape(std::move(s)) {}
=======
//sends shape to renderer
void Entity::Render() 
{
    Renderer::queue(_shape.get());
}

//sets new sprite to private sprite variable
Entity::Entity(unique_ptr<Sprite> s) : _shape(std::move(s)) {} 
>>>>>>> Stashed changes

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
