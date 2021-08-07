#pragma once
#include "Entity.h";
//inherits from entity
//checks if player is in radius of gravitational pull
//adds gravity 
//adds radius - area which planet can pull from

class Planet : public Entity
{
public:
	//setters
	void setRadius(float r) { _radius = r; };

	//getters
	bool searchRadius(sf::Vector2f& pos);
private:
	float _radius;
	bool _applyGravity;
};

