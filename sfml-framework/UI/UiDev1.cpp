#include "UiDev1.h"
#include "../InlcludeHeader/UiIncludeHeader.h"
#include "../Scenes/SceneDev1.h"
#include "../Framework/SoundMgr.h"

SpriteObj* UiDev1::cursor = new SpriteObj();
SpriteObj* UiDev1::PlayButton = new SpriteObj();
SpriteObj* UiDev1::ExitButton = new SpriteObj();
bool UiDev1::titleUi = true;
bool UiDev1::startSound = true;

UiDev1::UiDev1(Scene* scene)
	: UiMgr(scene)
{
}

UiDev1::~UiDev1()
{
}

void UiDev1::Init()
{
	Vector2i getSize = FRAMEWORK->GetWindowSize();
	Vector2f size = { (float)getSize.x,  (float)getSize.y };
	Font& font = *RESOURCE_MGR->GetFont("fonts/Mabinogi_Classic_TTF.ttf");
	auto testBackground = RESOURCE_MGR->GetTexture("graphics/title.png");
	auto playButtonImage = RESOURCE_MGR->GetTexture("graphics/PlayButton.png");
	auto startButtonImage = RESOURCE_MGR->GetTexture("graphics/StartButton.png");
	auto exitButtonImage = RESOURCE_MGR->GetTexture("graphics/ExitButton.png");
	auto backButtonImage = RESOURCE_MGR->GetTexture("graphics/BackButton.png");
	auto normalModeImage = RESOURCE_MGR->GetTexture("graphics/NormalMode.png");
	auto normalModeBackground = RESOURCE_MGR->GetTexture("graphics/ModeSelectBackground.png");
	auto ironCladBackgroundImage = RESOURCE_MGR->GetTexture("graphics/ironclad.png");
	auto charSelectImage = RESOURCE_MGR->GetTexture("graphics/ironcladSelect.png");
	
	// Public UI
	{
		// background
		{
			background = new SpriteObj();
			background->SetAll(*testBackground, { 1920 / 2, 1080 / 2 }, Origins::MC);
			uiObjList.push_back(background);
		}

		// BackButton
		{
			backButton = new SpriteObj();
			backButton->SetAll(*backButtonImage, { 100, size.y - 200.f }, Origins::MC);
		}
	}

	// Title UI
	{
		{
			StartButton = new SpriteObj();
			StartButton->SetAll(*startButtonImage, {100, 800}, Origins::MC);
			uiObjList.push_back(StartButton);

			ExitButton->SetAll(*exitButtonImage, { StartButton->GetPos().x, StartButton->GetPos().y + StartButton->GetSize().y + 50 }, Origins::MC);
			uiObjList.push_back(ExitButton);
		}
	}

	// ModeSelect UI
	{
		modeSelectBackground = new SpriteObj();
		normalMode = new SpriteObj();
		normalModeButton = new SpriteObj();
		normalModeFrame = new SpriteObj();
		normalModeName = new TextObj();
		normalModeExplanation = new TextObj();

		modeSelectBackground->SetAll(*normalModeBackground, { size.x / 2, size.y / 2 }, Origins::MC);
		uiObjList.push_back(modeSelectBackground);

		normalMode->SetAll(*normalModeImage, { size.x / 2, size.y / 2 }, Origins::MC);
		uiObjList.push_back(normalMode);

		normalModeButton->SetAll(*RESOURCE_MGR->GetTexture("graphics/normalmodeimage.png"), 
			{0, 0}, Origins::MC);
		normalModeButton->SetPos({ normalMode->GetPos().x, normalMode->GetPos().y - normalModeButton->GetSize().y / 1.5f - 5});
		normalModeFrame->SetAll(*RESOURCE_MGR->GetTexture("graphics/menuPanelFrame.png"), normalMode->GetPos(), Origins::MC);

		normalModeName->SetAll(font, "NORMAL", 50, Color::White, { normalMode->GetPos().x, normalMode->GetPos().y - normalMode->GetPos().y / 2 - 40});
		normalModeExplanation->SetAll(font, "Normal Mode", 50, Color::White, { normalMode->GetPos().x, normalMode->GetPos().y + 100 });

		uiObjList.push_back(normalModeButton);
		uiObjList.push_back(normalModeFrame);
		uiObjList.push_back(normalModeName);
		uiObjList.push_back(normalModeExplanation);
	}

	// CharSelectScene
	{
		charSelectBackgruond = new SpriteObj();
		charSelectBackgruond->SetAll(*ironCladBackgroundImage, { size.x / 2, size.y / 2 }, Origins::MC);
		uiObjList.push_back(charSelectBackgruond);

		charSelect = new SpriteObj();
		charSelect->SetAll(*charSelectImage, { size.x / 2, size.y / 2 + 300 }, Origins::MC);
		uiObjList.push_back(charSelect);

		PlayButton->SetAll(*playButtonImage, { size.x - 100, backButton->GetPos().y }, Origins::MC);
		PlayButton->SetActive(false);
		uiObjList.push_back(PlayButton);
	}

	// Back Button
	{
		uiObjList.push_back(backButton);
	}

	{
		cursor->SetAll(*RESOURCE_MGR->GetTexture("graphics/cursor.png"), { 0, 0 }, Origins::MC);
		uiObjList.push_back(cursor);
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
	titleUi = true;
	modeSelectUi = false;
	charSelectUi = false;
	StartUi = false;
	SOUND_MGR->StopAll();
}

void UiDev1::Update(float dt)
{
	UiMgr::Update(dt);
	Vector2f worldMousePos = parentScene->ScreenToUiPos((Vector2i)InputMgr::GetMousePos());
	cursor->SetPos(worldMousePos);

	
	// Title UI
	if (titleUi == true)
	{
		if (startSound == true)
		{
			SOUND_MGR->Play("sounds/Menu.ogg", true);
			startSound = false;
		}
		SetTitleUi(true);
		if (Button::ButtonOnRect(*cursor, *StartButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				SetTitleUi(false);
				titleUi = false;
				modeSelectUi = true;
				SOUND_MGR->Play("sounds/uiClick.wav", false);
			}
			if (uiHover == true)
			{
				SOUND_MGR->Play("sounds/uiHover.wav", false);
				uiHover = false;
			}
		}
		else if (Button::ButtonOnRect(*cursor, *ExitButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				SOUND_MGR->Play("sounds/uiClick.wav", false);
			}
			if (uiHover == true)
			{
				SOUND_MGR->Play("sounds/uiHover.wav", false);
				uiHover = false;
			}
		}
		else
			uiHover = true;
	}

	// ModeSelect UI
	if (modeSelectUi == true)
	{
		SetModeSelectUi(true);
		if (Button::ButtonOnRect(*cursor, *normalMode))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				modeSelectUi = false;
				charSelectUi = true;
				SOUND_MGR->Play("sounds/uiClick.wav", false);
			}
			if (uiHover == true)
			{
				SOUND_MGR->Play("sounds/uiHover.wav", false);
				uiHover = false;
			}
		}
		else if (Button::ButtonOnRect(*cursor, *backButton))
		{
			if (uiHover == true)
			{
				SOUND_MGR->Play("sounds/uiHover.wav", false);
				uiHover = false;
			}
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				modeSelectUi = false;
				titleUi = true;
				SOUND_MGR->Play("sounds/uiClick.wav", false);
			}
		}
		else
			uiHover = true;
	}
	else
	{
		SetModeSelectUi(false);
	}

	// CharSelect UI
	if (charSelectUi == true)
	{
		modeSelectBackground->SetActive(true);
		backButton->SetActive(true);
		SetCharSelectUi(true);
		if (Button::ButtonOnRect(*cursor, *backButton))
		{
			if (uiHover == true)
			{
				SOUND_MGR->Play("sounds/uiHover.wav", false);
				uiHover = false;
			}

			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				charSelectUi = false;
				modeSelectUi = true;
				SOUND_MGR->Play("sounds/uiClick.wav", false);
			}
		}
		else if (Button::ButtonOnRect(*cursor, *charSelect))
		{
			if (uiHover == true)
			{
				SOUND_MGR->Play("sounds/uiHover.wav", false);
				uiHover = false;
			}

			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				StartUi = true;
				SceneDev1::SetIsCharSelect(true);
				SOUND_MGR->Play("sounds/ironCladSelect.ogg", false);
			}
		}
		else if (Button::ButtonOnRect(*cursor, *PlayButton) && PlayButton->GetActive() == true)
		{
			if (uiHover == true)
			{
				SOUND_MGR->Play("sounds/uiHover.wav", false);
				uiHover = false;
			}

			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
				SOUND_MGR->Play("sounds/uiClick.wav", false);
		}
		else
			uiHover = true;
	}
	else
	{
		SetCharSelectUi(false);
	}

	// Start UI
	if (StartUi == true)
	{
		SetStartUi(true);
		if (Button::ButtonOnRect(*cursor, *backButton))
		{
			if (InputMgr::GetMouseButtonUp(Mouse::Button::Left))
			{
				StartUi = false;
				SOUND_MGR->Play("sounds/uiClick.wav", false);
			}
		}
	}
	else
	{
		SetStartUi(false);
	}

	UiMgr::Update(dt);
}

