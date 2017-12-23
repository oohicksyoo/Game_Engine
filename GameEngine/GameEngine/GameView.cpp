#include "stdafx.h"
#include "GameView.h"

Engine::GameView::GameView() {
	isPlaying = false;
	isFullscreen = false;


	camera.reset(FloatRect(0, 0, 750, 400));

	renderTexture.create(750, 400);
	renderTexture.setActive();
}

Engine::GameView::~GameView()
{
	//Use after copy of entity to new pointer is done
	for (auto it = hierarchy.begin(); it != hierarchy.end(); it++) {

		delete (*it);
	}
	hierarchy.clear();
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

		if (isPlaying) {
			e->CallUpdate();
		}		

		//Graphics Component
		auto gc = e->GetComponent<GraphicsComponent>();
		if (gc != nullptr) {
			Sprite s = gc->GetSprite();

			//Transform Component
			auto t = e->GetComponent<TransformComponent>();
			if (t != nullptr) {
				s.setPosition(t->GetPosition());
				s.setRotation(t->GetRotation());
				//s.setScale(t->GetScale());
			}
			

			renderTexture.draw(s);
		}
		
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

void Engine::GameView::SetIsPlaying(bool value)
{
	isPlaying = value;

	if (isPlaying) {
		//TODO: Save kinda like meta data of where everything was?
		Debug::getInstance().ClearLogWindow();
	} else {
		//TODO: Clear everything back to starting position
	}
}

bool Engine::GameView::GetIsPlaying()
{
	return isPlaying;
}

