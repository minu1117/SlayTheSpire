#include "PlayUi.h"
#include "../InlcludeHeader/UiIncludeHeader.h"
#include "../Scenes/SceneDev2_Play.h"
#include "UiDev1.h"
#include "../GameObject/Monster.h"
#include "../Framework/SoundMgr.h"
#include "../GameObject/BossMonster.h"

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
	uiObjList.push_back(getSmite);
	uiObjList.push_back(getClubbing);
	uiObjList.push_back(getSmiteGold);
	uiObjList.push_back(getClubbingGold);


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
	uiObjList.push_back(attackSkillButton2);

	// monster
	uiObjList.push_back(monster[0]);

	// Boss
	uiObjList.push_back(bossShadow);
	uiObjList.push_back(bossPlasma3);
	uiObjList.push_back(bossPlasma2);
	uiObjList.push_back(bossPlasma1);
	uiObjList.push_back(boss);


	// Monster / Boss Ui
	uiObjList.push_back(monsterMaxHpBar);
	uiObjList.push_back(monsterCurHpBar);
	uiObjList.push_back(monsterDefend);
	uiObjList.push_back(monsterCurHp);
	uiObjList.push_back(monsterMaxHp);
	uiObjList.push_back(monsterPattern);
	uiObjList.push_back(monsterDamage);
	uiObjList.push_back(monsterWeakenText);


	// gameClear
	uiObjList.push_back(gameClearBackground);
	uiObjList.push_back(clearText);


	// player
	uiObjList.push_back(energyLayer5);
	uiObjList.push_back(energyLayer1);
	uiObjList.push_back(energyLayer2);
	uiObjList.push_back(energyLayer3);
	uiObjList.push_back(energyLayer4);
	uiObjList.push_back(energyLayer);
	uiObjList.push_back(playerMaxHpBar);
	uiObjList.push_back(playerCurHpBar);
	uiObjList.push_back(ironClad);
	uiObjList.push_back(ironCladMaxHp);
	uiObjList.push_back(ironCladCurHp);
	uiObjList.push_back(ironCladCurEnergy);
	uiObjList.push_back(ironCladMaxEnergy);
	uiObjList.push_back(playerBlock);
	uiObjList.push_back(ironCladCurDefend);
	uiObjList.push_back(playerWeakenText);


	uiObjList.push_back(monsterAttackImage);
	uiObjList.push_back(playerAttackImage);



	uiObjList.push_back(monsterBlock);
	

	// Skill info
	uiObjList.push_back(normalAttackInfo);
	uiObjList.push_back(smiteInfo);
	uiObjList.push_back(clubbingInfo);
	uiObjList.push_back(normalAttackDamageText);
	uiObjList.push_back(smiteDamageText);
	uiObjList.push_back(clubbingDamageText);

	// clear
	uiObjList.push_back(clearBackground);
	uiObjList.push_back(continueButton);

	// map
	uiObjList.push_back(mapBackground);
	uiObjList.push_back(map);

	uiObjList.push_back(monsterMapIconOutLine);
	uiObjList.push_back(rewordMapIconOutLine);
	uiObjList.push_back(shopMapIconOutLine);
	uiObjList.push_back(questionMapIconOutLine);

	uiObjList.push_back(monsterMapIcon);
	uiObjList.push_back(rewordMapIcon);
	uiObjList.push_back(questionMapIcon);
	uiObjList.push_back(shopMapIcon);
	uiObjList.push_back(bossMapIconOutLine);
	uiObjList.push_back(bossMapIcon);

	for (int i = 0; i < 4; i++)
		uiObjList.push_back(mapClearIcon[i]);

	uiObjList.push_back(mapChoiceCircle);


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
	if (gameSound == true)
	{
		SOUND_MGR->Play("sounds/gamePlaySound.ogg", true);
		gameSound = false;
	}
	if (bossStageSound == true)
	{
		SOUND_MGR->StopAll();
		SOUND_MGR->Play("sounds/Boss.ogg", true);
		bossStageSound = false;
	}

	Vector2f worldMousePos = parentScene->ScreenToUiPos((Vector2i)InputMgr::GetMousePos());
	cursor->SetPos(worldMousePos);

	// Player / Monster HP, HP Bar Control
	HpControl();
	EnterTheStage(dt);

	attackDelay -= dt;
	monsterAttackDelay -= dt;
	playerAttackImage->SetRotation(playerAttackImage->GetRotate() + dt * 60);

	if (ironClad->GetCurEnergy() == 0 && lastEnergyAttack == true)
	{
		attackDelay = 0.1f;
		lastEnergyAttack = false;
	}

	if (attackDelay <= 0.f)
	{
		monsterAttackImage->SetActive(false);
		lastEnergyAttack = true;
	}
	if (monsterAttackDelay <= 0.f)
	{
		playerAttackImage->SetActive(false);
	}

	if (ironClad->GetDefend() > 0)
	{
		playerCurHpBar->SetFillColor({ 0, 103, 163 });
		playerBlock->SetFillColor({ 80, 188, 223 });
		playerBlock->SetActive(true);
	}
	else
	{
		playerCurHpBar->SetFillColor(Color::Red);
		playerBlock->SetActive(false);
	}

	if (monster[0]->GetDefend() > 0 || boss->GetDefend() > 0)
	{
		monsterCurHpBar->SetFillColor({ 0, 103, 163 });
		monsterBlock->SetFillColor({ 80, 188, 223 });
		monsterBlock->SetActive(true);
	}
	else
	{
		monsterCurHpBar->SetFillColor(Color::Red);
		monsterBlock->SetActive(false);
	}

	energyLayer1->SetRotation(energyLayer1->GetRotate() - dt * 50);
	energyLayer2->SetRotation(energyLayer2->GetRotate() + dt * 40);
	energyLayer3->SetRotation(energyLayer3->GetRotate() - dt * 30);
	energyLayer4->SetRotation(energyLayer4->GetRotate() + dt * 20);

	monsterPattern->SetOrigin(Origins::MC);
	playerWeakenText->SetOrigin(Origins::MC);
	monsterWeakenText->SetOrigin(Origins::MC);
	ironCladCurDefend->SetOrigin(Origins::MC);


	if (stage == Stage::Monster || stage == Stage::Boss)
	{
		if (stage == Stage::Monster)
		{
			if (ironClad->GetAlive() == true)
				SetDieUi(false);
			else
				SetDieUi(true);
		}
		else
		{
			if (ironClad->GetAlive() == true)
			{
				SetDieUi(false);
			}
		}
	}

	if (InputMgr::GetKeyDown(Keyboard::Key::T)) // dev
	{
		ironClad->AddGold(50000);
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Y)) // dev
	{
		ironClad->SetDamage(1000000);
	}

	if (stage == Stage::Start)
	{
		ironClad->SetTexture(*RESOURCE_MGR->GetTexture("graphics/ironcladimage.png"));
		SetGameClearUi(false);
		if (ironClad->GetAlive() == true)
			SetDieUi(false);
		else
			SetDieUi(true);

		MonsterSet(monster, false);
		SetActionUi(false);
		SetClearUi(false);
		StartMapPlayerUpgrade(dt);
	}

	if (Button::ButtonOnRect(*cursor, *continueButton) && continueButton->GetActive() == true)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
		{
			if (stage == Stage::Reword)
				isChestOpen = false;

			if (stage == Stage::Monster)
			{
				int randomStage = Utils::RandomRange(0, 5);
				int randomMonsterHp = Utils::RandomRange(36, 72);
				MonsterType randomMonsterLevel = (MonsterType)Utils::RandomRange(0, 3);

				monster[0]->SetMonster(randomMonsterHp, randomMonsterHp, 0, 0, randomMonsterLevel);
				monster[0]->SetAlive(true);
				MonsterSet(monster, true);
				monster[0]->SetIsWeaken(0);
				monsterWeakenText->SetText("");
				
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
			SOUND_MGR->Play("sounds/uiClick.wav", false);
			
			if (stage != Stage::Boss)
			{
				ironClad->SetDefend(0);
				ironCladCurDefend->SetText("");
				randomReword = true;
				stage = Stage::Map;
				choiceOrder++;
			}
			else
			{
				stage = Stage::None;
				ironClad->SetAlive(false);
				SetGameClearUi(true);
				clearText->SetOrigin(Origins::MC);
				energyLayer->SetActive(false);
				energyLayer1->SetActive(false);
				energyLayer2->SetActive(false);
				energyLayer3->SetActive(false);
				energyLayer4->SetActive(false);
				energyLayer5->SetActive(false);
				ironCladCurEnergy->SetActive(false);
				ironCladMaxEnergy->SetActive(false);
			}
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
	{
		SetShopMapUi(false);
		getSmiteGold->SetActive(false);
		getClubbingGold->SetActive(false);
	}


	if (stage == Stage::Boss)
	{
		bossPlasma1->SetActive(true);
		bossPlasma2->SetActive(true);
		bossPlasma3->SetActive(true);
		bossShadow->SetActive(true);

		bossPlasma1->SetRotation(bossPlasma1->GetRotate() + dt * 20);
		bossPlasma2->SetRotation(bossPlasma2->GetRotate() - dt * 30);
		bossPlasma3->SetRotation(bossPlasma3->GetRotate() + dt * 40);

		SetMonsterStage(dt);
		if (isMonsterTern == true || ironClad->GetAlive() == false)
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

		if (bossCount > 0)
			SetGameClearUi(false);

		if (boss->GetCurHp() <= 0)
			bossCount--;

		if (isAttackSkill == true)
			SetAttackSkillUi(true);
		else
			SetAttackSkillUi(false);

		if (ironClad->GetAlive() == false)
			SetDieUi(true);
	}
	else
	{
		boss->SetActive(false);
		bossPlasma1->SetActive(false);
		bossPlasma2->SetActive(false);
		bossPlasma3->SetActive(false);
		bossShadow->SetActive(false);
	}

	if (stage == Stage::Monster || stage == Stage::Boss)
	{
		if (stage == Stage::Monster)
		{
			monsterPattern->SetPos({ monster[0]->GetPos().x - 30, monster[0]->GetPos().y - monster[0]->GetSize().y / 2 - 10 });

			if (monsterCount > 0)
				SetClearUi(false);
			else
				SetClearUi(true);
		}
		else if (stage == Stage::Boss)
		{
			if (bossCount > 0)
				SetClearUi(false);
		}

		if (stage == Stage::Boss)
		{
			Vector2f setMonsterUiPos = { monster[0]->GetPos().x - 30, monster[0]->GetPos().y + (monster[0]->GetSize().y / 2) };

			monsterPattern->SetPos({ boss->GetPos().x, boss->GetPos().y - boss->GetSize().y / 2 });
			monsterWeakenText->SetPos({ boss->GetPos().x, boss->GetPos().y - boss->GetSize().y / 2 - 100 });

			monsterDefend->SetPos({ setMonsterUiPos.x - 50, setMonsterUiPos.y - 10 });
			monsterDamage->SetPos({ monsterDefend->GetPos().x, setMonsterUiPos.y + 30 });

			monsterCurHp->SetPos({ setMonsterUiPos.x - 30, setMonsterUiPos.y - 60});
			monsterMaxHp->SetText(" /  " + to_string(boss->GetMaxHp()));
			monsterMaxHp->SetPos({ setMonsterUiPos.x + 20, setMonsterUiPos.y - 60});

			monsterAttackImage->SetPos(boss->GetPos());
			monsterAttackImage->SetScale(3, 5);
		}
	}
	else
	{
		MonsterSet(monster, false);
		SetActionUi(false);
		clearBackground->SetActive(false);
		ternPassButtonHover->SetActive(false);
		isAttackSkill = false;
		monsterAttackImage->SetActive(false);
		playerAttackImage->SetActive(false);
	}

	// Option Ui Control
	if (giveupUi == false)
		OptionUiControl();

	// Map Ui Control
	if (giveupUi == false && optionUi == false)
		MapUiControl();

	// GiveUp Ui Control
	GiveUpUiControl();

	if (smiteOn == true)
		getSmite->SetActive(false);
	if (clubbingOn == true)
		getClubbing->SetActive(false);

	if (Button::ButtonOnRect(*cursor, *mainMenuButton))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && mainMenuButton->GetActive() == true)
		{
			ResetPlayUi();
			UiDev1::SetStartSound(true);
		}
	}

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
	bossMapIcon->SetActive(set);

	if (choiceOrder == 0)
	{
		for (int i = 0; i < mapClearIcon.size(); i++)
		{
			mapClearIcon[i]->SetActive(false);
		}
	}
	else
	{
		if (choiceOrder >= 1)
			mapClearIcon[3]->SetActive(set);
		if (choiceOrder >= 2)
			mapClearIcon[2]->SetActive(set);
		if (choiceOrder >= 3)
			mapClearIcon[1]->SetActive(set);
		if (choiceOrder >= 4)
			mapClearIcon[0]->SetActive(set);
	}
}

