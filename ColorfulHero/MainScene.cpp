#include"stdafx.h"
#include "MainScene.h"
#include"StageSelect.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	SoundMgr::GetInst()->Play(L"Body_Jammer.wav",true);
	m_BG = Sprite::Create(L"Painting/BG/MainBG.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	m_Start = Sprite::Create(L"Painting/UI/Start.png");
	m_Start->SetPosition(1560, 400);

	m_Exit = Sprite::Create(L"Painting/UI/Exit.png");
	m_Exit->SetPosition(1700, 600);

	m_Title = Sprite::Create(L"Painting/UI/Title.png");
	m_Title->SetPosition(400, 200);

	for (int i = 1; i <= 6; i++)
	{
		Equalizer* eq = new Equalizer;
		eq->Line = i;
		eq->Power = 0;

		m_EQ.push_back(eq);
	}

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 6; j++)
		{
			m_Bars[i][j] = Sprite::Create(L"Painting/Object/EQ.png");
			m_Bars[i][j]->SetPosition(100 + i * 145, 1020 - j * 50);

			if (i == 0)
				m_Bars[i][j]->SetColor(255, 255, 42 * j, 42 * j);
			if (i == 1)
				m_Bars[i][j]->SetColor(255, 255, 128 + 21 * j, 42 * j);
			if (i == 2)
				m_Bars[i][j]->SetColor(255, 255, 255, 42 * j);
			if (i == 3)
				m_Bars[i][j]->SetColor(255, 42 * j, 255, 42 * j);
			if (i == 4)
				m_Bars[i][j]->SetColor(255, 42 * j, 42 * j, 255);
		}

	m_Timer = 0.f;
	m_ChangePowerTime = 0.07f;
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	m_Timer += dt;
	SetEQ();
	if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Exit))
	{
		if (m_Exit->m_Scale.x <= 1.1f && m_Exit->m_Scale.y <= 1.1f)
		{
			m_Exit->m_Scale = Vec2(m_Exit->m_Scale.x + 0.01f, m_Exit->m_Scale.y + 0.01f);
		}

		if (INPUT->GetButtonDown())
		{
			exit(0);
			INPUT->ButtonDown(false);
		}
	}
	else
	{
		if (m_Exit->m_Scale.x > 1.0f && m_Exit->m_Scale.y > 1.0f)
			m_Exit->m_Scale = Vec2(m_Exit->m_Scale.x - 0.05f, m_Exit->m_Scale.y - 0.05f);
	}
	if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Start))
	{
		if (m_Start->m_Scale.x <= 1.1f && m_Start->m_Scale.y <= 1.1f)
		{
			m_Start->m_Scale = Vec2(m_Start->m_Scale.x + 0.01f, m_Start->m_Scale.y + 0.01f);
		}

		if (INPUT->GetButtonDown())
		{
			SceneDirector::GetInst()->ChangeScene(new StageSelect());
			INPUT->ButtonDown(false);
		}
	}
	else
	{
		if (m_Start->m_Scale.x > 1.0f && m_Start->m_Scale.y > 1.0f)
			m_Start->m_Scale = Vec2(m_Start->m_Scale.x - 0.05f, m_Start->m_Scale.y - 0.05f);
	}
}

void MainScene::Render()
{
	m_BG->Render();
	m_Start->Render();
	m_Exit->Render();
	m_Title->Render();

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 6; j++)
			m_Bars[i][j]->Render();
}

void MainScene::SetEQ()
{
	if (m_Timer >= m_ChangePowerTime)
	{
		for (int i = 1; i <= 5; i++)
		{
			int pm = rand() % 3;

			if (pm == 0 && m_EQ.at(i)->Power < 6)
				m_EQ.at(i)->Power += 1;
			if (pm == 1 && m_EQ.at(i)->Power >= 0)
				m_EQ.at(i)->Power -= 1;
		}

		m_Timer = 0.f;
	}


	for (int j = 1; j <= 5; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if (m_EQ.at(j)->Power < i)
				m_Bars[m_EQ.at(j)->Line - 2][i]->A = 0;
			else
				m_Bars[m_EQ.at(j)->Line - 2][i]->A = 255;
		}
	}
}

