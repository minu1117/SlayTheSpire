#pragma once
#include "UiMgr.h"
#include "../GameObject/TextObj.h"
#include "../GameObject/SpriteObj.h"

class Player;
class PlayUi : public UiMgr
{
protected:
	SpriteObj* cursor;
	SpriteObj* tempBackground;

	// ironClad
	Player* ironClad;
	TextObj* ironCladMaxHp;
	TextObj* ironCladCurHp;
	TextObj* ironCladGold;
	TextObj* ironCladCurEnergy;
	TextObj* ironCladMaxEnergy;
	TextObj* ironCladCurDefend;

	// 

public:
	PlayUi(Scene* scene);
	~PlayUi();
	virtual void Init() override;
	virtual void Release() override;
	virtual void Reset() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
};

