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


        //x dist and y dist
        float xdist;
        float ydist;

        xdist = planet1.get()->getPosition().x - p1.get()->getPosition().x;
        ydist = planet1.get()->getPosition().y - p1.get()->getPosition().y;


        //measure distance from centre
        sf::Vector2f direction = planet1.get()->getPosition() - p1.get()->getPosition();
        //measure angle from planet to player
        
        
            float gravity = 5.0f;
            float tempTime = (float)dt; 
            float distance = sqrt((xdist * xdist) + (ydist * ydist));

            if (distance < 0.5f && distance > 0.0f)
            {
                distance = 0.5f;
            }
            if (distance < -0.5f && distance > 0.0f)
            {
                distance = -0.5f;
            }
            sf::Vector2f force = (direction) * gravity / (float)(pow(distance,1.8));

            p1->move(force);
        
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