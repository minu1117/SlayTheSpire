#pragma once
#include "UiMgr.h"
#include "../GameObject/TextObj.h"
#include "../GameObject/SpriteObj.h"
#include <vector>

enum class PlayerType // 캐릭터 추가 시 Get함수로 가져오기 위함
{
	IronClad,
};

class Monster;
class Player;
class PlayUi : public UiMgr
{
protected:
	SpriteObj* cursor;
	SpriteObj* tempBackground;

	// ironClad
	TextObj* ironCladMaxHp;
	TextObj* ironCladCurHp;
	TextObj* ironCladCurEnergy;
	TextObj* ironCladMaxEnergy;
	TextObj* ironCladCurDefend;

	// Ui
	SpriteObj* testBorder;
	TextObj* gold;
	TextObj* curHp;
	TextObj* maxHp;


	SpriteObj* backButton;
	SpriteObj* option;
	SpriteObj* optionBackground;
	SpriteObj* giveUpButton;

	SpriteObj* yesButton;
	SpriteObj* noButton;
	SpriteObj* confirmMessage;
	SpriteObj* confirmBackground;


	SpriteObj* map;
	SpriteObj* mapIcon;
	SpriteObj* mapBackground;

	// choice
	//SpriteObj* choice1;
	//SpriteObj* choice2;
	//SpriteObj* choice3;

	bool optionUi = false;
	bool mapUi = false;
	bool giveupUi = false;

	//int playerSelect = 0;

	//vector<Monster*> monsters;
	Monster* monster;
	TextObj* monsterDefend;

public:
	PlayUi(Scene* scene);
	~PlayUi();
	virtual void Init() override;
	virtual void Release() override;
	virtual void Reset() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	void SetOptionUi(bool set);
	void SetMapUi(bool set);
	void SetGiveUpUi(bool set);

	static Player* ironClad;
	static Player* GetPlayer(PlayerType type);

	//void PlayerSet();
};

