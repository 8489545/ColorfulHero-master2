#include "stdafx.h"
#include "SawBlade.h"

SawBlade::SawBlade(std::wstring name,Vec2 startPos, Vec2 arrivePos, float scale, float speed,float removeTime, Movement move)
{
	m_Obj = Sprite::Create(L"Painting/Object/Obstacle/Saw/" + name + L".png");
	m_Obj->SetParent(this);
	m_Position = startPos;
	m_Scale = Vec2(m_Scale.x * scale, m_Scale.y * scale);

	if (move == Movement::FIXED)
		SetScale(0, 0);

	m_StartPos = startPos;
	m_ArrivePos = arrivePos;
	m_Speed = speed;
	m_Move = move;
	m_Radius = 0.f;
	m_Velocity = 0.f;
	m_Time = 0;
	m_RemoveTime = removeTime;
	m_ScaleRatio = scale;
	m_Shape = Shape::CIRCLE;

	m_Line = new LineMgr();
	m_Line->Init(2, true);
	m_Line->SetColor(D3DXCOLOR(255, 0, 0, 255));
}

SawBlade::~SawBlade()
{
}

void SawBlade::Update(float deltaTime, float Time)
{
	m_Radius = (m_Size.x / 2) * m_Scale.x;
	m_Rotation += D3DXToRadian(200) * dt;
	switch (m_Move)
	{
	case Movement::FIXED:
		if (m_AliveTime <= m_RemoveTime)
		{
			if (m_Scale.x <= m_ScaleRatio)
				m_Scale.x += 2.f * dt;
			if (m_Scale.y <= m_ScaleRatio)
				m_Scale.y += 2.f * dt;
		}
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
	m_Time++;
	m_AliveTime += dt;

	if (m_AliveTime >= m_RemoveTime)
	{
		m_Scale.x -= 1.f * dt;
		m_Scale.y -= 1.f * dt;
		
		if (m_Scale.x <= 0 && m_Scale.y <= 0)
			SetDestroy(true);
	}


	for (int i = 0; i < 360; i++)
	{
		a[i].x = cos(D3DXToRadian(i)) * m_Radius + m_Position.x;
		a[i].y = sin(D3DXToRadian(i)) * m_Radius + m_Position.y;
	}

}

void SawBlade::Render()
{
	m_Obj->Render();

	//m_Line->DrawLine(a, 360);
}

void SawBlade::OnCollision(Object* other)
{
}
