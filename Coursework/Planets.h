#pragma once
//inherits from entity
//checks if player is in radius of gravitational pull
//adds gravity 
//adds radius - area which planet can pull from

#include "Entity.h";

class Planet : public Entity
{
public:
	//constructor
	Planet();

	//update
	void Update(double dt) override;
	//render
	void Render() override;

	//setters
	void setRadius(float r) { _radius = r; };
	//getters
	bool searchRadius(sf::Vector2f& pos);

protected:
	float _radius;
};


