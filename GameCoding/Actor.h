#pragma once
class Actor
{
public:
	Actor();
	virtual ~Actor();

	virtual void BeginPlay();
	virtual void Tick();

	virtual void Render(HDC hdc);
	void SetPos(Vec2 pos) { _pos = pos; }
	Vec2 GetPos() { return _pos; }
	// 모든 액터가 스프라이트를 가지고 있지 않음

	Vec2 _pos = { 0,0 };

};

