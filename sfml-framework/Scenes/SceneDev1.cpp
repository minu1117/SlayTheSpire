#include "SceneDev1.h"
#include "../InlcludeHeader/SceneIncludeHeader.h"
#include "../UI/UiDev1.h"
#include "../Framework/Button.h"

SceneDev1::SceneDev1()
	: Scene(Scenes::Dev1)
{
}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Init()
{
	Release();

	uiMgr = new UiDev1(this);
	uiMgr->Init();

	for (auto obj : objList)
	{
		obj->Init();
	}
}

void SceneDev1::Release()
{
	if (uiMgr != nullptr)
	{
		uiMgr->Release();
		delete uiMgr;
		uiMgr = nullptr;
	}

	Scene::Release();
}

void SceneDev1::Enter()
{
	FRAMEWORK->GetWindow().setMouseCursorVisible(false);
	FRAMEWORK->GetWindow().setMouseCursorGrabbed(true);
	Vector2i size = FRAMEWORK->GetWindowSize();

	worldView.setSize(size.x, size.y);
	worldView.setCenter(0.f, 0.f);

	uiView.setSize(size.x, size.y);
	uiView.setCenter(size.x * 0.5f, size.y * 0.5f);
}

void SceneDev1::Exit()
{
	//FRAMEWORK->GetWindow().setMouseCursorVisible(true);

	uiMgr->Reset();
}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);

	if (Button::ButtonOnRect(*UiDev1::GetCursor(), *UiDev1::GetStartButton()) == true)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
		{
			SCENE_MGR->ChangeScene(Scenes::Dev2);
		}
	}
	if (Button::ButtonOnRect(*UiDev1::GetCursor(), *UiDev1::GetExitButton()) == true &&
		UiDev1::titleUi == true)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
		{
			exit(1);
		}
	}
	uiMgr->Update(dt);
}

void SceneDev1::Draw(RenderWindow& window)
{
	Scene::Draw(window);

	window.setView(worldView);
	uiMgr->Draw(window);
}
