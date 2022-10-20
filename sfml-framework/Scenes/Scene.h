#pragma once
#include "SFML/Graphics.hpp"
#include <list>
#include "../GameObject/Object.h"
using namespace std;
using namespace sf;

enum class Scenes
{
	None = -1,

	GameStart,
	CharSelect,
	Ending,
};

class Scene
{
protected:
	Scenes type;
	list<Object*> objList;
	list<Object*> uiObjList;

public:
	Scene(Scenes type);
	virtual ~Scene() {};

	virtual void Init() = 0;
	virtual void Exit() = 0;

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
};

