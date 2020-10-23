#pragma once
class SawBlade : public Obstacle
{
	Sprite* m_Obj;
	LineMgr* m_Line;
public:
	SawBlade(std::wstring name,Vec2 startPos,Vec2 arrivePos,float scale,float speed,float removeTime,Movement move);
	~SawBlade();

	Vec2 a[360];

	float m_RemoveTime;
	float m_AliveTime;
	float m_ScaleRatio;

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

