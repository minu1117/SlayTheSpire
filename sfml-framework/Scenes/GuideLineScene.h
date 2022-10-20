#pragma once
#include "Scene.h"

class GuideLineScene : public Scene
{
protected:

public:
	GuideLineScene();
	virtual ~GuideLineScene() {};

	virtual void Init() override;
	virtual void Exit() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override { Scene::Draw(window); };
};

