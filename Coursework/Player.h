#pragma once
#include "Entity.h";
/*
class Player : public Entity {

public:
    float _speed;
    Player();
    void Update(const float& dt) override;
};
*/

class Player : public Entity {
private:
	float _speed;

public:
	void Update(double dt) override;
	Player();
	void Render() override;
};