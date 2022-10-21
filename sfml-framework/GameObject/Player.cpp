#include "Player.h"
#include "../UI/UiMgr.h"

Player::Player(int curH, int maxH, int curG, int curE, int maxE, int curD)
	: curHP(curH), maxHP(maxH), curGold(curG), curEnergy(curE), maxEnergy(maxE), defend(curD)
{
}

Player::~Player()
{
}

void Player::MovePlayer(float dt)
{
	SetPos({ 0.001f * dt, GetPos().y });
}