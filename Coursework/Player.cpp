#include "Player.h";
#include "Global_Values.h";

//player constructor
Player::Player() : Entity(sf::IntRect(160, 32, 32, 32)) {
    setPosition({ gameHeight * .5f, gameHeight - 32.f });
}

void Player::Update(const float& dt)
{
    Entity::Update(dt);
}