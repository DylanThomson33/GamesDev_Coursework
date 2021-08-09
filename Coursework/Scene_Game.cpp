<<<<<<< Updated upstream
=======
#include "Scene_Game.h";
#include "Render.h";
#include "Player.h";
#include "Entity.h";
#include "Enemy.h";
#include "Global_Values.h";
#include "Scene.h";
#include "Planets.h";
#include <iostream>


sf::Text textG;
sf::Font fontG;

//initiating
std::shared_ptr<Scene> gameScene;
//list of planets in scene 
std::vector<std::shared_ptr<Planet>> planets;
std::shared_ptr <Player> p1 = std::make_shared<Player>();
std::shared_ptr <Enemy> g1 = std::make_shared<Enemy>();
std::shared_ptr <Enemy> g2 = std::make_shared<Enemy>();
std::shared_ptr <Enemy> g3 = std::make_shared<Enemy>();
std::shared_ptr <Enemy> g4 = std::make_shared<Enemy>();
std::shared_ptr <Enemy> g5 = std::make_shared<Enemy>();
std::shared_ptr <Enemy> g6 = std::make_shared<Enemy>();
std::shared_ptr <Enemy> g7 = std::make_shared<Enemy>();
std::shared_ptr <Enemy> g8 = std::make_shared<Enemy>();
std::shared_ptr <Enemy> g9 = std::make_shared<Enemy>();
std::shared_ptr <Enemy> g10 = std::make_shared<Enemy>();
std::shared_ptr <Planet> planet1 = std::make_shared<Planet>();
std::shared_ptr <Planet> planet2 = std::make_shared<Planet>();
std::shared_ptr <Planet> planet3 = std::make_shared<Planet>();
std::shared_ptr <Planet> planet4 = std::make_shared<Planet>();
std::shared_ptr <Planet> planet5 = std::make_shared<Planet>();
std::shared_ptr <Planet> planet6 = std::make_shared<Planet>();

void GameScene::load()
{
    //setting initial position
    g1->setPosition(sf::Vector2f(150, 30));
    g2->setPosition(sf::Vector2f(600, 234));
    g3->setPosition(sf::Vector2f(1000, 143));
    g4->setPosition(sf::Vector2f(200, 356));
    g5->setPosition(sf::Vector2f(400, 556));
    g6->setPosition(sf::Vector2f(650, 50));
    g7->setPosition(sf::Vector2f(1350, 1000));
    g8->setPosition(sf::Vector2f(100, 1250));
    g9->setPosition(sf::Vector2f(1450, 156));
    g10->setPosition(sf::Vector2f(1800, 1560));
    planet1->setPosition(sf::Vector2f(300,300));
    planet2->setPosition(sf::Vector2f(800, 800));
    planet3->setPosition(sf::Vector2f(1500, 200));
    planet4->setPosition(sf::Vector2f(1240, 500));
    planet5->setPosition(sf::Vector2f(100, 900));
    planet6->setPosition(sf::Vector2f(750, 400));

    //adding to list of ents for this scene
    _ents.list.push_back(p1);
    _ents.list.push_back(g1);
    _ents.list.push_back(g2);
    _ents.list.push_back(g3);
    _ents.list.push_back(g4);
    _ents.list.push_back(g5);
    _ents.list.push_back(g6);
    _ents.list.push_back(g7);
    _ents.list.push_back(g8);
    _ents.list.push_back(g9);
    _ents.list.push_back(g10);
    _ents.list.push_back(planet1);
    _ents.list.push_back(planet2);
    _ents.list.push_back(planet3);
    _ents.list.push_back(planet4);
    _ents.list.push_back(planet5);
    _ents.list.push_back(planet6);


    //list of planets in scene
    planets.push_back(planet1);
    planets.push_back(planet2);
    planets.push_back(planet3);
    planets.push_back(planet4);
    planets.push_back(planet5);
    planets.push_back(planet6);

    // Load font - face from res dir
        fontG.loadFromFile("C:/Users/Dylan/year3_games_summer/res/fonts/Roboto-Medium.ttf");
    // Set text element to use font
    textG.setFont(fontG);
    // set the character size to 24 pixels
    textG.setCharacterSize(24);
    // Update Score Text
    textG.setString("0");
    // Keep Score Text Centered
    textG.setPosition( 100,0);
}

//updates all ents in scene as well as any game logic for scene
void GameScene::update(double dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
        activeScene = menuScene;
    }

    textG.setString("Game - Press TAB to return to main menu");

    //checks if player is in radius of planet, if player is in radius then applies a force pulling player towards centre of planet
    sf::Vector2f ps = p1->getPosition();


    for (auto p : planets)
    {
        if (p.get()->searchRadius(ps))
        {
            std::cout << "planet is in radius" << std::endl;

            //x dist and y dist
            float xdist;
            float ydist;

            xdist = p.get()->getPosition().x - p1.get()->getPosition().x;
            ydist = p.get()->getPosition().y - p1.get()->getPosition().y;


            //measure distance from centre
            sf::Vector2f direction = p.get()->getPosition() - p1.get()->getPosition();
            //measure angle from planet to player


            float gravity = 2.0f;
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
            sf::Vector2f force = (direction)*gravity / (float)(pow(distance, 1.8));

            p1->move(force);

        }
        else {
            std::cout << "planet is not in radius" << std::endl;
            //DON'T APPLY GRAVITY TO PLAYER

        }

    }
   
    Scene::update(dt);
}

void GameScene::render()
{
    Renderer::queue(&textG);
    Scene::render();
    
}
>>>>>>> Stashed changes
