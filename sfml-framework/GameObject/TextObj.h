#pragma once
#include "Object.h"
#include "../Framework/Utils.h"

class TextObj : public Object
{
protected:
	Text text;

public:
	TextObj();
	virtual ~TextObj();

	Text& GetSfmlText() { return text; }

	virtual void Draw(RenderWindow& window) override;
	virtual const Vector2f& GetPos() const override;

	void SetFont(Font& font);
	void SetText(string str);
	void SetAll(Font& font, string str, int size, Color color, Vector2f pos);
	void SetColor(Color color);
	void SetOrigin(Origins origin);
	void SetPos(Vector2f pos);
	const FloatRect& GetSize() const;
	const string& GetText() const;
};

