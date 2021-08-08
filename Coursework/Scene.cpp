#include "Scene.h";
#include "Render.h";

<<<<<<< Updated upstream
void Scene::load()
{

}

void Scene::update(double dt)
{

}

void Scene::render() 
{
	//_ents.render();
}
=======
void Scene::update(double dt)
{ 
	_ents.update(dt); 
}

void Scene::render()
{ 
	_ents.render(); 
}

std::vector<std::shared_ptr<Entity>> &Scene::getEnts()
{
	return _ents.list;
}
>>>>>>> Stashed changes
