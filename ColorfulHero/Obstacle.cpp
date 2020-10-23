#include "stdafx.h"
#include "Obstacle.h"

Obstacle::Obstacle() 
	:m_ArrivePos(0, 0)
	,m_StartPos(0, 0)
	,m_Speed(0)
	,m_Velocity(0)
	,m_Time(0)
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::Update(float deltaTime, float time)
{
}

void Obstacle::Render()
{
}

void Obstacle::Throw(Obstacle* obj)
{
	Vec2 Direction = obj->m_ArrivePos - obj->m_StartPos;

	Vec2 NorDir;

	D3DXVec2Normalize(&NorDir, &Direction);


	obj->m_Velocity = (obj->m_Speed / 10) * obj->m_Time;
	if (m_Velocity <= 0)
		m_Velocity = 10.f;

	float dis = sqrt(pow((obj->m_Position.x - obj->m_ArrivePos.x), 2) + pow(obj->m_Position.y - obj->m_ArrivePos.y, 2));
	if (dis >= 30)
		Translate(NorDir.x * obj->m_Velocity * dt, NorDir.y * obj->m_Velocity * dt);
}

void Obstacle::Straight(Obstacle* obj)
{
	Vec2 Direction = obj->m_ArrivePos - obj->m_StartPos;

	Vec2 NorDir;

	D3DXVec2Normalize(&NorDir, &Direction);

	Translate(NorDir.x * obj->m_Speed * dt, NorDir.y * obj->m_Speed * dt);

}
