#include "Player.h"
#include "../Framework/Framework.h"

Player::Player(int curH, int maxH, int curG, int curE, int maxE, int curD, float dmg, PlayerType t)
	: curHP(curH), maxHP(maxH), curGold(curG), curEnergy(curE), maxEnergy(maxE), defend(curD), speed(1400.f), attackDamage(dmg), type(t)
{

}

Player::~Player()
{
}

void Player::Attack(float dt)
{
	if (isAlive == false)
		return;

	Vector2i size = FRAMEWORK->GetWindowSize();

	if (isAttack == true)
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
				isAttack = false;
			}
		}
	}
}

void Player::SetIsAttack(bool set)
{
	isAttack = set;
}

void Player::PlayerWeakenMotion(float dt)
{
	if (weakenMotion == false)
		return;

	Vector2i size = FRAMEWORK->GetWindowSize();

	if (weakenMotion == true)
	{
		if (weakenRightMove == true)
		{
			SetPos({ GetPos().x + speed/1.5f * dt , GetPos().y });
			if (GetPos().x > (float)size.x / 3.7)
			{
				weakenRightMove = false;
				weakenLeftMove = true;
			}
		}
		if (weakenLeftMove == true)
		{
			SetPos({ GetPos().x + -speed/1.5f * dt , GetPos().y });

			if (GetPos().x < (float)size.x / 4 && weakenMotionCount == 0)
			{
				weakenRightMove = true;
				weakenLeftMove = false;
				weakenMotion = false;
				weakenMotionCount = 3;
			}

			if (GetPos().x < (float)size.x / 4.2)
			{
				weakenRightMove = true;
				weakenLeftMove = false;
				weakenMotionCount--;
			}
		}
	}

}

void Player::Update(float dt)
{
	PlayerWeakenMotion(dt);
	Attack(dt);
	SpriteObj::Update(dt);
}
