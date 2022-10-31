#pragma once
#include "Scene.h"

class SceneDev2_Play : public Scene
{
protected:
	bool viewShakeRight = true;
	bool viewShakeLeft = false;

	bool viewShakeTop = true;
	bool viewShakeLow = false;


public:
	SceneDev2_Play();
	virtual ~SceneDev2_Play();

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	void ViewShakePlayerAttack(float dt);
	void ViewShakeMonsterAttack(float dt);

	static float attackDelay;
	static void SetAttackDelay(float set) { attackDelay = set; };

	static bool isAttack;
	static void SetIsAttack(bool set) { isAttack = set; };


	static float monsterAttackDelay;
	static void SetMonsterAttackDelay(float set) { monsterAttackDelay = set; };

	static bool monsterIsAttack;
	static void SetIsMonsterAttack(bool set) { monsterIsAttack = set; };
};

