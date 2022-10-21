#include "CardManager.h"
#include "../Framework/Utils.h"
#include <iostream>

CardManager::CardManager()
{
}

CardManager::~CardManager()
{
}

void CardManager::Hand(int hand)
{
	for (int i = 0; i < hand; i++)
	{
		curCard.push_back(cardMap[i]);
	}

	for (int i = 0; i < hand; i++)
	{
		cardMap.pop_front();
	}
}

void CardManager::Suffle()
{
	//cardShuffle.clear();

	//for (int i = 0; i < cardMap.size(); i++)
	//{
	//	do
	//	{
	//		random = Utils::RandomRange(0, cardMap.size());
	//	} while (random != prevRandom);

	//	cardShuffle.push_back(cardMap[random]);

	//	std::cout << random << std::endl;
	//	prevRandom = random;
	//}
	//cardMap.clear();

	//for (int i = 0; i < cardShuffle.size(); i++)
	//{
	//	cardMap.push_back(cardShuffle[i]);
	//}

	//cardShuffle.clear();
}

void CardManager::AttackCardPush(SpriteObj*& card)
{
	cardMap.push_back(card);
}

void CardManager::DefenceCardPush(SpriteObj*& card)
{
	cardMap.push_back(card);
}

void CardManager::PowerCardPush(SpriteObj*& card)
{
	cardMap.push_back(card);
}

void CardManager::UsingCard(int use)
{
	curCard.erase(curCard.begin() + use);
}
