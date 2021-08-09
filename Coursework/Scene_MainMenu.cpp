<<<<<<< Updated upstream
=======
#include "Scene_MainMenu.h";
#include "Render.h";
#include "Global_Values.h";
#include "Scene.h";

sf::Text text;
sf::Font font;
std::shared_ptr<Scene> menuScene;

void MenuScene::load() {
	//Set up the text element here!

	// Load font-face from res dir
	font.loadFromFile("C:/Users/Dylan/year3_games_summer/res/fonts/Roboto-Medium.ttf");
	// Set text element to use font
	text.setFont(font);
	// set the character size to 24 pixels
	text.setCharacterSize(24);
	// Update Score Text
	text.setString("0");
	// Keep Score Text Centered
	text.setPosition(gameWidth * 0.5, gameHeight * 0.5);
}

void MenuScene::update(double dt) {

	//menu -> game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		activeScene = gameScene;
	}

	//menu -> settings
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		activeScene = settingScene;
	}

	//menu -> EXIT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		abort();
	}

	Scene::update(dt);
	text.setString("Main menu, press spacebar to play, press S to go to settings, press E to abort");
}

void MenuScene::render() {
	Renderer::queue(&text);
	Scene::render();
}

>>>>>>> Stashed changes
