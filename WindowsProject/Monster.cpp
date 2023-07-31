#include "pch.h"
#include "Monster.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::Init()
{
	//TODO :
}

void Monster::Update()
{
}

void Monster::Render(HDC hdc)
{
	Utils::DrawRect(hdc, _pos, 50, 50);
}
