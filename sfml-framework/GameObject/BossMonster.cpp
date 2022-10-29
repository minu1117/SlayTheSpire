//#include "BossMonster.h"
//#include "Player.h"
//
//BossMonster::BossMonster(int curH, int maxH, int defend, float damage)
//	: Monster(*this)
//{
//	curHP = curH;
//	maxHP = maxH;
//	this->defend = defend;
//	this->damage = damage;
//}
//
//void BossMonster::BossPatten(float dt, BossPattern pattern, Player* player)
//{
//	switch (pattern)
//	{
//	case BossPattern::NormalAttack:
//		if (player->GetDefend() > 0)
//		{
//			if (player->GetDefend() >= damage)
//			{
//				int defend = player->GetDefend();
//				player->SetDefend(defend -= damage);
//				// ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
//			}
//			else if (player->GetDefend() < damage)
//			{
//				int piercingDamage = damage - player->GetDefend();
//				player->SetDefend(0);
//				player->SetCurHP(player->GetCurHP() - piercingDamage);
//				//ironCladCurDefend->SetText("D : " + to_string(ironClad->GetDefend()));
//				//ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
//				//curHp->SetText(to_string(ironClad->GetCurHP()));
//			}
//		}
//		else
//		{
//			player->SetCurHP(player->GetCurHP() - damage);
//			//ironCladCurHp->SetText(to_string(ironClad->GetCurHP()));
//			//curHp->SetText(to_string(ironClad->GetCurHP()));
//		}
//		break;
//	case BossPattern::Defense:
//		break;
//	case BossPattern::Smite:
//		break;
//	case BossPattern::Nuke:
//		break;
//	}
//}
//
//void BossMonster::Update(float dt)
//{
//
//}