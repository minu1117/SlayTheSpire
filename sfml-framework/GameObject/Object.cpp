#include "Object.h"

Object::Object()
{
	Init();
}

Object::~Object()
{
	Release();
}

void Object::Init()
{
}

void Object::Release()
{
}

void Object::Update(float dt)
{
}

void Object::Draw(RenderWindow& window)
{
}
