#pragma once
class Stage1 : public Scene
{
	Sprite* m_BG;
	Sprite* m_Filter;
	Sprite* m_Tutorial;

	Sprite* m_Ceil;
	Sprite* m_Floor;
public:
	Stage1();
	~Stage1();

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

	void PattenOne();
	void PattenTwo();
	void PattenThree();
};

