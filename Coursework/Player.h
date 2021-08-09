#pragma once

//inherits from ship
//adds score, fuel, etc

#include "Entity.h";


class Player : public Entity {
private:
	float _acceleration;
	//sf::Vector2f _speed;
public:
	void Update(double dt) override;
	Player();
  
	float getDirection();
	float getSpeed();
  void Render() override;
};
