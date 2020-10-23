#pragma once
class CollisionMgr : public Singleton<CollisionMgr>
{
public:
	CollisionMgr();
	~CollisionMgr();

	bool MouseWithBoxSize(Object* obj);
	
	bool CircleToCircle(Vec2 Pos1, float r1, Vec2 Pos2, float r2);
	bool CircleToSquare(Vec2 CPos,float r1,RECT* rc);

	bool PointToSquare(Vec2 point, RECT* rc);
	bool PointToCircle(Vec2 CPos, float r,Vec2 point);

	bool LineToLine(Vec2 FPos1, Vec2 FPos2, Vec2 SPos1, Vec2 SPos2);
};

