#pragma once

//inherits from ship
//adds score, fuel, etc

#include "Entity.h";
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes

class Player : public Entity {
private:
	float _acceleration;


public:
	void Update(double dt) override;
	Player();
	void Render(sf::RenderWindow& window) const override;
	float getDirection();
	float getSpeed();

};

