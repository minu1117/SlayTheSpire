#include "Button.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/TextObj.h"

bool Button::ButtonOnRect(const SpriteObj& cursor, const SpriteObj& rect)
{
	// ��ư ������ ���������
	if (cursor.GetPos().y >= rect.GetPos().y - rect.GetSize().y / 2 &&
		cursor.GetPos().y <= rect.GetPos().y + rect.GetSize().y / 2 &&
		cursor.GetPos().x >= rect.GetPos().x - rect.GetSize().x / 2 &&
		cursor.GetPos().x <= rect.GetPos().x + rect.GetSize().x / 2)
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
