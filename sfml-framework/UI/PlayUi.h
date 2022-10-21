#pragma once
#include "UiMgr.h"
#include "../GameObject/TextObj.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/Player.h"

class PlayUi : public UiMgr
{
protected:
	SpriteObj* cursor;

	Player* player;
	TextObj* playerMaxHp;
	TextObj* playerCurHp;
	TextObj* playerGold;
	TextObj* playerCurEnergy;
	TextObj* playerMaxEnergy;
	TextObj* playerCurDefend;

public:
	PlayUi(Scene* scene);
	~PlayUi();
	virtual void Init() override;
	virtual void Release() override;
	virtual void Reset() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
};

