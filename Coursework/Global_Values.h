#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h";
#include <memory>

//game height and width
constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;

//spritesheet
extern sf::Texture spritesheet;

//creating scene objects
//active scene is a placeholder for current scene being rendererd
extern std::shared_ptr<Scene> activeScene;
//setting scene will give option to change button layout, alter volume, turn of music and sound effects and change v-sync.
extern std::shared_ptr<Scene> settingScene;
//this is the main game scene
extern std::shared_ptr<Scene> gameScene;
//this is the main menu scene which will have an exit button, play button and setting menu button
extern std::shared_ptr<Scene> menuScene;

//declaring menu class
//his is where you will select what you are going to do with the application

//main menu
class MenuScene : public Scene {
private:
	sf::Text text;

public:
	MenuScene() = default;
	void update(double dt) override;
	void render() override;
	void load()override;
};

//settings menu
class SettingScene : public Scene {
private:
	sf::Text text;

public:
	SettingScene() = default;
	void update(double dt) override;
	void render() override;
	void load()override;
};

//declaring game scene class, this is where the gameplay will take place

//gamescene
class GameScene : public Scene {
private:
	sf::Text text;
	//sf::Clock scoreClock;
	void respawn();

public:
	GameScene() = default;
	void update(double dt) override;
	void render() override;
	void load() override;
};

