#pragma once
#include "Entity.h";

class Player : public Entity {

public:
    static float speed;
    Player();
    void Update(const float& dt) override;
};