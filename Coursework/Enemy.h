#pragma once
#include "Entity.h";

class Enemy : public Entity {

public:
    static bool direction;
    static float speed;
    Enemy(sf::IntRect ir, sf::Vector2f pos);
    Enemy();
    void Update(const float& dt) override;
};