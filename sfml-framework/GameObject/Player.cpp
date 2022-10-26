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

void Player::Update(float dt)
{
	Attack(dt);
	SpriteObj::Update(dt);
}
