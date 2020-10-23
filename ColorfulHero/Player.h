#pragma once
class Player : public Object
{
	Sprite* m_Obj;
	Sprite* m_Outline;

	Animation* m_Guard;
	

	LineMgr* m_Line;
	LineMgr* m_Line2;

public:
	Player();
	~Player();

	float m_Speed;
	float m_DashTime;
	float m_Timer;
	float m_Timer2;
	float m_DashCooltime;
	float m_GameOverTime;
	float m_ColorChangeTime;

	bool m_Dash;
	bool m_GuardOn;

	Vec2 m_PrevPos;
	Vec2 a[360];

	void Move();
	void Dash();
	void ChangeColor();
	void SetVertex();

	void Update(float deltaTime, float time);
	void Render();
	void OnCollision(Object* other);
};

