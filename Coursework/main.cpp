#include <SFML/Graphics.hpp>
#include "iostream";
#include "Global_Values.h";
#include "Entity.h";
#include "Enemy.h";
#include "Player.h";
#include "Planets.h";

sf::Texture spritesheet;
void Load()
{
    //testing if spritesheet loaded correctly 
    if (!spritesheet.loadFromFile("C:/Users/Dylan/year3_games_summer/res/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }

}


void Update()
{

}

void Render()
{

}


int main() {
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "CourseWork!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}