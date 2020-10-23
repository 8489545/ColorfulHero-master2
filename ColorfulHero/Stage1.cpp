#include "stdafx.h"
#include "Stage1.h"
#include"Player.h"
#include"ProgressBar.h"
#include"SawBlade.h"
#include"Bomb.h"
#include "Bullet.h"
#include"Laser.h"
#include"StageSelect.h"

Stage1::Stage1()
{

}

Stage1::~Stage1()
{
}

void Stage1::Init()
{
	SoundMgr::GetInst()->Stop();
	m_BG = Sprite::Create(L"Painting/BG/BG.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	m_Filter = Sprite::Create(L"Painting/BG/Filter.png");
	m_Filter->SetPosition(1920 / 2, 1080 / 2);

	m_Tutorial = Sprite::Create(L"Painting/UI/Tutorial.png");
	m_Tutorial->SetPosition(1920 / 2, 1080 / 2);
	m_Tutorial->A = 128;

	m_Filter->A = 200;
	m_Filter->color = COLOR::NONE;

	ObjMgr->AddObject(m_BG, "BG");
	ObjMgr->AddObject(m_Filter, "Filter");
	ObjMgr->AddObject(m_Tutorial, "UI");

	m_PrevColor = COLOR::RED;

	SoundMgr::GetInst()->Play(L"Heros_Tonight.wav", false);
	m_Timer = 0.0f;

	ObjMgr->AddObject(new Player(), "Player");
	ObjMgr->AddObject(new ProgressBar(208.f), "UI");

	m_Filter->color = COLOR::NONE;
}

void Stage1::Release()
{
	ObjMgr->RemoveObject(m_BG);
	ObjMgr->RemoveObject(m_Filter);
	ObjMgr->DeleteObject("UI");
	ObjMgr->DeleteObject("Player");
	ObjMgr->DeleteObject("Obstacle");
	ObjMgr->DeleteObject("Effect");
	GameMgr::GetInst()->InputPercent(1, (m_Timer / 208.f) * 100);
	SoundMgr::GetInst()->Stop();
}

void Stage1::SetColor(COLOR color)
{
	if (color == COLOR::RED)
	{
		m_Filter->SetColor(200, 255, 54, 40,15);
		m_Filter->color = COLOR::RED;
		if (m_Filter->A == 128 && m_Filter->R == 255 && m_Filter->G == 54 && m_Filter->B == 40)
		{
			change = false;
		}
	}
	if (color == COLOR::GREEN)
	{
		m_Filter->SetColor(200, 40, 255, 54,15);
		m_Filter->color = COLOR::GREEN;
		if (m_Filter->A == 128 && m_Filter->R == 40 && m_Filter->G == 255 && m_Filter->B == 54)
		{
			change = false;
		}
	}
	if (color == COLOR::BLUE)
	{
		m_Filter->SetColor(200, 54, 50, 255,15);
		m_Filter->color = COLOR::BLUE;
		if (m_Filter->A == 128 && m_Filter->R == 54 && m_Filter->G == 50 && m_Filter->B == 255)
		{
			change = false;
		}
	}
}
void Stage1::SyncTime(float time)
{
	if (m_Timer - (time) > 0 && m_Timer - (time) <= dt)
	{
		int Rand = rand() % 2 + 1;
		change = true;

		if (m_PrevColor == COLOR::RED)
		{
			if (Rand == 1)
				m_NowColor = COLOR::GREEN;
			if (Rand == 2)
				m_NowColor = COLOR::BLUE;
		}
		if (m_PrevColor == COLOR::GREEN)
		{
			if (Rand == 1)
				m_NowColor = COLOR::RED;
			if (Rand == 2)
				m_NowColor = COLOR::BLUE;
		}
		if (m_PrevColor == COLOR::BLUE)
		{
			if (Rand == 1)
				m_NowColor = COLOR::GREEN;
			if (Rand == 2)
				m_NowColor = COLOR::RED;
		}

		m_PrevColor = m_NowColor;

		time = 0;
	}
}

void Stage1::Update(float deltaTime, float time)
{
	m_RandX = rand() % 1920;
	m_RandY = rand() % 1080;
	m_Timer += dt;
	if (change)
	{
		SetColor(m_NowColor);
	}

	//if (INPUT->GetKey(VK_SPACE) == KeyState::DOWN)
	//	printf("if(m_Timer - (%f - 1.f) > 0 && m_Timer - (%f -1.f) <= dt)\n{\n\n}\n", m_Timer,m_Timer);

	SyncColor();
	PattenOne();
	PattenTwo();
	PattenThree();

	if (m_Timer >= 208.f)
	{
		Release();
		Camera::GetInst()->Init();
		SceneDirector::GetInst()->ChangeScene(new StageSelect());
	}
}

void Stage1::Render()
{
}

void Stage1::SyncColor()
{
	SyncTime(7.700002);
	SyncTime(9.600998);
	SyncTime(11.314996);
	SyncTime(13.247995);
	SyncTime(15.179991);
	SyncTime(17.015995);
	SyncTime(18.896992);
	SyncTime(20.815001);
	SyncTime(22.631004);
	SyncTime(24.533010);
	SyncTime(26.433016);
	SyncTime(28.231022);
	SyncTime(30.114023);
	SyncTime(32.030025);
	SyncTime(33.878979);
	SyncTime(35.681950);
	SyncTime(37.581909);
	SyncTime(45.145714);
	SyncTime(52.679420);
	SyncTime(60.127220);
	SyncTime(67.643814);
	SyncTime(75.110130);
	SyncTime(82.643440);
	SyncTime(88.275925);
	SyncTime(90.142754);
	SyncTime(92.059578);
	SyncTime(93.875412);
	SyncTime(95.725243);
	SyncTime(97.575073);
	SyncTime(99.556892);
	SyncTime(101.422722);
	SyncTime(103.289551);
	SyncTime(105.172379);
	SyncTime(107.023209);
	SyncTime(108.824043);
	SyncTime(110.739868);
	SyncTime(112.621696);
	SyncTime(120.105011);
	SyncTime(127.686317);
	SyncTime(135.154282);
	SyncTime(142.670471);
	SyncTime(150.139694);
	SyncTime(157.655731);
	SyncTime(165.206451);
	SyncTime(172.675461);
	SyncTime(180.173523);
	SyncTime(187.658615);
	SyncTime(191.308243);
	SyncTime(195.096802);
	SyncTime(198.863510);
	SyncTime(202.663055);
}

void Stage1::PattenOne()
{
	if (m_Timer - (7.668998 - 1.f) > 0 && m_Timer - (7.668998 - 1.f) <= dt)
	{
		m_Tutorial->m_Visible = false;
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 0, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 0, 30, 39.116833 - 6.668998, 1, true, 40), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw",Vec2(1920 / 2, 1080 / 2),Vec2(0,0), 2, 0, 39.116833 - 6.668998, Movement::FIXED), "Obstacle");
	}
	if (m_Timer - (8.568996 - 1.f) > 0 && m_Timer - (8.568996 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 20, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}
	if (m_Timer - (9.050997 - 1.f) > 0 && m_Timer - (9.050997 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 40, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}
	if (m_Timer - (9.568994 - 1.f) > 0 && m_Timer - (9.568994 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 60, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}
	if (m_Timer - (10.017992 - 1.f) > 0 && m_Timer - (10.017992 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 80, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}
	if (m_Timer - (10.502990 - 1.f) > 0 && m_Timer - (10.502990 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 100, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}	
	if (m_Timer - (10.917989 - 1.f) > 0 && m_Timer - (10.917989 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 120, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}	
	if (m_Timer - (11.381989 - 1.f) > 0 && m_Timer - (11.381989 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 140, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}	
	if (m_Timer - (11.834989 - 1.f) > 0 && m_Timer - (11.834989 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 160, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}	
	if (m_Timer - (12.316987 - 1.f) > 0 && m_Timer - (12.316987 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 180, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}	
	if (m_Timer - (12.767986 - 1.f) > 0 && m_Timer - (12.767986 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 200, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}
	if (m_Timer - (13.217984 - 1.f) > 0 && m_Timer - (13.217984 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 220, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}
	if (m_Timer - (13.699986 - 1.f) > 0 && m_Timer - (13.699986 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 240, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}
	if (m_Timer - (14.217984 - 1.f) > 0 && m_Timer - (14.217984 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 260, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}
	if (m_Timer - (14.648984 - 1.f) > 0 && m_Timer - (14.648984 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 280, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");

	}
	if (m_Timer - (15.184983 - 1.f) > 0 && m_Timer - (15.184983 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 300, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (15.616983 - 1.f) > 0 && m_Timer - (15.616983 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 320, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (16.049980 - 1.f) > 0 && m_Timer - (16.049980 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 340, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (16.534983 - 1.f) > 0 && m_Timer - (16.534983 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 360, 20, 1, 1, false, 0), "Obstacle");
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 90, 30, 39.116833 - 15.534983, 1, true, 40), "Obstacle");
	}
	if (m_Timer - (17.000986 - 1.f) > 0 && m_Timer - (17.000986 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 20, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (17.483990 - 1.f) > 0 && m_Timer - (17.483990 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 40, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (17.965992 - 1.f) > 0 && m_Timer - (17.965992 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 60, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (18.415995 - 1.f) > 0 && m_Timer - (18.415995 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 80, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (18.883993 - 1.f) > 0 && m_Timer - (18.883993 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 100, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (19.316992 - 1.f) > 0 && m_Timer - (19.316992 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 120, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (19.801996 - 1.f) > 0 && m_Timer - (19.801996 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 140, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (20.282997 - 1.f) > 0 && m_Timer - (20.282997 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 160, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (20.750000 - 1.f) > 0 && m_Timer - (20.750000 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 180, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (21.234995 - 1.f) > 0 && m_Timer - (21.234995 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 200, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (21.683001 - 1.f) > 0 && m_Timer - (21.683001 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 220, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (22.200003 - 1.f) > 0 && m_Timer - (22.200003 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 240, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (22.668001 - 1.f) > 0 && m_Timer - (22.668001 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 260, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (23.134003 - 1.f) > 0 && m_Timer - (23.134003 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 280, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (23.568001 - 1.f) > 0 && m_Timer - (23.568001 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 300, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (24.049006 - 1.f) > 0 && m_Timer - (24.049006 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 320, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (24.533007 - 1.f) > 0 && m_Timer - (24.533007 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 340, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (24.984009 - 1.f) > 0 && m_Timer - (24.984009 -1.f) <= dt)
	{
		ObjMgr->AddObject(new Laser(Vec2(1920 / 2, 1080 / 2), 360, 20, 1, 1, false, 0), "Obstacle");
	}
	if (m_Timer - (25.468014 - 1.f) > 0 && m_Timer - (25.468014 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw",Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5,Movement::THROW), "Obstacle");
	}
	if (m_Timer - (25.965019 - 1.f) > 0 && m_Timer - (25.965019 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (26.399021 - 1.f) > 0 && m_Timer - (26.399021 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (26.867025 - 1.f) > 0 && m_Timer - (26.867025 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (27.317026 - 1.f) > 0 && m_Timer - (27.317026 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (27.801033 - 1.f) > 0 && m_Timer - (27.801033 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (28.282036 - 1.f) > 0 && m_Timer - (28.282036 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (28.716036 - 1.f) > 0 && m_Timer - (28.716036 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (29.167040 - 1.f) > 0 && m_Timer - (29.167040 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (29.650042 - 1.f) > 0 && m_Timer - (29.650042 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (30.148041 - 1.f) > 0 && m_Timer - (30.148041 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (30.582043 - 1.f) > 0 && m_Timer - (30.582043 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (31.032043 - 1.f) > 0 && m_Timer - (31.032043 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (31.517048 - 1.f) > 0 && m_Timer - (31.517048 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (32.016052 - 1.f) > 0 && m_Timer - (32.016052 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (32.450043 - 1.f) > 0 && m_Timer - (32.450043 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (32.932030 - 1.f) > 0 && m_Timer - (32.932030 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (33.348015 - 1.f) > 0 && m_Timer - (33.348015 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (33.850010 - 1.f) > 0 && m_Timer - (33.850010 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (34.315002 - 1.f) > 0 && m_Timer - (34.315002 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (34.798985 - 1.f) > 0 && m_Timer - (34.798985 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (35.333961 - 1.f) > 0 && m_Timer - (35.333961 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (35.767948 - 1.f) > 0 && m_Timer - (35.767948 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (36.198929 - 1.f) > 0 && m_Timer - (36.198929 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (36.667927 - 1.f) > 0 && m_Timer - (36.667927 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (37.114918 - 1.f) > 0 && m_Timer - (37.114918 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (37.731892 - 1.f) > 0 && m_Timer - (37.731892 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (38.099880 - 1.f) > 0 && m_Timer - (38.099880 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (38.614857 - 1.f) > 0 && m_Timer - (38.614857 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (39.116833 - 1.f) > 0 && m_Timer - (39.116833 -1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(m_RandX, 1080), 0.5, 300, 1.5, Movement::THROW), "Obstacle");
	}
}

void Stage1::PattenTwo()
{
	Vec2 randPos = Vec2(rand() % 1920, rand() % 1080);
	if (m_Timer - (38.130798 - 1.f) > 0 && m_Timer - (38.130798 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (39.563705 - 1.f) > 0 && m_Timer - (39.563705 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (41.398613 - 1.f) > 0 && m_Timer - (41.398613 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (43.083557 - 1.f) > 0 && m_Timer - (43.083557 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 1080), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (45.564476 - 1.f) > 0 && m_Timer - (45.564476 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (47.114407 - 1.f) > 0 && m_Timer - (47.114407 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (48.916351 - 1.f) > 0 && m_Timer - (48.916351 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (50.615288 - 1.f) > 0 && m_Timer - (50.615288 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 1080), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (53.098198 - 1.f) > 0 && m_Timer - (53.098198 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (54.596142 - 1.f) > 0 && m_Timer - (54.596142 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (56.415100 - 1.f) > 0 && m_Timer - (56.415100 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (58.148029 - 1.f) > 0 && m_Timer - (58.148029 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 1080), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (60.697941 - 1.f) > 0 && m_Timer - (60.697941 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (62.096905 - 1.f) > 0 && m_Timer - (62.096905 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (63.930840 - 1.f) > 0 && m_Timer - (63.930840 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (65.596695 - 1.f) > 0 && m_Timer - (65.596695 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 1080), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (68.095467 - 1.f) > 0 && m_Timer - (68.095467 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (69.529335 - 1.f) > 0 && m_Timer - (69.529335 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (71.445160 - 1.f) > 0 && m_Timer - (71.445160 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (73.047012 - 1.f) > 0 && m_Timer - (73.047012 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 1080), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (77.028648 - 1.f) > 0 && m_Timer - (77.028648 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (78.913475 - 1.f) > 0 && m_Timer - (78.913475 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (80.526329 - 1.f) > 0 && m_Timer - (80.526329 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (85.409882 - 1.f) > 0 && m_Timer - (85.409882 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 1080), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (88.227623 - 1.f) > 0 && m_Timer - (88.227623 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (90.258438 - 1.f) > 0 && m_Timer - (90.258438 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 0), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (92.110268 - 1.f) > 0 && m_Timer - (92.110268 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (93.926102 - 1.f) > 0 && m_Timer - (93.926102 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 1080), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (95.758934 - 1.f) > 0 && m_Timer - (95.758934 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (97.658760 - 1.f) > 0 && m_Timer - (97.658760 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, m_RandY), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
	if (m_Timer - (99.525589 - 1.f) > 0 && m_Timer - (99.525589 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(m_RandX, 1080), Vec2(1920 / 2, 1080 / 2), 1, 300, 1, Movement::THROW), "Obstacle");
	}
}

void Stage1::PattenThree()
{
	if (m_Timer - (101.409195 - 1.f) > 0 && m_Timer - (101.409195 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150, 150), Vec2(0, 150), 2.7, 500, 201.731033 - 101.409195, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300, 150), Vec2(150, 150), 2.7, 500, 201.731033 - 101.409195, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300 * 2, 150), Vec2(300, 150), 2.7, 500, 201.731033 - 101.409195, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300 * 3, 150), Vec2(450, 150), 2.7, 500, 201.731033 - 101.409195, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300 * 4, 150), Vec2(600, 150), 2.7, 500, 201.731033 - 101.409195, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300 * 5, 150), Vec2(750, 150), 2.7, 500, 201.731033 - 101.409195, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300 * 6, 150), Vec2(750, 150), 2.7, 500, 201.731033 - 101.409195, Movement::FIXED), "Obstacle");

		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 380), Vec2(1920, 380), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 680), Vec2(1920, 680), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 980), Vec2(1920, 980), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (103.258026 - 1.f) > 0 && m_Timer - (103.258026 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 530), Vec2(0, 530), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 830), Vec2(0, 830), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (105.108856 - 1.f) > 0 && m_Timer - (105.108856 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 380), Vec2(1920, 380), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 680), Vec2(1920, 680), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 980), Vec2(1920, 980), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (106.989685 - 1.f) > 0 && m_Timer - (106.989685 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 530), Vec2(0, 530), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 830), Vec2(0, 830), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (108.823517 - 1.f) > 0 && m_Timer - (108.823517 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 380), Vec2(1920, 380), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 680), Vec2(1920, 680), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 980), Vec2(1920, 980), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (111.075310 - 1.f) > 0 && m_Timer - (111.075310 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 530), Vec2(0, 530), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 830), Vec2(0, 830), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (112.157211 - 1.f) > 0 && m_Timer - (112.157211 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 380), Vec2(1920, 380), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 680), Vec2(1920, 680), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 980), Vec2(1920, 980), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (114.538994 - 1.f) > 0 && m_Timer - (114.538994 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 530), Vec2(0, 530), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 830), Vec2(0, 830), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (116.421822 - 1.f) > 0 && m_Timer - (116.421822 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 380), Vec2(1920, 380), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 680), Vec2(1920, 680), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 980), Vec2(1920, 980), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (118.007675 - 1.f) > 0 && m_Timer - (118.007675 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 530), Vec2(0, 530), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 830), Vec2(0, 830), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (120.589439 - 1.f) > 0 && m_Timer - (120.589439 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 380), Vec2(1920, 380), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 680), Vec2(1920, 680), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 980), Vec2(1920, 980), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (122.023308 - 1.f) > 0 && m_Timer - (122.023308 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 530), Vec2(0, 530), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 830), Vec2(0, 830), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (123.888138 - 1.f) > 0 && m_Timer - (123.888138 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 380), Vec2(1920, 380), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 680), Vec2(1920, 680), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 980), Vec2(1920, 980), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (125.520988 - 1.f) > 0 && m_Timer - (125.520988 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 530), Vec2(0, 530), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 830), Vec2(0, 830), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (128.121796 - 1.f) > 0 && m_Timer - (128.121796 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 380), Vec2(1920, 380), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 680), Vec2(1920, 680), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(0, 980), Vec2(1920, 980), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	if (m_Timer - (129.554138 - 1.f) > 0 && m_Timer - (129.554138 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 530), Vec2(0, 530), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(1920, 830), Vec2(0, 830), 1.5, 500, 3.84, Movement::STRAIGHT), "Obstacle");
	}
	float randY = (rand() % 380) + 300;
	if (m_Timer - (129.738174 - 1.f) > 0 && m_Timer - (129.738174 - 1.f) <= dt)
	{
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150, 930), Vec2(0, 150), 2.7, 500, 201.731033 - 129.738174, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300, 930), Vec2(150, 150), 2.7, 500, 201.731033 - 129.738174, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300 * 2, 930), Vec2(300, 150), 2.7, 500, 201.731033 - 129.738174, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300 * 3, 930), Vec2(450, 150), 2.7, 500, 201.731033 - 129.738174, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300 * 4, 930), Vec2(600, 150), 2.7, 500, 201.731033 - 129.738174, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300 * 5, 930), Vec2(750, 150), 2.7, 500, 201.731033 - 129.738174, Movement::FIXED), "Obstacle");
		ObjMgr->AddObject(new SawBlade(L"Saw", Vec2(150 + 300 * 6, 930), Vec2(750, 150), 2.7, 500, 201.731033 - 129.738174, Movement::FIXED), "Obstacle");

		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, m_RandY), 180, 1, 800, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (129.971222 ) > 0 && m_Timer - (129.971222 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (130.188248 ) > 0 && m_Timer - (130.188248 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (130.688293 ) > 0 && m_Timer - (130.688293 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (131.188370 ) > 0 && m_Timer - (131.188370 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (131.388397 ) > 0 && m_Timer - (131.388397 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (131.871475 ) > 0 && m_Timer - (131.871475 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (132.071518 ) > 0 && m_Timer - (132.071518 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (132.305542 ) > 0 && m_Timer - (132.305542 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (132.538574 ) > 0 && m_Timer - (132.538574 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (132.755600 ) > 0 && m_Timer - (132.755600 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (132.988632 ) > 0 && m_Timer - (132.988632 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (133.521698 ) > 0 && m_Timer - (133.521698 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (133.939743 ) > 0 && m_Timer - (133.939743 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (134.172760 ) > 0 && m_Timer - (134.172760 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (134.638824 ) > 0 && m_Timer - (134.638824 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (134.822845 ) > 0 && m_Timer - (134.822845 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (135.654968 ) > 0 && m_Timer - (135.654968 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (135.854996 ) > 0 && m_Timer - (135.854996 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (136.106018 ) > 0 && m_Timer - (136.106018 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (136.489075 ) > 0 && m_Timer - (136.489075 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (136.738129 ) > 0 && m_Timer - (136.738129 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (137.022156 ) > 0 && m_Timer - (137.022156 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (137.239166 ) > 0 && m_Timer - (137.239166 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (137.488205 ) > 0 && m_Timer - (137.488205 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (137.722244 ) > 0 && m_Timer - (137.722244 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (138.189316 ) > 0 && m_Timer - (138.189316 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (138.656372 ) > 0 && m_Timer - (138.656372 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (138.873398 ) > 0 && m_Timer - (138.873398 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (139.355438 ) > 0 && m_Timer - (139.355438 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (139.556473 ) > 0 && m_Timer - (139.556473 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (139.789490 ) > 0 && m_Timer - (139.789490 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (139.989517 ) > 0 && m_Timer - (139.989517 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (140.188538 ) > 0 && m_Timer - (140.188538 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (140.439575 ) > 0 && m_Timer - (140.439575 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (141.005646 ) > 0 && m_Timer - (141.005646 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (141.422699 ) > 0 && m_Timer - (141.422699 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (141.689743 ) > 0 && m_Timer - (141.689743 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (142.173813 ) > 0 && m_Timer - (142.173813 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (142.355835 ) > 0 && m_Timer - (142.355835 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (143.156006 ) > 0 && m_Timer - (143.156006 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (143.373016 ) > 0 && m_Timer - (143.373016 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (143.673035 ) > 0 && m_Timer - (143.673035 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (144.073074 ) > 0 && m_Timer - (144.073074 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (144.290115 ) > 0 && m_Timer - (144.290115 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (144.556152 ) > 0 && m_Timer - (144.556152 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (144.789169 ) > 0 && m_Timer - (144.789169 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (145.023178 ) > 0 && m_Timer - (145.023178 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (145.272217 ) > 0 && m_Timer - (145.272217 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (145.673279 ) > 0 && m_Timer - (145.673279 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (146.140350 ) > 0 && m_Timer - (146.140350 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (146.356384 ) > 0 && m_Timer - (146.356384 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (146.839478 ) > 0 && m_Timer - (146.839478 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (147.072495 ) > 0 && m_Timer - (147.072495 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (147.289536 ) > 0 && m_Timer - (147.289536 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (147.489563 ) > 0 && m_Timer - (147.489563 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (147.690582 ) > 0 && m_Timer - (147.690582 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (147.940613 ) > 0 && m_Timer - (147.940613 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (148.156631 ) > 0 && m_Timer - (148.156631 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (148.522705 ) > 0 && m_Timer - (148.522705 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (148.873764 ) > 0 && m_Timer - (148.873764 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (149.089798 ) > 0 && m_Timer - (149.089798 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (149.656891 ) > 0 && m_Timer - (149.656891 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (149.889923 ) > 0 && m_Timer - (149.889923 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (150.673996 ) > 0 && m_Timer - (150.673996 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (150.857010 ) > 0 && m_Timer - (150.857010 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (151.107040 ) > 0 && m_Timer - (151.107040 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (151.557083 ) > 0 && m_Timer - (151.557083 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (151.790100 ) > 0 && m_Timer - (151.790100 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (152.057129 ) > 0 && m_Timer - (152.057129 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (152.290146 ) > 0 && m_Timer - (152.290146 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (152.541199 ) > 0 && m_Timer - (152.541199 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (152.756241 ) > 0 && m_Timer - (152.756241 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (153.156296 ) > 0 && m_Timer - (153.156296 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (153.624329 ) > 0 && m_Timer - (153.624329 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (153.857361 ) > 0 && m_Timer - (153.857361 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (154.323425 ) > 0 && m_Timer - (154.323425 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (154.541443 ) > 0 && m_Timer - (154.541443 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (154.841492 ) > 0 && m_Timer - (154.841492 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (155.040543 ) > 0 && m_Timer - (155.040543 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (155.290573 ) > 0 && m_Timer - (155.290573 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (155.540604 ) > 0 && m_Timer - (155.540604 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (155.973648 ) > 0 && m_Timer - (155.973648 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (156.423721 ) > 0 && m_Timer - (156.423721 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (156.640747 ) > 0 && m_Timer - (156.640747 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (157.140793 ) > 0 && m_Timer - (157.140793 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (157.357803 ) > 0 && m_Timer - (157.357803 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (158.140884 ) > 0 && m_Timer - (158.140884 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (158.323898 ) > 0 && m_Timer - (158.323898 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (158.606949 ) > 0 && m_Timer - (158.606949 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (159.006989 ) > 0 && m_Timer - (159.006989 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (159.257019 ) > 0 && m_Timer - (159.257019 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (159.557053 ) > 0 && m_Timer - (159.557053 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (159.774063 ) > 0 && m_Timer - (159.774063 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (160.008087 ) > 0 && m_Timer - (160.008087 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (160.226105 ) > 0 && m_Timer - (160.226105 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (160.675140 ) > 0 && m_Timer - (160.675140 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (161.107208 ) > 0 && m_Timer - (161.107208 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (161.357224 ) > 0 && m_Timer - (161.357224 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (161.824341 ) > 0 && m_Timer - (161.824341 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (162.057373 ) > 0 && m_Timer - (162.057373 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (162.290436 ) > 0 && m_Timer - (162.290436 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (162.524445 ) > 0 && m_Timer - (162.524445 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (162.724457 ) > 0 && m_Timer - (162.724457 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (162.974472 ) > 0 && m_Timer - (162.974472 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (163.491501 ) > 0 && m_Timer - (163.491501 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (163.924545 ) > 0 && m_Timer - (163.924545 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (164.174591 ) > 0 && m_Timer - (164.174591 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (164.641632 ) > 0 && m_Timer - (164.641632 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (164.890656 ) > 0 && m_Timer - (164.890656 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (165.674789 ) > 0 && m_Timer - (165.674789 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (165.858826 ) > 0 && m_Timer - (165.858826 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (166.141861 ) > 0 && m_Timer - (166.141861 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (166.574936 ) > 0 && m_Timer - (166.574936 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (166.790970 ) > 0 && m_Timer - (166.790970 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (167.074997 ) > 0 && m_Timer - (167.074997 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (167.276016 ) > 0 && m_Timer - (167.276016 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (167.508041 ) > 0 && m_Timer - (167.508041 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (167.758087 ) > 0 && m_Timer - (167.758087 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (168.175156 ) > 0 && m_Timer - (168.175156 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (168.692245 ) > 0 && m_Timer - (168.692245 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (168.925278 ) > 0 && m_Timer - (168.925278 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (169.391342 ) > 0 && m_Timer - (169.391342 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (169.625381 ) > 0 && m_Timer - (169.625381 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (169.875412 ) > 0 && m_Timer - (169.875412 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (170.091431 ) > 0 && m_Timer - (170.091431 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (170.325470 ) > 0 && m_Timer - (170.325470 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (170.541519 ) > 0 && m_Timer - (170.541519 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (171.008560 ) > 0 && m_Timer - (171.008560 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (171.424606 ) > 0 && m_Timer - (171.424606 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (171.642624 ) > 0 && m_Timer - (171.642624 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (172.191696 ) > 0 && m_Timer - (172.191696 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (172.425720 ) > 0 && m_Timer - (172.425720 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (173.158798 ) > 0 && m_Timer - (173.158798 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (173.375824 ) > 0 && m_Timer - (173.375824 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (173.624847 ) > 0 && m_Timer - (173.624847 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (174.024872 ) > 0 && m_Timer - (174.024872 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (174.241882 ) > 0 && m_Timer - (174.241882 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (174.542938 ) > 0 && m_Timer - (174.542938 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (174.758957 ) > 0 && m_Timer - (174.758957 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (174.958984 ) > 0 && m_Timer - (174.958984 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (175.225998 ) > 0 && m_Timer - (175.225998 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (175.459015 ) > 0 && m_Timer - (175.459015 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (175.859070 ) > 0 && m_Timer - (175.859070 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (176.226089 ) > 0 && m_Timer - (176.226089 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (176.442108 ) > 0 && m_Timer - (176.442108 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (176.859146 ) > 0 && m_Timer - (176.859146 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (177.092163 ) > 0 && m_Timer - (177.092163 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (177.343201 ) > 0 && m_Timer - (177.343201 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (177.576233 ) > 0 && m_Timer - (177.576233 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (177.792252 ) > 0 && m_Timer - (177.792252 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (178.025269 ) > 0 && m_Timer - (178.025269 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (178.442307 ) > 0 && m_Timer - (178.442307 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (178.876373 ) > 0 && m_Timer - (178.876373 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (179.109406 ) > 0 && m_Timer - (179.109406 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (179.625458 ) > 0 && m_Timer - (179.625458 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (179.843460 ) > 0 && m_Timer - (179.843460 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (180.642593 ) > 0 && m_Timer - (180.642593 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (180.842621 ) > 0 && m_Timer - (180.842621 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (181.143661 ) > 0 && m_Timer - (181.143661 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (181.558716 ) > 0 && m_Timer - (181.558716 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (181.775757 ) > 0 && m_Timer - (181.775757 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (182.075775 ) > 0 && m_Timer - (182.075775 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (182.292801 ) > 0 && m_Timer - (182.292801 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (182.492828 ) > 0 && m_Timer - (182.492828 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (182.725861 ) > 0 && m_Timer - (182.725861 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (183.142960 ) > 0 && m_Timer - (183.142960 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (183.626053 ) > 0 && m_Timer - (183.626053 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (183.843094 ) > 0 && m_Timer - (183.843094 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (184.359131 ) > 0 && m_Timer - (184.359131 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (184.593170 ) > 0 && m_Timer - (184.593170 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (184.810181 ) > 0 && m_Timer - (184.810181 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (185.010193 ) > 0 && m_Timer - (185.010193 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (185.227203 ) > 0 && m_Timer - (185.227203 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (185.443237 ) > 0 && m_Timer - (185.443237 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (185.676270 ) > 0 && m_Timer - (185.676270 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (186.010284 ) > 0 && m_Timer - (186.010284 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (186.459320 ) > 0 && m_Timer - (186.459320 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (186.692337 ) > 0 && m_Timer - (186.692337 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (187.193375 ) > 0 && m_Timer - (187.193375 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (187.410400 ) > 0 && m_Timer - (187.410400 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (188.810608 ) > 0 && m_Timer - (188.810608 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (189.593735 ) > 0 && m_Timer - (189.593735 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (191.392975 ) > 0 && m_Timer - (191.392975 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (193.311234 ) > 0 && m_Timer - (193.311234 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (195.145523 ) > 0 && m_Timer - (195.145523 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (197.060806 ) > 0 && m_Timer - (197.060806 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (198.795029 ) > 0 && m_Timer - (198.795029 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
	if (m_Timer - (200.761292 ) > 0 && m_Timer - (200.761292 ) <= dt)
	{
		ObjMgr->AddObject(new Bullet(L"Square", Vec2(1920, randY), 180, 1, 1200, Shape::SQUARE), "Obstacle");
	}
}

