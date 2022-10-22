#include "PlayUi.h"
#include "../InlcludeHeader/UiIncludeHeader.h"
#include "../Scenes/SceneDev2_Play.h"
#include "UiDev1.h"
#include "../GameObject/Player.h"

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
	auto tempBackgroundImage = RESOURCE_MGR->GetTexture("graphics/testbackground2.png");
	auto testButton1 = RESOURCE_MGR->GetTexture("graphics/UtilCard.png");
	auto testButton2 = RESOURCE_MGR->GetTexture("graphics/DefenseCard.png");

	Vector2f windowSize = (Vector2f)FRAMEWORK->GetWindowSize();

	{
		// 캐릭터 생성
		ironClad = new Player(80, 80, 99, 3, 3, 0); // 파일입출력 하면 좋을듯
		ironClad->SetAll(*RESOURCE_MGR->GetTexture("graphics/ironcladimage.png"), 
			{ windowSize.x / 4, windowSize.y / 3 + windowSize.y / 3 }, Origins::MC);
		uiObjList.push_back(ironClad);


		// 정보 텍스트
		ironCladMaxHp = new TextObj();
		ironCladCurHp = new TextObj();
		ironCladGold = new TextObj();
		ironCladCurEnergy = new TextObj();
		ironCladMaxEnergy = new TextObj();
		ironCladCurDefend = new TextObj();

		Vector2f setPlayerHpPos = { ironClad->GetPos().x - 30, ironClad->GetPos().y + (ironClad->GetSize().y / 2) };

		ironCladCurHp->SetAll(font, "H" + to_string(ironClad->GetCurHP()), 30, Color::White, setPlayerHpPos);

		ironCladMaxHp->SetAll(font, "/ MH" + to_string(ironClad->GetMaxHP()), 30, Color::White,
			{ ironCladCurHp->GetPos().x + 55, setPlayerHpPos.y});

		ironCladCurEnergy->SetAll(font, to_string(ironClad->GetCurEnergy()), 30, Color::White,
			{ 100, windowSize.y - 100 });
		ironCladCurEnergy->SetOrigin(Origins::MC);

		ironCladMaxEnergy->SetAll(font, to_string(ironClad->GetMaxEnergy()), 30, Color::White,
			{ ironCladCurEnergy->GetPos().x + 20, ironCladCurEnergy->GetPos().y });
		ironCladMaxEnergy->SetOrigin(Origins::MC);
		

		ironCladGold->SetAll(font, "GOLD " + to_string(ironClad->GetCurGold()), 30, Color::White, { 50, 50 });


		ironCladCurDefend->SetAll(font, "D : " + to_string(ironClad->GetDefend()), 30, Color::White,
			{ setPlayerHpPos.x, setPlayerHpPos.y + 40});
		
		uiObjList.push_back(ironCladMaxHp);
		uiObjList.push_back(ironCladCurHp);
		uiObjList.push_back(ironCladGold);
		uiObjList.push_back(ironCladCurEnergy);
		uiObjList.push_back(ironCladMaxEnergy);
		uiObjList.push_back(ironCladCurDefend);
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
		ironClad->AddGold(-10);
		ironCladGold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
	}

	// test code
	if (InputMgr::GetKeyDown(Keyboard::Key::Z))
	{
		ironClad->SetIsMove(true);
		ironClad->MovePlayer(dt);
	}

	// test code
	if (InputMgr::GetKeyDown(Keyboard::Key::X))
	{
		ironClad->SetCurEnergy(1);
		ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));
	}

	UiMgr::Update(dt);
}

void PlayUi::Draw(RenderWindow& window)
{
	window.setView(parentScene->GetUiView());
	UiMgr::Draw(window);
}