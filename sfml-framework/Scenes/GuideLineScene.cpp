#include "GuideLineScene.h"
#include "../InlcludeHeader/SceneIncludeHeader.h"

GuideLineScene::GuideLineScene()
	: Scene(Scenes::None) // Scene
{
}

void GuideLineScene::Init()
{
	// �� ���� �� �۾�
	// �÷��̾�, ���� ���..
}

void GuideLineScene::Exit()
{
	// �� ������ �� �� �ϵ�
	SOUND_MGR->StopAll();
}

void GuideLineScene::Update(float dt)
{
	// if (Input) { Next Scene }

	Scene::Update(dt);
}
