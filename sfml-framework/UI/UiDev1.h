#pragma once
#include "UiMgr.h"
#include "../GameObject/TextObj.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/Player.h"
#include <list>

class UiDev1 : public UiMgr
{
protected:
	TextObj* startText;
	SpriteObj* cursor;
	SpriteObj* test;
	SpriteObj* PlayButton;

	Player* player;
	TextObj* playerMaxHp;
	TextObj* playerCurHp;
	TextObj* playerGold;
	TextObj* playerCurEnergy;
	TextObj* playerMaxEnergy;
	TextObj* playerCurDefend;

public:
	UiDev1(Scene* scene);
	~UiDev1();
	virtual void Init() override;
	virtual void Release() override;
	virtual void Reset() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
};

