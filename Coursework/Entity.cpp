<<<<<<< Updated upstream
=======
#include "Entity.h";
#include "Global_Values.h";
#include "Render.h";

using namespace std;
using namespace sf;

//constructor
Entity::Entity(unique_ptr<Sprite> s) : _sprite(std::move(s)) {}

const Vector2f Entity::getPosition() { return _position; }

void Entity::setPosition(const Vector2f& pos) { _position = pos; }

void Entity::move(const Vector2f& pos) { _position += pos; }

void Entity::Update(const double dt) {
    _sprite->setPosition(_position);
}

//sends shape to renderer
void Entity::Render() 
{
    Renderer::queue(_sprite.get());
}

void EntityManager::update(const double dt)
{
    for (std::shared_ptr<Entity>& e : list)
    {
        //updates all objects in list
        e->Update(dt);
    }
}

void EntityManager::render()
{
    for (std::shared_ptr<Entity>& e : list)
    {
        e->Render();
    }
}
>>>>>>> Stashed changes
