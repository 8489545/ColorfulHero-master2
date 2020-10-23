#include "stdafx.h"
#include "ProgressBar.h"

ProgressBar::ProgressBar(float endTime)
{
	m_Outline = Sprite::Create(L"Painting/UI/BarOutline.png");
	m_Outline->SetParent(this);
	SetPosition(1920 / 2, 50);
	
	m_Bar = Sprite::Create(L"Painting/UI/Bar.png");
	m_Bar->m_Position = m_Position;

	m_EndTime = endTime;
	m_NowTime = 0.f;
	m_ProgressGage = 0.f;
	m_Layer = 2;
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::Update(float deltaTime, float Time)
{
	m_Bar->m_Position = m_Position;
	m_NowTime += dt;
}

void ProgressBar::Render()
{
	m_Outline->Render();
	m_Bar->Render();

	m_ProgressGage = m_Bar->m_Size.x / m_EndTime;

	int time = m_EndTime - m_NowTime;

	SetRect(&m_Bar->m_Collision, m_Bar->m_Position.x - m_Bar->m_Size.x / 2, m_Bar->m_Position.y - m_Bar->m_Size.y / 2,
		m_Bar->m_Position.x + m_Bar->m_Size.x / 2, m_Bar->m_Position.y + m_Bar->m_Size.y / 2);

	m_Bar->m_Rect.right = m_Bar->m_Size.x - (time * m_ProgressGage);
}
