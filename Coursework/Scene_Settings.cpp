
#include "Scene_MainMenu.h";
#include "Render.h";
#include "Global_Values.h";
#include "Scene.h";

sf::Text texts;
sf::Font fonts;
std::shared_ptr<Scene> settingScene;

void SettingScene::load() {
	// Load font-face from res dir
	fonts.loadFromFile("C:/Users/Dylan/year3_games_summer/res/fonts/Roboto-Medium.ttf");
	// Set text element to use font
	texts.setFont(fonts);
	// set the character size to 24 pixels
	texts.setCharacterSize(24);
	// Update Score Text
	texts.setString("0");
	// Keep Score Text Centered
	texts.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}

void SettingScene::update(double dt) {

	//settings -> menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
		activeScene = menuScene;
	}
	Scene::update(dt);
	texts.setString("Settings!!!!  press 'M' to got back to menu");
}

void SettingScene::render() {
	Renderer::queue(&texts);
	Scene::render();
}