void PlayUi::SetGiveUpUi(bool set)
{
	confirmBackground->SetActive(set);
	yesButton->SetActive(set);
	noButton->SetActive(set);
	confirmMessage->SetActive(set);
}

void PlayUi::MonsterAttack(float dt)
{
	if (stage == Stage::Monster)
	{
		if (monster[0]->GetIsWeaken() == 0)
		{
			MonsterAttackDamage(monster[0]->GetDamage());
			playerAttackImage->SetActive(true);
			monsterAttackDelay = 0.1f;
		}
		else if (monster[0]->GetIsWeaken() > 0)
		{
			MonsterAttackDamage(monster[0]->GetDamage() / 2);
			playerAttackImage->SetActive(true);
			monsterAttackDelay = 0.1f;
		}
	}
	else if (stage == Stage::Boss)
	{
		if (boss->GetIsWeaken() == 0)
		{
			MonsterAttackDamage(boss->GetDamage());
			playerAttackImage->SetActive(true);
			monsterAttackDelay = 0.1f;
		}
		else if (boss->GetIsWeaken() > 0)
		{
			MonsterAttackDamage(boss->GetDamage() / 2);
			playerAttackImage->SetActive(true);
			monsterAttackDelay = 0.1f;
		}
	}

	if (ironClad->GetAlive() == true)
	{
		SceneDev2_Play::SetIsMonsterAttack(true);
		SceneDev2_Play::SetMonsterAttackDelay(0.f);
	}
}

void PlayUi::PlayerAttack(float dt, Skill skill)
{
	ironClad->SetIsAttack(true);
	ironClad->Attack(dt);
	SceneDev2_Play::SetIsAttack(true);
	SceneDev2_Play::SetAttackDelay(0.05f);

	if (stage == Stage::Monster)
	{
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
			monsterWeakenText->SetText("Weaken : " + to_string(monster[0]->GetIsWeaken()));

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
	else if (stage == Stage::Boss)
	{
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

			boss->SetIsWeaken(boss->GetIsWeaken() + 2);
			monsterWeakenText->SetText("Weaken : " + to_string(boss->GetIsWeaken()));

			if (randomMonsterPattern >= 4 && randomMonsterPattern < 8)
				monsterDamage->SetText("A : " + to_string((int)boss->GetDamage() / 2));
			else if (randomMonsterPattern == 8)
				monsterDamage->SetText("A : " + to_string((int)boss->GetDamage() / 2) + " X 6");
		}
		else if (skill == Skill::clubbing)
		{
			if (ironClad->GetIsWeaken() > 0)
				PlayerAttackDamage(ironClad->GetDamage() * 4 / 2);
			else
				PlayerAttackDamage(ironClad->GetDamage() * 4);
		}
	}
}

