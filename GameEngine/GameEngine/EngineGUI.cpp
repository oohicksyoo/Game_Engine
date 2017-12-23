#include "stdafx.h"
#include "EngineGUI.h"

Engine::EngineGUI::EngineGUI()
{
}

void Engine::EngineGUI::Initialize(RenderWindow& window) {
	SFML::Init(window);
	StyleColorsDark();
	GetStyle().FrameBorderSize = 1.0f;
}

void Engine::EngineGUI::Shutdown()
{
	SFML::Shutdown();
}

void Engine::EngineGUI::ProcessEvents(Event e)
{
	SFML::ProcessEvent(e);

	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Z && e.key.control) {
			Undo();
		} else if (e.key.code == Keyboard::Y && e.key.control) {
			Redo();
		} else if (e.key.code == Keyboard::X && e.key.control) {
			Cut();
		} else if (e.key.code == Keyboard::C && e.key.control) {
			Copy();
		} else if (e.key.code == Keyboard::V && e.key.control) {
			Paste();
		}
	}
}

void Engine::EngineGUI::Update(RenderWindow & window, Time deltaClock)
{
	SFML::Update(window, deltaClock);
}

void Engine::EngineGUI::Draw(Sprite sceneView)
{
	//Draw some widgets here	
	MenuBar();
	StatsWindow();
	EntityMenu();
	LoggingWindow();
	SceneWindow(sceneView);

	ShowTestWindow();
}

void Engine::EngineGUI::Render(RenderWindow & window)
{
	SFML::Render(window);
}

#pragma region Windows
void Engine::EngineGUI::StatsWindow()
{
	float frameRate = GetIO().Framerate;
	float cpuThread = 1000.0f / frameRate;

	//Handle plot lines data
	fpsNodes.push_back(frameRate);
	if (fpsNodes.size() >= 101) {
		fpsNodes.erase(fpsNodes.begin());
	}
	float values[100];
	copy(fpsNodes.begin(), fpsNodes.end(), values);

	//Position and setup window
	ImVec2 windowPosition = ImVec2(GetIO().DisplaySize.x, 20);
	ImVec2 windowPivot = ImVec2(1.0f, 0.0f);
	SetNextWindowPos(windowPosition, ImGuiCond_Always, windowPivot);
	SetNextWindowSize(ImVec2(125, 150));
	PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.3f)); //Transparent background
	Begin("Stats", (bool*)0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);
	Text("FPS: %.1f", frameRate);
	Text("CPU: %.1f ms", cpuThread);
	PlotLines("", values, IM_ARRAYSIZE(values), 0, "", 30, 65, ImVec2(0, 80)); //Minus 1 so the line doesnt just dip hard to the 0
	End();
	PopStyleColor();
}

void Engine::EngineGUI::MenuBar()
{

	if (BeginMainMenuBar()) {
		if (BeginMenu("File")) {

			if (MenuItem("Save")) {

			}

			Separator();

			if (MenuItem("Quit", "ALT+F4")) {
				RenderEngine::getInstance().CloseWindow();
			}

			EndMenu();
		}

		if (BeginMenu("Edit")) {
			if (MenuItem("Undo", "CTRL+Z")) {
				Undo();
			}

			if (MenuItem("Redo", "CTRL+Y", false, false)) {
				Redo();
			}

			Separator();

			if (MenuItem("Cut", "CTRL+X")) {
				Cut();
			}

			if (MenuItem("Copy", "CTRL+C")) {
				Copy();
			}

			if (MenuItem("Paste", "CTRL+V")) {
				Paste();
			}

			EndMenu();
		}

		if (BeginMenu("Window")) {
			if (BeginMenu("Theme")) {
				if (MenuItem("Classic")) {
					StyleColorsClassic();
				}

				if (MenuItem("Dark")) {
					StyleColorsDark();
				}

				if (MenuItem("Light")) {
					StyleColorsLight();
				}
				EndMenu();
			}
			EndMenu();
		}
		EndMainMenuBar();
	}
	
}

void Engine::EngineGUI::EntityMenu() {
	//Needed Properties
	vector<Entity*> entities = EntityManager::getInstance().GetEntities();
	vector<Entity*> hEntities = GameView::getInstance().GetHierarchy();

	//Window Properties
	ImVec2 windowPosition = ImVec2(0, 20); //Top left
	ImVec2 windowPivot = ImVec2(0, 0);
	SetNextWindowPos(windowPosition, ImGuiCond_Always, windowPivot);
	SetNextWindowSize(ImVec2(350, GetIO().DisplaySize.y - 20));

	//Window Design
	Begin("Properties", (bool*)0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);
	
	Entities(entities);
	Hierarchy(hEntities);
	SelectedEntity();

	End();
}

