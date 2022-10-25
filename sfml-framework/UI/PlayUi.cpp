#include "PlayUi.h"
#include "../InlcludeHeader/UiIncludeHeader.h"
#include "../Scenes/SceneDev2_Play.h"
#include "UiDev1.h"
#include "../GameObject/Player.h"
#include "../GameObject/Monster.h"

Player* PlayUi::ironClad = new Player(80, 80, 99, 3, 3, 0, 5); // �÷��̾� ����
vector<Monster*> PlayUi::monster;

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

	// Action Window
	uiObjList.push_back(actionWindow);
	uiObjList.push_back(attackButton);
	uiObjList.push_back(defendButton);
	uiObjList.push_back(attackCount);
	uiObjList.push_back(defendCount);
	uiObjList.push_back(ternPassButton);

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

	// option
	uiObjList.push_back(optionBackground);
	uiObjList.push_back(backButton);
	uiObjList.push_back(giveUpButton);
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
	UiMgr::Update(dt);
	Vector2f worldMousePos = parentScene->ScreenToUiPos((Vector2i)InputMgr::GetMousePos());
	cursor->SetPos(worldMousePos);

	// Player / Monster HP, HP Bar Control
	HpControl();

	if (stage == Stage::Start)
	{
		MonsterSet(monster, false);
		SetActionUi(false);
		if (InputMgr::GetKeyDown(Keyboard::Key::Enter))
			stage = Stage::Monster;
	}

	if (stage == Stage::Monster)
	{
		SetActionUi(true);
		MonsterSet(monster, true);

		this->attackCount->SetText("COUNT : " + to_string(ironClad->GetAttackCount()));
		this->defendCount->SetText("COUNT : " + to_string(ironClad->GetDefendCount()));
		this->attackCount->SetOrigin(Origins::MC);
		this->defendCount->SetOrigin(Origins::MC);

		monsterPatternDelay -= dt;

		// Tern Pass
		if (Button::ButtonOnRect(*cursor, *ternPassButton) && isPlayerTern == true && monster[0]->GetAlive() == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Left))
				SetMonsterTern();
		}

		// Monster Tern Control
		if (monsterPatternDelay <= 0.f && isPlayerTern == false)
			MonsterAction(dt);

		// Monster Pattern Set
		if (isMonsterTern == true && monsterRandomPatternSetting == true)
			SetNextMonsterAction();

		// player Tern Control
		if (isPlayerTern == true && isMonsterTern == false && ironClad->GetCurEnergy() > 0)
			PlayerTern(dt);

		if (monsterCount == 0)
		{
			//isStageClear = true;
			SetClearUi(true);
		}
	}
	else
		SetClearUi(false);

	if (Button::ButtonOnRect(*cursor, *continueButton))
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
		{
			SetClearUi(false);
			stage = Stage::Map;
		}
	}

	if (stage == Stage::Map)
	{
		MonsterSet(monster, false);
		SetActionUi(false);

		MapUiControl();
	}

	// Option Ui Control
	if (giveupUi == false)
		OptionUiControl();

	// Map Ui Control
	if (giveupUi == false && optionUi == false)
		MapUiControl();

	// GiveUp Ui Control
	GiveUpUiControl();

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
}

void PlayUi::SetMapUi(bool set)
{
	map->SetActive(set);
	mapBackground->SetActive(set);
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
	if (ironClad->GetDefend() > 0)
	{
		if (ironClad->GetDefend() >= monster[0]->GetDamage())
		{
			int defend = ironClad->GetDefend();
			ironClad->SetDefend(defend -= monster[0]->GetDamage());
			ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
		}
		else if (ironClad->GetDefend() < monster[0]->GetDamage())
		{
			int piercingDamage = monster[0]->GetDamage() - ironClad->GetDefend();
			ironClad->SetDefend(0);
			ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
			ironClad->SetCurHP(ironClad->GetCurHP() - piercingDamage);
			ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
			curHp->SetText(to_string(ironClad->GetCurHP()));
		}
	}
	else
	{
		ironClad->SetCurHP(ironClad->GetCurHP() - monster[0]->GetDamage());
		ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
		curHp->SetText(to_string(ironClad->GetCurHP()));
	}
}

void PlayUi::PlayerAttack(float dt)
{
	ironClad->SetIsAttack(true);
	ironClad->Attack(dt);

	if (monster[0]->GetDefend() > 0)
	{
		if (monster[0]->GetDefend() >= ironClad->GetDamage())
		{
			int defend = monster[0]->GetDefend();
			monster[0]->SetDefend(defend -= ironClad->GetDamage());
			monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));
		}
		else if (monster[0]->GetDefend() < ironClad->GetDamage())
		{
			int piercingDamage = ironClad->GetDamage() - monster[0]->GetDefend();
			monster[0]->SetDefend(0);
			monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));
			monster[0]->SetCurHp(monster[0]->GetCurHp() - piercingDamage);
			monsterCurHp->SetText(to_string(monster[0]->GetCurHp()));
		}
	}
	else
	{
		monster[0]->SetCurHp(monster[0]->GetCurHp() - ironClad->GetDamage());
		monsterCurHp->SetText(to_string(monster[0]->GetCurHp()));
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


	if (Button::ButtonOnRect(*cursor, *attackButton) && ironClad->GetAttackCount() > 0 && energy > 0)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Left))
		{
			int attCount = ironClad->GetAttackCount();

			PlayerAttack(dt);
			ironClad->SetCurEnergy(energy -= 1);
			ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

			ironClad->SetAttackCount(attCount -= 1);
		}
	}

	if (Button::ButtonOnRect(*cursor, *defendButton) && ironClad->GetDefendCount() > 0 && energy > 0)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Left))
		{
			int defCount = ironClad->GetDefendCount();

			ironClad->SetDefend(defend += 5);
			ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
			ironClad->SetCurEnergy(energy -= 1);
			ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

			ironClad->SetDefendCount(defCount -= 1);
		}
	}
}

