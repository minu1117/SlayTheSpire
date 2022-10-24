#pragma once
#include "Scene.h"

//class Player;
//class Monster;
class SceneDev2_Play : public Scene
{
protected:
	//Player* ironClad;
	//Monster* monster;

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

