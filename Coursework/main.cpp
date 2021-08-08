#include <SFML/Graphics.hpp>
<<<<<<< Updated upstream

int main(){
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()){
      sf::Event event;
      while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        window.close();
      }
    }
    window.clear();
    window.draw(shape);
    window.display();
  }
  return 0;
}
=======
#include <vector>
#include "Bullets.cpp"
#include "Bullets.h"
#include "game.h"
	
using namespace sf;
using namespace std;



void Reset()
{
	//FR i think we should use this as a respawn method - it probably needs moved to another class though
}

void Load() {
	// Update Everything
	

	Reset();
}

void Update(RenderWindow& window) {
	// Reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();

	// check and consume events
	Event event;

	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}

	// Quit Via ESC Key - as per usual
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		Bullets::Fire(sf::Vector2f(0.0f, 0.0f), true);
	}
}


//FR MOVE THIS SOMEWHERE ELSE 
void Render(RenderWindow& window) {
	// Draw Everything
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "S L I N G S H O T");


	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}
>>>>>>> Stashed changes
