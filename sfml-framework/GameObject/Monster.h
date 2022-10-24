#pragma once
#include "SpriteObj.h"

enum class Pattern
{
	Attack,
	Defence,
	// ... etc
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

	MonsterType type;

public:
	Monster(int curH, int maxH, int defend, float damage, MonsterType t);
	virtual ~Monster() {};

	void SetCurHp(float hp) { curHP = hp; };
	int GetCurHp() const { return curHP; };

	void SetMaxHp(float hp) { maxHP = hp; };
	int GetMaxHp() const { return maxHP; };

	void SetDefend(float df) { defend = df; };
	int GetDefend() const { return defend; };

	void SetDamage(float dmg) { damage = dmg; };
	float GetDamage() const { return damage; };
	
	MonsterType GetType() const { return type; };

	void Patton(int pattern, float dt);
	void SetIsAttack(bool set);
	void Attack(float dt);


	virtual void Update(float dt) override;
};

