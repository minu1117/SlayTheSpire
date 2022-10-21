#pragma once
#include "Scene.h"

class SceneDev2_Play : public Scene
{
protected:


public:
	SceneDev2_Play();
	virtual ~SceneDev2_Play();

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
};