void PlayUi::MonsterSet(vector<Monster*> monster, bool set)
{
	if (stage == Stage::Monster)
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
	else if (stage == Stage::Boss)
	{
		monster[0]->SetActive(false);
		monster[0]->SetAlive(false);

		if (set == true)
		{
			if (boss->GetCurHp() <= 0)
			{
				boss->SetAlive(false);
				boss->SetActive(false);
				bossPlasma1->SetActive(false);
				bossPlasma2->SetActive(false);
				bossPlasma3->SetActive(false);
				bossShadow->SetActive(false);
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
				boss->SetAlive(set);
				boss->SetActive(set);

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
		else
		{
			monster[0]->SetActive(false);
			monster[0]->SetAlive(false);

			boss->SetAlive(set);
			boss->SetActive(set);

			monsterCurHp->SetActive(set);
			monsterMaxHp->SetActive(set);
			monsterDamage->SetActive(set);
			monsterDefend->SetActive(set);
			monsterPattern->SetActive(set);
			monsterCurHpBar->SetActive(set);
			monsterMaxHpBar->SetActive(set);
		}
	}
	else
	{
		monster[0]->SetActive(false);
		monster[0]->SetAlive(false);
		boss->SetAlive(false);
		boss->SetActive(false);
		monsterCurHp->SetActive(false);
		monsterMaxHp->SetActive(false);
		monsterDamage->SetActive(false);
		monsterDefend->SetActive(false);
		monsterPattern->SetActive(false);
		monsterCurHpBar->SetActive(false);
		monsterMaxHpBar->SetActive(false);
	}
}

void PlayUi::PlayerTern(float dt)
{
	// player tern
	int maxEnergy = ironClad->GetMaxEnergy();
	playerTurnSoundDelay -= dt;

	if (playerActionCountSet == true && playerTurnSoundDelay <= 0.f)
	{
		int count = Utils::RandomRange(0, maxEnergy + 2);

		ironClad->SetAttackCount(count);

		int attCount = ironClad->GetAttackCount();
		ironClad->SetDefendCount((maxEnergy -= count) + 2);

		SOUND_MGR->Play("sounds/playerTernStart.ogg", false);
		playerActionCountSet = false;
	}
	else if (playerActionCountSet == true && playerTurnSoundDelay >= 0.f)
	{
		ironClad->SetAttackCount(0);
		ironClad->SetDefendCount(0);
	}

	if (stage == Stage::Monster)
	{
		AttackButtonControl(monsterCount, dt);
	}
	else if (stage == Stage::Boss)
	{
		AttackButtonControl(bossCount, dt);
	}
}

void PlayUi::SetNextMonsterAction()
{
	if (stage == Stage::Monster)
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
	else if (stage == Stage::Boss)
	{
		randomMonsterPattern = Utils::RandomRange(0, 9);

		if (randomMonsterPattern <= 1)
		{
			monsterPattern->SetText("DEFENCE");
			monsterDamage->SetText("");
			monsterDamage->SetActive(false);
		}
		else if (randomMonsterPattern == 2 || randomMonsterPattern == 3)
		{
			monsterPattern->SetText("Status Ailment");
			monsterDamage->SetText("");
			monsterDamage->SetActive(false);
		}
		else if (randomMonsterPattern == 4 || randomMonsterPattern == 5 || randomMonsterPattern == 6)
		{
			int setDamage = Utils::RandomRange(6, 12);
			boss->SetDamage(setDamage);
			monsterPattern->SetText("NORMAL ATTACK");

			if (boss->GetIsWeaken() == 0)
				monsterDamage->SetText("A : " + to_string((int)boss->GetDamage()));
			else
				monsterDamage->SetText("A : " + to_string((int)boss->GetDamage() / 2));

			monsterDamage->SetActive(true);
		}
		else if (randomMonsterPattern == 7)
		{
			int setDamage = Utils::RandomRange(20, 40);
			boss->SetDamage(setDamage);
			monsterPattern->SetText("SMITE");

			if (boss->GetIsWeaken() == 0)
				monsterDamage->SetText("A : " + to_string((int)boss->GetDamage()));
			else
				monsterDamage->SetText("A : " + to_string((int)boss->GetDamage() / 2));

			monsterDamage->SetActive(true);
		}
		else if (randomMonsterPattern == 8)
		{
			boss->SetDamage(6);
			monsterPattern->SetText("NUKE");

			if (boss->GetIsWeaken() == 0)
				monsterDamage->SetText("A : " + to_string((int)boss->GetDamage()) + " X 6");
			else
				monsterDamage->SetText("A : " + to_string((int)boss->GetDamage() / 2) + " X 6");

			monsterDamage->SetActive(true);
		}

		monsterRandomPatternSetting = false;
		isMonsterTern = false;
	}
}

void PlayUi::MonsterAction(float dt)
{
	if (ironClad->GetIsWeaken() > 0)
		ironClad->SetIsWeaken(ironClad->GetIsWeaken() - 1);

	if (stage == Stage::Monster)
	{
		monster[0]->Pattern(randomMonsterPattern, dt);
		if (monster[0]->GetPattern() == MonsterPattern::Attack)
		{
			MonsterAttack(dt);
			SOUND_MGR->Play("sounds/enemyAttack.ogg", false);
		}

		if (monster[0]->GetPattern() == MonsterPattern::Weaken)
		{
			ironClad->SetIsWeaken(ironClad->GetIsWeaken() + 1);
			playerWeakenText->SetText("Weaken : " + to_string(ironClad->GetIsWeaken()));
			SOUND_MGR->Play("sounds/debuff.ogg", false);
			ironClad->SetIsWeakenMotion(true);
		}

		if (monster[0]->GetPattern() == MonsterPattern::Defence)
			SOUND_MGR->Play("sounds/defence.ogg", false);

		monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));
	}
	if (stage == Stage::Boss)
	{
		boss->BossPattenSet(randomMonsterPattern, ironClad);

		if (boss->GetBossPattern() == BossPattern::NormalAttack)
		{
			MonsterAttack(dt);
			SOUND_MGR->Play("sounds/bossAttack.ogg", false);
		}
		if (boss->GetBossPattern() == BossPattern::Smite)
		{
			MonsterAttack(dt);
			SOUND_MGR->Play("sounds/bossHeavyAttack.ogg", false);
		}

		if (boss->GetBossPattern() == BossPattern::Weaken)
		{
			playerWeakenText->SetText("Weaken : " + to_string(ironClad->GetIsWeaken()));
			ironClad->SetIsWeakenMotion(true);
			SOUND_MGR->Play("sounds/debuff.ogg", false);
		}

		if (boss->GetBossPattern() == BossPattern::Nuke)
		{
			nukeDelay -= dt;

			if (boss->GetNukeCount() > 0 && nukeDelay <= 0.f)
			{
				MonsterAttack(dt);
				boss->SetNukeCount(boss->GetNukeCount() - 1);
				nukeDelay = 0.2f;
				SOUND_MGR->Play("sounds/bossAttack.ogg", false);
			}
		}

		if (boss->GetBossPattern() == BossPattern::Defense)
		{
			SOUND_MGR->Play("sounds/defence.ogg", false);
		}

		monsterDefend->SetText("D : " + to_string(boss->GetDefend()));
	}


	if (stage == Stage::Boss)
	{
		if (boss->GetBossPattern() == BossPattern::Nuke)
		{
			if (boss->GetNukeCount() == 0)
			{
				if (ironClad->GetIsWeaken() > 0)
				{
					ironClad->SetIsWeaken(ironClad->GetIsWeaken());
					playerWeakenText->SetText("Weaken : " + to_string(ironClad->GetIsWeaken()));
				}
				else if (ironClad->GetIsWeaken() == 0)
				{
					playerWeakenText->SetText("");
				}

				ironClad->SetCurEnergy(ironClad->GetMaxEnergy());
				ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

				isPlayerTern = true;
				monsterRandomPatternSetting = true;
				playerActionCountSet = true;
				ternPassButton->SetActive(true);

				if (boss->GetIsWeaken() > 0)
				{
					boss->SetIsWeaken(boss->GetIsWeaken() - 1);
					monsterWeakenText->SetText("Weaken : " + to_string(boss->GetIsWeaken()));
				}
				if (boss->GetIsWeaken() == 0)
					monsterWeakenText->SetText("");

				boss->SetNukeCount(6);

				ironClad->SetDefend(0);
				ironCladCurDefend->SetText("");
				playerTurnSoundDelay = 1.f;
			}
		}
		else
		{
			if (ironClad->GetIsWeaken() > 0)
			{
				ironClad->SetIsWeaken(ironClad->GetIsWeaken());
				playerWeakenText->SetText("Weaken : " + to_string(ironClad->GetIsWeaken()));
			}
			else if (ironClad->GetIsWeaken() == 0)
			{
				playerWeakenText->SetText("");
			}

			ironClad->SetCurEnergy(ironClad->GetMaxEnergy());
			ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

			isPlayerTern = true;
			monsterRandomPatternSetting = true;
			playerActionCountSet = true;
			ternPassButton->SetActive(true);

			if (boss->GetIsWeaken() > 0)
			{
				boss->SetIsWeaken(boss->GetIsWeaken() - 1);
				monsterWeakenText->SetText("Weaken : " + to_string(boss->GetIsWeaken()));
			}
			if (boss->GetIsWeaken() == 0)
				monsterWeakenText->SetText("");

			boss->SetNukeCount(6);

			ironClad->SetDefend(0);
			ironCladCurDefend->SetText("");
			playerTurnSoundDelay = 1.f;
		}
	}
	else
	{
		if (ironClad->GetIsWeaken() > 0)
		{
			ironClad->SetIsWeaken(ironClad->GetIsWeaken());
			playerWeakenText->SetText("Weaken : " + to_string(ironClad->GetIsWeaken()));
		}
		else if (ironClad->GetIsWeaken() == 0)
		{
			playerWeakenText->SetText("");
		}

		ironClad->SetCurEnergy(ironClad->GetMaxEnergy());
		ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

		isPlayerTern = true;
		monsterRandomPatternSetting = true;
		playerActionCountSet = true;
		ternPassButton->SetActive(true);

		if (monster[0]->GetIsWeaken() > 0)
		{
			monster[0]->SetIsWeaken(monster[0]->GetIsWeaken() - 1);
			monsterWeakenText->SetText("Weaken : " + to_string(monster[0]->GetIsWeaken()));
		}
		if (monster[0]->GetIsWeaken() == 0)
			monsterWeakenText->SetText("");

		ironClad->SetDefend(0);
		ironCladCurDefend->SetText("");
		playerTurnSoundDelay = 1.f;
	}
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
		monster[0]->SetAll(*RESOURCE_MGR->GetTexture("graphics/monsterImage.png"),
			{ windowSize.x / 1.4f, windowSize.y / 1.7f }, Origins::MC);
		monster[0]->SetScale(1, 1);
		monsterCount = monster.size();

		Vector2f setMonsterUiPos = { monster[0]->GetPos().x - 30, monster[0]->GetPos().y + (monster[0]->GetSize().y / 3) + 20 };


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

		// Weaken Text
		{
			monsterWeakenText = new TextObj();
			monsterWeakenText->SetAll(font, "", 30, Color::White, 
				{monster[0]->GetPos().x - 20, monster[0]->GetPos().y - monster[0]->GetSize().y / 2 - 50});
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
			attackSkillButton2 = new SpriteObj();

			actionWindow = new SpriteObj();
			attackCount = new TextObj();
			defendCount = new TextObj();

			ironCladMaxHp = new TextObj();
			ironCladCurHp = new TextObj();
			ironCladCurEnergy = new TextObj();
			ironCladMaxEnergy = new TextObj();
			ironCladCurDefend = new TextObj();

			Vector2f setPlayerUiPos = { ironClad->GetPos().x - 10, ironClad->GetPos().y + (ironClad->GetSize().y / 2) };

			ironCladCurHp->SetAll(font, to_string(ironClad->GetCurHP()), 30, Color::White, setPlayerUiPos);

			ironCladMaxHp->SetAll(font, "/ " + to_string(ironClad->GetMaxHP()), 30, Color::White,
				{ ironCladCurHp->GetPos().x + 40, setPlayerUiPos.y });

			ironCladCurEnergy->SetAll(font, to_string(ironClad->GetCurEnergy()), 35, Color::White,
				{ 100, windowSize.y - 100 });
			ironCladCurEnergy->SetOrigin(Origins::MC);

			ironCladMaxEnergy->SetAll(font, "    / " + to_string(ironClad->GetMaxEnergy()), 35, Color::White,
				{ ironCladCurEnergy->GetPos().x + 20, ironCladCurEnergy->GetPos().y + 3 });
			ironCladMaxEnergy->SetOrigin(Origins::MC);

			ironCladCurDefend->SetAll(font, "", 30, Color::Black,
				{ setPlayerUiPos.x - 85, setPlayerUiPos.y + 10});


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

				attackSkillButton2->SetAll(*RESOURCE_MGR->GetTexture("graphics/clubbingSkillButton.png"), { 0, 0 }, Origins::MC);
				attackSkillButton2->SetPos({ -200, -200 });


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

			// Weaken Text
			{
				playerWeakenText = new TextObj();

				playerWeakenText->SetAll(font, "", 30, Color::White,
					{ironClad->GetPos().x, ironClad->GetPos().y - ironClad->GetSize().y / 2 - 30});
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

	//ending
	{
		gameClearBackground = new SpriteObj();
		clearText = new TextObj();


		gameClearBackground->SetAll(*RESOURCE_MGR->GetTexture("graphics/ending.png"), windowSize * 0.5f, Origins::MC);
		clearText->SetAll(font, "CLEAR ?", 200, Color::White, { 0, 0 });
		clearText->SetPos({windowSize.x * 0.5f, clearText->GetSize().top + 200});
	}

	// choice
	{
		choice1 = new SpriteObj();
		choice2 = new SpriteObj();
		choice3 = new SpriteObj();

		choice1->SetAll(*RESOURCE_MGR->GetTexture("graphics/choice1.png"), {-200, -200 }, Origins::MC);
		choice2->SetAll(*RESOURCE_MGR->GetTexture("graphics/choice2.png"), { -200, -200 }, Origins::MC);
		choice3->SetAll(*RESOURCE_MGR->GetTexture("graphics/choice3.png"), { -200, -200 }, Origins::MC);
	}


	// Map Icon
	{
		monsterMapIcon = new SpriteObj();
		rewordMapIcon = new SpriteObj();
		questionMapIcon = new SpriteObj();
		shopMapIcon = new SpriteObj();
		bossMapIcon = new SpriteObj();
		bossMapIconOutLine = new SpriteObj();
		monsterMapIconOutLine = new SpriteObj();
		rewordMapIconOutLine = new SpriteObj();
		shopMapIconOutLine = new SpriteObj();
		questionMapIconOutLine = new SpriteObj();

		monsterMapIcon->SetAll(*RESOURCE_MGR->GetTexture("graphics/monsterMapIcon.png"), { 0, 0 }, Origins::MC);
		rewordMapIcon->SetAll(*RESOURCE_MGR->GetTexture("graphics/rewordMapIcon.png"), { 0, 0 }, Origins::MC);
		questionMapIcon->SetAll(*RESOURCE_MGR->GetTexture("graphics/questionMapIcon.png"), { 0, 0 }, Origins::MC);
		shopMapIcon->SetAll(*RESOURCE_MGR->GetTexture("graphics/shopMapIcon.png"), { 0, 0 }, Origins::MC);
		bossMapIcon->SetAll(*RESOURCE_MGR->GetTexture("graphics/hexaghost.png"), { 0, 0 }, Origins::MC);
		bossMapIconOutLine->SetAll(*RESOURCE_MGR->GetTexture("graphics/hexaghostOutLine.png"), { 0, 0 }, Origins::MC);
		bossMapIconOutLine->SetActive(false);
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
			monsterMapIconYPos = windowSize.y * 0.9f;
			questionMapIconYPos = windowSize.y * 0.8f;
			shopMapIconYPos = windowSize.y * 0.7f;
			rewordMapIconYPos = windowSize.y * 0.6f;

			monsterMapOrder = 0;
			questionMapOrder = 1;
			shopMapOrder = 2;
			rewordMapOrder = 3;

			break;

		case 1:
			monsterMapIconYPos = windowSize.y * 0.8f;
			questionMapIconYPos = windowSize.y * 0.9f;
			shopMapIconYPos = windowSize.y * 0.6f;
			rewordMapIconYPos = windowSize.y * 0.7f;

			monsterMapOrder = 1;
			questionMapOrder = 0;
			shopMapOrder = 3;
			rewordMapOrder = 2;

			break;

		case 2:
			monsterMapIconYPos = windowSize.y * 0.7f;
			questionMapIconYPos = windowSize.y * 0.6f;
			shopMapIconYPos = windowSize.y * 0.8f;
			rewordMapIconYPos = windowSize.y * 0.9f;

			monsterMapOrder = 2;
			questionMapOrder = 3;
			shopMapOrder = 1;
			rewordMapOrder = 0;

			break;

		case 3:
			monsterMapIconYPos = windowSize.y * 0.6f;
			questionMapIconYPos = windowSize.y * 0.7f; 
			shopMapIconYPos = windowSize.y * 0.9f;
			rewordMapIconYPos = windowSize.y * 0.8f;

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
		bossMapIcon->SetPos({ windowSize.x * 0.5f, windowSize.y * 0.3f });
		bossMapIconOutLine->SetPos({ windowSize.x * 0.5f, windowSize.y * 0.3f });

		monsterMapIcon->SetFillColor(Color::Black);
		rewordMapIcon->SetFillColor(Color::Black);
		questionMapIcon->SetFillColor(Color::Black);
		shopMapIcon->SetFillColor(Color::Black);
		bossMapIcon->SetFillColor(Color::Black);

		monsterMapIconOutLine->SetAll(*RESOURCE_MGR->GetTexture("graphics/monsterOutline.png"), monsterMapIcon->GetPos(), Origins::MC);
		rewordMapIconOutLine->SetAll(*RESOURCE_MGR->GetTexture("graphics/chestOutline.png"), rewordMapIcon->GetPos(), Origins::MC);
		shopMapIconOutLine->SetAll(*RESOURCE_MGR->GetTexture("graphics/shopOutline.png"), shopMapIcon->GetPos(), Origins::MC);
		questionMapIconOutLine->SetAll(*RESOURCE_MGR->GetTexture("graphics/eventOutline.png"), questionMapIcon->GetPos(), Origins::MC);
	
		for (int i = 0; i < 4; i++)
			mapClearIcon.push_back(new SpriteObj());

		mapClearIcon[0]->SetAll(*RESOURCE_MGR->GetTexture("graphics/mapCompleteIcon.png"), { windowSize.x * 0.5f, windowSize.y * 0.6f }, Origins::MC);
		mapClearIcon[1]->SetAll(*RESOURCE_MGR->GetTexture("graphics/mapCompleteIcon.png"), { windowSize.x * 0.5f, windowSize.y * 0.7f }, Origins::MC);
		mapClearIcon[2]->SetAll(*RESOURCE_MGR->GetTexture("graphics/mapCompleteIcon.png"), { windowSize.x * 0.5f, windowSize.y * 0.8f }, Origins::MC);
		mapClearIcon[3]->SetAll(*RESOURCE_MGR->GetTexture("graphics/mapCompleteIcon.png"), { windowSize.x * 0.5f, windowSize.y * 0.9f }, Origins::MC);
	
		for (int i = 0; i < mapClearIcon.size(); i++)
			mapClearIcon[i]->SetScale(1.5f, 1.5f);

		mapChoiceCircle = new SpriteObj();
		mapChoiceCircle->SetAll(*RESOURCE_MGR->GetTexture("graphics/circle.png"), {0, 0}, Origins::MC);
		mapChoiceCircle->SetActive(false);
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
		getSmite = new SpriteObj();
		getClubbing = new SpriteObj();
		getSmiteGold = new TextObj();
		getClubbingGold = new TextObj();

		damageUp->SetAll(*RESOURCE_MGR->GetTexture("graphics/damageSale.png"), {0, 0}, Origins::MC);
		defenseUp->SetAll(*RESOURCE_MGR->GetTexture("graphics/defenseSale.png"), {0, 0}, Origins::MC);
		energyUp->SetAll(*RESOURCE_MGR->GetTexture("graphics/energytSale.png"), {0, 0}, Origins::MC);
		hpUp->SetAll(*RESOURCE_MGR->GetTexture("graphics/hpSale.png"), {0, 0}, Origins::MC);
		getSmite->SetAll(*RESOURCE_MGR->GetTexture("graphics/smiteAttakButton.png"), {0, 0}, Origins::MC);
		getClubbing->SetAll(*RESOURCE_MGR->GetTexture("graphics/clubbingSkillButton.png"), {0, 0}, Origins::MC);

		getSmiteGold->SetAll(font, "", 40, Color::White, {0, 0});
		getClubbingGold->SetAll(font, "", 40, Color::White, { 0, 0 });
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


	// Boss
	{
		boss = new BossMonster(150, 150, 0, 0);
		boss->SetAll(*RESOURCE_MGR->GetTexture("graphics/core.png"), 
			{ monster[0]->GetPos().x, monster[0]->GetPos().y - 100 }, Origins::MC);

		bossPlasma1 = new SpriteObj();
		bossPlasma2 = new SpriteObj();
		bossPlasma3 = new SpriteObj();
		bossShadow = new SpriteObj();

		bossPlasma1->SetAll(*RESOURCE_MGR->GetTexture("graphics/plasma1.png"), boss->GetPos(), Origins::MC);
		bossPlasma2->SetAll(*RESOURCE_MGR->GetTexture("graphics/plasma2.png"), boss->GetPos(), Origins::MC);
		bossPlasma3->SetAll(*RESOURCE_MGR->GetTexture("graphics/plasma3.png"), boss->GetPos(), Origins::MC);
		bossShadow->SetAll(*RESOURCE_MGR->GetTexture("graphics/shadow.png"), boss->GetPos(), Origins::MC);
	}

	// energy
	{
		energyLayer = new SpriteObj();
		energyLayer1 = new SpriteObj();
		energyLayer2 = new SpriteObj();
		energyLayer3 = new SpriteObj();
		energyLayer4 = new SpriteObj();
		energyLayer5 = new SpriteObj();

		energyLayer->SetAll(*RESOURCE_MGR->GetTexture("graphics/energyLayer.png"), 
			{ ironCladMaxEnergy->GetPos().x + 5, ironCladMaxEnergy->GetPos().y + 5 }, Origins::MC);
		energyLayer1->SetAll(*RESOURCE_MGR->GetTexture("graphics/energyLayer1.png"), energyLayer->GetPos(), Origins::MC);
		energyLayer2->SetAll(*RESOURCE_MGR->GetTexture("graphics/energyLayer2.png"), energyLayer->GetPos(), Origins::MC);
		energyLayer3->SetAll(*RESOURCE_MGR->GetTexture("graphics/energyLayer3.png"), energyLayer->GetPos(), Origins::MC);
		energyLayer4->SetAll(*RESOURCE_MGR->GetTexture("graphics/energyLayer4.png"), energyLayer->GetPos(), Origins::MC);
		energyLayer5->SetAll(*RESOURCE_MGR->GetTexture("graphics/energyLayer5.png"), energyLayer->GetPos(), Origins::MC);
	}

	// Attack Skill Info
	{
		normalAttackInfo = new SpriteObj();
		smiteInfo = new SpriteObj();
		clubbingInfo = new SpriteObj();

		normalAttackDamageText = new TextObj();
		smiteDamageText = new TextObj();
		clubbingDamageText = new TextObj();

		normalAttackInfo->SetAll(*RESOURCE_MGR->GetTexture("graphics/normalAttackInfo.png"), {0, 0}, Origins::MC);
		smiteInfo->SetAll(*RESOURCE_MGR->GetTexture("graphics/smiteInfo.png"), {0, 0}, Origins::MC);
		clubbingInfo->SetAll(*RESOURCE_MGR->GetTexture("graphics/clubbingInfo.png"), {0, 0}, Origins::MC);

		normalAttackInfo->SetActive(false);
		smiteInfo->SetActive(false);
		clubbingInfo->SetActive(false);


		normalAttackDamageText->SetAll(font, "", 30, Color::White, {0, 0});
		smiteDamageText->SetAll(font, "", 30, Color::White, { 0, 0 });
		clubbingDamageText->SetAll(font, "", 30, Color::White, { 0, 0 });
	}

	// Player / Monster Block Image
	{
		monsterBlock = new SpriteObj();
		playerBlock = new SpriteObj();

		monsterBlock->SetAll(*RESOURCE_MGR->GetTexture("graphics/block.png"), 
			{ monsterMaxHpBar->GetPos().x - monsterMaxHpBar->GetSize().x + 25, monsterMaxHpBar->GetPos().y}, Origins::MC);

		playerBlock->SetAll(*RESOURCE_MGR->GetTexture("graphics/block.png"), 
			{playerMaxHpBar->GetPos().x - playerMaxHpBar->GetSize().x / 4 + 35, playerMaxHpBar->GetPos().y}, Origins::MC);
	}


	{
		monsterAttackImage = new SpriteObj();
		playerAttackImage = new SpriteObj();


		monsterAttackImage->SetAll(*RESOURCE_MGR->GetTexture("graphics/slash_1.png"), 
			{ monster[0]->GetPos().x - 20, monster[0]->GetPos().y }, Origins::MC);
		monsterAttackImage->SetFillColor({80, 188, 223});
		monsterAttackImage->SetRotation(100);
		monsterAttackImage->SetScale(2, 4);

		playerAttackImage->SetAll(*RESOURCE_MGR->GetTexture("graphics/monsterAttack.png"), 
			{ ironClad->GetPos().x + 30, ironClad->GetPos().y - 10 }, Origins::MC);
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
	float bossCurHpBarSet = (boss->GetMaxHp() - boss->GetCurHp()) * (100.f / boss->GetMaxHp() * 0.01f);

	playerCurHpBar->SetScale(0.8f - playerCurHpBarSet, 1);
	playerMaxHpBar->SetScale(0.8f, 1);

	if (stage == Stage::Monster)
	{
		monsterCurHpBar->SetScale(0.8f - monsterCurHpBarSet, 1);
		monsterMaxHpBar->SetScale(0.8f, 1);

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
	}
	if (stage == Stage::Boss) 
	{
		monsterCurHpBar->SetScale(1 - bossCurHpBarSet, 1);
		monsterMaxHpBar->SetScale(1, 1);

		monsterCurHpBar->SetPos({ boss->GetPos().x + monsterCurHpBar->GetSize().x / 2, boss->GetPos().y + boss->GetSize().y / 2 - 45.f});
		monsterMaxHpBar->SetPos(monsterCurHpBar->GetPos());

		monsterCurHp->SetText(to_string(boss->GetCurHp()));
		monsterMaxHp->SetText(to_string(boss->GetMaxHp()));

		if (boss->GetCurHp() <= 0)
		{
			boss->SetCurHp(0);
			monsterCurHp->SetText(to_string(boss->GetCurHp()));
			boss->SetActive(false);
			MonsterSet(monster, false);
		}
	}

	if (ironClad->GetCurHP() <= 0)
	{
		ironClad->SetCurHP(0);
		ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
		curHp->SetText(to_string(ironClad->GetCurHP()));
		ironClad->SetAlive(false);
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
	if (stage == Stage::Monster)
	{
		if (Button::ButtonOnRect(*cursor, *ternPassButton) &&
			isPlayerTern == true &&
			monster[0]->GetAlive() == true &&
			dieOrGiveup->GetActive() == false)
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
	}

	if (stage == Stage::Boss)
	{
		if (Button::ButtonOnRect(*cursor, *ternPassButton) && 
		isPlayerTern == true && 
		bossCount > 0 &&
		dieOrGiveup->GetActive() == false)
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

	this->attackCount->SetText("AC : " + to_string(ironClad->GetAttackCount()));
	this->defendCount->SetText("DC : " + to_string(ironClad->GetDefendCount()));
	this->attackCount->SetOrigin(Origins::MC);
	this->defendCount->SetOrigin(Origins::MC);

	if (stage == Stage::Monster)
	{
		if (monsterCount == 0)
		{
			if (ironClad->GetType() == PlayerType::IronClad)
			{
				int hp = ironClad->GetCurHP();
				hp + 6 >= ironClad->GetMaxHP() ? ironClad->SetCurHP(ironClad->GetMaxHP()) : ironClad->SetCurHP(hp += 6);
				ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
				curHp->SetText(to_string(ironClad->GetCurHP()));
				playerActionCountSet = true;
				ironClad->SetIsWeaken(0);
				playerWeakenText->SetText("");
				SOUND_MGR->Play("sounds/heal.ogg", false);

				ironClad->AddGold(40);
				gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
				SOUND_MGR->Play("sounds/gold.ogg", false);
			}
			SetClearUi(true);
			monsterKillCount++;
		}
	}
	else if (stage == Stage::Boss)
	{
		if (bossCount == 0)
		{
			playerWeakenText->SetText("");
			SetClearUi(true);
			monsterKillCount++;
		}
	}
}

void PlayUi::EnterTheStage(float dt)
{
	choiceDelay -= dt;

	if (monsterMapIcon->GetActive() == true && stage == Stage::Map)
	{
		if (Button::ButtonOnRect(*cursor, *monsterMapIcon) && monsterMapOrder == choiceOrder)
		{
			monsterMapIconOutLine->SetActive(true);
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				choiceDelay = 0.5f;
				SOUND_MGR->Play("sounds/mapSelect.ogg", false);
				mapChoiceCircle->SetPos(monsterMapIcon->GetPos());
				mapChoiceCircle->SetActive(true);
				mapChoice = true;
			}
		}
		else
			monsterMapIconOutLine->SetActive(false);

		if (Button::ButtonOnRect(*cursor, *rewordMapIcon) && rewordMapOrder == choiceOrder)
		{
			rewordMapIconOutLine->SetActive(true);
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				choiceDelay = 0.5f;
				SOUND_MGR->Play("sounds/mapSelect.ogg", false);
				mapChoiceCircle->SetPos(rewordMapIcon->GetPos());
				mapChoiceCircle->SetActive(true);
				mapChoice = true;
			}
		}
		else
			rewordMapIconOutLine->SetActive(false);

		if (Button::ButtonOnRect(*cursor, *questionMapIcon) && questionMapOrder == choiceOrder)
		{
			questionMapIconOutLine->SetActive(true);
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				choiceDelay = 0.5f;
				SOUND_MGR->Play("sounds/mapSelect.ogg", false);
				mapChoiceCircle->SetPos(questionMapIcon->GetPos());
				mapChoiceCircle->SetActive(true);
				mapChoice = true;
			}
		}
		else
			questionMapIconOutLine->SetActive(false);

		if (Button::ButtonOnRect(*cursor, *shopMapIcon) && shopMapOrder == choiceOrder)
		{
			shopMapIconOutLine->SetActive(true);
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				choiceDelay = 0.5f;
				SOUND_MGR->Play("sounds/mapSelect.ogg", false);
				mapChoiceCircle->SetPos(shopMapIcon->GetPos());
				mapChoiceCircle->SetActive(true);
				mapChoice = true;
			}
		}
		else
			shopMapIconOutLine->SetActive(false);


		if (Button::ButtonOnRect(*cursor, *bossMapIcon) && bossMapOrder == choiceOrder)
		{
			bossMapIconOutLine->SetActive(true);
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				choiceDelay = 0.5f;
				SOUND_MGR->Play("sounds/mapSelect.ogg", false);
				mapChoice = true;
			}
		}
		else
			bossMapIconOutLine->SetActive(false);


		if (choiceDelay <= 0.f && monsterMapOrder == choiceOrder && mapChoice == true)
		{
			stage = Stage::Monster;
			mapChoiceCircle->SetActive(false);
			mapUi = false;
			mapChoice = false;
		}
		if (choiceDelay <= 0.f && rewordMapOrder == choiceOrder && mapChoice == true)
		{
			stage = Stage::Reword;
			mapChoiceCircle->SetActive(false);
			mapUi = false;
			mapChoice = false;
		}
		if (choiceDelay <= 0.f && shopMapOrder == choiceOrder && mapChoice == true)
		{
			stage = Stage::Shop;
			mapChoiceCircle->SetActive(false);
			mapUi = false;
			mapChoice = false;
		}
		if (choiceDelay <= 0.f && questionMapOrder == choiceOrder && mapChoice == true)
		{
			stage = Stage::Question;
			mapChoiceCircle->SetActive(false);
			mapUi = false;
			mapChoice = false;
		}
		if (choiceDelay <= 0.f && bossMapOrder == choiceOrder && mapChoice == true)
		{
			stage = Stage::Boss;
			bossStageSound = true;
			mapUi = false;
			mapChoice = false;
		}
	}
	else
	{
		monsterMapIconOutLine->SetActive(false);
		rewordMapIconOutLine->SetActive(false);
		shopMapIconOutLine->SetActive(false);
		questionMapIconOutLine->SetActive(false);
		bossMapIconOutLine->SetActive(false);
	}
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
		monster[0]->SetIsWeaken(0);
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
		monster[0]->SetIsWeaken(0);
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
	defenseUp->SetPos({ damageUp->GetPos().x + defenseUp->GetSize().x * 4, windowSize.y / 3});
	energyUp->SetPos({ defenseUp->GetPos().x + energyUp->GetSize().x * 4, windowSize.y / 3 });
	hpUp->SetPos({ energyUp->GetPos().x + hpUp->GetSize().x * 4, windowSize.y / 3 });


	getSmite->SetPos({ windowSize.x / 2 - getSmite->GetSize().x * 1.5f, windowSize.y / 1.5f});
	getClubbing->SetPos({ windowSize.x / 2 + getClubbing->GetSize().x * 1.5f, windowSize.y / 1.5f });

	getSmiteGold->SetPos({ getSmite->GetPos().x, getSmite->GetPos().y - getSmite->GetSize().y + 10});
	getSmiteGold->SetOrigin(Origins::MC);

	getClubbingGold->SetPos({ getClubbing->GetPos().x, getClubbing->GetPos().y - getClubbing->GetSize().y + 10 });
	getClubbingGold->SetOrigin(Origins::MC);

	getSmiteGold->SetText("50 GOLD");
	getClubbingGold->SetText("50 GOLD");

	if (Button::ButtonOnRect(*cursor, *damageUp))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && ironClad->GetCurGold() >= 20 && damageUp->GetActive() == true)
		{
			ironClad->AddDamage(1);

			ironClad->SetGold(ironClad->GetCurGold() - 20);
			gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
			SOUND_MGR->Play("sounds/upgradeDamage.ogg", false);
		}
	}
	if (Button::ButtonOnRect(*cursor, *energyUp))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && ironClad->GetCurGold() >= 30 && energyUp->GetActive() == true)
		{
			if (ironClad->GetMaxEnergy() < 9)
			{
				int e = ironClad->GetCurEnergy();
				int maxe = ironClad->GetMaxEnergy();
				ironClad->SetMaxEnergy(e += 1);
				ironClad->SetCurEnergy(maxe += 1);

				ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));
				ironCladMaxEnergy->SetText("    / " + to_string(ironClad->GetMaxEnergy()));

				ironClad->SetGold(ironClad->GetCurGold() - 30);
				gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));

				SOUND_MGR->Play("sounds/playerTernStart.ogg", false);
			}
		}
	}
	if (Button::ButtonOnRect(*cursor, *defenseUp))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && ironClad->GetCurGold() >= 20 && defenseUp->GetActive() == true)
		{
			ironClad->SetAddDefend(ironClad->GetAddDefend() + 1);

			ironClad->SetGold(ironClad->GetCurGold() - 20);
			gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
			
			SOUND_MGR->Play("sounds/playerDefense.ogg", false);
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
			
			SOUND_MGR->Play("sounds/heal.ogg", false);
		}
	}


	if (Button::ButtonOnRect(*cursor, *getSmite))
	{
		smiteInfo->SetPos({ getSmite->GetPos().x, getSmite->GetPos().y + getSmite->GetSize().y });
	
		smiteDamageText->SetPos({ smiteInfo->GetPos().x + 5, smiteInfo->GetPos().y });
		smiteDamageText->SetText(to_string((int)ironClad->GetDamage() + 5));

		smiteInfo->SetActive(true);
		smiteDamageText->SetActive(true);

		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && ironClad->GetCurGold() >= 50 && smiteOn == false)
		{
			normalAttackInfo->SetActive(false);
			smiteInfo->SetActive(false);
			clubbingInfo->SetActive(false);

			if (clubbingOn == false)
			{
				normalAttackButton->SetPos({ attackButton->GetPos().x - normalAttackButton->GetSize().x / 2,
					attackButton->GetPos().y - attackButton->GetSize().y });
				attackSkillButton1->SetPos({ normalAttackButton->GetPos().x + attackSkillButton1->GetSize().x,
					normalAttackButton->GetPos().y });

				normalAttackInfo->SetPos({ normalAttackButton->GetPos().x, normalAttackButton->GetPos().y - normalAttackInfo->GetSize().y });
				smiteInfo->SetPos({ attackSkillButton1->GetPos().x, attackSkillButton1->GetPos().y - smiteInfo->GetSize().y });
			}
			else if (clubbingOn == true)
			{
				normalAttackButton->SetPos({ attackButton->GetPos().x - normalAttackButton->GetSize().x / 2 - normalAttackButton->GetSize().x / 2,
					attackButton->GetPos().y - attackButton->GetSize().y });
				attackSkillButton1->SetPos({ normalAttackButton->GetPos().x + attackSkillButton1->GetSize().x,
					normalAttackButton->GetPos().y });
				attackSkillButton2->SetPos({ attackSkillButton1->GetPos().x + attackSkillButton2->GetSize().x,
					normalAttackButton->GetPos().y });

				normalAttackInfo->SetPos({ normalAttackButton->GetPos().x, normalAttackButton->GetPos().y - normalAttackInfo->GetSize().y });
				smiteInfo->SetPos({ attackSkillButton1->GetPos().x, attackSkillButton1->GetPos().y - smiteInfo->GetSize().y });
				clubbingInfo->SetPos({ attackSkillButton2->GetPos().x, attackSkillButton2->GetPos().y - clubbingInfo->GetSize().y });
			}
			smiteOn = true;
			getSmiteGold->SetActive(false);
			ironClad->SetGold(ironClad->GetCurGold() - 50);
			gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
			

			SOUND_MGR->Play("sounds/sold.ogg", false);
		}
	}
	else
	{
		smiteInfo->SetActive(false);
		smiteDamageText->SetActive(false);

		smiteInfo->SetPos({ attackSkillButton1->GetPos().x, attackSkillButton1->GetPos().y - smiteInfo->GetSize().y });
		smiteDamageText->SetPos({ smiteInfo->GetPos().x + 5, smiteInfo->GetPos().y });
	}

	if (Button::ButtonOnRect(*cursor, *getClubbing))
	{
		clubbingInfo->SetPos({ getClubbing->GetPos().x, getClubbing->GetPos().y + getClubbing->GetSize().y });
		clubbingDamageText->SetPos({ clubbingInfo->GetPos().x + 5, clubbingInfo->GetPos().y + 10 });
		clubbingDamageText->SetText(to_string((int)ironClad->GetDamage() * 4));

		clubbingInfo->SetActive(true);
		clubbingDamageText->SetActive(true);

		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left) && ironClad->GetCurGold() >= 50 && clubbingOn == false)
		{
			normalAttackInfo->SetActive(false);
			smiteInfo->SetActive(false);
			clubbingInfo->SetActive(false);

			if (smiteOn == false)
			{
				normalAttackButton->SetPos({ attackButton->GetPos().x - normalAttackButton->GetSize().x / 2,
					attackButton->GetPos().y - attackButton->GetSize().y });
				attackSkillButton2->SetPos({ normalAttackButton->GetPos().x + attackSkillButton2->GetSize().x,
					normalAttackButton->GetPos().y });


				normalAttackInfo->SetPos({ normalAttackButton->GetPos().x, normalAttackButton->GetPos().y - normalAttackInfo->GetSize().y });
				clubbingInfo->SetPos({ attackSkillButton2->GetPos().x, attackSkillButton2->GetPos().y - clubbingInfo->GetSize().y });
			}
			else if (smiteOn == true)
			{
				normalAttackButton->SetPos({ attackButton->GetPos().x - normalAttackButton->GetSize().x / 2 - normalAttackButton->GetSize().x / 2,
					attackButton->GetPos().y - attackButton->GetSize().y });
				attackSkillButton1->SetPos({ normalAttackButton->GetPos().x + attackSkillButton1->GetSize().x,
					normalAttackButton->GetPos().y });
				attackSkillButton2->SetPos({ attackSkillButton1->GetPos().x + attackSkillButton2->GetSize().x,
					normalAttackButton->GetPos().y });

				normalAttackInfo->SetPos({ normalAttackButton->GetPos().x, normalAttackButton->GetPos().y - normalAttackInfo->GetSize().y });
				smiteInfo->SetPos({ attackSkillButton1->GetPos().x, attackSkillButton1->GetPos().y - smiteInfo->GetSize().y });
				clubbingInfo->SetPos({ attackSkillButton2->GetPos().x, attackSkillButton2->GetPos().y - clubbingInfo->GetSize().y });
			}
			clubbingOn = true;
			getClubbingGold->SetActive(false);
			ironClad->SetGold(ironClad->GetCurGold() - 50);
			gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));

			SOUND_MGR->Play("sounds/sold.ogg", false);
		}
	}
	else
	{
		clubbingInfo->SetActive(false);
		clubbingDamageText->SetActive(false);

		clubbingInfo->SetPos({ attackSkillButton2->GetPos().x, attackSkillButton2->GetPos().y - clubbingInfo->GetSize().y });
		clubbingDamageText->SetPos({ clubbingInfo->GetPos().x + 5, clubbingInfo->GetPos().y });
	}
}

