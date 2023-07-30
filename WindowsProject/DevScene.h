#pragma once
#include "Scene.h"

class DevScene : public Scene
{
public:
	DevScene();
	virtual ~DevScene() override;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

public:
	// test
	Pos _playerPos = { 300,300 };
	float _speed = 10000000;
};

