#include "stdafx.h"
#include "GameView.h"

Engine::GameView::GameView() {
	isPlaying = false;
	isFullscreen = false;

	//Pre setting some things to test scene mode
	if (texture.loadFromFile("Textures/Checker.png")) {
		Debug::getInstance().Log("Loaded Checker Texture");
	}
	sprite.setTexture(texture, true);

	camera.reset(FloatRect(0, 0, 750, 400));

	renderTexture.create(750, 400);
	renderTexture.setActive();
}

void Engine::GameView::ProcessEvents(Event e) {
	if (e.type == Event::MouseButtonPressed) {
		/*if (e.mouseButton.button == Mouse::Left) {
			camera.move(Vector2f(10, 0));
		}

		if (e.mouseButton.button == Mouse::Right) {
			camera.move(Vector2f(-10, 0));
		}*/
	}
}

Texture Engine::GameView::GetSceneView() {
	//Cleanup
	renderTexture.clear(Color::Red);
	renderTexture.resetGLStates();

	//Camera Work
	renderTexture.setView(camera);

	//Drawing
	renderTexture.draw(sprite);

	//Displaying
	renderTexture.display();
	return renderTexture.getTexture();
}

