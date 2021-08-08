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
	text.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}

void MenuScene::update(double dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		activeScene = gameScene;
	}
	Scene::update(dt);
	text.setString("Almost Pacman");
}

void MenuScene::render() {
	Renderer::queue(&text);
	Scene::render();
}

