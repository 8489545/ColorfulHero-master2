#include "stdafx.h"
#include "Laser.h"

Laser::Laser(Vec2 startPos, float rotation, float weight, float aliveTime, float appearTime, bool spin, float spinSpeed)
{
	m_Obj = Sprite::Create(L"Painting/Object/Obstacle/Laser/Laser.png");
	m_Obj->SetParent(this);
	m_Obj->A = 55;

	m_Rotation = D3DXToRadian(rotation);

	m_StartPos = startPos;
	m_FirstRot = D3DXToRadian(rotation);
	m_Position = startPos;
	m_Weight = weight;
	m_AliveTime = aliveTime;
	m_AppearTime = appearTime;
	m_SpinSpeed = spinSpeed;
	m_Shape = Shape::NONE;

	m_isSpin = spin;

	m_Timer = 0.f;

	m_Scale.y = ((weight - m_Scale.y) / m_Scale.y * 100.f) / 10000.f;

	m_Line = new LineMgr();

	m_Line->Init(2, true);
	m_Line->SetColor(D3DXCOLOR(255, 0, 0, 255));
}

Laser::~Laser()
{
}

void Laser::Update(float deltaTime, float time)
{
	m_Timer += dt;

	if (m_AppearTime - m_Timer <= dt * 20 && m_Obj->A < 255)
	{
		m_Obj->A += 10;
		m_Shape = Shape::ROTSQUARE;
	}
	if (m_AppearTime <= dt * 20)
	{
		m_Obj->A = 255;
	}

	if (m_isSpin)
	{
		m_Rotation += D3DXToRadian(m_SpinSpeed) * dt;
	}


	if (m_AliveTime <= m_Timer)
	{
		SetDestroy(true);
	}

	m_Vertex[0].x = cos(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * (m_Size.y * m_Scale.y / 2) + m_Position.x;
	m_Vertex[0].y = -(-sin(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * (m_Size.y * m_Scale.y / 2)) + m_Position.y;

	m_Vertex[1].x = cos(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * (m_Size.y * m_Scale.y / 2) + m_Position.x;
	m_Vertex[1].y = -(-sin(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * (m_Size.y * m_Scale.y / 2)) + m_Position.y;

	m_Vertex[2].x = cos(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * -(m_Size.y * m_Scale.y / 2) + m_Position.x;
	m_Vertex[2].y = -(-sin(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * -(m_Size.y * m_Scale.y / 2)) + m_Position.y;

	m_Vertex[3].x = cos(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * -(m_Size.y * m_Scale.y / 2) + m_Position.x;
	m_Vertex[3].y = -(-sin(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * -(m_Size.y * m_Scale.y / 2)) + m_Position.y;
}

void Laser::Render()
{
	m_Obj->Render();

	//m_Line->DrawLine(m_Vertex, 4);
}