#pragma region EntityMenu Functions
void Engine::EngineGUI::Entities(vector<Entity*> Entities)
{
	if (CollapsingHeader("Entities")) {
		Indent();
		for (int i = 0; i < Entities.size(); i++) {
			Text(Entities[i]->GetName().c_str());
			if (IsItemHovered()) {
				BeginTooltip();
				string id = "ID (" + to_string(Entities[i]->GetID()) + ")";
				Text(id.c_str());
				Text("Components");
				Separator();

				//Entity Components
				vector<Component*> coms = Entities[i]->GetComponents();
				for (int x = 0; x < coms.size(); x++) {
					string componentName = coms[x]->GetComponentName();
					BulletText(componentName.c_str());
				}

				EndTooltip();
			}

			if (IsItemClicked()) {
				Debug::getInstance().Log("Just clicked entity (" + Entities[i]->GetName() + ")");
				//Create copy of Entity and send it to the game view
				Entity* e = new Entity(Entities[i]->GetState());
				e->Initialize(LuaManager::getInstance().getNewID(), Entities[i]->GetName());

				//Loop through and copy components
				vector<Component*> coms = Entities[i]->GetComponents();
				for (int i = 0; i < coms.size(); i++) {
					type_index type = coms[i]->GetType();
					string typeName = coms[i]->GetComponentName() + "component"; //Add Component to end so naming is same in the factory					
					if (type != type_index(typeid(TransformComponent))) {
						Debug::getInstance().Log("Creating component (" + typeName + ")");
						Component* c = ComponentFactory::getInstance().CreateComponent(e->GetState(), typeName);
						//Properly set properties of the component
						c->SetInformation(coms[i]->GetRef());
						e->AddComponent(type, c);
					}
				}


				GameView::getInstance().AddEntityToScene(e);
			}
		}
		Unindent();
	}
}

void Engine::EngineGUI::Hierarchy(vector<Entity*> hEntities)
{
	if (CollapsingHeader("Scene Hierarchy")) {
		Indent();
		static int selected = -1;
		for (int i = 0; i < hEntities.size(); i++) {

			//Register is this is the selected entity
			bool isSelected = (selected == i) ? true : false;
			//Make text with selected entity
			string textName = hEntities[i]->GetName() + "##" + to_string(hEntities[i]->GetID()); //This gives each entity in the UI a special ID to avoid clashing
			if (Selectable(textName.c_str(), isSelected, ImGuiSelectableFlags_AllowDoubleClick)) {
				//Make this a double click
				if (IsMouseDoubleClicked) {
					selected = (selected == i) ? -1 : i; //check to see if we are already selected

					if (selected != -1) {
						selectedHeirarchy = hEntities[i];
					}
					else {
						selectedHeirarchy = nullptr;
					}
				}
			}
			if (IsItemHovered()) {
				BeginTooltip();
				string id = "ID (" + to_string(hEntities[i]->GetID()) + ")";
				Text(id.c_str());
				Text("Components");
				Separator();

				//Entity Components
				vector<Component*> coms = hEntities[i]->GetComponents();
				for (int x = 0; x < coms.size(); x++) {
					string componentName = coms[x]->GetComponentName();
					BulletText(componentName.c_str());
				}

				EndTooltip();
			}
		}
		Unindent();
	}
}

void Engine::EngineGUI::SelectedEntity()
{
	if (CollapsingHeader("Property Panel")) {
		if (selectedHeirarchy != nullptr) {
			//Show Entity Properties here
			//Maybe have the components do the rendering?
			Indent();
			if (CollapsingHeader("Entity Information")) {
				Indent();
				selectedHeirarchy->DrawPanelInformation();
				Unindent();
			}			

			//Loop through components and create collasping Headers
			//Entity Components
			vector<Component*> coms = selectedHeirarchy->GetComponents();
			for (int x = 0; x < coms.size(); x++) {
				string componentName = coms[x]->GetComponentName();
				if (CollapsingHeader(componentName.c_str())) {
					//Component details go here
					Indent();
					coms[x]->DrawPanelInformation();
					Unindent();
				}
			}

			Unindent();
		}
	}
}
#pragma endregion

void Engine::EngineGUI::LoggingWindow() {
	Debug::getInstance().DrawConsoleWindow();
}

void Engine::EngineGUI::SceneWindow(Sprite sceneView) {
	ImVec2 windowPosition = ImVec2(375, 20); //Top left
	ImVec2 windowPivot = ImVec2(0, 0);
	SetNextWindowPos(windowPosition, ImGuiCond_Always, windowPivot);
	SetNextWindowSize(ImVec2(765, 465));// 15 border on right and bottom
	Begin("Scene View", (bool*)0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
	
	if (!GameView::getInstance().GetIsPlaying()) {
		if (Button("Play")) {
			GameView::getInstance().SetIsPlaying(true);
		}
	} else {
		if (Button("Stop")) {
			GameView::getInstance().SetIsPlaying(false);
		}
	}
	
	

	ImGui::Image(sceneView);
	End();
}
#pragma endregion

#pragma region Menu Functions
void Engine::EngineGUI::Undo()
{
	Debug::getInstance().Log("Undo");
}

void Engine::EngineGUI::Redo()
{
	Debug::getInstance().Log("Redo");
}

void Engine::EngineGUI::Cut()
{
	Debug::getInstance().Log("Cut");
}

void Engine::EngineGUI::Copy()
{
	Debug::getInstance().Log("Copy");
}

void Engine::EngineGUI::Paste()
{
	Debug::getInstance().Log("Paste");
}
#pragma endregion




