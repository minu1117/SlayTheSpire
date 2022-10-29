#include "PlayUi.h"
#include "../InlcludeHeader/UiIncludeHeader.h"
#include "../Scenes/SceneDev2_Play.h"
#include "UiDev1.h"
#include "../GameObject/Monster.h"
#include "../Framework/SoundMgr.h"

Player* PlayUi::ironClad;
vector<Monster*> PlayUi::monster;
SpriteObj* PlayUi::mainMenuButton = new SpriteObj();

PlayUi::PlayUi(Scene* scene)
	: UiMgr(scene)
{
}

PlayUi::~PlayUi()
{
}

void PlayUi::Init()
{
	UiCreate();

	// Background
	uiObjList.push_back(tempBackground);
	uiObjList.push_back(choice1);
	uiObjList.push_back(choice2);
	uiObjList.push_back(choice3);
	uiObjList.push_back(damageUp);
	uiObjList.push_back(defenseUp);
	uiObjList.push_back(energyUp);
	uiObjList.push_back(hpUp);
	uiObjList.push_back(getSkill);

	uiObjList.push_back(rewordImage);
	uiObjList.push_back(rewordText);
	uiObjList.push_back(chest);
	uiObjList.push_back(addGold);
	uiObjList.push_back(addDamage);
	uiObjList.push_back(addDefend);
	uiObjList.push_back(addHp);

	// Action Window
	uiObjList.push_back(actionWindow);
	uiObjList.push_back(attackButton);
	uiObjList.push_back(defendButton);
	uiObjList.push_back(attackCount);
	uiObjList.push_back(defendCount);
	uiObjList.push_back(ternPassButton);
	uiObjList.push_back(ternPassButtonHover);
	uiObjList.push_back(normalAttackButton);
	uiObjList.push_back(attackSkillButton1);

	// monster
	uiObjList.push_back(monster[0]);
	uiObjList.push_back(monsterMaxHpBar);
	uiObjList.push_back(monsterCurHpBar);
	uiObjList.push_back(monsterDefend);
	uiObjList.push_back(monsterCurHp);
	uiObjList.push_back(monsterMaxHp);
	uiObjList.push_back(monsterPattern);
	uiObjList.push_back(monsterDamage);

	// player
	uiObjList.push_back(playerMaxHpBar);
	uiObjList.push_back(playerCurHpBar);
	uiObjList.push_back(ironClad);
	uiObjList.push_back(ironCladMaxHp);
	uiObjList.push_back(ironCladCurHp);
	uiObjList.push_back(ironCladCurEnergy);
	uiObjList.push_back(ironCladMaxEnergy);
	uiObjList.push_back(ironCladCurDefend);
	uiObjList.push_back(ironCladDamage);

	// clear
	uiObjList.push_back(clearBackground);
	uiObjList.push_back(continueButton);

	// map
	uiObjList.push_back(mapBackground);
	uiObjList.push_back(map);
	uiObjList.push_back(monsterMapIcon);
	uiObjList.push_back(rewordMapIcon);
	uiObjList.push_back(questionMapIcon);
	uiObjList.push_back(shopMapIcon);

	// option
	uiObjList.push_back(optionBackground);
	uiObjList.push_back(backButton);
	uiObjList.push_back(giveUpButton);
	uiObjList.push_back(gameOffButton);
	uiObjList.push_back(confirmBackground);
	uiObjList.push_back(confirmMessage);
	uiObjList.push_back(yesButton);
	uiObjList.push_back(noButton);

	// Top Ui
	uiObjList.push_back(testBorder);
	uiObjList.push_back(gold);
	uiObjList.push_back(curHp);
	uiObjList.push_back(maxHp);
	uiObjList.push_back(mapIcon);
	uiObjList.push_back(option);

	// die
	uiObjList.push_back(dieOrGiveup);
	uiObjList.push_back(floors);
	uiObjList.push_back(monsterKilled);
	uiObjList.push_back(mainMenuButton);

	cursor = UiDev1::GetCursor();
	uiObjList.push_back(cursor);

	UiMgr::Init();
}

void PlayUi::Release()
{
	UiMgr::Release();
}

void PlayUi::Reset()
{
	UiMgr::Reset();
}

void PlayUi::Update(float dt)
{
	Vector2f worldMousePos = parentScene->ScreenToUiPos((Vector2i)InputMgr::GetMousePos());
	cursor->SetPos(worldMousePos);

	// Player / Monster HP, HP Bar Control
	HpControl();
	EnterTheStage(dt);

	if (ironClad->GetAlive() == true)
		SetDieUi(false);
	else
		SetDieUi(true);


	if (stage == Stage::Start)
	{
		MonsterSet(monster, false);
		SetActionUi(false);
		StartMapPlayerUpgrade(dt);
	}

	if (Button::ButtonOnRect(*cursor, *continueButton) && continueButton->GetActive() == true)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
		{
			if (stage == Stage::Monster)
			{
				int randomStage = Utils::RandomRange(0, 5);
				int randomMonsterHp = Utils::RandomRange(36, 72);
				MonsterType randomMonsterLevel = (MonsterType)Utils::RandomRange(0, 3);

				monster[0]->SetMonster(randomMonsterHp, randomMonsterHp, 0, 0, randomMonsterLevel);
				monster[0]->SetAlive(true);
				MonsterSet(monster, true);

				SetNextMonsterAction();
				monster[0]->SetDamage(monster[0]->GetDamage());

				monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));
				monsterMaxHp->SetText("/ " + to_string(monster[0]->GetMaxHp()));
				monsterCurHp->SetText(to_string(monster[0]->GetCurHp()));

				ironClad->SetCurEnergy(ironClad->GetMaxEnergy());
				ironClad->SetMaxEnergy(ironClad->GetMaxEnergy());
				ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));
				monsterCount = monster.size();
			}

			SetClearUi(false);
			ironClad->SetDefend(0);
			ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
			randomReword = true;
			stage = Stage::Map;
			choiceOrder++;
			SOUND_MGR->Play("sounds/uiClick.wav", false);
		}
	}

	if (stage == Stage::Monster)
	{
		SetMonsterStage(dt);
		if (isMonsterTern == true)
			SetActionUi(false);

		if (Button::ButtonOnRect(*cursor, *attackButton) && isPlayerTern == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				if (isAttackSkill == false)
					isAttackSkill = true;
				else
					isAttackSkill = false;
			}
		}
		if (Button::ButtonOnRect(*cursor, *defendButton) && isPlayerTern == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				isAttackSkill = false;
			}
		}

		if (isAttackSkill == true)
			SetAttackSkillUi(true);
		else
			SetAttackSkillUi(false);
	}
	else
	{
		SetActionUi(false);
		SetClearUi(false);
		ternPassButtonHover->SetActive(false);
		isAttackSkill = false;
	}

	if (stage == Stage::Map)
	{
		MonsterSet(monster, false);
		SetActionUi(false);

		mapUi = true;
	}

	if (stage == Stage::Question)
	{
		QuestionStage();
	}

	if (stage == Stage::Reword)
	{
		MonsterSet(monster, false);
		SetActionUi(false);
		RewordStage();
	}
	else
	{
		SetRewordMapUi(false);
		SetRewordUi(false);
		chest->SetTexture(*RESOURCE_MGR->GetTexture("graphics/largeChest.png"));
	}

	if (stage == Stage::Shop)
	{
		SetShopMapUi(true);
		MonsterSet(monster, false);
		SetActionUi(false);
		ShopStage();
	}
	else
		SetShopMapUi(false);

	// Option Ui Control
	if (giveupUi == false)
		OptionUiControl();

	// Map Ui Control
	if (giveupUi == false && optionUi == false)
		MapUiControl();

	// GiveUp Ui Control
	GiveUpUiControl();

	if (skillCount == 1)
		getSkill->SetActive(false);

	UiMgr::Update(dt);
}

void PlayUi::Draw(RenderWindow& window)
{
	window.setView(parentScene->GetUiView());
	UiMgr::Draw(window);
}

Player* PlayUi::GetPlayer(PlayerType type)
{
	switch (type)
	{
	case PlayerType::IronClad:
		return ironClad;
		break;
	}
}

