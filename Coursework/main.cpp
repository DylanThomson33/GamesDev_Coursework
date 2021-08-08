#include <SFML/Graphics.hpp>
#include "iostream";
#include "Global_Values.h";
#include "Entity.h";
#include "Enemy.h";
#include "Player.h";
#include "Planets.h";
#include "Render.h";

<<<<<<< Updated upstream

/*
sf::Texture spritesheet;
auto rect = sf::IntRect(0, 0, 32, 32);
sf::Vector2f position(150,150);
auto e1 = new Enemy(rect, position);
auto p1 = new Player;
std::vector<Entity*> ents;
*/

EntityManager em;
std::shared_ptr <Player> p1 = std::make_shared<Player>();
std::shared_ptr <Ghost> g1 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g2 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g3 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g4 = std::make_shared<Ghost>();

void Load()
{
    /*
    //testing if spritesheet loaded correctly 
    if (!spritesheet.loadFromFile("C:/Users/Dylan/year3_games_summer/res/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    ents.push_back(e1);
    ents.push_back(p1);
    */
=======
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
>>>>>>> Stashed changes

    g1->SetColour(sf::Color::Green);
    g1->setPosition(sf::Vector2f(150, 30));
    g2->SetColour(sf::Color::Blue);
    g2->setPosition(sf::Vector2f(200, 234));
    g3->SetColour(sf::Color::Red);
    g3->setPosition(sf::Vector2f(50, 143));
    g4->SetColour(sf::Color::Magenta);
    g4->setPosition(sf::Vector2f(700, 356));

    em.list.push_back(p1);
    em.list.push_back(g1);
    em.list.push_back(g2);
    em.list.push_back(g3);
    em.list.push_back(g4);
}

void Update(sf::RenderWindow& window)
{
    // Reset clock, recalculate deltatime
    static sf::Clock clock;
    float dt = clock.restart().asSeconds();
    // check and consume events
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return;
        }
    }
    /*
    for (auto& e : ents) {
        e->Update(dt);
    };
    */
    em.update(dt);
}

void Render(sf::RenderWindow& window)
{
    /*
    for (const auto e : ents) {
        window.draw(*e);
    }
    */
    Renderer::initialise(window);
    //goes through all drawable objects and renders it based on order of queue
    em.render(window);
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