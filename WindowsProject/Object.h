#pragma once

enum class ObjectType
{
	None,
	Player,
	Monster,
	Projectile,
};

class Object
{
public:
	Object();
	Object(ObjectType type);
	virtual ~Object();

public:
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

public:
	ObjectType GetObjectType() { return _type; }
	Pos GetPos() { return _pos; }
	void setPos(Pos pos) { _pos = pos; }
protected:
	ObjectType _type = ObjectType::None;
	Pos _pos = {};
	Stat _stat = {};
};

