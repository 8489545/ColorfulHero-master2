#pragma once
struct Equalizer
{
	int Line;
	int Power;
};
class MainScene : public Scene
{
	Sprite* m_BG;
	
	Sprite* m_Title;
	Sprite* m_Start;
	Sprite* m_Exit;

	Sprite* m_Bars[5][6];

	std::vector<Equalizer*> m_EQ;
public:
	MainScene();
	~MainScene();

	float m_Timer;
	float m_ChangePowerTime;

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();

	void SetEQ();
};

