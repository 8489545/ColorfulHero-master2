#include"stdafx.h"
#include "Camera.h"
Camera::Camera()
{
	Init();
}

Camera::~Camera()
{
}

void Camera::Init()
{
	m_Rotation = 0;
	m_Position = Vec2(0, 0);
	m_Scale = Vec2(1.f, 1.f);
	m_MaxPos = Vec2(0, 0);
	m_MinPos = Vec2(0, 0);
	m_MovingMode = false;
	m_Limit = false;
	Follow(nullptr);
}

void Camera::Translate()
{
	if (INPUT->GetKey(VK_INSERT) == KeyState::DOWN)
	{
		if (m_MovingMode)
			m_MovingMode = false;
		else
			m_MovingMode = true;
	}
	if (m_MovingMode)
	{
		if (INPUT->GetKey(VK_UP) == KeyState::PRESS)
		{
			m_Position.y -= 600 * dt;
		}
		if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS)
		{
			m_Position.y += 600 * dt;
		}
		if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
		{
			m_Position.x -= 600 * dt;
		}
		if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS)
		{
			m_Position.x += 600 * dt;
		}
	}
}

void Camera::Follow(Object* obj)
{
	if (obj != nullptr && !m_MovingMode && (obj->m_Position.x != 0 && obj->m_Position.y != 0))
	{
		if (obj->m_Position.x - App::GetInst()->m_Width / 2 < m_MaxPos.x && obj->m_Position.x - 400 > m_MinPos.x)
			m_Position.x = obj->m_Position.x - 400;
		if (obj->m_Position.y - App::GetInst()->m_Height / 2 < m_MaxPos.y && obj->m_Position.y - App::GetInst()->m_Height / 2 > m_MinPos.y)
			m_Position.y = obj->m_Position.y - App::GetInst()->m_Height / 2;
	}
}

void Camera::Zoom()
{
}


void Camera::Update(float deltaTime, float time)
{
	Translate();
	//Zoom();

	if (m_Rotation >= 360)
		m_Rotation = 0;

	if (m_Limit)
	{
		if (m_Position.x > m_MaxPos.x)
			m_Position.x = m_MaxPos.x;

		if (m_Position.y > m_MaxPos.y)
			m_Position.y = m_MaxPos.y;

		if (m_Position.x < m_MinPos.x)
			m_Position.x = m_MinPos.x;

		if (m_Position.y < m_MinPos.y)
			m_Position.y = m_MinPos.y;
	}
}

void Camera::Render()
{
	D3DXMatrixRotationZ(&mRot, D3DXToRadian(m_Rotation));
	D3DXMatrixTranslation(&mTrans, -m_Position.x, -m_Position.y, 1.f);
	D3DXMatrixScaling(&mScale, m_Scale.x, m_Scale.y, 1.f);

	// Ä«¸Þ¶ó 
	//mScale* mRot* mTrans
	mWorld = mScale * mRot * mTrans;
}
