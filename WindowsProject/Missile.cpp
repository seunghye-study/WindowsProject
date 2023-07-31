#include "pch.h"
#include "Missile.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ObjectManager.h"

Missile::Missile()
{
}

Missile::~Missile()
{
}

void Missile::Init()
{
	// todo
	_stat.hp = 1;
	_stat.maxHp = 1;
	_stat.speed = 600;
}

void Missile::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	_pos.y -= deltaTime * _stat.speed;

	//TODO: 충돌
	// 충돌하면 삭제, 범위를 벗어나면 삭제 등
	// 주의해서 해야함

	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object == this) continue;
		if (object->GetObjectType() != ObjectType::Monster) continue;

		Pos p1 = GetPos();
		Pos p2 = object->GetPos();

		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;
		float dist = sqrt(dx * dx + dy + dy);
		if (dist < 25)
		{
			// 괜찮을까?
			GET_SINGLE(ObjectManager)->Remove(object);
			GET_SINGLE(ObjectManager)->Remove(this);
			return;
		}
	}

	if (_pos.y < -200)
	{
		// 이렇게 삭제를 하면 return을 했을 때 어떤일이 벌어질것인가?
		// 삭제와 리턴 사이에 삭제된 객체에 대한 정보를 건드리는 일을 넣으면 안된다
		// 넘어가긴 하겠지만 메모리 오염이 발생함
		// 
		GET_SINGLE(ObjectManager)->Remove(this);
		return;
	}
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}
