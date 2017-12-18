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

Engine::GameView::~GameView()
{
	//TODO: Use after copy of entity to new pointer is done
	/*(for (auto it = hierarchy.begin(); it != hierarchy.end(); it++) {

		delete (*it);
	}
	hierarchy.clear();*/
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
	renderTexture.clear(Color::Black);
	renderTexture.resetGLStates();

	//Camera Work
	renderTexture.setView(camera);

	//Drawing
	//renderTexture.draw(sprite);
	for (int i = 0; i < hierarchy.size(); i++) {
		Entity* e = hierarchy[i];
		//GraphicsComponent* c = e->GetGraphics();
		auto gc = e->GetComponent<GraphicsComponent>();
		Sprite s = gc->GetSprite();
		renderTexture.draw(s);
	}

	//Displaying
	renderTexture.display();
	return renderTexture.getTexture();
}

void Engine::GameView::AddEntityToScene(Entity * entity)
{
	hierarchy.push_back(entity);
}

vector<Entity*> Engine::GameView::GetHierarchy()
{
	return hierarchy;
}