Monster* PlayUi::GetMonster()
{
	return monster[0];
}

void PlayUi::SetOptionUi(bool set)
{
	backButton->SetActive(set);
	optionBackground->SetActive(set);
	giveUpButton->SetActive(set);
	gameOffButton->SetActive(set);
}

void PlayUi::SetMapUi(bool set)
{
	map->SetActive(set);
	mapBackground->SetActive(set);
	monsterMapIcon->SetActive(set);
	rewordMapIcon->SetActive(set);
	questionMapIcon->SetActive(set);
	shopMapIcon->SetActive(set);
}

void PlayUi::SetGiveUpUi(bool set)
{
	confirmBackground->SetActive(set);
	yesButton->SetActive(set);
	noButton->SetActive(set);
	confirmMessage->SetActive(set);
}

void PlayUi::MonsterAttack()
{
	if (monster[0]->GetIsWeaken() == 0)
		MonsterAttackDamage(monster[0]->GetDamage());
	else if (monster[0]->GetIsWeaken() > 0)
		MonsterAttackDamage(monster[0]->GetDamage() / 2);
}

void PlayUi::PlayerAttack(float dt, Skill skill)
{
	ironClad->SetIsAttack(true);
	ironClad->Attack(dt);

	if (skill == Skill::Normal)
	{
		if (ironClad->GetIsWeaken() > 0)
			PlayerAttackDamage(ironClad->GetDamage() / 2);
		else
			PlayerAttackDamage(ironClad->GetDamage());
	}
	else if (skill == Skill::Smite)
	{
		if (ironClad->GetIsWeaken() > 0)
			PlayerAttackDamage(ironClad->GetDamage() + 5 / 2);
		else
			PlayerAttackDamage(ironClad->GetDamage() + 5);

		monster[0]->SetIsWeaken(monster[0]->GetIsWeaken() + 2);

		if (randomMonsterPattern <= 1)
			monsterDamage->SetText("A : " + to_string((int)monster[0]->GetDamage() / 2));
	}
	else if (skill == Skill::clubbing)
	{
		if (ironClad->GetIsWeaken() > 0)
			PlayerAttackDamage(ironClad->GetDamage() * 4 / 2);
		else
			PlayerAttackDamage(ironClad->GetDamage() * 4);
	}
}

void PlayUi::MonsterSet(vector<Monster*> monster, bool set)
{
	if (set == true)
	{
		for (int i = 0; i < monster.size(); i++)
		{
			if (monster[i]->GetCurHp() <= 0)
			{
				monster[i]->SetAlive(false);
				monster[i]->SetActive(false);
				monsterCurHp->SetActive(false);
				monsterMaxHp->SetActive(false);
				monsterDamage->SetActive(false);
				monsterDefend->SetActive(false);
				monsterPattern->SetActive(false);
				monsterCurHpBar->SetActive(false);
				monsterMaxHpBar->SetActive(false);
			}
			else
			{
				monster[i]->SetAlive(set);
				monster[i]->SetActive(set);

				// vector �� �����
				monsterCurHp->SetActive(set);
				monsterMaxHp->SetActive(set);
				monsterDamage->SetActive(set);
				monsterDefend->SetActive(set);
				monsterPattern->SetActive(set);
				monsterCurHpBar->SetActive(set);
				monsterMaxHpBar->SetActive(set);
			}
		}

	}
	else
	{
		for (int i = 0; i < monster.size(); i++)
		{
			monster[i]->SetAlive(set);
			monster[i]->SetActive(set);
		}

		monsterCurHp->SetActive(set);
		monsterMaxHp->SetActive(set);
		monsterDamage->SetActive(set);
		monsterDefend->SetActive(set);
		monsterPattern->SetActive(set);
		monsterCurHpBar->SetActive(set);
		monsterMaxHpBar->SetActive(set);
	}
}

void PlayUi::PlayerTern(float dt)
{
	// player tern
	int maxEnergy = ironClad->GetMaxEnergy();
	int energy = ironClad->GetCurEnergy();
	int defend = ironClad->GetDefend();

	if (playerActionCountSet == true)
	{
		int count = Utils::RandomRange(0, maxEnergy + 2);

		ironClad->SetAttackCount(count);

		int attCount = ironClad->GetAttackCount();
		ironClad->SetDefendCount((maxEnergy -= count) + 2);

		playerActionCountSet = false;
	}


	if (Button::ButtonOnRect(*cursor, *normalAttackButton) &&
		ironClad->GetAttackCount() > 0 &&
		energy > 0 && monsterCount > 0 && 
		dieOrGiveup->GetActive() == false && 
		normalAttackButton->GetActive() == true)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Left))
		{
			int attCount = ironClad->GetAttackCount();

			PlayerAttack(dt, Skill::Normal);
			ironClad->SetCurEnergy(energy -= 1);
			ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

			ironClad->SetAttackCount(attCount -= 1);
		}
	}
	if (Button::ButtonOnRect(*cursor, *attackSkillButton1) &&
		ironClad->GetAttackCount() >= 2 && 
		energy >= 2 && 
		monsterCount > 0 && 
		dieOrGiveup->GetActive() == false &&
		attackSkillButton1->GetActive() == true)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Left))
		{
			int attCount = ironClad->GetAttackCount();

			PlayerAttack(dt, Skill::Smite);
			ironClad->SetCurEnergy(energy -= 2);
			ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

			ironClad->SetAttackCount(attCount -= 2);
		}
	}


	if (Button::ButtonOnRect(*cursor, *defendButton) && ironClad->GetDefendCount() > 0 && energy > 0 && monsterCount > 0 && dieOrGiveup->GetActive() == false)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Left))
		{
			int defCount = ironClad->GetDefendCount();

			if (ironClad->GetIsWeaken() > 0)
			{
				int D = ironClad->GetAddDefend();
				ironClad->SetWeakenDefend(D / 2);

				ironClad->SetDefend(defend += ironClad->GetWeakenDefend());
				ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
				ironClad->SetCurEnergy(energy -= 1);
				ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

				ironClad->SetDefendCount(defCount -= 1);
			}
			else
			{
				ironClad->SetDefend(defend += ironClad->GetAddDefend());
				ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
				ironClad->SetCurEnergy(energy -= 1);
				ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

				ironClad->SetDefendCount(defCount -= 1);
			}
		}
	}
}

void PlayUi::SetNextMonsterAction()
{
	randomMonsterPattern = Utils::RandomRange(0, 4);
	if (randomMonsterPattern <= 1)
	{
		int setDamage = 0;

		switch (monster[0]->GetType())
		{
		case MonsterType::Easy:
			setDamage = Utils::RandomRange(4, 8);
			monster[0]->SetDamage(setDamage);
			break;
		case MonsterType::Normal:
			setDamage = Utils::RandomRange(8, 15);
			monster[0]->SetDamage(setDamage);
			break;
		case MonsterType::Hard:
			setDamage = Utils::RandomRange(6, 23);
			monster[0]->SetDamage(setDamage);
			break;
		}

		monsterPattern->SetText("ATTACK");

		if (monster[0]->GetIsWeaken() == 0)
			monsterDamage->SetText("A : " + to_string((int)monster[0]->GetDamage()));
		else
			monsterDamage->SetText("A : " + to_string((int)monster[0]->GetDamage() / 2));

		monsterDamage->SetActive(true);
	}
	else if (randomMonsterPattern == 2)
	{
		monsterPattern->SetText("DEFENCE");
		monsterDamage->SetText("");
		monsterDamage->SetActive(false);
	}
	else if (randomMonsterPattern == 3)
	{
		monsterPattern->SetText("Status Ailment");
		monsterDamage->SetText("");
		monsterDamage->SetActive(false);
	}

	monsterRandomPatternSetting = false;
	isMonsterTern = false;
}

