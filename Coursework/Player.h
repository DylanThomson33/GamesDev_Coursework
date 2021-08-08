#pragma once
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
<<<<<<< Updated upstream
};
>>>>>>> Stashed changes
=======
};
>>>>>>> Stashed changes
=======
};
>>>>>>> Stashed changes
