#include "stdafx.h"
#include "Stage2.h"
#include"Player.h"
#include"ProgressBar.h"
#include"SawBlade.h"
#include"Bomb.h"
#include "Bullet.h"
#include"Laser.h"
#include"StageSelect.h"

Stage2::Stage2()
{
}

Stage2::~Stage2()
{
}

void Stage2::Init()
{
	SoundMgr::GetInst()->Stop();
	m_BG = Sprite::Create(L"Painting/BG/BG.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	m_Filter = Sprite::Create(L"Painting/BG/Filter.png");
	m_Filter->SetPosition(1920 / 2, 1080 / 2);

	m_Filter->A = 200;
	m_Filter->color = COLOR::NONE;

	ObjMgr->AddObject(m_BG, "BG");
	ObjMgr->AddObject(m_Filter, "Filter");

	m_PrevColor = COLOR::RED;

	SoundMgr::GetInst()->Play(L"Jumper2.wav", false);
	m_Timer = 0.0f;

	ObjMgr->AddObject(new Player(), "Player");
	ObjMgr->AddObject(new ProgressBar(224.f), "UI");

	m_Filter->color = COLOR::NONE;
}

void Stage2::Release()
{
	ObjMgr->RemoveObject(m_BG);
	ObjMgr->RemoveObject(m_Filter);
	ObjMgr->DeleteObject("UI");
	ObjMgr->DeleteObject("Player");
	ObjMgr->DeleteObject("Obstacle");
	ObjMgr->DeleteObject("Effect");
	GameMgr::GetInst()->InputPercent(2, (m_Timer / 224.f) * 100);
	SoundMgr::GetInst()->Stop();
}

void Stage2::SetColor(COLOR color)
{
	if (color == COLOR::RED)
	{
		m_Filter->SetColor(200, 255, 54, 40, 15);
		m_Filter->color = COLOR::RED;
		if (m_Filter->A == 128 && m_Filter->R == 255 && m_Filter->G == 54 && m_Filter->B == 40)
		{
			change = false;
		}
	}
	if (color == COLOR::GREEN)
	{
		m_Filter->SetColor(200, 40, 255, 54, 15);
		m_Filter->color = COLOR::GREEN;
		if (m_Filter->A == 128 && m_Filter->R == 40 && m_Filter->G == 255 && m_Filter->B == 54)
		{
			change = false;
		}
	}
	if (color == COLOR::BLUE)
	{
		m_Filter->SetColor(200, 54, 50, 255, 15);
		m_Filter->color = COLOR::BLUE;
		if (m_Filter->A == 128 && m_Filter->R == 54 && m_Filter->G == 50 && m_Filter->B == 255)
		{
			change = false;
		}
	}
}

void Stage2::SyncTime(float time)
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

void Stage2::Update(float deltaTime, float time)
{
	m_RandX = rand() % 1920;
	m_RandY = rand() % 1080;
	m_Timer += dt;
	if (change)
	{
		SetColor(m_NowColor);
	}

	if (INPUT->GetKey(VK_SPACE) == KeyState::DOWN)
		printf("SyncTime(%f);\n", m_Timer);
	//	printf("if(m_Timer - (%f - 1.f) > 0 && m_Timer - (%f -1.f) <= dt)\n{\n\n}\n", m_Timer,m_Timer);

	SyncColor();

	if (m_Timer >= 224.f)
	{
		Release();
		Camera::GetInst()->Init();
		SceneDirector::GetInst()->ChangeScene(new StageSelect());
	}
}

void Stage2::Render()
{
}

void Stage2::SyncColor()
{
	SyncTime(12.380995);
	SyncTime(15.380986);
	SyncTime(18.363993);
	SyncTime(21.383011);
	SyncTime(24.450031);
	SyncTime(27.214046);
	SyncTime(30.232067);
	SyncTime(33.297031);
	SyncTime(36.315922);
	SyncTime(39.313789);
	SyncTime(42.313694);
	SyncTime(45.348587);
	SyncTime(48.364487);
	SyncTime(49.913445);
	SyncTime(51.463387);
	SyncTime(52.913342);
	SyncTime(54.446297);
	SyncTime(55.897232);
	SyncTime(57.362186);
	SyncTime(58.962147);
	SyncTime(60.462097);
	SyncTime(61.979065);
	SyncTime(63.429020);
	SyncTime(64.944923);
	SyncTime(66.445786);
	SyncTime(68.013641);
	SyncTime(69.445511);
	SyncTime(70.995369);
	SyncTime(72.461235);
	SyncTime(74.079086);
	SyncTime(75.544952);
	SyncTime(77.078812);
	SyncTime(78.559677);
	SyncTime(80.058540);
	SyncTime(81.542404);
	SyncTime(83.059265);
	SyncTime(87.643845);
	SyncTime(89.191704);
	SyncTime(92.141434);
	SyncTime(93.692291);
	SyncTime(95.207153);
	SyncTime(96.725014);
	SyncTime(99.708740);
	SyncTime(101.224602);
	SyncTime(102.742462);
	SyncTime(104.256325);
	SyncTime(105.740189);
	SyncTime(108.756912);
	SyncTime(114.807358);
	SyncTime(120.837807);
	SyncTime(123.853531);
	SyncTime(126.871254);
	SyncTime(129.854446);
	SyncTime(132.920044);
	SyncTime(134.406250);
	SyncTime(135.888489);
	SyncTime(137.407776);
	SyncTime(138.922058);
	SyncTime(140.438278);
	SyncTime(141.973511);
	SyncTime(143.523758);
	SyncTime(145.006973);
	SyncTime(146.490250);
	SyncTime(147.990433);
	SyncTime(149.507675);
	SyncTime(151.055923);
	SyncTime(152.525162);
	SyncTime(154.023392);
	SyncTime(155.575684);
	SyncTime(157.124954);
	SyncTime(158.607193);
	SyncTime(160.091415);
	SyncTime(161.540649);
	SyncTime(163.190948);
	SyncTime(164.559158);
	SyncTime(166.092453);
	SyncTime(167.625732);
	SyncTime(172.142517);
	SyncTime(175.226044);
	SyncTime(178.159592);
	SyncTime(181.228149);
	SyncTime(184.276566);
	SyncTime(187.211914);
	SyncTime(190.246277);
	SyncTime(193.295746);
	SyncTime(196.328247);
	SyncTime(199.262741);
	SyncTime(202.279236);
	SyncTime(205.396820);
	SyncTime(208.415283);
	SyncTime(211.364792);
	SyncTime(214.349319);
	SyncTime(217.430847);
}
