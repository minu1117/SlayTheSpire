#pragma once
#include "SpriteObj.h"
#include <map>
#include <vector>
#include <list>
#include <deque>

class CardManager : public SpriteObj
{
protected:
	deque<SpriteObj*> curCard;		// �տ� �ִ� ī��
	deque<SpriteObj*> cardMap;		// ī�并ġ
	deque<SpriteObj*> cardShuffle;	// �����

	deque<SpriteObj*> unuseCard;		// �� ī�� ��¿�

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

