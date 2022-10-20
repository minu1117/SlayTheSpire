#include "SceneManager.h"
// ������ ���� ��Ŭ���

SceneManager::SceneManager() : curScene(Scenes::None) {}

bool SceneManager::Init()
{
	// SceneMap�� ���� �־��ֱ�

	//sceneMap[Scenes::Dev1] = new SceneDev1();
	//sceneMap[Scenes::Dev2] = new SceneDev2();

	//curScene = Scenes::Dev1;


	sceneMap[curScene]->Init();

	return true;
}

void SceneManager::ChangeScene(Scenes scene)
{
	sceneMap[curScene]->Exit();
	curScene = scene;

	sceneMap[curScene]->Init();
}

void SceneManager::Update(float dt)
{
	sceneMap[curScene]->Update(dt);
}

void SceneManager::Draw(RenderWindow& window)
{
	sceneMap[curScene]->Draw(window);
}
