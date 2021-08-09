#include "Scene_Game.h";
#include "Render.h";
#include "Player.h";
#include "Entity.h";
#include "Enemy.h";
#include "Global_Values.h";
#include "Scene.h";
#include "Planets.h";
#include <iostream>

std::shared_ptr<Scene> gameScene;

std::shared_ptr <Player> p1 = std::make_shared<Player>();
std::shared_ptr <Ghost> g1 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g2 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g3 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g4 = std::make_shared<Ghost>();
std::shared_ptr <Planet> planet1 = std::make_shared<Planet>();


void GameScene::load()
{
    g1->setPosition(sf::Vector2f(150, 30));
    g2->setPosition(sf::Vector2f(200, 234));
    g3->setPosition(sf::Vector2f(50, 143));
    g4->setPosition(sf::Vector2f(700, 356));
    planet1->setPosition(sf::Vector2f(300,300));

    _ents.list.push_back(p1);
    //_ents.list.push_back(g1);
    //_ents.list.push_back(g2);
    //_ents.list.push_back(g3);
    //_ents.list.push_back(g4);
    _ents.list.push_back(planet1);
}

void GameScene::update(double dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
        activeScene = menuScene;
    }

    sf::Vector2f ps = p1->getPosition();

    if (planet1.get()->searchRadius(ps))
    {
        std::cout << "planet is in radius" << std::endl;
        //APPLY GRAVITY TO PLAYER  
        //APPLY A FORCE TO PLAYER THAT PULLS PLAYER TOWARDS CENTRE, DEPENDING ON HOW FAR AWAY PLAYER IS FROM CENTRE 

        //measure distance from centre
       // sf::Vector2f distance = planet1.get()->getPosition() - p1.get()->getPosition();

        sf::Vector2f gravity = sf::Vector2f(0.0f,-9.8);
        p1->move(gravity);
        
        //p1->move(gravity);
        

    }
    else {
        std::cout << "planet is not in radius" << std::endl;
        //DON'T APPLY GRAVITY TO PLAYER

    }

    Scene::update(dt);
}

void GameScene::render()
{
    Scene::render();
}