void UiDev1::Draw(RenderWindow& window)
{
	window.setView(parentScene->GetUiView());
	UiMgr::Draw(window);
}

SpriteObj* UiDev1::GetCursor()
{
	return cursor;
}

SpriteObj* UiDev1::GetStartButton()
{
	return PlayButton;
}

SpriteObj* UiDev1::GetExitButton()
{
	return ExitButton;
}

void UiDev1::SetTitleUi(bool set)
{
	StartButton->SetActive(set);
	ExitButton->SetActive(set);
	modeSelectBackground->SetActive(false);
	backButton->SetActive(false);
}

void UiDev1::SetModeSelectUi(bool set)
{
	modeSelectBackground->SetActive(set);
	backButton->SetActive(set);
	normalMode->SetActive(set);
	normalModeButton->SetActive(set);
	normalModeFrame->SetActive(set);
	normalModeName->SetActive(set);
	normalModeExplanation->SetActive(set);

	normalModeName->SetOrigin(Origins::MC);
	normalModeExplanation->SetOrigin(Origins::MC);
}

void UiDev1::SetCharSelectUi(bool set)
{
	charSelect->SetActive(set);
}

void UiDev1::SetStartUi(bool set)
{
	charSelectBackgruond->SetActive(set);
	PlayButton->SetActive(set);
}