void PlayUi::MonsterAction(float dt)
{
	if (ironClad->GetIsWeaken() > 0)
		ironClad->SetIsWeaken(ironClad->GetIsWeaken() - 1);
	if (ironClad->GetIsWeaken() == 0)
		ironCladDamage->SetText("A : " + to_string((int)ironClad->GetDamage()));

	if (stage == Stage::Monster)
	{
		monster[0]->Pattern(randomMonsterPattern, dt);
		if (monster[0]->GetPattern() == MonsterPattern::Attack)
			MonsterAttack();

		if (monster[0]->GetPattern() == MonsterPattern::Weaken)
		{
			ironClad->SetIsWeaken(ironClad->GetIsWeaken() + 1);
			ironCladDamage->SetText("A : " + to_string((int)ironClad->GetDamage() / 2));
		}

		monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));
	}
	if (stage == Stage::Boss)
	{
		//monster[0]->Pattern(randomMonsterPattern, dt);
		//if (monster[0]->GetPattern() == MonsterPattern::Attack)
			//MonsterAttack();

		//monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));
	}

	ironClad->SetCurEnergy(ironClad->GetMaxEnergy());
	ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

	isPlayerTern = true;
	monsterRandomPatternSetting = true;
	playerActionCountSet = true;
	ternPassButton->SetActive(true);

	if (monster[0]->GetIsWeaken() > 0)
		monster[0]->SetIsWeaken(monster[0]->GetIsWeaken() - 1);	

	cout << ironClad->GetIsWeaken() << endl;

	ironClad->SetDefend(0);
	ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
}

void PlayUi::OptionUiControl()
{
	if (Button::ButtonOnRect(*cursor, *option))
	{
		if (optionUi == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				SOUND_MGR->Play("sounds/uiClick.wav", false);
				optionUi = false;
			}
		}
		else
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				SOUND_MGR->Play("sounds/uiClick.wav", false);
				optionUi = true;
			}
		}
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Escape))
	{
		if (optionUi == true)
		{
			optionUi = false;
			SOUND_MGR->Play("sounds/uiClick.wav", false);
			SetOptionUi(false);
		}
		else
		{
			optionUi = true;
			SOUND_MGR->Play("sounds/uiClick.wav", false);
			SetOptionUi(true);
		}
	}

	if (optionUi == true)
	{
		SetOptionUi(true);
		if (Button::ButtonOnRect(*cursor, *backButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				optionUi = false;
				SOUND_MGR->Play("sounds/uiClick.wav", false);
				SetOptionUi(false);
			}
		}
		if (Button::ButtonOnRect(*cursor, *gameOffButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				exit(1);
			}
		}
	}
	else
		SetOptionUi(false);
}

void PlayUi::MapUiControl()
{
	if (stage != Stage::Map)
	{
		if (Button::ButtonOnRect(*cursor, *mapIcon) && dieOrGiveup->GetActive() == false)
		{
			if (mapUi == true)
			{
				if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
				{
					SOUND_MGR->Play("sounds/mapIcon.ogg", false);
					mapUi = false;
				}
			}
			else
			{
				if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
				{
					SOUND_MGR->Play("sounds/mapIcon.ogg", false);
					mapUi = true;
				}
			}
		}

		if (InputMgr::GetKeyDown(Keyboard::Key::M) && dieOrGiveup->GetActive() == false)
		{
			if (mapUi == false)
			{
				SOUND_MGR->Play("sounds/mapIcon.ogg", false);
				mapUi = true;
			}
			else
			{
				SOUND_MGR->Play("sounds/mapIcon.ogg", false);
				mapUi = false;
			}
		}
	}


	mapUi == true ? SetMapUi(true) : SetMapUi(false);
}

void PlayUi::GiveUpUiControl()
{
	if (optionUi == true && dieOrGiveup->GetActive() == false)
	{
		if (Button::ButtonOnRect(*cursor, *giveUpButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				SOUND_MGR->Play("sounds/uiClick.wav", false);
				giveupUi = true;
			}
		}

		else if (Button::ButtonOnRect(*cursor, *yesButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				SOUND_MGR->Play("sounds/uiClick.wav", false);
				ironClad->SetAlive(false);
				SetDieUi(true);
			}
		}

		else if (Button::ButtonOnRect(*cursor, *noButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				SOUND_MGR->Play("sounds/uiClick.wav", false);
				giveupUi = false;
			}
		}
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Escape) && giveupUi == true && dieOrGiveup->GetActive() == false)
	{
		giveupUi = false;
	}

	giveupUi == true ? SetGiveUpUi(true) : SetGiveUpUi(false);
}