void PlayUi::SetNextMonsterAction()
{
	randomMonsterPattern = Utils::RandomRange(0, 3);
	if (randomMonsterPattern <= 1)
	{
		int setDamage = Utils::RandomRange(8, 15);
		monster[0]->SetDamage(setDamage);
		monsterPattern->SetText("ATTACK");
		monsterDamage->SetText("A : " + to_string((int)monster[0]->GetDamage()));
		monsterDamage->SetActive(true);
	}
	else
	{
		monsterPattern->SetText("DEFENCE");
		monsterDamage->SetActive(false);
	}

	monsterRandomPatternSetting = false;
	isMonsterTern = false;
}

void PlayUi::MonsterAction(float dt)
{
	monster[0]->Pattern(randomMonsterPattern, dt);
	if (monster[0]->GetPattern() == MonsterPattern::Attack)
		MonsterAttack();

	monsterDefend->SetText("D : " + to_string(monster[0]->GetDefend()));

	ironClad->SetCurEnergy(3);
	ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));

	isPlayerTern = true;
	monsterRandomPatternSetting = true;
	playerActionCountSet = true;
	ternPassButton->SetActive(true);

	// ���� �ð� �ڿ� �� ������� �Ϸ��� �� �� ����������...
	// ������ �׳� �����
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
				optionUi = false;
			}
		}
		else
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				optionUi = true;
			}
		}
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Escape))
	{
		if (optionUi == true)
		{
			optionUi = false;
			SetOptionUi(false);
		}
		else
		{
			optionUi = true;
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
				SetOptionUi(false);
			}
		}
	}
	else
		SetOptionUi(false);
}

void PlayUi::MapUiControl()
{
	if (Button::ButtonOnRect(*cursor, *mapIcon))
	{
		if (mapUi == true)
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				mapUi = false;
			}
		}
		else
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				mapUi = true;
			}
		}
	}

	if (InputMgr::GetKeyDown(Keyboard::Key::M))
	{
		if (mapUi == false)
			mapUi = true;
		else
			mapUi = false;
	}


	mapUi == true ? SetMapUi(true) : SetMapUi(false);
}

void PlayUi::GiveUpUiControl()
{
	if (optionUi == true)
	{
		if (Button::ButtonOnRect(*cursor, *giveUpButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				giveupUi = true;
			}
		}

		if (Button::ButtonOnRect(*cursor, *yesButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				// ����
			}
		}
		if (Button::ButtonOnRect(*cursor, *noButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				giveupUi = false;
			}
		}
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Escape) && giveupUi == true)
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
			{ windowSize.x / 1.5f, windowSize.y / 1.7f }, Origins::MC);
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
		ironClad->SetAll(*RESOURCE_MGR->GetTexture("graphics/ironcladimage.png"),
			{ windowSize.x / 4, windowSize.y / 1.7f }, Origins::MC);

		// ����
		{
			ternPassButton = new SpriteObj();
			attackButton = new SpriteObj();
			defendButton = new SpriteObj();
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

				attackButton->SetAll(*RESOURCE_MGR->GetTexture("graphics/attackButton.png"),
					{ 0, 0 }, Origins::MC);
				attackButton->SetPos({ actionWindow->GetPos().x - attackButton->GetSize().x,
					actionWindow->GetPos().y });

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

			backButton->SetAll(*testBackButton, { 100, windowSize.y - 200.f }, Origins::MC);
			optionBackground->SetAll(*testOptionBackground, windowSize * 0.5f, Origins::MC);
			giveUpButton->SetAll(*testGiveUpButton, windowSize * 0.5f, Origins::MC);
		}

		// ���� ����
		{
			yesButton = new SpriteObj();
			noButton = new SpriteObj();
			confirmMessage = new SpriteObj();
			confirmBackground = new SpriteObj();


			confirmMessage->SetAll(*testConfirmMessage, windowSize * 0.5f, Origins::MC);
			yesButton->SetAll(*testYesButton, { confirmMessage->GetPos().x - 100, confirmMessage->GetPos().y + confirmMessage->GetPos().y / 2 - 50 }, Origins::MC);
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

		maxHp->SetAll(font, to_string(ironClad->GetMaxHP()), 30, Color::Red, { curHp->GetPos().x + 40, curHp->GetPos().y });
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
}

void PlayUi::SetActionUi(bool set)
{
	actionWindow->SetActive(set);
	attackButton->SetActive(set);
	defendButton->SetActive(set);
	attackCount->SetActive(set);
	defendCount->SetActive(set);
	ternPassButton->SetActive(set);
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
}

void PlayUi::SetMonsterTern()
{
	ternPassButton->SetActive(false);
	isMonsterTern = true;
	monsterRandomPatternSetting = false;
	isPlayerTern = false;
	monsterPatternDelay = 1.f;
}

void PlayUi::SetClearUi(bool set)
{
	clearBackground->SetActive(set);
	continueButton->SetActive(set);
}