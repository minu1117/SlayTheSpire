#pragma once
#include "SpriteObj.h"

enum class MonsterPattern
{
	Attack,
	Defence,
	Weaken,
};

enum class MonsterType
{
	Easy,
	Normal,
	Hard,
};

class Monster : public SpriteObj
{
protected:
	int curHP;
	int maxHP;

	int minDefend = 0;
	int defend;

	float speed;

	float damage;

	bool isAttack = false;
	bool rightMove = false;
	bool leftMove = true;
	bool isAlive = true;

	int isWeaken = 0;

	MonsterType type;
	MonsterPattern patternType;

public:
	Monster() {};
	Monster(int curH, int maxH, int defend, float damage, MonsterType t);
	virtual ~Monster() {};

	virtual void SetCurHp(float hp) { curHP = hp; };
	virtual int GetCurHp() const { return curHP; };

	virtual void SetMaxHp(float hp) { maxHP = hp; };
	virtual int GetMaxHp() const { return maxHP; };

	virtual void SetDefend(float df) { defend = df; };
	virtual int GetDefend() const { return defend; };

	virtual void SetDamage(float dmg) { damage = dmg; };
	virtual float GetDamage() const { return damage; };
	
	virtual bool GetAlive() const { return isAlive; };
	virtual void SetAlive(bool set) { isAlive = set; };

	void SetMonster(int curH, int maxH, int defend, float damage, MonsterType t);

	MonsterType GetType() const { return type; };
	MonsterPattern GetPattern() const { return  patternType; };

	void Pattern(int pattern, float dt);
	void SetIsAttack(bool set);
	void Attack(float dt);

	virtual void SetIsWeaken(int w) { isWeaken = w; };
	virtual int GetIsWeaken() const { return isWeaken; };

	virtual void Update(float dt) override;
};