void PlayUi::UiCreate()
{
	Font& font = *RESOURCE_MGR->GetFont("fonts/Mabinogi_Classic_TTF.ttf");
	auto testBackground = RESOURCE_MGR->GetTexture("graphics/testbackground.png");
	auto tempBackgroundImage = RESOURCE_MGR->GetTexture("graphics/testbackground2.png");
	auto testButton1 = RESOURCE_MGR->GetTexture("graphics/UtilCard.png");
	auto testButton2 = RESOURCE_MGR->GetTexture("graphics/DefenseCard.png");
	auto testBorderImage = RESOURCE_MGR->GetTexture("graphics/testborder.png");
	auto testBackButton = RESOURCE_MGR->GetTexture("graphics/BackButton.png");
	auto testOptionButton = RESOURCE_MGR->GetTexture("graphics/option.png");
	auto testOptionBackground = RESOURCE_MGR->GetTexture("graphics/ModeSelectBackground.png");
	auto testMapIcon = RESOURCE_MGR->GetTexture("graphics/mapicon.png");
	auto testMap = RESOURCE_MGR->GetTexture("graphics/map.png");
	auto testMapBackground = RESOURCE_MGR->GetTexture("graphics/MapBackground.png");
	auto testYesButton = RESOURCE_MGR->GetTexture("graphics/yesButton.png");
	auto testNoButton = RESOURCE_MGR->GetTexture("graphics/noButton.png");
	auto testConfirmMessage = RESOURCE_MGR->GetTexture("graphics/confirmMessage.png");
	auto testGiveUpButton = RESOURCE_MGR->GetTexture("graphics/giveupButton.png");
	auto CurHpBarImage = RESOURCE_MGR->GetTexture("graphics/CurHpBar.png");
	auto MaxHpBarImage = RESOURCE_MGR->GetTexture("graphics/MaxHpBar.png");


	Vector2f windowSize = (Vector2f)FRAMEWORK->GetWindowSize();


	// �⺻ ��׶���
	{
		tempBackground = new SpriteObj();
		tempBackground->SetAll(*testBackground, windowSize * 0.5f, Origins::MC);
	}

	// Monster
	{
		monster.push_back(new Monster(43, 43, 0, 10, MonsterType::Easy));
		monster[0]->SetAll(*RESOURCE_MGR->GetTexture("graphics/ironcladimage.png"),
			{ windowSize.x / 1.4f, windowSize.y / 1.7f }, Origins::MC);
		monster[0]->SetScale(-1, 1);
		monsterCount = monster.size();

		Vector2f setMonsterUiPos = { monster[0]->GetPos().x - 30, monster[0]->GetPos().y + (monster[0]->GetSize().y / 2) };


		monsterDefend = new TextObj();
		monsterMaxHp = new TextObj();
		monsterCurHp = new TextObj();
		monsterDamage = new TextObj();
		monsterPattern = new TextObj();
		monsterDamage = new TextObj();
		monsterCurHpBar = new SpriteObj();
		monsterMaxHpBar = new SpriteObj();


		monsterDefend->SetAll(font, "D : " + to_string(monster[0]->GetDefend()), 30, Color::White,
			{ setMonsterUiPos.x - 50, setMonsterUiPos.y + 40 });

		monsterCurHp->SetAll(font, to_string(monster[0]->GetCurHp()), 30, Color::White,
			{ setMonsterUiPos.x - 50, setMonsterUiPos.y });

		monsterMaxHp->SetAll(font, "/ " + to_string(monster[0]->GetMaxHp()), 30, Color::White,
			{ setMonsterUiPos.x - 10, setMonsterUiPos.y });

		monsterPattern->SetAll(font, "", 30, Color::White,
			{ monster[0]->GetPos().x - monster[0]->GetSize().x / 4, monster[0]->GetPos().y - monster[0]->GetSize().y / 2 - 20 });
		monsterPattern->SetOrigin(Origins::MC);

		monsterDamage->SetAll(font, "", 30, Color::White,
			{ monsterDefend->GetPos().x, setMonsterUiPos.y + 80 });

		// HP BAR
		{
			monsterCurHpBar->SetAll(*CurHpBarImage, { 0, 0 }, Origins::MR);
			monsterMaxHpBar->SetAll(*MaxHpBarImage, { 0, 0 }, Origins::MR);

			monsterCurHpBar->SetPos({ setMonsterUiPos.x + monsterCurHpBar->GetSize().x / 2 - 30, setMonsterUiPos.y + 15 });
			monsterMaxHpBar->SetPos({ setMonsterUiPos.x + monsterMaxHpBar->GetSize().x / 2 - 30, setMonsterUiPos.y + 15 });
		}
	}


	// ĳ���� ���� UI
	{
		// ĳ���� ����
		ironClad = new Player(80, 80, 99, 3, 3, 0, 5, PlayerType::IronClad);
		ironClad->SetAll(*RESOURCE_MGR->GetTexture("graphics/ironcladimage.png"),
			{ windowSize.x / 4, windowSize.y / 1.7f }, Origins::MC);

		// ����
		{
			ternPassButton = new SpriteObj();
			ternPassButtonHover = new SpriteObj();
			attackButton = new SpriteObj();
			defendButton = new SpriteObj();
			normalAttackButton = new SpriteObj();
			attackSkillButton1 = new SpriteObj();

			actionWindow = new SpriteObj();
			attackCount = new TextObj();
			defendCount = new TextObj();

			ironCladMaxHp = new TextObj();
			ironCladCurHp = new TextObj();
			ironCladCurEnergy = new TextObj();
			ironCladMaxEnergy = new TextObj();
			ironCladCurDefend = new TextObj();
			ironCladDamage = new TextObj();

			Vector2f setPlayerUiPos = { ironClad->GetPos().x - 10, ironClad->GetPos().y + (ironClad->GetSize().y / 2) };

			ironCladCurHp->SetAll(font, to_string(ironClad->GetCurHP()), 30, Color::White, setPlayerUiPos);

			ironCladMaxHp->SetAll(font, "/ " + to_string(ironClad->GetMaxHP()), 30, Color::White,
				{ ironCladCurHp->GetPos().x + 40, setPlayerUiPos.y });

			ironCladCurEnergy->SetAll(font, to_string(ironClad->GetCurEnergy()), 30, Color::White,
				{ 100, windowSize.y - 100 });
			ironCladCurEnergy->SetOrigin(Origins::MC);

			ironCladMaxEnergy->SetAll(font, to_string(ironClad->GetMaxEnergy()), 30, Color::White,
				{ ironCladCurEnergy->GetPos().x + 20, ironCladCurEnergy->GetPos().y });
			ironCladMaxEnergy->SetOrigin(Origins::MC);

			ironCladCurDefend->SetAll(font, "D : " + to_string(ironClad->GetDefend()), 30, Color::White,
				{ setPlayerUiPos.x, setPlayerUiPos.y + 40 });

			ironCladDamage->SetAll(font, "A : " + to_string((int)ironClad->GetDamage()), 30, Color::White,
				{ setPlayerUiPos.x, setPlayerUiPos.y + 80 });

			// Action Ui
			{
				actionWindow->SetAll(*RESOURCE_MGR->GetTexture("graphics/actionWindow.png"), { 0, 0 }, Origins::MC);
				actionWindow->SetPos({ windowSize.x / 2, windowSize.y - (actionWindow->GetSize().y / 2) });

				attackButton->SetAll(*RESOURCE_MGR->GetTexture("graphics/attackButton.png"), { 0, 0 }, Origins::MC);
				attackButton->SetPos({ actionWindow->GetPos().x - attackButton->GetSize().x,
					actionWindow->GetPos().y });

				normalAttackButton->SetAll(*RESOURCE_MGR->GetTexture("graphics/normalAttackButton.png"), {0, 0}, Origins::MC);
				normalAttackButton->SetPos({ attackButton->GetPos().x, attackButton->GetPos().y - attackButton->GetSize().y});

				attackSkillButton1->SetAll(*RESOURCE_MGR->GetTexture("graphics/smiteAttakButton.png"), { 0, 0 }, Origins::MC);
				attackSkillButton1->SetPos({ -200, -200 });


				defendButton->SetAll(*RESOURCE_MGR->GetTexture("graphics/defenseButton.png"),
					{ 0, 0 }, Origins::MC);
				defendButton->SetPos({ attackButton->GetPos().x + (defendButton->GetSize().x * 2), attackButton->GetPos().y });

				attackCount->SetAll(font, "", 50, Color::Black, { 0, 0 });
				attackCount->SetPos({ attackButton->GetPos().x, attackButton->GetPos().y - (attackCount->GetSize().height / 4) });
				attackCount->SetOrigin(Origins::MC);

				defendCount->SetAll(font, "", 50, Color::Black, { defendButton->GetPos().x, attackCount->GetPos().y });
				defendCount->SetOrigin(Origins::MC);

				ternPassButton->SetAll(*RESOURCE_MGR->GetTexture("graphics/ternPassButton.png"),
					{ actionWindow->GetPos().x, actionWindow->GetPos().y }, Origins::MC);
				ternPassButtonHover->SetAll(*RESOURCE_MGR->GetTexture("graphics/ternPassButtonHover.png"),
					ternPassButton->GetPos(), Origins::MC);
			}


			// Hp bar
			{
				playerCurHpBar = new SpriteObj();
				playerMaxHpBar = new SpriteObj();

				playerCurHpBar->SetAll(*CurHpBarImage, { setPlayerUiPos.x - 57, setPlayerUiPos.y + 15 }, Origins::ML);
				playerMaxHpBar->SetAll(*MaxHpBarImage, { setPlayerUiPos.x - 57, setPlayerUiPos.y + 15 }, Origins::ML);
			}
		}
	}

	// ��
	{
		mapBackground = new SpriteObj();
		map = new SpriteObj();
		mapIcon = new SpriteObj();

		mapBackground->SetAll(*testMapBackground, windowSize * 0.5f, Origins::MC);
		map->SetAll(*testMap, windowSize * 0.5f, Origins::MC);
	}

	// �ɼ�
	{
		// ó�� ������
		{
			backButton = new SpriteObj();
			option = new SpriteObj();
			optionBackground = new SpriteObj();
			giveUpButton = new SpriteObj();
			gameOffButton = new SpriteObj();


			backButton->SetAll(*testBackButton, { 100, windowSize.y - 200.f }, Origins::MC);
			optionBackground->SetAll(*testOptionBackground, windowSize * 0.5f, Origins::MC);
			giveUpButton->SetAll(*testGiveUpButton, windowSize * 0.5f, Origins::MC);
			gameOffButton->SetAll(*RESOURCE_MGR->GetTexture("graphics/gameOffButton.png"), {0, 0}, Origins::MC);
			gameOffButton->SetPos({ windowSize.x - gameOffButton->GetSize().x, backButton->GetPos().y});
		}

		// ���� ����
		{
			yesButton = new SpriteObj();
			noButton = new SpriteObj();
			confirmMessage = new SpriteObj();
			confirmBackground = new SpriteObj();


			confirmMessage->SetAll(*testConfirmMessage, windowSize * 0.5f, Origins::MC);
			yesButton->SetAll(*testYesButton, { confirmMessage->GetPos().x - 100, confirmMessage->GetPos().y + 100 }, Origins::MC);
			noButton->SetAll(*testNoButton, { yesButton->GetPos().x + 200, yesButton->GetPos().y }, Origins::MC);
			confirmBackground->SetAll(*testOptionBackground, windowSize * 0.5f, Origins::MC);
		}
	}

	// �ֻ�� UI��
	{
		testBorder = new SpriteObj();
		gold = new TextObj();
		curHp = new TextObj();
		maxHp = new TextObj();

		testBorder->SetAll(*testBorderImage, windowSize * 0.5f, Origins::MC);
		gold->SetAll(font, "GOLD " + to_string(ironClad->GetCurGold()), 30, Color::White, { 100, 50 });
		gold->SetOrigin(Origins::MC);

		curHp->SetAll(font, to_string(ironClad->GetCurHP()), 30, Color::Red, { gold->GetPos().x * 4 , gold->GetPos().y });
		curHp->SetOrigin(Origins::MC);

		maxHp->SetAll(font, to_string(ironClad->GetMaxHP()), 30, Color::Red, { curHp->GetPos().x + 50, curHp->GetPos().y });
		maxHp->SetOrigin(Origins::MC);

		// option icon
		option->SetAll(*testOptionButton, { windowSize.x - 100, gold->GetPos().y }, Origins::MC);

		// map icon
		mapIcon->SetAll(*testMapIcon, { option->GetPos().x - 100, option->GetPos().y }, Origins::MC);
	}

	// clear
	{
		clearBackground = new SpriteObj();
		continueButton = new SpriteObj();

		clearBackground->SetAll(*RESOURCE_MGR->GetTexture("graphics/clearBackground.png"), windowSize * 0.5f, Origins::MC);
		continueButton->SetAll(*RESOURCE_MGR->GetTexture("graphics/continueButton.png"), { 0, 0 }, Origins::MC);
		continueButton->SetPos({ windowSize.x - continueButton->GetSize().x, windowSize.y - continueButton->GetSize().y });
	}

	// choice
	{
		choice1 = new SpriteObj();
		choice2 = new SpriteObj();
		choice3 = new SpriteObj();

		choice1->SetAll(*RESOURCE_MGR->GetTexture("graphics/choice1.png"), {0, 0}, Origins::MC);
		choice2->SetAll(*RESOURCE_MGR->GetTexture("graphics/choice2.png"), {0, 0}, Origins::MC);
		choice3->SetAll(*RESOURCE_MGR->GetTexture("graphics/choice3.png"), {0, 0}, Origins::MC);
	}


	// Map Icon
	{
		monsterMapIcon = new SpriteObj();
		rewordMapIcon = new SpriteObj();
		questionMapIcon = new SpriteObj();
		shopMapIcon = new SpriteObj();

		monsterMapIcon->SetAll(*RESOURCE_MGR->GetTexture("graphics/monsterMapIcon.png"), { 0, 0 }, Origins::MC);
		rewordMapIcon->SetAll(*RESOURCE_MGR->GetTexture("graphics/rewordMapIcon.png"), { 0, 0 }, Origins::MC);
		questionMapIcon->SetAll(*RESOURCE_MGR->GetTexture("graphics/questionMapIcon.png"), { 0, 0 }, Origins::MC);
		shopMapIcon->SetAll(*RESOURCE_MGR->GetTexture("graphics/shopMapIcon.png"), { 0, 0 }, Origins::MC);
	}

	// Map Creat
	{
		int randomMap = Utils::RandomRange(0, 4);
		float monsterMapIconYPos = 0.f;
		float questionMapIconYPos = 0.f;
		float shopMapIconYPos = 0.f;
		float rewordMapIconYPos = 0.f;

		switch (randomMap)
		{
		case 0:
			monsterMapIconYPos = windowSize.y * 0.7f;
			questionMapIconYPos = windowSize.y * 0.6f;
			shopMapIconYPos = windowSize.y * 0.5f;
			rewordMapIconYPos = windowSize.y * 0.4f;

			monsterMapOrder = 0;
			questionMapOrder = 1;
			shopMapOrder = 2;
			rewordMapOrder = 3;

			break;

		case 1:
			monsterMapIconYPos = windowSize.y * 0.6f;
			questionMapIconYPos = windowSize.y * 0.7f;
			shopMapIconYPos = windowSize.y * 0.4f;
			rewordMapIconYPos = windowSize.y * 0.5f;

			monsterMapOrder = 1;
			questionMapOrder = 0;
			shopMapOrder = 3;
			rewordMapOrder = 2;

			break;

		case 2:
			monsterMapIconYPos = windowSize.y * 0.5f;
			questionMapIconYPos = windowSize.y * 0.4f;
			shopMapIconYPos = windowSize.y * 0.6f;
			rewordMapIconYPos = windowSize.y * 0.7f;

			monsterMapOrder = 2;
			questionMapOrder = 3;
			shopMapOrder = 1;
			rewordMapOrder = 0;

			break;

		case 3:
			monsterMapIconYPos = windowSize.y * 0.4f;
			questionMapIconYPos = windowSize.y * 0.5f;
			shopMapIconYPos = windowSize.y * 0.7f;
			rewordMapIconYPos = windowSize.y * 0.6f;

			monsterMapOrder = 3;
			questionMapOrder = 2;
			shopMapOrder = 0;
			rewordMapOrder = 1;

			break;
		}

		monsterMapIcon->SetPos({ windowSize.x * 0.5f, monsterMapIconYPos });
		rewordMapIcon->SetPos({ windowSize.x * 0.5f, rewordMapIconYPos });
		questionMapIcon->SetPos({ windowSize.x * 0.5f, questionMapIconYPos });
		shopMapIcon->SetPos({ windowSize.x * 0.5f, shopMapIconYPos });
	}

	// die
	{
		dieOrGiveup = new SpriteObj();
		floors = new TextObj();
		monsterKilled = new TextObj();

		dieOrGiveup->SetAll(*RESOURCE_MGR->GetTexture("graphics/DieOrGiveup.png"), 
			windowSize * 0.5f, Origins::MC);

		floors->SetAll(font, "", 50, Color::White, dieOrGiveup->GetPos());
		monsterKilled->SetAll(font, "", 50, Color::White, { floors->GetPos().x, floors->GetPos().y + floors->GetSize().top / 4});
	}

	// Main Menu Button
	{
		mainMenuButton = new SpriteObj();
		mainMenuButton->SetAll(*RESOURCE_MGR->GetTexture("graphics/mainMenuButton.png"), { 0, 0}, Origins::MC);
		mainMenuButton->SetPos({ monsterKilled->GetPos().x, monsterKilled->GetPos().y + mainMenuButton->GetSize().y * 2 });
	}

	// ShopStage
	{
		damageUp = new SpriteObj();
		defenseUp = new SpriteObj();
		energyUp = new SpriteObj();
		hpUp = new SpriteObj();
		getSkill = new SpriteObj();

		damageUp->SetAll(*RESOURCE_MGR->GetTexture("graphics/AttactCard.png"), {0, 0}, Origins::MC);
		defenseUp->SetAll(*RESOURCE_MGR->GetTexture("graphics/DefenseCard.png"), {0, 0}, Origins::MC);
		energyUp->SetAll(*RESOURCE_MGR->GetTexture("graphics/UtilCard.png"), {0, 0}, Origins::MC);
		hpUp->SetAll(*RESOURCE_MGR->GetTexture("graphics/UtilCard.png"), {0, 0}, Origins::MC);
		getSkill->SetAll(*RESOURCE_MGR->GetTexture("graphics/ironcladSelect.png"), {0, 0}, Origins::MC);
	}

	// reword
	{
		rewordImage = new SpriteObj();
		chest = new SpriteObj();
		chest->SetAll(*RESOURCE_MGR->GetTexture("graphics/largeChest.png"), monster[0]->GetPos(), Origins::MC);
		chest->SetScale(0.5f, 0.5f);
		rewordImage->SetAll(*RESOURCE_MGR->GetTexture("graphics/rewardScreen.png"), { -500, 0}, Origins::MC);

		addGold = new TextObj();
		addDamage = new TextObj();
		addDefend = new TextObj();
		addHp = new TextObj();
		rewordText = new TextObj();

		addGold->SetAll(font, "", 40, Color::White, { -500,0 });
		addDamage->SetAll(font, "", 40, Color::White, { -500,0 });
		addDefend->SetAll(font, "", 40, Color::White, { -500,0 });
		addHp->SetAll(font, "", 40, Color::White, { -500,0 });
		rewordText->SetAll(font, "REWORD!", 80, Color::White, { -500,0 });
	}
}

