#include <SFML/Graphics.hpp>
#include "iostream";
#include "Global_Values.h";
#include "Entity.h";
#include "Enemy.h";
#include "Player.h";
#include "Planets.h";
#include "Render.h";
#include "Scene.h";

std::shared_ptr<Scene> activeScene;
sf::Texture spritesheet;
void Load()
{
    if (!spritesheet.loadFromFile("D:/University/3rd year/Games Engineering/The Actual Folder Im Using For Slingshot/GamesDev_Coursework/res/SpaceSrites.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    // Load Scene-Local Assets
    gameScene.reset(new GameScene());
    menuScene.reset(new MenuScene());
    settingScene.reset(new SettingScene());
    gameScene->load();
    menuScene->load();
    settingScene->load();
    // Start at main menu
    activeScene = menuScene;

}

void Update(sf::RenderWindow& window)
{
    static sf::Clock clock;
    float dt = clock.restart().asSeconds();
    activeScene->update(dt);

}

void Render(sf::RenderWindow& window)
{
    Renderer::initialise(window);
    activeScene->render();
    Renderer::render();
}


int main() {
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "CourseWork");
    Load();
    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}