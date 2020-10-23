#pragma once
enum class COLOR
{
	RED,
	BLUE,
	GREEN,
	NONE
};
class GameMgr : public Singleton<GameMgr>
{
public:
	GameMgr();
	~GameMgr();

	struct Stage
	{
		int StageNum;
		int Percent;
	};

	std::vector<Stage*> m_Stages;

	void InputPercent(int stageNum, int percent);
	
	int GetStagePercentage(int stageNum);
};

