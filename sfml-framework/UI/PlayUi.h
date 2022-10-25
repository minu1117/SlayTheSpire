#pragma once
#include "UiMgr.h"
#include "../GameObject/TextObj.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/Player.h"
#include <vector>

enum class Stage
{
	Start,
	Monster,
	Map,
	Question,
	Shop,
	Reword,
};

class Monster;
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
	TextObj* ironCladDamage;

	TextObj* attackCount;
	TextObj* defendCount;

	SpriteObj* attackButton;
	SpriteObj* defendButton;
	SpriteObj* actionWindow;

	SpriteObj* ternPassButton;

	// Ui
	SpriteObj* testBorder;
	TextObj* gold;
	TextObj* curHp;
	TextObj* maxHp;

	// option
	SpriteObj* backButton;
	SpriteObj* option;
	SpriteObj* optionBackground;
	SpriteObj* giveUpButton;

	// giveup
	SpriteObj* yesButton;
	SpriteObj* noButton;
	SpriteObj* confirmMessage;
	SpriteObj* confirmBackground;

	// map
	SpriteObj* map;
	SpriteObj* mapIcon;
	SpriteObj* mapBackground;

	SpriteObj* monsterMapIcon;
	SpriteObj* rewordMapIcon;
	SpriteObj* questionMapIcon;
	SpriteObj* shopMapIcon;

	int monsterMapOrder;
	int rewordMapOrder;
	int questionMapOrder;
	int shopMapOrder;

	int choiceOrder = 0;

	// choice
	//SpriteObj* choice1;
	//SpriteObj* choice2;
	//SpriteObj* choice3;

	bool optionUi = false;
	bool mapUi = false;
	bool giveupUi = false;

	// Monster
	TextObj* monsterDefend;
	TextObj* monsterMaxHp;
	TextObj* monsterCurHp;
	TextObj* monsterDamage;
	TextObj* monsterPattern;
	bool monsterRandomPatternSetting = true;
	bool isMonsterTern = true;
	bool isPlayerTern = true;
	bool playerActionCountSet = true;
	bool isStageClear = false;
	int randomMonsterPattern;
	int monsterCount;
	float monsterPatternDelay;

	SpriteObj* playerCurHpBar;
	SpriteObj* playerMaxHpBar;
	SpriteObj* monsterCurHpBar;
	SpriteObj* monsterMaxHpBar;

	Stage stage = Stage::Start;

	SpriteObj* clearBackground;
	SpriteObj* continueButton;

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
	void SetActionUi(bool set);
	void SetClearUi(bool set);

	void MonsterAttack();
	void PlayerAttack(float dt);

	void MonsterSet(vector<Monster*> monster, bool set);

	void SetNextMonsterAction();
	void PlayerTern(float dt);
	void MonsterAction(float dt);

	void OptionUiControl();
	void MapUiControl();
	void GiveUpUiControl();
	void SetMonsterTern();

	void UiCreate();

	void HpControl();

	void SetStage(Stage s) { stage = s; };
	const Stage& GetStage() { return stage; };

	void SetMonsterStage(float dt);

	void EnterTheStage();

	void QuestionStage();

	static Player* ironClad;
	static Player* GetPlayer(PlayerType type);

	static vector<Monster*> monster;
	static Monster* GetMonster();
};