void PlayUi::RewordStage()
{
	Vector2f windowSize = (Vector2f)FRAMEWORK->GetWindowSize();

	SetRewordMapUi(true);
	if (Button::ButtonOnRect(*cursor, *chest) && isChestOpen == false)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
		{
			SOUND_MGR->Play("sounds/chestOpen.ogg", false);
			chest->SetTexture(*RESOURCE_MGR->GetTexture("graphics/largeChestOpened.png"));
			SetRewordUi(true);
			rewordUi = true;
			isChestOpen = true;
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

		if (Button::ButtonOnRect(*cursor, *addGold) && addGold->GetActive() == true && isChestOpen == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				SOUND_MGR->Play("sounds/gold.ogg", false);
				ironClad->SetGold(ironClad->GetCurGold() + getGold);
				gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
				addGold->SetActive(false);
			}
		}
		if (Button::ButtonOnRect(*cursor, *addDamage) && addDamage->GetActive() == true && isChestOpen == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				SOUND_MGR->Play("sounds/upgradeDamage.ogg", false);
				ironClad->AddDamage(getDamage);
				addDamage->SetActive(false);
			}
		}
		if (Button::ButtonOnRect(*cursor, *addDefend) && addDefend->GetActive() == true && isChestOpen == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				SOUND_MGR->Play("sounds/defence.ogg", false);
				ironClad->SetAddDefend(ironClad->GetAddDefend() + getDefend);
				addDefend->SetActive(false);
			}
		}
		if (Button::ButtonOnRect(*cursor, *addHp) && addHp->GetActive() == true && isChestOpen == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				int hp = ironClad->GetCurHP();

				if (hp + getHp <= ironClad->GetMaxHP())
				{
					ironClad->SetCurHP(hp += getHp);
					ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
					curHp->SetText(to_string(ironClad->GetCurHP()));
				}
				else if (hp + getHp > ironClad->GetMaxHP())
				{
					int maxh = ironClad->GetMaxHP();
					int excessHpCalculation = (hp + getHp) - maxh;

					ironClad->SetCurHP(hp += getHp - excessHpCalculation);
					ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
					curHp->SetText(to_string(ironClad->GetCurHP()));
				}

				addHp->SetActive(false);
				SOUND_MGR->Play("sounds/heal.ogg", false);
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
			choice1->SetPos({ 0 + choice1->GetSize().x, windowSize.y - choice1->GetSize().y * 3 });
			choice2->SetPos({ 0 + choice1->GetSize().x, windowSize.y - choice1->GetSize().y });

			choice1->SetActive(true);
			choice2->SetActive(true);
			choice3->SetActive(false);
			break;
		case 1:
			choice1->SetPos({ 0 + choice1->GetSize().x, windowSize.y - choice1->GetSize().y * 3 });
			choice3->SetPos({ 0 + choice1->GetSize().x, windowSize.y - choice1->GetSize().y });

			choice1->SetActive(true);
			choice2->SetActive(false);
			choice3->SetActive(true);
			break;
		case 2:
			choice2->SetPos({ 0 + choice1->GetSize().x, windowSize.y - choice1->GetSize().y * 3 });
			choice3->SetPos({ 0 + choice1->GetSize().x, windowSize.y - choice1->GetSize().y });

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
				ironClad->SetCurHP(hp += 15);
				ironClad->SetMaxHP(maxhp += 15);

				ironCladCurHp->SetText(to_string(ironClad->GetMaxHP()));
				ironCladMaxHp->SetText("/ " + to_string(ironClad->GetMaxHP()));
				curHp->SetText(to_string(ironClad->GetMaxHP()));
				maxHp->SetText(to_string(ironClad->GetMaxHP()));

				choice1->SetActive(false);
				choice2->SetActive(false);
				choice3->SetActive(false);

				choiceDelay = 1.f;

				SOUND_MGR->Play("sounds/heal.ogg", false);
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
				ironCladMaxEnergy->SetText("    / " + to_string(ironClad->GetMaxEnergy()));

				choice1->SetActive(false);
				choice2->SetActive(false);
				choice3->SetActive(false);

				choiceDelay = 1.f;


				SOUND_MGR->Play("sounds/heavyAttack.ogg", false);
				SOUND_MGR->Play("sounds/playerTernStart.ogg", false);
				SceneDev2_Play::SetIsMonsterAttack(true);
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

				choice1->SetActive(false);
				choice2->SetActive(false);
				choice3->SetActive(false);

				choiceDelay = 1.f;


				SOUND_MGR->Play("sounds/heavyAttack.ogg", false);
				SOUND_MGR->Play("sounds/upgradeDamage.ogg", false);
				SceneDev2_Play::SetIsMonsterAttack(true);
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
	getSmite->SetActive(set);
	getClubbing->SetActive(set);
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
	SetGameClearUi(false);

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
	smiteOn = false;
	rewordUi = false;
	randomReword = true;
	clubbingOn = false;
	isChestOpen = false;
	gameSound = true;
	bossStageSound = false;
	stage = Stage::Start;
	bossCount = 1;
	SOUND_MGR->StopAll();
}

