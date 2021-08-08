#include <SFML/Graphics.hpp>
#include "iostream";
#include "Global_Values.h";
#include "Entity.h";
#include "Enemy.h";
#include "Player.h";
#include "Planets.h";
#include "Render.h";




EntityManager em;
std::shared_ptr <Player> p1 = std::make_shared<Player>();
std::shared_ptr <Ghost> g1 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g2 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g3 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g4 = std::make_shared<Ghost>();

void Load()
{
    

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
    
    em.update(dt);
}

void Render(sf::RenderWindow& window)
{
   
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