void PlayUi::SetActionUi(bool set)
{
	actionWindow->SetActive(set);
	attackButton->SetActive(set);
	defendButton->SetActive(set);
	attackCount->SetActive(set);
	defendCount->SetActive(set);
	ternPassButton->SetActive(set);
	SetAttackSkillUi(set);
}

void PlayUi::HpControl()
{
	float playerCurHpBarSet = (ironClad->GetMaxHP() - ironClad->GetCurHP()) * (80.f / ironClad->GetMaxHP() * 0.01f);
	float monsterCurHpBarSet = (monster[0]->GetMaxHp() - monster[0]->GetCurHp()) * (80.f / monster[0]->GetMaxHp() * 0.01f);


	playerCurHpBar->SetScale(0.8f - playerCurHpBarSet, 1);
	playerMaxHpBar->SetScale(0.8f, 1);

	monsterCurHpBar->SetScale(0.8f - monsterCurHpBarSet, 1);
	monsterMaxHpBar->SetScale(0.8f, 1);

	if (ironClad->GetCurHP() <= 0)
	{
		ironClad->SetCurHP(0);
		ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
		curHp->SetText(to_string(ironClad->GetCurHP()));
		ironClad->SetAlive(false);
	}

	for (int i = 0; i < monster.size(); i++)
	{
		if (monster[i]->GetCurHp() <= 0)
		{
			monster[i]->SetCurHp(0);
			monsterCurHp->SetText(to_string(monster[i]->GetCurHp()));
			monsterCount--;
			MonsterSet(monster, false);
		}
	}

	curHp->SetOrigin(Origins::MC);
	maxHp->SetOrigin(Origins::MC);
	ironCladCurHp->SetOrigin(Origins::TL);
}

