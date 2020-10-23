#pragma once
class ProgressBar : public Object
{
	Sprite* m_Outline;
	Sprite* m_Bar;
public:
	ProgressBar(float endTime);
	~ProgressBar();

	float m_EndTime;
	float m_NowTime;
	float m_ProgressGage;

	void Update(float deltaTime, float Time);
	void Render();
};

