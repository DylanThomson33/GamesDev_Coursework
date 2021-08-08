#pragma once
#include "Entity.h";

class Ghost : public Entity {
private:
	float _speed;

public:
	void Update(double dt) override;
	Ghost();
<<<<<<< Updated upstream
	void Render(sf::RenderWindow& window) const override;

	void SetColour(sf::Color c) { _shape->setFillColor(c); }

=======
	void Render() override;
>>>>>>> Stashed changes
};