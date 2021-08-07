#include "Enemy.h";
#include "Global_Values.h";

Enemy::Enemy() {};

Enemy::Enemy(sf::IntRect ir, sf::Vector2f pos) : Entity(ir) {
	//setOrigin(16, 16);
	setPosition(pos);
}

//update
void Enemy::Update(const float& dt)
{
    Entity::Update(dt);
}


