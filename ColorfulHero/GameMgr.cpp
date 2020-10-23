#include "stdafx.h"
#include "GameMgr.h"

GameMgr::GameMgr()
{
}

GameMgr::~GameMgr()
{
}

void GameMgr::InputPercent(int stageNum, int percent)
{
	if (m_Stages.size() == 0)
	{
		Stage* stage = new Stage();

		stage->Percent = percent;
		stage->StageNum = stageNum;

		m_Stages.push_back(stage);
	}
	for (auto& iter : m_Stages)
	{
		if (iter->StageNum == stageNum && iter->Percent <= percent)
		{
			iter->Percent = percent;
			iter->StageNum = stageNum;
		}
		else
		{
			Stage* stage = new Stage();

			stage->Percent = percent;
			stage->StageNum = stageNum;

			m_Stages.push_back(stage);
		}
	}
}

int GameMgr::GetStagePercentage(int stageNum)
{
	for (auto& iter : m_Stages)
	{
		if (iter->StageNum == stageNum)
		{
			return iter->Percent;
		}
	}
	return 0;
}
