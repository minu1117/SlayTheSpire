#pragma once
#include "SpriteObj.h"

class Player : public SpriteObj
{
protected:
	int curHP;
	int maxHP;

	int minGold = 0;
	int curGold;

	int curEnergy;
	int maxEnergy;
	int minEnergy = 0;

	int minDefend = 0;
	int defend;

	int attackCount;
	int defendCount;

	float attackDamage;

	float speed;

	bool isAlive = true;
	bool isAttack = false;
	bool rightMove = true;
	bool leftMove = false;

public:
	Player(int curH, int maxH, int curG, int curE, int maxE, int curD, float dmg);
	~Player();

	int GetCurHP() const { return curHP; };
	int GetMaxHP() const { return maxHP; };

	void SetCurHP(float hp) { curHP = hp; };
	void SetMaxHP(float hp) { maxHP = hp; };

	int GetCurGold() const { return curGold; };

	int GetCurEnergy() const { return curEnergy; };
	void SetCurEnergy(int energy) 
	{ if (curEnergy < 9) curEnergy = energy; };
	void SetMaxEnergy(int max) { if (maxEnergy < 9) maxEnergy = max; };
	int GetMaxEnergy() const { return maxEnergy; };

	void SetDefend(int def) { defend = def; };
	int GetDefend() { return defend; };

	void AddGold(int gold) { curGold += gold; };
	void AddEnergy(int energy) { curEnergy += energy; };
	void AddMaxHealth(int health) { maxHP += health; };
	void AddCurHealth(int health) { curHP += health; };

	void AddDamage(float dmg) { attackDamage += dmg; };
	float GetDamage() const { return attackDamage; };

	void SetIsAttack(bool set);
	void Attack(float dt);
	
	bool GetAlive() { return isAlive; };
	void SetAlive(bool set) { isAlive = set; };

	void SetAttackCount(int count) { attackCount = count; };
	void SetDefendCount(int count) { defendCount = count; };
	int GetAttackCount() const { return attackCount; };
	int GetDefendCount() const { return defendCount; };

	virtual void Update(float dt) override;
};

