#pragma once
class Bomb : public Obstacle
{
	Sprite* m_Obj;
public:
	Bomb(Vec2 startPos, Vec2 arrivePos, float scale, int bulletNum, float speed,float bulletSpeed,float bombTime, Movement move);
	~Bomb();

	float m_Radius;
	int m_BulletNum;
	float m_BulletSpeed;
	float m_BombTime;
	float m_ScaleRatio;
	float m_BombTimer;

	void Remove();

	void Update(float deltaTime, float time);
	void Render();
};

