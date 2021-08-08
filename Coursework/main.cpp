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
    if (!spritesheet.loadFromFile("C:/Users/Dylan/year3_games_summer/res/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    // Load Scene-Local Assets
   gameScene.reset(new GameScene());
   menuScene.reset(new MenuScene());
   gameScene->load();
   menuScene->load();
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