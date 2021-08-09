#pragma once

//inherits from ship
//adds score, fuel, etc

#include "Entity.h";


class Player : public Entity {
private:
	float _acceleration;


public:
	void Update(double dt) override;
	Player();

	float getPrograde();
	float getSpeed();
	void Render() override;
};