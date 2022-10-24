#include "PlayUi.h"
#include "../InlcludeHeader/UiIncludeHeader.h"
#include "../Scenes/SceneDev2_Play.h"
#include "UiDev1.h"
#include "../GameObject/Player.h"
#include "../GameObject/Monster.h"

Player* PlayUi::ironClad = new Player(80, 80, 99, 3, 3, 0, 10); // 플레이어 생성

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


	//auto testChoiceImage1 = RESOURCE_MGR->GetTexture("graphics/choice1.png");
	//auto testChoiceImage2 = RESOURCE_MGR->GetTexture("graphics/choice2.png");
	//auto testChoiceImage3 = RESOURCE_MGR->GetTexture("graphics/choice3.png");

	Vector2f windowSize = (Vector2f)FRAMEWORK->GetWindowSize();

	// test Monster
	{
		monster = new Monster(40, 40, 0, 10, MonsterType::Easy);
		monster->SetAll(*RESOURCE_MGR->GetTexture("graphics/ironcladimage.png"),
				{ windowSize.x / 1.5f, windowSize.y / 3 + windowSize.y / 3 }, Origins::MC);
		monster->SetScale(-1, 1);

		monsterDefend = new TextObj();
		monsterDefend->SetAll(font, to_string(monster->GetDefend()), 30, Color::White, 
			{ monster->GetPos().x, monster->GetPos().y + 100});
		monsterDefend->SetOrigin(Origins::MC);
	}

	// 기본 백그라운드
	{
		tempBackground = new SpriteObj();
		tempBackground->SetAll(*testBackground, windowSize * 0.5f, Origins::MC);
		uiObjList.push_back(tempBackground);
	}

	// choice 보류
	{
		//choice1 = new SpriteObj();
		//choice2 = new SpriteObj();
		//choice3 = new SpriteObj();

		//choice1->SetAll(*testChoiceImage1, { 0, 1000 }, Origins::MC);
		//choice2->SetAll(*testChoiceImage2, { 0, 1000 }, Origins::MC);
		//choice3->SetAll(*testChoiceImage3, { 0, 1000 }, Origins::MC);

		//uiObjList.push_back(choice1);
		//uiObjList.push_back(choice2);
		//uiObjList.push_back(choice3);
	}

	// 캐릭터 관련 UI
	{
		// 캐릭터 생성
		{
			ironClad->SetAll(*RESOURCE_MGR->GetTexture("graphics/ironcladimage.png"),
				{ windowSize.x / 4, windowSize.y / 3 + windowSize.y / 3 }, Origins::MC);
		}

		// 정보 텍스트
		{
			ironCladMaxHp = new TextObj();
			ironCladCurHp = new TextObj();
			ironCladCurEnergy = new TextObj();
			ironCladMaxEnergy = new TextObj();
			ironCladCurDefend = new TextObj();

			Vector2f setPlayerHpPos = { ironClad->GetPos().x - 30, ironClad->GetPos().y + (ironClad->GetSize().y / 2) };

			ironCladCurHp->SetAll(font, "H" + to_string(ironClad->GetCurHP()), 30, Color::White, setPlayerHpPos);

			ironCladMaxHp->SetAll(font, "/ MH" + to_string(ironClad->GetMaxHP()), 30, Color::White,
				{ ironCladCurHp->GetPos().x + 55, setPlayerHpPos.y });

			ironCladCurEnergy->SetAll(font, to_string(ironClad->GetCurEnergy()), 30, Color::White,
				{ 100, windowSize.y - 100 });
			ironCladCurEnergy->SetOrigin(Origins::MC);

			ironCladMaxEnergy->SetAll(font, to_string(ironClad->GetMaxEnergy()), 30, Color::White,
				{ ironCladCurEnergy->GetPos().x + 20, ironCladCurEnergy->GetPos().y });
			ironCladMaxEnergy->SetOrigin(Origins::MC);


			ironCladCurDefend->SetAll(font, "D : " + to_string(ironClad->GetDefend()), 30, Color::White,
				{ setPlayerHpPos.x, setPlayerHpPos.y + 40 });
		}


		uiObjList.push_back(monster);
		uiObjList.push_back(monsterDefend);
		uiObjList.push_back(ironClad);
		uiObjList.push_back(ironCladMaxHp);
		uiObjList.push_back(ironCladCurHp);
		uiObjList.push_back(ironCladCurEnergy);
		uiObjList.push_back(ironCladMaxEnergy);
		uiObjList.push_back(ironCladCurDefend);
	}


	// 맵
	{
		mapBackground = new SpriteObj();
		map = new SpriteObj();
		mapIcon = new SpriteObj();

		mapBackground->SetAll(*testMapBackground, windowSize * 0.5f, Origins::MC);
		map->SetAll(*testMap, windowSize * 0.5f, Origins::MC);

		uiObjList.push_back(mapBackground);
		uiObjList.push_back(map);
	}


	// 옵션
	{
		// 처음 들어갔을때
		{
			backButton = new SpriteObj();
			option = new SpriteObj();
			optionBackground = new SpriteObj();
			giveUpButton = new SpriteObj();

			backButton->SetAll(*testBackButton, { 100, windowSize.y - 200.f }, Origins::MC);
			optionBackground->SetAll(*testOptionBackground, windowSize * 0.5f, Origins::MC);
			giveUpButton->SetAll(*testGiveUpButton, windowSize * 0.5f, Origins::MC);

			uiObjList.push_back(optionBackground);
			uiObjList.push_back(backButton);
			uiObjList.push_back(giveUpButton);
		}

		// 전투 포기
		{
			yesButton = new SpriteObj();
			noButton = new SpriteObj();
			confirmMessage = new SpriteObj();
			confirmBackground = new SpriteObj();


			confirmMessage->SetAll(*testConfirmMessage, windowSize * 0.5f , Origins::MC);
			yesButton->SetAll(*testYesButton, { confirmMessage->GetPos().x - 100, confirmMessage->GetPos().y + confirmMessage->GetPos().y / 2 - 50 }, Origins::MC);
			noButton->SetAll(*testNoButton, { yesButton->GetPos().x + 200, yesButton->GetPos().y }, Origins::MC);
			confirmBackground->SetAll(*testOptionBackground, windowSize * 0.5f, Origins::MC);


			uiObjList.push_back(confirmBackground);
			uiObjList.push_back(confirmMessage);
			uiObjList.push_back(yesButton);
			uiObjList.push_back(noButton);
		}
	}

	// 최상단 UI들
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

		maxHp->SetAll(font, to_string(ironClad->GetMaxHP()), 30, Color::Red, { curHp->GetPos().x + 40, curHp->GetPos().y});
		maxHp->SetOrigin(Origins::MC);

		// option icon
		option->SetAll(*testOptionButton, {windowSize.x - 100, gold->GetPos().y}, Origins::MC);

		// map icon
		mapIcon->SetAll(*testMapIcon, { option->GetPos().x - 100, option->GetPos().y }, Origins::MC);
		

		uiObjList.push_back(testBorder);
		uiObjList.push_back(gold);
		uiObjList.push_back(curHp);
		uiObjList.push_back(maxHp);
		uiObjList.push_back(mapIcon);
		uiObjList.push_back(option);

		cursor = UiDev1::GetCursor();
		uiObjList.push_back(cursor);
	}

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

	// monster patton test
	if (InputMgr::GetKeyDown(Keyboard::Key::A))
	{
		monster->Patton(Utils::RandomRange(0, 2), dt);
		monsterDefend->SetText(to_string(monster->GetDefend()));
	}

	if (InputMgr::GetKeyDown(Keyboard::Key::Add))
	{
		ironClad->AddGold(10);
		gold->SetText("GOLD " + to_string(ironClad->GetCurGold()));
	}

	// test code (player attack motion)
	if (InputMgr::GetKeyDown(Keyboard::Key::Z))
	{
		ironClad->SetIsAttack(true);
		ironClad->Attack(dt);
	}

	// test code (energy control)
	if (InputMgr::GetKeyDown(Keyboard::Key::X))
	{
		ironClad->SetCurEnergy(1);
		ironCladCurEnergy->SetText(to_string(ironClad->GetCurEnergy()));
	}


	// Option Ui Control
	{
		if (giveupUi == false)
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
	}
	
	// Map Ui Control
	{
		if (optionUi == false && giveupUi == false)
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
	}

	// GiveUp Ui Control
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
					// 죽음
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

	UiMgr::Update(dt);
}

void PlayUi::Draw(RenderWindow& window)
{
	window.setView(parentScene->GetUiView());
	UiMgr::Draw(window);
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

Player* PlayUi::GetPlayer(PlayerType type)
{
	switch (type)
	{
	case PlayerType::IronClad:
		return ironClad;
		break;
	}
}

//void PlayUi::PlayerSet()
//{
//}
