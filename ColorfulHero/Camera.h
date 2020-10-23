#pragma once
class Camera : public Singleton<Camera>
{
private:
	Matrix mRot;
	Matrix mTrans;
	Matrix mScale;
	Matrix mWorld;
public:
	Camera();
	~Camera();


	float m_Rotation;
	Vec2 m_Position;
	Vec2 m_Scale;
	bool m_MovingMode;
	bool m_Limit;

	Vec2 m_MaxPos;
	Vec2 m_MinPos;


	Matrix GetWorld()
	{
		return mWorld;
	}

	void Init();
	void Translate();
	void Follow(Object* obj);
	void Zoom();
	void Update(float deltaTime, float time);
	void Render();
};
