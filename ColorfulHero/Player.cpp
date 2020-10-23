#include "stdafx.h"
#include "Player.h"
#include"StageSelect.h"
#include"Trail.h"
#include"Bullet.h"

Player::Player()
{
	m_Obj = Sprite::Create(L"Painting/Object/Player/Player.png");
	m_Obj->SetParent(this);
	SetPosition(1920 / 2, 1080 / 2);

	m_Outline = Sprite::Create(L"Painting/Object/Player/Outline.png");
	m_Outline->SetPosition(1920 / 2, 1080 / 2);

	m_Guard = new Animation();
	m_Guard->AddContinueFrame(L"Painting/Object/Player/Guard/", 1, 7);
	m_Guard->Init(2, true);
	m_Guard->SetScale(1.5, 1.5);

	m_Guard->A = 0;

	m_Speed = 300.f;

	m_DashTime = 0.15f;
	m_Timer = 0.f;
	m_Timer2 = 0.f;
	m_DashCooltime = 0.f;
	m_GameOverTime = 1.0f;
	m_ColorChangeTime = 0.0f;

	m_Dash = false;
	m_GuardOn = false;

	color = COLOR::NONE;

	m_Line = new LineMgr();
	m_Line->Init(4, true);
	m_Line->SetColor(D3DXCOLOR(255, 0, 0, 255));
	m_Line2 = new LineMgr();
	m_Line2->Init(4, true);
	m_Line2->SetColor(D3DXCOLOR(0, 0, 255, 255));
}

Player::~Player()
{
}

void Player::Move()
{
	if (INPUT->GetKey(VK_UP) == KeyState::PRESS && m_Position.y > 0 + m_Size.y)
	{
		m_Position.y -= m_Speed * dt;
	}
	if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS && m_Position.y < 1080 - m_Size.y)
	{
		m_Position.y += m_Speed * dt;
	}
	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS && m_Position.x > 0 + m_Size.x)
	{
		m_Position.x -= m_Speed * dt;
	}
	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS && m_Position.x < 1920 - m_Size.x)
	{
		m_Position.x += m_Speed * dt;
	}
	m_Outline->m_Position = m_Position;
}

void Player::Dash()
{
	if (INPUT->GetKey(VK_SPACE) == KeyState::DOWN && m_DashCooltime <= 0)
	{
		m_Dash = true;
	}
	if (m_Dash)
	{
		ObjMgr->AddObject(new Trail(m_PrevPos), "Effect");
		m_Timer += dt;
		m_Speed = 1200.f;

		if (m_Timer >= m_DashTime)
		{
			m_Timer = 0.f;
			m_Dash = false;
		}
	}
	if (!m_Dash)
	{
		m_DashCooltime -= dt;
		m_Speed = 300.f;
	}
	else
	{
		m_DashCooltime = 0.5f;
	}
}

void Player::ChangeColor()
{
	if (INPUT->GetKey('Q') == KeyState::DOWN)
	{
		m_Obj->SetColor(255, 255, 0, 0);
		color = COLOR::RED;
		m_ColorChangeTime = 0.1f;
	}
	if (INPUT->GetKey('W') == KeyState::DOWN)
	{
		m_Obj->SetColor(255, 0, 255, 0);
		color = COLOR::GREEN;
		m_ColorChangeTime = 0.1f;
	}
	if (INPUT->GetKey('E') == KeyState::DOWN)
	{
		m_Obj->SetColor(255, 0, 0, 255);
		color = COLOR::BLUE;
		m_ColorChangeTime = 0.1f;
	}

}