void PlayUi::SetMonsterTern()
{
	ternPassButton->SetActive(false);
	isMonsterTern = true;
	monsterRandomPatternSetting = false;
	isPlayerTern = false;
	monsterPatternDelay = 2.f;
}

void PlayUi::SetClearUi(bool set)
{
	clearBackground->SetActive(set);
	continueButton->SetActive(set);
}

void PlayUi::SetMonsterStage(float dt)
{
	SetActionUi(true);
	MonsterSet(monster, true);
	monsterPatternDelay -= dt;

	// Tern Pass
	if (Button::ButtonOnRect(*cursor, *ternPassButton) && isPlayerTern == true && monster[0]->GetAlive() == true && dieOrGiveup->GetActive() == false)
	{
		isHover = true;
		if (isHover == true)
		{
			if (uiHoverSoundPlay == true)
			{
				SOUND_MGR->Play("sounds/uiHover.wav", false);
				uiHoverSoundPlay = false;
			}
			ternPassButtonHover->SetActive(true);
		}

		if (InputMgr::GetMouseButtonUp(Mouse::Left))
		{
			SetMonsterTern();
			isAttackSkill = false;
			SOUND_MGR->Play("sounds/ternEnd.ogg", false);
		}
	}
	else
	{
		uiHoverSoundPlay = true;
		isHover = false;
		ternPassButtonHover->SetActive(false);
	}

	// Monster Tern Control
	if (monsterPatternDelay <= 0.f && isPlayerTern == false)
		MonsterAction(dt);

	// Monster Pattern Set
	if (isMonsterTern == true && monsterRandomPatternSetting == true)
		SetNextMonsterAction();

	// player Tern Control
	if (isPlayerTern == true && isMonsterTern == false && ironClad->GetCurEnergy() > 0)
	{
		PlayerTern(dt);
	}

	this->attackCount->SetText("COUNT : " + to_string(ironClad->GetAttackCount()));
	this->defendCount->SetText("COUNT : " + to_string(ironClad->GetDefendCount()));
	this->attackCount->SetOrigin(Origins::MC);
	this->defendCount->SetOrigin(Origins::MC);

	if (monsterCount == 0)
	{
		if (ironClad->GetType() == PlayerType::IronClad)
		{
			int hp = ironClad->GetCurHP();
			hp + 6 >= ironClad->GetMaxHP() ? ironClad->SetCurHP(ironClad->GetMaxHP()) : ironClad->SetCurHP(hp += 6);
			ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
			curHp->SetText(to_string(ironClad->GetCurHP()));
			playerActionCountSet = true;
		}
		SetClearUi(true);
		monsterKillCount++;
	}
}

void PlayUi::EnterTheStage(float dt)
{
	choiceDelay -= dt;

	if (monsterMapIcon->GetActive() == true && stage == Stage::Map)
	{
		if (Button::ButtonOnRect(*cursor, *monsterMapIcon) && monsterMapOrder == choiceOrder)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				choiceDelay = 0.5f;
				SOUND_MGR->Play("sounds/mapSelect.ogg", false);
				mapChoice = true;
			}
		}

		if (Button::ButtonOnRect(*cursor, *rewordMapIcon) && rewordMapOrder == choiceOrder)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				choiceDelay = 0.5f;
				SOUND_MGR->Play("sounds/mapSelect.ogg", false);
				mapChoice = true;
			}
		}

		if (Button::ButtonOnRect(*cursor, *questionMapIcon) && questionMapOrder == choiceOrder)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				choiceDelay = 0.5f;
				SOUND_MGR->Play("sounds/mapSelect.ogg", false);
				mapChoice = true;
			}
		}

		if (Button::ButtonOnRect(*cursor, *shopMapIcon) && shopMapOrder == choiceOrder)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				choiceDelay = 0.5f;
				SOUND_MGR->Play("sounds/mapSelect.ogg", false);
				mapChoice = true;
			}
		}


		if (choiceDelay <= 0.f && monsterMapOrder == choiceOrder && mapChoice == true)
		{
			stage = Stage::Monster;
			mapUi = false;
			mapChoice = false;
		}
		if (choiceDelay <= 0.f && rewordMapOrder == choiceOrder && mapChoice == true)
		{
			stage = Stage::Reword;
			mapUi = false;
			mapChoice = false;
		}
		if (choiceDelay <= 0.f && shopMapOrder == choiceOrder && mapChoice == true)
		{
			stage = Stage::Shop;
			mapUi = false;
			mapChoice = false;
		}
		if (choiceDelay <= 0.f && questionMapOrder == choiceOrder && mapChoice == true)
		{
			stage = Stage::Question;
			mapUi = false;
			mapChoice = false;
		}
	}
	// boss
}

void PlayUi::QuestionStage()
{
	int randomStage = Utils::RandomRange(0, 5);
	int randomMonsterHp = Utils::RandomRange(36, 72);
	MonsterType randomMonsterLevel = (MonsterType)Utils::RandomRange(0, 3);

	switch (randomStage)
	{
	case 0:
		stage = Stage::Monster;
		monster[0]->SetMonster(randomMonsterHp, randomMonsterHp, 10, 0, randomMonsterLevel);
		monster[0]->SetAlive(true);
		MonsterSet(monster, true);

		SetNextMonsterAction();
		monster[0]->SetDamage(monster[0]->GetDamage());

		monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));
		monsterMaxHp->SetText("/ " + to_string(monster[0]->GetMaxHp()));
		monsterCurHp->SetText(to_string(monster[0]->GetCurHp()));
		
		ironClad->SetCurEnergy(ironClad->GetMaxEnergy());
		ironClad->SetMaxEnergy(ironClad->GetMaxEnergy());
		ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));
		monsterCount = monster.size();
		mapUi = false;
		break;
	case 1:
		stage = Stage::Monster;
		monster[0]->SetMonster(randomMonsterHp, randomMonsterHp, 10, 0, randomMonsterLevel);
		monster[0]->SetAlive(true);
		MonsterSet(monster, true);

		SetNextMonsterAction();
		monster[0]->SetDamage(monster[0]->GetDamage());

		monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));
		monsterMaxHp->SetText("/ " + to_string(monster[0]->GetMaxHp()));
		monsterCurHp->SetText(to_string(monster[0]->GetCurHp()));

		ironClad->SetCurEnergy(ironClad->GetMaxEnergy());
		ironClad->SetMaxEnergy(ironClad->GetMaxEnergy());
		ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));
		monsterCount = monster.size();
		mapUi = false;
		break;
	case 2:
		stage = Stage::Shop;
		mapUi = false;
		break;
	case 3:
		stage = Stage::Reword;
		mapUi = false;
		break;
	case 4:
		stage = Stage::Reword;
		mapUi = false;
		break;
	}
}

