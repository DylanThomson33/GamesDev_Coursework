#include "Scene_MainMenu.h";
#include "Render.h";

void MenuScene::update(double dt) {
	Scene::update(dt);
	text.setString("Almost Pacman");
}

void MenuScene::render() {
	Renderer::queue(&text);
	Scene::render();
}

void MenuScene::load() {
	//Set up the text element here!
}