#pragma once
#include "Object.h"

class SpriteObj : public Object
{
protected:
	Sprite sprite;

public:
	SpriteObj() {};
	virtual ~SpriteObj() {};

	virtual void Init() override {};
	virtual void Update(float dt) override {};
	virtual void Draw(RenderWindow& window) override { window.draw(sprite); };

	void SetTexture(Texture& tex) { sprite.setTexture(tex); };
	void SetScale(float x, float y) { sprite.setScale(x, y); };
};

