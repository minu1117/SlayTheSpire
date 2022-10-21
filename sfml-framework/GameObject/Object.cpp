#include "Object.h"

int Object::objCount = 0;

Object::Object()
{
    id = ++objCount;
}

Object::~Object()
{
}

int Object::GetObjId() const
{
    return id;
}

void Object::SetActive(bool active)
{
    enabled = active;
}

bool Object::GetActive() const
{
    return enabled;
}

void Object::Init()
{
    Reset();
}

void Object::Release()
{
}

void Object::Reset()
{
    enabled = true;
}

void Object::SetPos(const Vector2f& pos)
{
    position = pos;
}

const Vector2f& Object::GetPos() const
{
    return position;
}

void Object::Update(float dt)
{
}

void Object::Draw(RenderWindow& window)
{

}

void Object::Translate(const Vector2f& delta)
{
    SetPos(position + delta);
}

