#pragma once
class StageSelect : public Scene
{
	Sprite* m_BG;
	Sprite* m_NowStage;
	Sprite* m_PrevStage;
	Sprite* m_NextStage;
	TextMgr* m_Percentage;

	struct Stage
	{
		std::wstring FileName;
		int Num;
	};

	std::vector<Stage*> m_Stages;
public:
	StageSelect();
	~StageSelect();

	int m_NowStageNum;
	std::wstring m_EmptyStage;

	bool m_isPrev;
	bool m_isNext;

	void Init();
	void Release();
	void PushStage(std::wstring filename,int num);
	void LoadStage();
	std::wstring GetStageName(int num);

	void Update(float deltaTime, float time);
	void Render();
};

