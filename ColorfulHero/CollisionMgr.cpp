#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}

bool CollisionMgr::MouseWithBoxSize(Object* obj)
{
	Vec2 Mouse = INPUT->GetMousePos();
	if (Mouse.x > obj->m_Position.x - obj->m_Size.x
		&& Mouse.x < obj->m_Position.x + obj->m_Size.x / 2
		&& Mouse.y > obj->m_Position.y - obj->m_Size.y
		&& Mouse.y < obj->m_Position.y + obj->m_Size.y / 2)
	{
		return true;
	}

	return false;
}

bool CollisionMgr::CircleToCircle(Vec2 Pos1, float r1, Vec2 Pos2, float r2)
{
	float X = Pos1.x - Pos2.x;
	float Y = Pos1.y - Pos2.y;

	float dis = sqrt(X * X + Y * Y);

	if (dis > (r1 + r2))
		return true;

	return false;
}

bool CollisionMgr::CircleToSquare(Vec2 CPos, float r1,RECT* rc)
{
	RECT rcex =
	{
		rc->left - r1,
		rc->top - r1,
		rc->right + r1,
		rc->bottom + r1
	};

	if ((rc->left <= CPos.x && CPos.x <= rc->right) ||
		(rc->top <= CPos.y && CPos.y <= rc->bottom))
	{

		if ((rcex.left < CPos.x && CPos.x < rcex.right) || (rcex.top < CPos.y && CPos.y && rcex.bottom < rcex.bottom))
			return true;

	}
	else
	{
		if(PointToCircle(CPos, r1,Vec2(rcex.left,rcex.top))) return true;
		if(PointToCircle(CPos, r1,Vec2(rcex.left,rcex.bottom))) return true;

		if(PointToCircle(CPos, r1,Vec2(rcex.right,rcex.top))) return true;
		if(PointToCircle(CPos, r1,Vec2(rcex.right,rcex.bottom))) return true;
	}

	return false;
}

bool CollisionMgr::PointToSquare(Vec2 point, RECT* rc)
{
	if ((rc->left <= point.x && point.x <= rc->right) && (rc->top <= point.y && point.y <= rc->bottom))
		return true;

	return false;
}

bool CollisionMgr::PointToCircle(Vec2 CPos, float r, Vec2 point)
{
	float X = CPos.x - point.x;
	float Y = CPos.y - point.y;

	float dis = sqrt(X * X + Y * Y);

	if (dis > r)
		return false;

	return true;
}

bool CollisionMgr::LineToLine(Vec2 FPos1, Vec2 FPos2, Vec2 SPos1, Vec2 SPos2)
{
	float den;
	float CondA;
	float CondB;

	den = (SPos2.y, -SPos1.y) * (FPos2.x - FPos1.x) - (SPos2.x - SPos1.x) * (FPos2.y - FPos1.y);

	if (den == 0)
		return false;


	CondA = ((SPos2.x - SPos1.x) * (FPos1.y - SPos1.y) - (SPos2.y - SPos1.y) * (FPos1.x - SPos1.x)) / den;

	CondB = ((FPos2.x - FPos1.x) * (FPos1.y - SPos1.y) - (FPos2.y - FPos1.y) * (FPos1.x - SPos1.x)) / den;

	if (CondA < 0.f || CondA > 1.f || CondB < 0.f || CondB > 1.f)
		return false;


	return true;
}
