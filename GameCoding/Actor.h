#pragma once
#include "Component.h"


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

	void SetLayerType(LAYER_TYPE layer) { _layer = layer; }
	LAYER_TYPE GetLayerType() { return _layer; }
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);
	// 모든 액터가 스프라이트를 가지고 있지 않음
protected:
	Vec2 _pos = { 0,0 };

	LAYER_TYPE _layer = LAYER_OBJECT;
	vector<Component*> _components;

};

