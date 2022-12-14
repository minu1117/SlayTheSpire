#include "Monster.h"
#include "../Framework/Framework.h"
#include "../Framework/Utils.h"

Monster::Monster(int curH, int maxH, int defend, float damage, MonsterType t)
	: curHP(curH), maxHP(maxH), defend(defend), damage(damage), speed(1400.f), type(t)
{
}

void Monster::SetMonster(int curH, int maxH, int defend, float damage, MonsterType t)
{
	curHP = curH;
	maxHP = maxH;
	this->defend = defend;
	this->damage = damage;
	speed = 1400.f;
	type = t;
}

void Monster::Pattern(int pattern, float dt)
{
	float df = Utils::RandomRange(5, 15);

	switch (pattern)
	{
	case 0: case 1:
		SetIsAttack(true);
		Attack(dt);
		patternType = MonsterPattern::Attack;
		break;
	case 2:
		SetDefend(defend + df);
		patternType = MonsterPattern::Defence;
		break;
	case 3:
		patternType = MonsterPattern::Weaken;
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
			if (GetPos().x < (float)size.x / 1.5)
			{
				rightMove = true;
				leftMove = false;
			}
		}
		if (rightMove == true)
		{
			SetPos({ GetPos().x + speed * dt , GetPos().y });
			if (GetPos().x > (float)size.x / 1.4)
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
