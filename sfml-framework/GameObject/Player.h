#pragma once
#include "SpriteObj.h"

enum class PlayerType
{
	IronClad,
};

enum class Skill
{
	Normal,
	Smite,
	clubbing,
};

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
	int addDefend = 5;
	int weakenAddDefend;
	int notWeakenAddDefend;

	float attackDamage;
	float weakenDamage;
	float notWeakenDamage;

	float speed;

	bool isAlive = true;
	bool isAttack = false;
	bool rightMove = true;
	bool leftMove = false;

	int isWeaken = 0;
	bool weakenMotion = false;
	bool weakenRightMove = true;
	bool weakenLeftMove = false;
	int weakenMotionCount = 3;

	PlayerType type;

public:
	Player(int curH, int maxH, int curG, int curE, int maxE, int curD, float dmg, PlayerType t);
	~Player();

	const PlayerType GetType() { return type; };

	int GetCurHP() const { return curHP; };
	int GetMaxHP() const { return maxHP; };

	void SetCurHP(float hp) { curHP = hp; };
	void SetMaxHP(float hp) { maxHP = hp; };

	int GetCurGold() const { return curGold; };
	void SetGold(int gold) { curGold = gold; };

	int GetCurEnergy() const { return curEnergy; };
	void SetCurEnergy(int energy) 
	{ if (curEnergy <= 9) curEnergy = energy; };
	void SetMaxEnergy(int max) { if (maxEnergy <= 9) maxEnergy = max; };
	int GetMaxEnergy() const { return maxEnergy; };

	void SetDefend(int def) { defend = def; };
	int GetDefend() { return defend; };

	void SetAddDefend(int def) { addDefend = def; };
	int GetAddDefend() { return addDefend; };

	void AddGold(int gold) { curGold += gold; };
	void AddEnergy(int energy) { curEnergy += energy; };
	void AddMaxHealth(int health) { maxHP += health; };
	void AddCurHealth(int health) { curHP += health; };

	void AddDamage(float dmg) { attackDamage += dmg; };
	void SetDamage(float dmg) { attackDamage = dmg; };
	float GetDamage() const { return attackDamage; };

	void SetIsAttack(bool set);
	void Attack(float dt);
	
	bool GetAlive() { return isAlive; };
	void SetAlive(bool set) { isAlive = set; };

	void SetAttackCount(int count) { attackCount = count; };
	void SetDefendCount(int count) { defendCount = count; };
	int GetAttackCount() const { return attackCount; };
	int GetDefendCount() const { return defendCount; };

	void SetIsWeaken(int w) { isWeaken = w; };
	int GetIsWeaken() const { return isWeaken; };

	void SetWeakenDamage(float w) { weakenDamage = w; };
	float GetWeakenDamage() const { return weakenDamage; };

	void SetNotWeakenDamage(float w) { notWeakenDamage = w; };
	float GetNotWeakenDamage() const { return notWeakenDamage; };

	void SetWeakenDefend(float w) { weakenAddDefend = w; };
	float GetWeakenDefend() const { return weakenAddDefend; };

	void SetNotWeakenDefend(float w) { notWeakenAddDefend = w; };
	float GetNotWeakenDefend() const { return notWeakenAddDefend; };

	void SetIsWeakenMotion(bool set) { weakenMotion = set; };
	void PlayerWeakenMotion(float dt);

	virtual void Update(float dt) override;
};

