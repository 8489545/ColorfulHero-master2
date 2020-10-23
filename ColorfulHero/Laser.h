#pragma once
class Laser : public Obstacle
{
	Sprite* m_Obj;

	LineMgr* m_Line;
public:
	Laser(Vec2 startPos,float rotation,float weight,float aliveTime,float appearTime,bool spin,float spinSpeed);
	~Laser();

	Vec2 m_StartPos;
	
	float m_FirstRot;
	float m_Weight;
	float m_AliveTime;
	float m_AppearTime;
	float m_SpinTime;
	float m_SpinSpeed;

	float m_Timer;

	bool m_isSpin;

	void Update(float deltaTime, float time);
	void Render();
};

