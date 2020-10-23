#include "stdafx.h"
#include "Bomb.h"
#include"Bullet.h"

Bomb::Bomb(Vec2 startPos, Vec2 arrivePos, float scale, int bulletNum, float speed, float bulletSpeed, float bombTime, Movement move)
{
	m_Obj = Sprite::Create(L"Painting/Object/Obstacle/Bomb/Bomb.png");
	m_Obj->SetParent(this);
	m_Position = startPos;
	m_Scale = Vec2(m_Scale.x * scale, m_Scale.y * scale);

	if (move == Movement::FIXED)
		SetScale(0, 0);

	m_StartPos = startPos;
	m_ArrivePos = arrivePos;
	m_Speed = speed;
	m_Move = move;
	m_Radius = 50.f * scale;
	m_Velocity = 0.f;
	m_Time = 0;
	m_BombTime = bombTime;
	m_ScaleRatio = scale;
	m_BulletNum = bulletNum;
	m_BulletSpeed = bulletSpeed;
	m_Shape = Shape::CIRCLE;

	m_Obj->SetColor(255, 0, 168, 243);
}

Bomb::~Bomb()
{
}

void Bomb::Remove()
{
	if (m_Obj->R + 15 < 255)
		m_Obj->R += 15;

	if (m_Obj->G + 7 < 255)
		m_Obj->G += 7;

	if (m_Obj->B + 3 < 255)
		m_Obj->B += 3;

	m_Scale.x += 1 * dt;
	m_Scale.y += 1 * dt;
	
	if (m_Obj->R + 15 >= 255 && m_Obj->G + 7 >= 255 && m_Obj->B + 3 >= 255)
	{
		float m_Rot = 360 / m_BulletNum;

		for(int i = 0;i <= m_BulletNum;i++)
			ObjMgr->AddObject(new Bullet(L"Square", m_Position, m_Rot * i, 1, m_BulletSpeed, Shape::SQUARE), "Obstacle");
		ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/Bomb/", 1,7,3, m_Position), "Effect");
		SetDestroy(true);
	}
}

void Bomb::Update(float deltaTime, float time)
{
	m_Rotation += D3DXToRadian(1);
	switch (m_Move)
	{
	case Movement::FIXED:
		if (m_Scale.x <= m_ScaleRatio)
			m_Scale.x += 2.f * dt;
		if (m_Scale.y <= m_ScaleRatio)
			m_Scale.y += 2.f * dt;
		break;
	case Movement::THROW:
		Throw(this);
		break;
	case Movement::STRAIGHT:
		Straight(this);
		break;
	default:
		break;
	}

	if (m_BombTimer >= m_BombTime)
	{
		Remove();
	}

	m_Time++;
	m_BombTimer += dt;
}

void Bomb::Render()
{
	m_Obj->Render();
}
