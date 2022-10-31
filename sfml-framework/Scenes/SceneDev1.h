#pragma once
#include "Scene.h"

class SpriteObj;
class SceneDev1 : public Scene
{
protected:
	bool viewShakeTop = true;
	bool viewShakeLow = false;
	int shakeTimes = 2;

public:
	SceneDev1();
	virtual ~SceneDev1();

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	static bool isCharSelect;
	static void SetIsCharSelect(bool set) { isCharSelect = set; };

	void ViewShakeCharSelect(float dt);
};

