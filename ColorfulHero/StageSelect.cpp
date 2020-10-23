#include "stdafx.h"
#include "StageSelect.h"
#include "Stage1.h"
#include "Stage2.h"

StageSelect::StageSelect()
{
}

StageSelect::~StageSelect()
{
}

void StageSelect::Init()
{
	SoundMgr::GetInst()->Play(L"Body_Jammer.wav", true);
	m_BG = Sprite::Create(L"Painting/BG/StageSelect.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	m_NowStageNum = 1;

	PushStage(L"Stage1.png", 1);
	PushStage(L"Stage2.png", 2);

	LoadStage();
}

void StageSelect::Release()
{
}

void StageSelect::PushStage(std::wstring filename, int num)
{
	Stage* stage = new Stage;
	stage->FileName = L"Painting/UI/Songs/" + filename;
	stage->Num = num;

	m_Stages.push_back(stage);
}

void StageSelect::LoadStage()
{
	m_NowStage = Sprite::Create(GetStageName(m_NowStageNum));
	m_NowStage->SetPosition(1920 / 2, 1080 / 2);

	m_PrevStage = Sprite::Create(GetStageName(m_NowStageNum - 1));
	m_PrevStage->SetPosition(300, 1080 / 2);
	m_PrevStage->SetScale(0.75, 0.75);

	m_NextStage = Sprite::Create(GetStageName(m_NowStageNum + 1));
	m_NextStage->SetPosition(1620, 1080 / 2);
	m_NextStage->SetScale(0.75, 0.75);

	m_Percentage = new TextMgr();
	m_Percentage->Init(64, true, false, "Mathematical");
	m_Percentage->SetColor(255, 255, 255, 255);

	if (GetStageName(m_NowStageNum - 1) == m_EmptyStage)
		m_isPrev = false;
	else
		m_isPrev = true;

	if (GetStageName(m_NowStageNum + 1) == m_EmptyStage)
		m_isNext = false;
	else
		m_isNext = true;
}

std::wstring StageSelect::GetStageName(int num)
{
	for (auto& iter : m_Stages)
	{
		if (iter->Num == num)
		{
			return m_Stages.at(num - 1)->FileName;
		}
	}
	m_EmptyStage = L"Painting/UI/Songs/NoStage.png";
	return m_EmptyStage;
}

void StageSelect::Update(float deltaTime, float time)
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(m_NowStage) && INPUT->GetButtonDown())
	{
		switch (m_NowStageNum)
		{
		case 1:
			SceneDirector::GetInst()->ChangeScene(new Stage1());
			break;
		case 2:
			SceneDirector::GetInst()->ChangeScene(new Stage2());
			break;
		default:
			break;
		}
		INPUT->ButtonDown(false);
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_PrevStage) && INPUT->GetButtonDown() && m_isPrev)
	{
		m_NowStageNum -= 1;
		LoadStage();
		INPUT->ButtonDown(false);
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_NextStage) && INPUT->GetButtonDown() && m_isNext)
	{
		m_NowStageNum += 1;
		LoadStage();
		INPUT->ButtonDown(false);
	}
}

void StageSelect::Render()
{
	m_BG->Render();
	m_NowStage->Render();
	m_PrevStage->Render();
	m_NextStage->Render();

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Percentage->print(std::to_string(GameMgr::GetInst()->GetStagePercentage(m_NowStageNum)) + "%", 1920 / 2, 600);
	Renderer::GetInst()->GetSprite()->End();

}
