#pragma once
enum class Movement
{
	FIXED,
	THROW,
	STRAIGHT
};
class Obstacle : public Object
{
public:
	Obstacle();
	~Obstacle();

	Vec2 m_StartPos;
	Vec2 m_ArrivePos;
	float m_Speed;
	float m_Velocity;
	float m_Time;
	Movement m_Move;

	virtual void Update(float deltaTime, float time);
	virtual void Render();

	void Throw(Obstacle* obj);
	void Straight(Obstacle* obj);
};

