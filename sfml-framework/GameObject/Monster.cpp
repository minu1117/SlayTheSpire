#include "Monster.h"
#include "../Framework/Framework.h"
#include "../Framework/Utils.h"

Monster::Monster(int curH, int maxH, int defend, float damage, MonsterType t)
	: curHP(curH), maxHP(maxH), defend(defend), damage(damage), speed(700.f), type(t)
{
}

void Monster::Patton(int pattern, float dt)
{
	switch (pattern)
	{
	case (int)Pattern::Attack:
		SetIsAttack(true);
		Attack(dt);
		break;
	case (int)Pattern::Defence:
		float df = Utils::RandomRange(5, 10);
		SetDefend(defend + df);
		break;
	}
}

void Monster::SetIsAttack(bool set)
{
	isAttack = set;
}

void Monster::Attack(float dt)
{
	Vector2i size = FRAMEWORK->GetWindowSize();

	if (isAttack == true)
	{
		if (leftMove == true)
		{
			SetPos({ GetPos().x + -speed * dt , GetPos().y });
			if (GetPos().x < (float)size.x / 1.7)
			{
				rightMove = true;
				leftMove = false;
			}
		}
		if (rightMove == true)
		{
			SetPos({ GetPos().x + speed * dt , GetPos().y });
			if (GetPos().x > (float)size.x / 1.5)
			{
				rightMove = false;
				leftMove = true;
				isAttack = false;
			}
		}
	}
}

void Monster::Update(float dt)
{
	Attack(dt);
	SpriteObj::Update(dt);
}
