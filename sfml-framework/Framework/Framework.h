#pragma once
#include <SFML/Graphics.hpp>
#include "InputMgr.h"

using namespace sf;

class Framework
{
protected:
	RenderWindow window;
	Vector2i windowSize;

	Clock clock;
	Time deltaTime;

public:
	Framework(int width, int height);
	virtual ~Framework();

	float GetDT() const;

	bool Init();
	bool Play();
};