void PlayUi::ShopStage()
{
	Vector2f windowSize = (Vector2f)FRAMEWORK->GetWindowSize();

	continueButton->SetActive(true);

	damageUp->SetPos({ windowSize.x / 5, windowSize.y / 3 });
	defenseUp->SetPos({ windowSize.x / 4, windowSize.y / 3 });
	energyUp->SetPos({ windowSize.x / 2, windowSize.y / 3 });
	hpUp->SetPos({ windowSize.x / 1.3f, windowSize.y / 3 });
	getSkill->SetPos({ windowSize.x / 2, windowSize.y / 1.5f });

	if (Button::ButtonOnRect(*cursor, *damageUp))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && ironClad->GetCurGold() >= 20 && damageUp->GetActive() == true)
		{
			ironClad->AddDamage(1);
			ironCladDamage->SetText("A : " + to_string((int)ironClad->GetDamage()));

			ironClad->SetGold(ironClad->GetCurGold() - 20);
			gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
			// 돈 사운드
		}
	}
	if (Button::ButtonOnRect(*cursor, *energyUp))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && ironClad->GetCurGold() >= 30 && energyUp->GetActive() == true)
		{
			int e = ironClad->GetCurEnergy();
			int maxe = ironClad->GetMaxEnergy();
			ironClad->SetMaxEnergy(e += 1);
			ironClad->SetCurEnergy(maxe += 1);

			ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));
			ironCladMaxEnergy->SetText(to_string(ironClad->GetMaxEnergy()));

			ironClad->SetGold(ironClad->GetCurGold() - 30);
			gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
			// 돈 사운드
		}
	}
	if (Button::ButtonOnRect(*cursor, *defenseUp))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && ironClad->GetCurGold() >= 20 && defenseUp->GetActive() == true)
		{
			ironClad->SetAddDefend(ironClad->GetAddDefend() + 1);

			ironClad->SetGold(ironClad->GetCurGold() - 20);
			gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
			// 돈 사운드
		}
	}
	if (Button::ButtonOnRect(*cursor, *hpUp))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && ironClad->GetCurGold() >= 10 && hpUp->GetActive() == true)
		{
			int hp = ironClad->GetCurHP();
			int maxhp = ironClad->GetMaxHP();
			ironClad->SetCurHP(hp += 10);
			ironClad->SetMaxHP(maxhp += 10);

			ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
			ironCladMaxHp->SetText("/ " + to_string(ironClad->GetMaxHP()));
			curHp->SetText(to_string(ironClad->GetCurHP()));
			maxHp->SetText(to_string(ironClad->GetMaxHP()));

			ironClad->SetGold(ironClad->GetCurGold() - 10);
			gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
			// 돈 사운드
		}
	}

	if (Button::ButtonOnRect(*cursor, *getSkill))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && ironClad->GetCurGold() >= 70 && getSkill->GetActive() == true)
		{
			normalAttackButton->SetPos({ attackButton->GetPos().x - normalAttackButton->GetSize().x / 2,
					attackButton->GetPos().y - attackButton->GetSize().y });

			attackSkillButton1->SetPos({ normalAttackButton->GetPos().x + attackSkillButton1->GetSize().x,
				normalAttackButton->GetPos().y });

			ironClad->SetGold(ironClad->GetCurGold() - 70);
			gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
			// 돈 사운드

			skillCount++;
		}
	}
}

void PlayUi::RewordStage()
{
	Vector2f windowSize = (Vector2f)FRAMEWORK->GetWindowSize();

	SetRewordMapUi(true);
	if (Button::ButtonOnRect(*cursor, *chest))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
		{
			chest->SetTexture(*RESOURCE_MGR->GetTexture("graphics/largeChestOpened.png"));
			SetRewordUi(true);
			rewordUi = true;
		}
	}

	// 골드, 공++, 방++, 체력++
	if (rewordImage->GetActive() == true && rewordUi == true)
	{
		if (randomReword == true)
		{
			randomChoice = Utils::RandomRange(0, 6);

			getGold = Utils::RandomRange(10, 50);
			getDamage = Utils::RandomRange(1, 3);
			getDefend = Utils::RandomRange(1, 3);
			getHp = Utils::RandomRange(3, 10);

			addGold->SetText("Add Gold : " + to_string(getGold));
			addDamage->SetText("Add Damage : " + to_string(getDamage));
			addDefend->SetText("Add Defend : " + to_string(getDefend));
			addHp->SetText("Heal : " + to_string(getHp));

			addGold->SetOrigin(Origins::MC);
			addDamage->SetOrigin(Origins::MC);
			addDefend->SetOrigin(Origins::MC);
			addHp->SetOrigin(Origins::MC);
			rewordText->SetOrigin(Origins::MC);

			rewordImage->SetPos(windowSize * 0.5f);
			rewordText->SetPos({ rewordImage->GetPos().x, rewordImage->GetPos().y - (rewordText->GetSize().height * 5) });

			randomReword = false;
		}
		continueButton->SetActive(true);
		addGold->SetPos(windowSize * 0.5f);

		switch (randomChoice)
		{
		case 0:
			addDamage->SetActive(false);
			addDefend->SetActive(false);
			addHp->SetPos({ addGold->GetPos().x, addGold->GetPos().y + (addHp->GetSize().height * 3) });
			break;
		case 1:
			addDamage->SetActive(false);
			addDefend->SetPos({ addGold->GetPos().x, addGold->GetPos().y + (addDefend->GetSize().height * 3) });
			addHp->SetPos({ addDefend->GetPos().x, addDefend->GetPos().y + (addHp->GetSize().height * 3) });
			break;
		case 2:
			addDamage->SetPos({ addGold->GetPos().x, addGold->GetPos().y + (addDamage->GetSize().height * 3) });
			addDefend->SetActive(false);
			addHp->SetPos({ addDefend->GetPos().x, addDefend->GetPos().y + (addHp->GetSize().height * 3) });
			break;
		case 3:
			addDamage->SetActive(false);
			addDefend->SetActive(false);
			addHp->SetActive(false);
			break;
		case 4:
			addDamage->SetPos({ addGold->GetPos().x, addGold->GetPos().y + (addDamage->GetSize().height * 3) });
			addDefend->SetActive(false);
			addHp->SetActive(false);
			break;
		case 5:
			addDamage->SetPos({ addGold->GetPos().x, addGold->GetPos().y + (addDamage->GetSize().height * 3) });
			addDefend->SetPos({ addDamage->GetPos().x, addDamage->GetPos().y + (addDefend->GetSize().height * 3) });
			addHp->SetActive(false);
			break;
		}

		if (Button::ButtonOnRect(*cursor, *addGold) && addGold->GetActive() == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				ironClad->SetGold(ironClad->GetCurGold() + getGold);
				gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
				addGold->SetActive(false);
			}
		}
		if (Button::ButtonOnRect(*cursor, *addDamage) && addDamage->GetActive() == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				ironClad->AddDamage(getDamage);
				ironCladDamage->SetText("A : " + to_string((int)ironClad->GetDamage()));
				addDamage->SetActive(false);
			}
		}
		if (Button::ButtonOnRect(*cursor, *addDefend) && addDefend->GetActive() == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				ironClad->SetAddDefend(ironClad->GetAddDefend() + getDefend);
				addDefend->SetActive(false);
			}
		}
		if (Button::ButtonOnRect(*cursor, *addHp) && addHp->GetActive() == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				int hp = ironClad->GetCurHP();

				if (hp + getHp <= ironClad->GetMaxHP())
				{
					ironClad->SetCurHP(hp += getHp);
					ironCladCurHp->SetText(to_string(ironClad->GetMaxHP()));
					curHp->SetText(to_string(ironClad->GetMaxHP()));
				}
				else if (hp + getHp > ironClad->GetMaxHP())
				{
					int maxh = ironClad->GetMaxHP();
					int excessHpCalculation = (hp + getHp) - maxh;

					ironClad->SetCurHP(hp += getHp - excessHpCalculation);
					ironCladCurHp->SetText(to_string(ironClad->GetMaxHP()));
					curHp->SetText(to_string(ironClad->GetMaxHP()));
				}

				addHp->SetActive(false);
			}
		}
	}
}

