#pragma once
#include "UiMgr.h"
#include "../GameObject/TextObj.h"
#include "../GameObject/SpriteObj.h"

class UiDev1 : public UiMgr
{
protected:
	SpriteObj* background;

	SpriteObj* backButton; // �ڷ� ��ư
	SpriteObj* StartButton;

	SpriteObj* normalMode;
	SpriteObj* normalModeButton;
	SpriteObj* normalModeFrame;
	TextObj* normalModeName;
	TextObj* normalModeExplanation;


	SpriteObj* modeSelectBackground; // ������ ���� ��üȭ�� �̹���
	SpriteObj* charSelect;

	SpriteObj* charSelectBackgruond; // ĳ���� ���� ��üȭ�� �̹���
	SpriteObj* ironCladBackground;

	

	bool modeSelectUi = false;
	bool charSelectUi = false;
	bool StartUi = false;
	bool uiHover = true;

public:
	UiDev1(Scene* scene);
	~UiDev1();
	virtual void Init() override;
	virtual void Release() override;
	virtual void Reset() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	static SpriteObj* cursor;
	static SpriteObj* PlayButton;  // ���� ��ư
	static SpriteObj* ExitButton;

	static SpriteObj* GetCursor();
	static SpriteObj* GetStartButton();
	static SpriteObj* GetExitButton();

	static bool titleUi;
	static bool startSound;
	static void SetStartSound(bool set) { startSound = set; };

	void SetTitleUi(bool set);
	void SetModeSelectUi(bool set);
	void SetCharSelectUi(bool set);
	void SetStartUi(bool set);
};