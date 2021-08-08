#pragma once
<<<<<<< Updated upstream
// basic scene class
//includes - render, update, entity list, reset, etc
// look up pacman part1 for more inormation

#include "Entity.h"
class Scene {
public:
	//constructor
	Scene() = default;
	//deconstructor
	virtual ~Scene() = default;

	//update
	virtual void update(double dt);
	//render
	virtual void render();
	//load
	virtual void load() = 0;
	//list of Entites
	std::vector<std::shared_ptr<Entity>>& getEnts();

protected:
	//entities for this scene
	EntityManager _ents;
};
=======
#include "Entity.h"
class Scene {
public:
	Scene() = default;

	virtual ~Scene() = default;
	virtual void update(double dt);
	virtual void render();
	virtual void load() = 0;
	std::vector<std::shared_ptr<Entity>>& getEnts();

protected:
	EntityManager _ents;
};
>>>>>>> Stashed changes
