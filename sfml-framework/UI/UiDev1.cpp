#include "UiDev1.h"
#include "../InlcludeHeader/UiIncludeHeader.h"
#include "../Scenes/SceneDev1.h"
#include "../Framework/Button.h"

UiDev1::UiDev1(Scene* scene)
	: UiMgr(scene)
{
}

UiDev1::~UiDev1()
{
}

void UiDev1::Init()
{
	Font& font = *RESOURCE_MGR->GetFont("fonts/Mabinogi_Classic_TTF.ttf");
	auto testbackground = RESOURCE_MGR->GetTexture("graphics/UtilCard.png");
	
	{
		PlayButton = new SpriteObj();
		PlayButton->SetAll();
	}
	{
		player = new Player(80, 80, 50, 3, 3, 0);
		player->SetAll(*RESOURCE_MGR->GetTexture("graphics/DefenseCard.png"), { 1920 / 2, 1080 / 2 }, Origins::MC);
		uiObjList.push_back(player);


		playerMaxHp = new TextObj();
		playerCurHp = new TextObj();
		playerGold = new TextObj();
		playerCurEnergy = new TextObj();
		playerMaxEnergy = new TextObj();
		playerCurDefend = new TextObj();

		playerMaxHp->SetAll(font, "/   MH" + to_string(player->GetMaxHP()), 30, Color::White,
			{ player->GetPos().x, player->GetPos().y + (player->GetSize().y / 2) });

		playerCurHp->SetAll(font, "H" + to_string(player->GetCurHP()), 30, Color::White,
			{ player->GetPos().x - 80, player->GetPos().y + (player->GetSize().y / 2) });


		playerGold->SetAll(font, "GOLD" + to_string(player->GetCurGold()), 30, Color::White, { 100, 100 });


		playerCurEnergy->SetAll(font, to_string(player->GetCurEnergy()), 30, Color::White,
			{ 1000, 200 });

		playerMaxEnergy->SetAll(font, "/ " + to_string(player->GetMaxEnergy()), 30, Color::White,
			{ 1020, 200 });


		playerCurDefend->SetAll(font, "D : " + to_string(player->GetDefend()), 30, Color::White,
			{ 1000, 300 });

		uiObjList.push_back(playerMaxHp);
		uiObjList.push_back(playerCurHp);
		uiObjList.push_back(playerGold);
		uiObjList.push_back(playerCurEnergy);
		uiObjList.push_back(playerMaxEnergy);
		uiObjList.push_back(playerCurDefend);
	}

	{
		test = new SpriteObj();
		test->SetAll(*testbackground, { 1920 / 2, 1080 / 2 }, Origins::MC);
		uiObjList.push_back(test);
	}
	{
		cursor = new SpriteObj();
		cursor->SetAll(*RESOURCE_MGR->GetTexture("graphics/DefenseCard.png"), {0, 0}, Origins::MC);
		uiObjList.push_back(cursor);
	}
	{
		startText = new TextObj();
		startText->SetAll(font, "START", 40, Color::Blue, {0, 0});
		uiObjList.push_back(startText);
	}

	UiMgr::Init();
}

void UiDev1::Release()
{
	UiMgr::Release();
}

void UiDev1::Reset()
{
	UiMgr::Reset();
}

void UiDev1::Update(float dt)
{
	UiMgr::Update(dt);
	Vector2f worldMousePos = parentScene->
		ScreenToUiPos((Vector2i)InputMgr::GetMousePos());
	cursor->SetPos(worldMousePos);

	// test
	if (Button::ButtonOnRect(*cursor, *test) == true)
	{
		if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
		{
			test->SetActive(false);
		}
	}
	else
		test->SetActive(false);

	if (InputMgr::GetKeyDown(Keyboard::Key::Add))
	{
		player->AddGold(500);
		playerGold->SetText("GOLD " + to_string(player->GetCurGold()));
	}

	//if (InputMgr::GetKeyDown(Keyboard::Key::Z))
	//{
	//	player->MovePlayer(dt);
	//}

	UiMgr::Update(dt);
}

void UiDev1::Draw(RenderWindow& window)
{
	window.setView(parentScene->GetUiView());
	UiMgr::Draw(window);
}