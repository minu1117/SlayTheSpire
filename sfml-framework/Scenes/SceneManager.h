#pragma once
#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "../3rd/Singleton.h"
#include <map>
using namespace sf;
using namespace std;

class SceneManager : public Singleton<SceneManager>
{
private:
	map<Scenes, Scene*> sceneMap;
	Scenes curScene;

public:
	SceneManager();
	~SceneManager() {};

	Scenes GetCurScene() const { return curScene; };
	Scene* GetScene(Scenes scene) { return sceneMap[scene]; };

	bool Init();
	void ChangeScene(Scenes scene);

	void Update(float dt);
	void Draw(RenderWindow& window);
};

#define SCENE_MGR (SceneManager::GetInstance())