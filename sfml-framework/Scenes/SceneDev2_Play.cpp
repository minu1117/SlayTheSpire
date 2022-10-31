#include "SceneDev2_Play.h"
#include "../InlcludeHeader/SceneIncludeHeader.h"
#include "../Framework/Button.h"
#include "../UI/PlayUi.h"
#include "../UI/UiDev1.h"

bool SceneDev2_Play::isAttack = false;
float SceneDev2_Play::attackDelay = 0.f;
bool SceneDev2_Play::monsterIsAttack = false;
float SceneDev2_Play::monsterAttackDelay = 0.f;

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

	if (Button::ButtonOnRect(*UiDev1::GetCursor(), *PlayUi::GetMainMenuButton()))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && PlayUi::GetMainMenuButton()->GetActive() == true)
		{
			SCENE_MGR->ChangeScene(Scenes::Dev1);
		}
	}
	
	ViewShakePlayerAttack(dt);
	ViewShakeMonsterAttack(dt);
	uiMgr->Update(dt);
}

void SceneDev2_Play::Draw(RenderWindow& window)
{
	Scene::Draw(window);

	window.setView(worldView);
	uiMgr->Draw(window);
}

void SceneDev2_Play::ViewShakePlayerAttack(float dt)
{
	if (isAttack == false)
		return;

	attackDelay -= dt;

	auto& uiView = Scene::GetUiView();
	Vector2i size = FRAMEWORK->GetWindowSize();
	Vector2f rightMove = { 1920 * 0.5f + 50.f, 1080 * 0.5f };
	Vector2f leftMove = { 1920 * 0.5f, 1080 * 0.5f };
	auto& view = uiView.getCenter();

	if (isAttack == true && attackDelay <= 0.f)
	{
		if (viewShakeRight == true)
		{
			uiView.setCenter(view.x + (dt * 2000.f), uiView.getCenter().y);
			if (view.x >= rightMove.x)
			{
				viewShakeRight = false;
				viewShakeLeft = true;
			}
		}
		if (viewShakeLeft == true)
		{
			uiView.setCenter(view.x - (dt * 1000.f), uiView.getCenter().y);

			if (view.x <= leftMove.x)
			{
				viewShakeRight = true;
				viewShakeLeft = false;
				isAttack = false;
			}
		}
	}
}

void SceneDev2_Play::ViewShakeMonsterAttack(float dt)
{
	if (monsterIsAttack == false)
		return;

	monsterAttackDelay -= dt;

	auto& uiView = Scene::GetUiView();
	Vector2i size = FRAMEWORK->GetWindowSize();
	Vector2f topMove = { 1920 * 0.5f, 1080 * 0.5f - 50.f };
	Vector2f lowMove = { 1920 * 0.5f, 1080 * 0.5f };
	auto& view = uiView.getCenter();

	if (monsterIsAttack == true && monsterAttackDelay <= 0.f)
	{
		if (viewShakeTop == true)
		{
			uiView.setCenter(view.x, view.y - (dt * 3000.f));
			if (view.y <= topMove.y)
			{
				viewShakeTop = false;
				viewShakeLow = true;
			}
		}
		if (viewShakeLow == true)
		{
			uiView.setCenter(view.x, view.y + (dt * 2000.f));

			if (view.y >= lowMove.y)
			{
				viewShakeTop = true;
				viewShakeLow = false;
				monsterIsAttack = false;
			}
		}
	}
}