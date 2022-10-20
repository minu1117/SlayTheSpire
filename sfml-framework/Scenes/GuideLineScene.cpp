#include "GuideLineScene.h"
#include "../InlcludeHeader/SceneIncludeHeader.h"

GuideLineScene::GuideLineScene()
	: Scene(Scenes::None) // Scene
{
}

void GuideLineScene::Init()
{
	// 씬 들어가기 전 작업
	// 플레이어, 몬스터 등등..
}

void GuideLineScene::Exit()
{
	// 씬 나가기 전 할 일들
	SOUND_MGR->StopAll();
}

void GuideLineScene::Update(float dt)
{
	// if (Input) { Next Scene }

	Scene::Update(dt);
}
