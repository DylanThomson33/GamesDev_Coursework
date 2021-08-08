#pragma once
#include "Scene.h";
<<<<<<< Updated upstream

class GameScene : public Scene {
private:
	sf::Text text;
	sf::Clock scoreClock;
	void respawn();

public:
	GameScene() = default;
	void update(double dt) override;
	void render() override;
	void load() override;
};
=======
//initialise all entity that are on screen during gameplay 
//inherits from scene
// all entities are updated in main
>>>>>>> Stashed changes
