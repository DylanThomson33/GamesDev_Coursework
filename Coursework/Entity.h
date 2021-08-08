#pragma once
#include <SFML/Graphics.hpp>
//sprite
/*
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
	virtual void Render(sf::RenderWindow& window) const = 0;

protected:
	//used to store how much it has rotated
	float _rotation;
	//sprite
	sf::IntRect _sprite;
	//constructor
	Entity();
};

struct EntityManager {
	std::vector<std::shared_ptr<Entity>> list;
	void update(double dt);
	void render(sf::RenderWindow& window);
};
*/

class Entity {
public:
	Entity() = delete;
	virtual ~Entity() = default;

	virtual void Update(const double dt);
	virtual void Render(sf::RenderWindow& window) const = 0;

	const sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& pos);
	void move(const sf::Vector2f& pos);

protected:
	std::unique_ptr<sf::Shape> _shape;
	sf::Vector2f _position;
	Entity(std::unique_ptr<sf::Shape> shp);
};

struct EntityManager {
	std::vector<std::shared_ptr<Entity>> list;
	void update(double dt);
	void render(sf::RenderWindow& window);
};