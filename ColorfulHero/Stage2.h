#pragma once
class Stage2 : public Scene
{
	Sprite* m_BG;
	Sprite* m_Filter;
	Sprite* m_Tutorial;
public:

	Stage2();
	~Stage2();

	float m_RandX;
	float m_RandY;
	float m_Timer;
	bool change;
	COLOR m_NowColor;
	COLOR m_PrevColor;

	void Init();
	void Release();

	void SetColor(COLOR color);

	void SyncTime(float time);

	void Update(float deltaTime, float time);
	void Render();

	void SyncColor();
};