void PlayUi::SetAttackSkillUi(bool set)
{
	normalAttackButton->SetActive(set);
	attackSkillButton1->SetActive(set);
	attackSkillButton2->SetActive(set);
}

void PlayUi::PlayerAttackDamage(int damage)
{
	if (stage == Stage::Monster)
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
				SOUND_MGR->Play("sounds/defenseBreak.ogg", false);
			}
		}
		else
		{
			monster[0]->SetCurHp(monster[0]->GetCurHp() - damage);
			monsterCurHp->SetText(to_string(monster[0]->GetCurHp()));
		}
	}
	else if (stage == Stage::Boss)
	{
		if (boss->GetDefend() > 0)
		{
			if (boss->GetDefend() >= damage)
			{
				int defend = boss->GetDefend();
				boss->SetDefend(defend -= damage);
				monsterDefend->SetText("D : " + to_string(boss->GetDefend()));
			}
			else if (boss->GetDefend() < damage)
			{
				int piercingDamage = damage - boss->GetDefend();
				boss->SetDefend(0);
				monsterDefend->SetText("D : " + to_string(boss->GetDefend()));
				boss->SetCurHp(boss->GetCurHp() - piercingDamage);
				monsterCurHp->SetText(to_string(boss->GetCurHp()));
				SOUND_MGR->Play("sounds/defenseBreak.ogg", false);
			}
		}
		else
		{
			boss->SetCurHp(boss->GetCurHp() - damage);
			monsterCurHp->SetText(to_string(boss->GetCurHp()));
		}
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
			ironCladCurDefend->SetText(to_string(ironClad->GetDefend()));
		}
		else if (ironClad->GetDefend() < damage)
		{
			int piercingDamage = damage - ironClad->GetDefend();
			ironClad->SetDefend(0);
			ironCladCurDefend->SetText("");
			ironClad->SetCurHP(ironClad->GetCurHP() - piercingDamage);
			ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
			curHp->SetText(to_string(ironClad->GetCurHP()));
			SOUND_MGR->Play("sounds/defenseBreak.ogg", false);
		}
	}
	else
	{
		ironClad->SetCurHP(ironClad->GetCurHP() - damage);
		ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
		curHp->SetText(to_string(ironClad->GetCurHP()));
	}
}

