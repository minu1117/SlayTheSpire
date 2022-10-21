#include "PlayUi.h"
#include "../InlcludeHeader/UiIncludeHeader.h"
#include "../Scenes/SceneDev2_Play.h"
#include "UiDev1.h"

PlayUi::PlayUi(Scene* scene)
	: UiMgr(scene)
{
}

PlayUi::~PlayUi()
{
}

void PlayUi::Init()
{
	Font& font = *RESOURCE_MGR->GetFont("fonts/Mabinogi_Classic_TTF.ttf");
	auto testBackground = RESOURCE_MGR->GetTexture("graphics/testbackground.png");
	auto testButton1 = RESOURCE_MGR->GetTexture("graphics/UtilCard.png");
	auto testButton2 = RESOURCE_MGR->GetTexture("graphics/DefenseCard.png");

	{
		player = new Player(80, 80, 50, 3, 3, 0); // 파일입출력 하면 좋을듯
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

void PlayUi::Draw(RenderWindow& window)
{
	window.setView(parentScene->GetUiView());
	UiMgr::Draw(window);
}