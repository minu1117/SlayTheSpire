#include "SceneDev2_Play.h"
#include "../InlcludeHeader/SceneIncludeHeader.h"
#include "../Framework/Button.h"
#include "../UI/PlayUi.h"
//#include "../GameObject/Monster.h"

SceneDev2_Play::SceneDev2_Play()
	: Scene(Scenes::Dev2)
{
}

SceneDev2_Play::~SceneDev2_Play()
{
}

void SceneDev2_Play::Init()
{
	Release();

	uiMgr = new PlayUi(this);
	uiMgr->Init();

	for (auto obj : objList)
	{
		obj->Init();
	}
}

void SceneDev2_Play::Release()
{
	if (uiMgr != nullptr)
	{
		uiMgr->Release();
		delete uiMgr;
		uiMgr = nullptr;
	}

	Scene::Release();
}

void SceneDev2_Play::Enter()
{
	FRAMEWORK->GetWindow().setMouseCursorVisible(false);
	FRAMEWORK->GetWindow().setMouseCursorGrabbed(true);
	Vector2i size = FRAMEWORK->GetWindowSize();

	worldView.setSize(size.x, size.y);
	worldView.setCenter(0.f, 0.f);

	uiView.setSize(size.x, size.y);
	uiView.setCenter(size.x * 0.5f, size.y * 0.5f);
}

void SceneDev2_Play::Exit()
{
	uiMgr->Reset();
}

void SceneDev2_Play::Update(float dt)
{
	Scene::Update(dt);

	//if (InputMgr::GetKeyDown(Keyboard::Key::Escape))
	//{
	//	SCENE_MGR->ChangeScene(Scenes::Dev1);
	//}

	uiMgr->Update(dt);
}

void SceneDev2_Play::Draw(RenderWindow& window)
{
	Scene::Draw(window);

	window.setView(worldView);
	uiMgr->Draw(window);
}