void PlayUi::AttackButtonControl(int monsterCount, float dt)
{
	int energy = ironClad->GetCurEnergy();
	int defend = ironClad->GetDefend();

	if (Button::ButtonOnRect(*cursor, *normalAttackButton) &&
		ironClad->GetAttackCount() > 0 &&
		energy > 0 &&
		monsterCount > 0 &&
		dieOrGiveup->GetActive() == false &&
		normalAttackButton->GetActive() == true)
	{
		if (isAttackSkill == true)
		{
			normalAttackInfo->SetPos({ normalAttackButton->GetPos().x,
	normalAttackButton->GetPos().y - normalAttackInfo->GetSize().y });

			normalAttackInfo->SetActive(true);

			if (ironClad->GetIsWeaken() > 0)
				normalAttackDamageText->SetText(to_string((int)ironClad->GetDamage() / 2));
			else
				normalAttackDamageText->SetText(to_string((int)ironClad->GetDamage()));

			normalAttackDamageText->SetPos({ normalAttackInfo->GetPos().x + 15, normalAttackInfo->GetPos().y + 10 });
		}
		else
		{
			normalAttackInfo->SetActive(false);
			normalAttackDamageText->SetText("");
		}

		if (InputMgr::GetMouseButtonUp(Mouse::Left))
		{
			int attCount = ironClad->GetAttackCount();

			PlayerAttack(dt, Skill::Normal);
			ironClad->SetCurEnergy(energy -= 1);
			ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

			ironClad->SetAttackCount(attCount -= 1);

			SOUND_MGR->Play("sounds/attack.ogg", false);
			monsterAttackImage->SetActive(true);
			attackDelay = 0.1f;
		}
	}
	else
	{
		normalAttackInfo->SetActive(false);
		normalAttackDamageText->SetText("");
	}

	if (Button::ButtonOnRect(*cursor, *attackSkillButton1) &&
		ironClad->GetAttackCount() >= 2 &&
		energy >= 2 &&
		monsterCount > 0 &&
		dieOrGiveup->GetActive() == false &&
		smiteOn == true)
	{
		if (isAttackSkill == true)
		{
			smiteInfo->SetActive(true);
			smiteDamageText->SetActive(true);

			if (ironClad->GetIsWeaken() > 0)
				smiteDamageText->SetText(to_string((int)ironClad->GetDamage() + 5 / 2));
			else
				smiteDamageText->SetText(to_string((int)ironClad->GetDamage() + 5));

			smiteDamageText->SetPos({ smiteInfo->GetPos().x + 15, smiteInfo->GetPos().y });
		}
		else
		{
			smiteInfo->SetActive(false);
			smiteDamageText->SetText("");
		}

		if (InputMgr::GetMouseButtonUp(Mouse::Left))
		{
			int attCount = ironClad->GetAttackCount();

			PlayerAttack(dt, Skill::Smite);
			ironClad->SetCurEnergy(energy -= 2);
			ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

			ironClad->SetAttackCount(attCount -= 2);

			SOUND_MGR->Play("sounds/playerHeavyAttack.ogg", false);
			monsterAttackImage->SetActive(true);
			attackDelay = 0.1f;
		}
	}
	else
	{
		smiteInfo->SetActive(false);
		smiteDamageText->SetText("");
	}

	if (Button::ButtonOnRect(*cursor, *attackSkillButton2) &&
		ironClad->GetAttackCount() >= 3 &&
		energy >= 3 &&
		monsterCount > 0 &&
		dieOrGiveup->GetActive() == false &&
		clubbingOn == true)
	{
		if (isAttackSkill == true)
		{
			clubbingInfo->SetActive(true);
			clubbingDamageText->SetActive(true);

			if (ironClad->GetIsWeaken() > 0)
				clubbingDamageText->SetText(to_string((int)ironClad->GetDamage() * 4 / 2));
			else
				clubbingDamageText->SetText(to_string((int)ironClad->GetDamage() * 4));

			clubbingDamageText->SetPos({ clubbingInfo->GetPos().x + 15, clubbingInfo->GetPos().y + 10 });
		}
		else
		{
			clubbingInfo->SetActive(false);
			clubbingDamageText->SetText("");
		}


		if (InputMgr::GetMouseButtonUp(Mouse::Left))
		{
			int attCount = ironClad->GetAttackCount();

			PlayerAttack(dt, Skill::clubbing);
			ironClad->SetCurEnergy(energy -= 3);
			ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

			ironClad->SetAttackCount(attCount -= 3);

			SOUND_MGR->Play("sounds/heavyAttack.ogg", false);
			monsterAttackImage->SetActive(true);
			attackDelay = 0.1f;
		}
	}
	else
	{
		clubbingInfo->SetActive(false);
		clubbingDamageText->SetText("");
	}


	if (Button::ButtonOnRect(*cursor, *defendButton) &&
		ironClad->GetDefendCount() > 0 &&
		energy > 0 &&
		monsterCount > 0 &&
		dieOrGiveup->GetActive() == false)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Left))
		{
			int defCount = ironClad->GetDefendCount();

			if (ironClad->GetIsWeaken() > 0)
			{
				int D = ironClad->GetAddDefend();
				ironClad->SetWeakenDefend(D / 2);

				ironClad->SetDefend(defend += ironClad->GetWeakenDefend());
				ironCladCurDefend->SetText(to_string(ironClad->GetDefend()));
				ironClad->SetCurEnergy(energy -= 1);
				ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

				ironClad->SetDefendCount(defCount -= 1);
			}
			else
			{
				ironClad->SetDefend(defend += ironClad->GetAddDefend());
				ironCladCurDefend->SetText(to_string(ironClad->GetDefend()));
				ironClad->SetCurEnergy(energy -= 1);
				ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

				ironClad->SetDefendCount(defCount -= 1);
			}

			SOUND_MGR->Play("sounds/playerDefense.ogg", false);
		}
	}

	if (energy == 0)
	{
		normalAttackInfo->SetActive(false);
		normalAttackDamageText->SetText("");
		smiteInfo->SetActive(false);
		smiteDamageText->SetText("");
		clubbingInfo->SetActive(false);
		clubbingDamageText->SetText("");
	}
}

void PlayUi::SetGameClearUi(bool set)
{
	gameClearBackground->SetActive(set);
	clearText->SetActive(set);

	floors->SetText("Floors : " + to_string(choiceOrder));
	monsterKilled->SetText("Monster Killed : " + to_string(monsterKillCount));
	floors->SetOrigin(Origins::MC);
	monsterKilled->SetOrigin(Origins::MC);

	floors->SetActive(set);
	monsterKilled->SetActive(set);
	mainMenuButton->SetActive(set);
}