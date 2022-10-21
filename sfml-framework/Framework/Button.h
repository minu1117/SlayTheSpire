#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class SpriteObj;
class TextObj;
class Button
{
protected:


public:
	Button() {};
	~Button() {};
	static bool ButtonOnRect(const SpriteObj& cursor, const SpriteObj& rect);
	static bool ButtonOnRect(const TextObj& cursor, const TextObj& rect);
	void ButtonClick();
};

