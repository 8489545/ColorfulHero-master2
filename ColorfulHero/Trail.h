#pragma once
class Trail : public Object
{
	Sprite* m_Obj;
public:
	Trail(Vec2 Pos);
	~Trail();

	float timer;

	void Update(float deltaTime, float Time);
	void Render();
};

