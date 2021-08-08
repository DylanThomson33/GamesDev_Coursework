#pragma once
#include "Entity.h";
/*
class Enemy : public Entity {

public:
    static bool direction;
    static float speed;
    Enemy(sf::IntRect ir, sf::Vector2f pos);
    Enemy();
    void Update(const float& dt) override;
};
*/

class Ghost : public Entity {
private:
	float _speed;

public:
	void Update(double dt) override;
	Ghost();
	void Render(sf::RenderWindow& window) const override;

	void SetColour(sf::Color c) { _shape->setFillColor(c); }

};