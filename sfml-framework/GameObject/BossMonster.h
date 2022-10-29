//#include "Monster.h"
//
//enum class BossPattern
//{
//	NormalAttack,
//	Defense,
//	Smite,
//	Nuke,
//};
//
//class Player;
//class BossMonster : public Monster
//{
//protected:
//	int nukeCount = 6;
//	BossPattern pattern;
//
//public:
//	BossMonster(int curH, int maxH, int defend, float damage);
//	virtual ~BossMonster();
//
//	virtual void SetCurHp(float hp) { curHP = hp; };
//	virtual int GetCurHp() const { return curHP; };
//
//	virtual void SetMaxHp(float hp) { maxHP = hp; };
//	virtual int GetMaxHp() const { return maxHP; };
//
//	virtual void SetDefend(float df) { defend = df; };
//	virtual int GetDefend() const { return defend; };
//
//	virtual void SetDamage(float dmg) { damage = dmg; };
//	virtual float GetDamage() const { return damage; };
//
//	virtual bool GetAlive() const { return isAlive; };
//	virtual void SetAlive(bool set) { isAlive = set; };
//
//	virtual void SetIsWeaken(int w) { isWeaken = w; };
//	virtual int GetIsWeaken() const { return isWeaken; };
//
//	
//	void BossPatten(float dt, BossPattern pattern, Player* player);
//
//
//	virtual void Update(float dt) override;
//};