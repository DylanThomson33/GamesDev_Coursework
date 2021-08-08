#pragma once
<<<<<<< Updated upstream
//inherits from ship
//adds score, fuel, etc
=======
#include "Entity.h";


class Player : public Entity {
private:
	float _acceleration;

public:
	void Update(double dt) override;
	Player();
	void Render(sf::RenderWindow& window) const override;
	float getDirection();
	float getSpeed();
<<<<<<< Updated upstream
};
>>>>>>> Stashed changes
=======
};
>>>>>>> Stashed changes
