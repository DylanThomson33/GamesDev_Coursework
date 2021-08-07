#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

//There's probably a more elegant way to do this
const int gameWidth = 800;
const int gameHeight = 600;


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
