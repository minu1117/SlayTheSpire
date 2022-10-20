#pragma once
#include "Object.h"
#include "../Framework/Utils.h"

class TextObject :
    public Object
{
protected:
    Text text;

public:
    TextObject() {};
    virtual ~TextObject() {};

    virtual void Init() override {};
    virtual void Update(float dt) override { text.setPosition(position); };
    virtual void Draw(RenderWindow& window) override { window.draw(text); };

    void SetFont(Font& font) { text.setFont(font); };
    void SetText(string str) { text.setString(str); };
    void SetTextColor(Color color) { text.setFillColor(color); };
    void SetTextSize(float size) { text.setCharacterSize(size); };
    void SetOrigin(Origins origin) { Utils::SetOrigin(text, origin); };
    
    void SetAll(Font& font, string str, Color color, float size, Origins origin)
    {
        text.setFont(font);
        text.setString(str);
        text.setFillColor(color);
        text.setCharacterSize(size);
        Utils::SetOrigin(text, origin);
    };
};

