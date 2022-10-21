#pragma once
#include "SpriteObj.h"
#include <map>
#include <vector>
#include <list>
#include <deque>

class CardManager : public SpriteObj
{
protected:
	deque<SpriteObj*> curCard;		// 손에 있는 카드
	deque<SpriteObj*> cardMap;		// 카드뭉치
	deque<SpriteObj*> cardShuffle;	// 섞기용

	deque<SpriteObj*> unuseCard;		// 쓴 카드 담는용

	int random = 0;
	int prevRandom = -1;

public:
	CardManager();
	~CardManager();

	void Hand(int hand);
	void Suffle();

	void AttackCardPush(SpriteObj*& card);
	void DefenceCardPush(SpriteObj*& card);
	void PowerCardPush(SpriteObj*& card);

	void UsingCard(int use);
};

