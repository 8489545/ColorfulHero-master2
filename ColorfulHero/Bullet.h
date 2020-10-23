#pragma once
class Bullet : public Obstacle
{
	Sprite* m_Obj;
public:
	Bullet(std::wstring name, Vec2 Pos, float Rotation, float scale,float speed, Shape shape);
	~Bullet();

	Vec2 m_Dire;
	float m_ScaleRatio;

	void Update(float deltaTime,float time);
	void Render();
	void OnCollision(Object* other);
};

