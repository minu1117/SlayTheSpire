#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <map>

using namespace sf;
using namespace std;

enum class Axis
{
	Horizontal,
	Vertical,
};

struct AxisInfo
{
	Axis axis;
	list<Keyboard::Key> positives;
	list<Keyboard::Key> negatives;
};

class InputMgr
{
private:
	static map<Axis, AxisInfo> axisInfoMap;

	static list<Keyboard::Key> downList;
	static list<Keyboard::Key> ingList;
	static list<Keyboard::Key> upList;

	static list<Mouse::Button> mouseDownList;
	static list<Mouse::Button> mouseIngList;
	static list<Mouse::Button> mouseUpList;

public:
	static void Init();
	static void ClearInput();
	static void UpdateInput(Event& ev);

	static bool GetKeyDown(Keyboard::Key key);
	static bool GetKey(Keyboard::Key key);
	static bool GetKeyUp(Keyboard::Key key);

	static bool GetMouseButtonDown(Mouse::Button mouse);
	static bool GetMouseButton(Mouse::Button mouse);
	static bool GetMouseButtonUp(Mouse::Button mouse);

	static float GetAxisRaw(Axis axis);
};
