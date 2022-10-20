#pragma once
#include <random>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

enum class Origins
{
	TopLeft,	// 0
	TopCenter,
	TopRight,
	MiddleLeft,
	MiddleCenter,
	MiddleRight,
	LowLeft,
	LowCenter,
	LowRight,	// 8
};

class Utils
{
private:
	static random_device rd;
	static mt19937 gen;

public:
	static void SetOrigin(Text& obj, Origins origin);
	static void SetOrigin(Sprite& obj, Origins origin);
	static void SetOrigin(Shape& obj, Origins origin);
	static void SetOrigin(Transformable& obj, Origins origin, FloatRect rect);
	
	static int RandomRange(int min, int maxExclude);
};

