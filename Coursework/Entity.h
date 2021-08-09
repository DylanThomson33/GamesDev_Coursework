#pragma once
<<<<<<< Updated upstream
//basic object class
//position
//sprite
=======
#include <SFML/Graphics.hpp>

class Entity {
public:
	//constructor
	Entity() = delete;
	//deconstructor
	virtual ~Entity() = default;

	//update function - can be overwritten by inherited classes
	virtual void Update(const double dt);
	//render runction - can be overwitten by inherited classes
	virtual void Render();

	//gets position of entity
	const sf::Vector2f getPosition();
	//sets potition of entity
	void setPosition(const sf::Vector2f& pos);
	//moves entity to position
	void move(const sf::Vector2f& pos);

protected:
	//pointer to sprite obeject, any class which inherits from entity has to be made with sprite constructor
	std::unique_ptr<sf::Sprite> _sprite;
	sf::Vector2f _position;
	//constructor
	Entity(std::unique_ptr<sf::Sprite> shp);
};

//stores list of entities which is then used to render and update each one in order
struct EntityManager {
	std::vector<std::shared_ptr<Entity>> list;
	void update(double dt);
	void render();
};
>>>>>>> Stashed changes