void PlayUi::StartMapPlayerUpgrade(float dt)
{
	Vector2f windowSize = (Vector2f)FRAMEWORK->GetWindowSize();

	choiceDelay -= dt;

	if (chooseOption == true)
	{
		int randomChoice = Utils::RandomRange(0, 3);

		switch (randomChoice)
		{
		case 0:
			choice1->SetPos({ 0 + choice1->GetSize().x * 2, windowSize.y - choice1->GetSize().y * 3 });
			choice2->SetPos({ 0 + choice1->GetSize().x * 2, windowSize.y - choice1->GetSize().y });

			choice1->SetActive(true);
			choice2->SetActive(true);
			choice3->SetActive(false);
			break;
		case 1:
			choice1->SetPos({ 0 + choice1->GetSize().x * 2, windowSize.y - choice1->GetSize().y * 3 });
			choice3->SetPos({ 0 + choice1->GetSize().x * 2, windowSize.y - choice1->GetSize().y });

			choice1->SetActive(true);
			choice2->SetActive(false);
			choice3->SetActive(true);
			break;
		case 2:
			choice2->SetPos({ 0 + choice1->GetSize().x * 2, windowSize.y - choice1->GetSize().y * 3 });
			choice3->SetPos({ 0 + choice1->GetSize().x * 2, windowSize.y - choice1->GetSize().y });

			choice1->SetActive(false);
			choice2->SetActive(true);
			choice3->SetActive(true);
			break;
		}

		chooseOption = false;
	}

	if (stage == Stage::Start && dieOrGiveup->GetActive() == false)
	{
		if (Button::ButtonOnRect(*cursor, *choice1))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && choice1->GetActive() == true)
			{
				int hp = ironClad->GetCurHP();
				int maxhp = ironClad->GetMaxHP();
				ironClad->SetCurHP(hp += 5);
				ironClad->SetMaxHP(maxhp += 5);

				ironCladCurHp->SetText(to_string(ironClad->GetMaxHP()));
				ironCladMaxHp->SetText("/ " + to_string(ironClad->GetMaxHP()));
				curHp->SetText(to_string(ironClad->GetMaxHP()));
				maxHp->SetText(to_string(ironClad->GetMaxHP()));

				choice1->SetActive(false);
				choice2->SetActive(false);
				choice3->SetActive(false);

				choiceDelay = 1.f;
			}
		}
		if (Button::ButtonOnRect(*cursor, *choice2))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && choice2->GetActive() == true)
			{
				int hp = ironClad->GetCurHP();
				int maxhp = ironClad->GetMaxHP();
				ironClad->SetCurHP(hp -= 20);
				ironClad->SetMaxHP(maxhp -= 20);

				ironCladCurHp->SetText(to_string(ironClad->GetMaxHP()));
				ironCladMaxHp->SetText("/ " + to_string(ironClad->GetMaxHP()));
				curHp->SetText(to_string(ironClad->GetMaxHP()));
				maxHp->SetText(to_string(ironClad->GetMaxHP()));


				int e = ironClad->GetCurEnergy();
				int maxe = ironClad->GetMaxEnergy();
				ironClad->SetMaxEnergy(e += 2);
				ironClad->SetCurEnergy(maxe += 2);


				ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));
				ironCladMaxEnergy->SetText(to_string(ironClad->GetMaxEnergy()));

				choice1->SetActive(false);
				choice2->SetActive(false);
				choice3->SetActive(false);

				choiceDelay = 1.f;
			}
		}
		if (Button::ButtonOnRect(*cursor, *choice3))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && choice3->GetActive() == true)
			{
				int hp = ironClad->GetCurHP();
				int maxhp = ironClad->GetMaxHP();
				ironClad->SetCurHP(hp -= 10);
				ironClad->SetMaxHP(maxhp -= 10);

				ironCladCurHp->SetText(to_string(ironClad->GetMaxHP()));
				ironCladMaxHp->SetText("/ " + to_string(ironClad->GetMaxHP()));
				curHp->SetText(to_string(ironClad->GetMaxHP()));
				maxHp->SetText(to_string(ironClad->GetMaxHP()));

				ironClad->AddDamage(2);
				ironCladDamage->SetText("A : " + to_string((int)ironClad->GetDamage()));

				choice1->SetActive(false);
				choice2->SetActive(false);
				choice3->SetActive(false);

				choiceDelay = 1.f;
			}
		}

		if (choiceDelay <= 0.f 
			&& choice1->GetActive() == false
			&& choice2->GetActive() == false
			&& choice3->GetActive() == false)
			stage = Stage::Map;
	}
	else
	{
		choice1->SetActive(false);
		choice2->SetActive(false);
		choice3->SetActive(false);
	}
}

void PlayUi::SetDieUi(bool set)
{
	floors->SetText("Floors : " + to_string(choiceOrder));
	monsterKilled->SetText("Monster Killed : " + to_string(monsterKillCount));
	floors->SetOrigin(Origins::MC);
	monsterKilled->SetOrigin(Origins::MC);

	dieOrGiveup->SetActive(set);
	floors->SetActive(set);
	monsterKilled->SetActive(set);
	mainMenuButton->SetActive(set);

	if (dieOrGiveup->GetActive() == true)
	{
		optionUi = false;
		mapUi = false;
		giveupUi = false;

		if (Button::ButtonOnRect(*cursor, *mainMenuButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && mainMenuButton->GetActive() == true)
			{
				ResetPlayUi();
				UiDev1::SetStartSound(true);
			}
		}
	}
}

void PlayUi::SetShopMapUi(bool set)
{
	damageUp->SetActive(set);
	defenseUp->SetActive(set);
	energyUp->SetActive(set);
	hpUp->SetActive(set);
	getSkill->SetActive(set);
}

void PlayUi::SetRewordMapUi(bool set)
{
	chest->SetActive(set);
}

void PlayUi::SetRewordUi(bool set)
{
	addGold->SetActive(set);
	addDamage->SetActive(set);
	addDefend->SetActive(set);
	addHp->SetActive(set);
	rewordImage->SetActive(set);
	rewordText->SetActive(set);
}

void PlayUi::ResetPlayUi()
{
	monster.clear();
	uiObjList.clear();

	Init();

	ironClad->SetAlive(true);
	monster[0]->SetAlive(true);
	SetDieUi(false);

	monsterRandomPatternSetting = true;
	isMonsterTern = true;
	isPlayerTern = true;
	playerActionCountSet = true;
	isStageClear = false;
	chooseOption = true;
	monsterKillCount = 0;
	optionUi = false;
	mapUi = false;
	giveupUi = false;
	choiceOrder = 0;
	stage = Stage::Start;
	SOUND_MGR->StopAll();
}

void PlayUi::SetAttackSkillUi(bool set)
{
	normalAttackButton->SetActive(set);
	attackSkillButton1->SetActive(set);
}

void PlayUi::PlayerAttackDamage(int damage)
{
	if (monster[0]->GetDefend() > 0)
	{
		if (monster[0]->GetDefend() >= damage)
		{
			int defend = monster[0]->GetDefend();
			monster[0]->SetDefend(defend -= damage);
			monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));
		}
		else if (monster[0]->GetDefend() < damage)
		{
			int piercingDamage = damage - monster[0]->GetDefend();
			monster[0]->SetDefend(0);
			monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));
			monster[0]->SetCurHp(monster[0]->GetCurHp() - piercingDamage);
			monsterCurHp->SetText(to_string(monster[0]->GetCurHp()));
		}
	}
	else
	{
		monster[0]->SetCurHp(monster[0]->GetCurHp() - damage);
		monsterCurHp->SetText(to_string(monster[0]->GetCurHp()));
	}
}

void PlayUi::MonsterAttackDamage(int damage)
{
	if (ironClad->GetDefend() > 0)
	{
		if (ironClad->GetDefend() >= damage)
		{
			int defend = ironClad->GetDefend();
			ironClad->SetDefend(defend -= damage);
			ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
		}
		else if (ironClad->GetDefend() < damage)
		{
			int piercingDamage = damage - ironClad->GetDefend();
			ironClad->SetDefend(0);
			ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
			ironClad->SetCurHP(ironClad->GetCurHP() - piercingDamage);
			ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
			curHp->SetText(to_string(ironClad->GetCurHP()));
		}
	}
	else
	{
		ironClad->SetCurHP(ironClad->GetCurHP() - damage);
		ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
		curHp->SetText(to_string(ironClad->GetCurHP()));
	}
}