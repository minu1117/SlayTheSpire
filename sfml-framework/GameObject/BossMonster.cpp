#include "BossMonster.h"
#include "Player.h"
#include "../Framework/Framework.h"
#include "../Framework/Utils.h"
#include "TextObj.h"

BossMonster::BossMonster(int curH, int maxH, int defend, float damage)
{
	curHP = curH;
	maxHP = maxH;
	this->defend = defend;
	this->damage = damage;
}

void BossMonster::BossPattenSet(int pattern, Player* player)
{
	float df = Utils::RandomRange(10, 30);

	switch (pattern)
	{
	case -1:
		bossPattern = BossPattern::Question;
		break;
	case 0: case 1:
		SetDefend(defend + df);
		bossPattern = BossPattern::Defense;
		break;

	case 2: case 3:
		player->SetIsWeaken(player->GetIsWeaken() + 2);
		bossPattern = BossPattern::Weaken;
		break;

	case 4: case 5: case 6:
		bossPattern = BossPattern::NormalAttack;
		break;

	case 7:
		bossPattern = BossPattern::Smite;
		break;

	case 8:
		bossPattern = BossPattern::Nuke;
		break;
	}
}

void BossMonster::Update(float dt)
{
	SpriteObj::Update(dt);
}