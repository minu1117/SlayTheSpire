#pragma once
#include "SpriteObj.h"

class Scene;
class UiMgr;
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

	float speed;

	bool isMove = false;
	bool rightMove = true;
	bool leftMove = false;

public:
	Player(int curH, int maxH, int curG, int curE, int maxE, int curD);
	~Player();

	int GetCurHP() const { return curHP; };
	int GetMaxHP() const { return maxHP; };

	int GetCurGold() const { return curGold; };

	int GetCurEnergy() const { return curEnergy; };
	void SetCurEnergy(int energy) 
	{ if (curEnergy < 9) curEnergy += energy; };
	void SetMaxEnergy(int max) { if (maxEnergy < 9) maxEnergy = max; };
	int GetMaxEnergy() const { return maxEnergy; };

	void SetDefend(int def) { defend = def; };
	int GetDefend() const { return defend; };

	void AddGold(int gold) { curGold += gold; };
	void AddEnergy(int energy) { curEnergy += energy; };
	void AddMaxHealth(int health) { maxHP += health; };
	void AddCurHealth(int health) { curHP += health; };

	void MovePlayer(float dt);
	void SetIsMove(bool set);

	virtual void Update(float dt) override;
};

