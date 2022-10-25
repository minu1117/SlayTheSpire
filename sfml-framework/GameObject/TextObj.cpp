#include "../Framework/Utils.h"
#include "TextObj.h"

TextObj::TextObj()
{
}

TextObj::~TextObj()
{
}

void TextObj::Draw(RenderWindow& window)
{
	window.draw(text);
}

const Vector2f& TextObj::GetPos() const
{
	return text.getPosition();
}

void TextObj::SetFont(Font& font)
{
	text.setFont(font);
}

void TextObj::SetText(string str)
{
	text.setString(str);
}

void TextObj::SetAll(Font& font, string str, int size, Color color, Vector2f pos)
{
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(pos);
}

void TextObj::SetColor(Color color)
{
	text.setFillColor(color);
}

void TextObj::SetOrigin(Origins origin)
{
	Utils::SetOrigin(text, origin);
}

void TextObj::SetPos(Vector2f pos)
{
	text.setPosition(pos);
}

const FloatRect& TextObj::GetSize() const
{
	return text.getGlobalBounds();
}

const string& TextObj::GetText() const
{
	return text.getString();
}