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
	Object(ObjectType type);
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

public:
	ObjectType GetObjectType() { return _type; }

	Pos GetPos() { return _pos; }
	void setPos(Pos pos) { _pos = pos; }

protected:
	ObjectType		_type = ObjectType::None;
	Stat			_stat = {};
	Pos				_pos = {};
	
};

