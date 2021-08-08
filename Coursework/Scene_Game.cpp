#include "Scene_Game.h";
#include "Render.h";
#include "Player.h";
#include "Entity.h";
#include "Enemy.h";
#include "Global_Values.h";
#include "Scene.h";

std::shared_ptr<Scene> gameScene;

std::shared_ptr <Player> p1 = std::make_shared<Player>();
std::shared_ptr <Ghost> g1 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g2 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g3 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g4 = std::make_shared<Ghost>();

void GameScene::load()
{
    g1->setPosition(sf::Vector2f(150, 30));
    g2->setPosition(sf::Vector2f(200, 234));
    g3->setPosition(sf::Vector2f(50, 143));
    g4->setPosition(sf::Vector2f(700, 356));

    _ents.list.push_back(p1);
    _ents.list.push_back(g1);
    _ents.list.push_back(g2);
    _ents.list.push_back(g3);
    _ents.list.push_back(g4);

}

void GameScene::update(double dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
        activeScene = menuScene;
    }
    Scene::update(dt);
}

void GameScene::render()
{
    Scene::render();
}