#include "Button.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/TextObj.h"

bool Button::ButtonOnRect(const SpriteObj& cursor, const SpriteObj& rect)
{
	// ���콺 Ŭ�� ��Ʈ�ڽ� = ���� ������ ��,��� 10�ȼ�
	// Button Origin = MC !!!!
	// Mouse Click HitBox = LeftTop Mouse Cursor Position - x : 10, y : 10 pixel
	if (cursor.GetPos().y - cursor.GetSize().y + 10 >= rect.GetPos().y - rect.GetSize().y / 2 &&
		cursor.GetPos().y - cursor.GetSize().y + 10 <= rect.GetPos().y + rect.GetSize().y / 2 &&
		cursor.GetPos().x - cursor.GetSize().x + 10 >= rect.GetPos().x - rect.GetSize().x / 2 &&
		cursor.GetPos().x - cursor.GetSize().x + 10 <= rect.GetPos().x + rect.GetSize().x / 2)
	{
		return true;
	}
	else
		return false;
}

bool Button::ButtonOnRect(const TextObj& cursor, const TextObj& rect)
{
	return false;
}

void Button::ButtonClick()
{
}
