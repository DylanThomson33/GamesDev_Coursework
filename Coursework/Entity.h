#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite 
{
public:

	//constructor
	explicit Entity (sf::IntRect ir);
	//decontructor
	virtual ~Entity();

	//getters
	float getRotation() { return _rotation; }

	//setters
	virtual void Update(const float& dt);
	void setRotation(float r) { _rotation = r; };

protected:
	float _rotation;
	sf::IntRect _sprite;
	Entity();
};



