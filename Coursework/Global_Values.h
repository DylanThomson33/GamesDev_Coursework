#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h";

//game height and width
constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;

//spritesheet
extern sf::Texture spritesheet;

<<<<<<< Updated upstream
//Scenes
extern std::shared_ptr<Scene> menuScene;
extern std::shared_ptr<Scene> settingsScene;
extern std::shared_ptr<Scene> gameScene;

//current active scene
extern std::shared_ptr<Scene> activeScene;
=======
extern std::shared_ptr<Scene> gameScene;
extern std::shared_ptr<Scene> menuScene;
extern std::shared_ptr<Scene> settingScene;
extern std::shared_ptr<Scene> activeScene;
>>>>>>> Stashed changes