void Player::SetVertex()
{
	m_Vertex[0].x = cos(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * (m_Size.y * m_Scale.y / 2) + m_Position.x;
	m_Vertex[0].y = -(-sin(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * (m_Size.y * m_Scale.y / 2)) + m_Position.y;

	m_Vertex[1].x = cos(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * (m_Size.y * m_Scale.y / 2) + m_Position.x;
	m_Vertex[1].y = -(-sin(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * (m_Size.y * m_Scale.y / 2)) + m_Position.y;

	m_Vertex[2].x = cos(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * -(m_Size.y * m_Scale.y / 2) + m_Position.x;
	m_Vertex[2].y = -(-sin(m_Rotation) * -((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * -(m_Size.y * m_Scale.y / 2)) + m_Position.y;

	m_Vertex[3].x = cos(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + sin(m_Rotation) * -(m_Size.y * m_Scale.y / 2) + m_Position.x;
	m_Vertex[3].y = -(-sin(m_Rotation) * ((m_Size.x * m_Scale.x) / 2) + cos(m_Rotation) * -(m_Size.y * m_Scale.y / 2)) + m_Position.y;
}

void Player::Update(float deltaTime, float time)
{
	SetCursor(NULL);
	ObjMgr->CollisionCheak(this, "Filter");
	ObjMgr->CollisionCheak(this, "Obstacle");

	Move();
	Dash();
	SetVertex();

	if(m_ColorChangeTime <= 0)
		ChangeColor();
	if (m_ColorChangeTime > 0)
	{   
		m_ColorChangeTime -= dt;
	}
	m_PrevPos = m_Position;
	m_Radius = (m_Size.x / 2) * m_Scale.x;
	m_Guard->m_Position = m_Position;

	for (auto iter : ObjMgr->m_Objects)
	{
		if (iter->m_Shape == Shape::ROTSQUARE)
		{
			if ((CollisionMgr::GetInst()->LineToLine(m_Vertex[0], m_Vertex[1], iter->m_Vertex[0], iter->m_Vertex[1]) ||
				CollisionMgr::GetInst()->LineToLine(m_Vertex[1], m_Vertex[2], iter->m_Vertex[1], iter->m_Vertex[2]) ||
				CollisionMgr::GetInst()->LineToLine(m_Vertex[2], m_Vertex[3], iter->m_Vertex[2], iter->m_Vertex[3]) ||
				CollisionMgr::GetInst()->LineToLine(m_Vertex[3], m_Vertex[0], iter->m_Vertex[3], iter->m_Vertex[0]) ||
				CollisionMgr::GetInst()->LineToLine(m_Vertex[1], m_Vertex[2], iter->m_Vertex[0], iter->m_Vertex[1])) && !m_GuardOn)
			{
				ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/Death/", 1, 9, 7, m_Position), "Death");
				ObjMgr->RemoveObject(this);
			}
		}
	}

	for (int i = 0; i < 360; i++)
	{
		a[i].x = cos(D3DXToRadian(i)) * m_Radius + m_Position.x;
		a[i].y = sin(D3DXToRadian(i)) * m_Radius + m_Position.y;
	}

	if (INPUT->GetKey('Z') == KeyState::DOWN)
	{
		if (m_GuardOn)
			m_GuardOn = false;
		else if (!m_GuardOn)
			m_GuardOn = true;
	}

	if (m_GuardOn)
	{
		m_Guard->A = 255;
	}
	else
	{
		m_Guard->A = 0;
	}

	m_Guard->Update(deltaTime, time);
}

void Player::Render()
{
	m_Obj->Render();
	m_Outline->Render();
	m_Guard->Render();

	//m_Line->DrawLine(m_Vertex, 4);
	//m_Line2 ->DrawLine(a, 360);
}

void Player::OnCollision(Object* other)
{
	if (other->m_Tag == "Filter")
	{
		if (other->color != color && other->color != COLOR::NONE)
		{
			m_Timer2 += dt;
			if (m_Timer2 >= m_GameOverTime && !m_GuardOn)
			{
				m_Timer2 = 0.f;
				ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/Death/", 1, 9,7, m_Position),"Death");
				ObjMgr->RemoveObject(this);
			}
		}
		else
		{
			m_Timer2 = 0.f;
		}
	}

	if (other->m_Tag == "Obstacle")
	{
		if (other->m_Shape == Shape::SQUARE && !m_GuardOn)
		{
			ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/Death/", 1, 9, 7, m_Position), "Death");
			ObjMgr->RemoveObject(this);
		}
		if (other->m_Shape == Shape::CIRCLE && !m_GuardOn)
		{
			if (other->m_Scale.x >= 1)
			{
				if (CollisionMgr::GetInst()->CircleToCircle(other->m_Position, other->m_Radius, m_Position, m_Radius))
				{
					ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/Death/", 1, 9, 7, m_Position), "Death");
					ObjMgr->RemoveObject(this);
				}
			}
			else
			{
				ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/Death/", 1, 9, 7, m_Position), "Death");
				ObjMgr->RemoveObject(this);
			}
		}
	}
}
