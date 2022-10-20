#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Object
{
protected:
	int id;
	string name;
	bool enabled;

	Vector2f position;
	float rotation;

public:
	Object() { Init(); };
	virtual ~Object() { Release(); };

	virtual void SetActive(bool active) { enabled = active; };
	virtual bool GetActive() const { return enabled; };

	virtual void SetPos(const Vector2f& pos) { position = pos; };
	virtual const Vector2f& GetPos() { return position; };

	virtual void Init() {};
	virtual void Release() {};
	virtual void Update(float dt) {};
	virtual void Draw(RenderWindow& window) {};
};

