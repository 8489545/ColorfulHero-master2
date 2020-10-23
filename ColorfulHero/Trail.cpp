#include "stdafx.h"
#include "Trail.h"
Trail::Trail(Vec2 Pos)
{
	m_Obj = Sprite::Create(L"Painting/Object/Player/Player.png");
	m_Obj->SetParent(this);
	m_Position = Pos;
	m_Obj->A = 80;
	timer = 0.f;
}

Trail::~Trail()
{
}

void Trail::Update(float deltaTime, float Time)
{
	timer += dt;

	if (timer >= 0.1f)
		SetDestroy(true);
}

void Trail::Render()
{
	m_Obj->Render();
}
