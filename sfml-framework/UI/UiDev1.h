#pragma once
#include "UiMgr.h"
#include "../GameObject/TextObj.h"
#include "../GameObject/SpriteObj.h"

class UiDev1 : public UiMgr
{
protected:
	TextObj* startText;
	SpriteObj* background;

	SpriteObj* backButton; // 뒤로 버튼
	SpriteObj* StartButton;

	SpriteObj* normalMode;
	SpriteObj* modeSelectBackground; // 반투명 검정 전체화면 이미지
	SpriteObj* charSelect;

	SpriteObj* charSelectBackgruond; // 캐릭터 설명 전체화면 이미지
	SpriteObj* ironCladBackground;


	bool modeSelectUi = false;
	bool charSelectUi = false;
	bool StartUi = false;

public:
	UiDev1(Scene* scene);
	~UiDev1();
	virtual void Init() override;
	virtual void Release() override;
	virtual void Reset() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	static SpriteObj* cursor;
	static SpriteObj* PlayButton;  // 출정 버튼
	static SpriteObj* ExitButton;

	static SpriteObj* GetCursor();
	static SpriteObj* GetStartButton();
	static SpriteObj* GetExitButton();

	static bool titleUi;

	void SetTitleUi(bool set);
	void SetModeSelectUi(bool set);
	void SetCharSelectUi(bool set);
	void SetStartUi(bool set);
};