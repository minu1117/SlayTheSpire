#include "Player.h"
#include "../UI/UiMgr.h"
#include "../Framework/Framework.h"

Player::Player(int curH, int maxH, int curG, int curE, int maxE, int curD)
	: curHP(curH), maxHP(maxH), curGold(curG), curEnergy(curE), maxEnergy(maxE), defend(curD), speed(700.f)
{

}

Player::~Player()
{
}

void Player::MovePlayer(float dt)
{
	Vector2i size = FRAMEWORK->GetWindowSize();

	if (isMove == true)
	{
		if (rightMove == true)
		{
			SetPos({ GetPos().x + speed * dt , GetPos().y });
			if (GetPos().x > (float)size.x / 3.5)
			{
				rightMove = false;
				leftMove = true;
			}
		}
		if (leftMove == true)
		{
			SetPos({ GetPos().x + -speed * dt , GetPos().y });
			if (GetPos().x < (float)size.x / 4)
			{
				rightMove = true;
				leftMove = false;
				isMove = false;
			}
		}
	}
}

void Player::SetIsMove(bool set)
{
	isMove = set;
}

void Player::Update(float dt)
{
	MovePlayer(dt);
	SpriteObj::Update(dt);
}
