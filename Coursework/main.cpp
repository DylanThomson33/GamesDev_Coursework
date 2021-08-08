#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

<<<<<<< Updated upstream
//There's probably a more elegant way to do this
const int gameWidth = 800;
const int gameHeight = 600;

=======
EntityManager em;
std::shared_ptr <Player> p1 = std::make_shared<Player>();
std::shared_ptr <Ghost> g1 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g2 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g3 = std::make_shared<Ghost>();
std::shared_ptr <Ghost> g4 = std::make_shared<Ghost>();
>>>>>>> Stashed changes

void Reset()
{
<<<<<<< Updated upstream
	//FR i think we should use this as a respawn method - it probably needs moved to another class though
}
=======
    
>>>>>>> Stashed changes

void Load() {
	// Update Everything
	

	Reset();
}

<<<<<<< Updated upstream
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
}

=======
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
>>>>>>> Stashed changes

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
