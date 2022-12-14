#pragma once
#include "UiMgr.h"
#include "../GameObject/TextObj.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/Player.h"
#include <vector>

enum class Stage
{
	None = -1,
	Start,
	Monster,
	Map,
	Question,
	Shop,
	Reword,
	Boss,
};

class BossMonster;
class Monster;
class PlayUi : public UiMgr
{
protected:
	bool gameSound = true;
	bool bossStageSound = false;

	SpriteObj* tempBackground;

	// ironClad
	TextObj* ironCladMaxHp;
	TextObj* ironCladCurHp;
	TextObj* ironCladCurEnergy;
	TextObj* ironCladMaxEnergy;
	TextObj* ironCladCurDefend;

	TextObj* attackCount;
	TextObj* defendCount;

	SpriteObj* attackButton;
	SpriteObj* defendButton;
	SpriteObj* actionWindow;

	SpriteObj* normalAttackButton;
	SpriteObj* attackSkillButton1;
	SpriteObj* attackSkillButton2;

	SpriteObj* ternPassButton;
	SpriteObj* ternPassButtonHover;
	bool isHover = false;
	bool uiHoverSoundPlay = true;

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
	SpriteObj* bossMapIcon;
	SpriteObj* bossMapIconOutLine;

	SpriteObj* monsterMapIconOutLine;
	SpriteObj* rewordMapIconOutLine;
	SpriteObj* shopMapIconOutLine;
	SpriteObj* questionMapIconOutLine;

	int monsterMapOrder;
	int rewordMapOrder;
	int questionMapOrder;
	int shopMapOrder;
	int bossMapOrder = 4;

	int choiceOrder = 0;

	// choice
	SpriteObj* choice1;
	SpriteObj* choice2;
	SpriteObj* choice3;

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
	float choiceDelay;
	bool chooseOption = true;

	SpriteObj* playerCurHpBar;
	SpriteObj* playerMaxHpBar;
	SpriteObj* monsterCurHpBar;
	SpriteObj* monsterMaxHpBar;

	Stage stage = Stage::Start;

	SpriteObj* clearBackground;
	SpriteObj* continueButton;

	// die
	SpriteObj* dieOrGiveup;
	TextObj* floors;
	TextObj* monsterKilled;
	int monsterKillCount;

	SpriteObj* gameOffButton;

	// BossClear
	SpriteObj* gameClearBackground;
	TextObj* clearText;


	// shop
	SpriteObj* damageUp;
	SpriteObj* defenseUp;
	SpriteObj* energyUp;
	SpriteObj* hpUp;
	SpriteObj* getSmite;
	SpriteObj* getClubbing;
	
	// Skill Unlock Gold
	TextObj* getSmiteGold;
	TextObj* getClubbingGold;

	// reword
	SpriteObj* chest;
	SpriteObj* rewordImage;
	TextObj* addGold;
	TextObj* addDamage;
	TextObj* addDefend;
	TextObj* addHp;
	TextObj* rewordText;
	bool randomReword = true;
	bool rewordUi = false;
	int randomChoice;
	int getGold;
	int getDamage;
	int getDefend;
	int getHp;
	bool mapChoice = false;

	bool isAttackSkill = false;
	bool smiteOn = false;
	bool clubbingOn = false;
	bool isChestOpen = false;


	// boss
	BossMonster* boss;
	int bossCount = 1;
	float nukeDelay = 0.2f;

	SpriteObj* bossPlasma1;
	SpriteObj* bossPlasma2;
	SpriteObj* bossPlasma3;
	SpriteObj* bossShadow;

	float dieDelay;

	int firstPatturn = -1;
	int secondPatturn = 8;
	int bossSecondPatturn = 1;


	//energy image
	SpriteObj* energyLayer;
	SpriteObj* energyLayer1;
	SpriteObj* energyLayer2;
	SpriteObj* energyLayer3;
	SpriteObj* energyLayer4;
	SpriteObj* energyLayer5;


	// map clear icon
	vector<SpriteObj*> mapClearIcon;
	SpriteObj* mapChoiceCircle;

	// Weaken Text
	TextObj* playerWeakenText;
	TextObj* monsterWeakenText;


	// Attack Skill Info
	SpriteObj* normalAttackInfo;
	SpriteObj* smiteInfo;
	SpriteObj* clubbingInfo;

	// Attack Skill Damage Text
	TextObj* normalAttackDamageText;
	TextObj* smiteDamageText;
	TextObj* clubbingDamageText;

	// Player / Monster Block Image
	SpriteObj* monsterBlock;
	SpriteObj* playerBlock;

	// attack ui
	SpriteObj* monsterAttackImage;
	SpriteObj* playerAttackImage;
	float attackDelay;
	float monsterAttackDelay;
	bool lastEnergyAttack = true;
	float playerTurnSoundDelay = 1.f;

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

	void MonsterAttack(float dt);
	void PlayerAttack(float dt, Skill skill);

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

	void EnterTheStage(float dt);

	void QuestionStage();

	void ShopStage();

	void RewordStage();

	void StartMapPlayerUpgrade(float dt);

	void SetDieUi(bool set);

	void SetShopMapUi(bool set);

	void SetRewordMapUi(bool set);

	void SetRewordUi(bool set);

	void SetAttackSkillUi(bool set);
	void SetDefenseSkillUi(bool set);

	static Player* ironClad;
	static Player* GetPlayer(PlayerType type);

	static vector<Monster*> monster;
	static Monster* GetMonster();

	SpriteObj* cursor;
	SpriteObj* GetCursor() { return cursor; };

	static SpriteObj* mainMenuButton;
	static SpriteObj* GetMainMenuButton() { return mainMenuButton; };

	void ResetPlayUi();

	void PlayerAttackDamage(int damage);
	void MonsterAttackDamage(int damage);

	void AttackButtonControl(int monsterCount, float dt);

	void SetGameClearUi(bool set);
};