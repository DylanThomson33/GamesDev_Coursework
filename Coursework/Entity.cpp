#include "Entity.h";
#include "Global_Values.h";

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
