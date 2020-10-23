#include"stdafx.h"
#include "Bullet.h"
Bullet::Bullet(std::wstring name, Vec2 Pos, float Rotation, float scale,float speed, Shape shape)
{
	m_Obj = Sprite::Create(L"Painting/Object/Obstacle/Bullet/" + name + L".png");
	m_Obj->SetParent(this);

	SetScale(m_Scale.x * scale, m_Scale.y * scale);
	m_Position = Pos;

	m_StartPos = Pos;
	m_ArrivePos = Vec2(cos(D3DXToRadian(Rotation)), sin(D3DXToRadian(Rotation)));

	m_Speed = speed;

	m_Shape = shape;
	m_ScaleRatio = scale;
	m_Time = 0;
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime, float time)
{
	m_Dire = m_ArrivePos - m_StartPos;

	D3DXVec2Normalize(&m_Dire, &m_ArrivePos);

	Translate(m_Dire.x * m_Speed * dt, m_Dire.y * m_Speed * dt);

	m_Time++;
}

void Bullet::Render()
{
	m_Obj->Render();
}

void Bullet::OnCollision(Object* other)
{
}
