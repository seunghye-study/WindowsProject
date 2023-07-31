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

	//TODO: �浹
	// �浹�ϸ� ����, ������ ����� ���� ��
	// �����ؼ� �ؾ���

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
			// ��������?
			GET_SINGLE(ObjectManager)->Remove(object);
			GET_SINGLE(ObjectManager)->Remove(this);
			return;
		}
	}

	if (_pos.y < -200)
	{
		// �̷��� ������ �ϸ� return�� ���� �� ����� ���������ΰ�?
		// ������ ���� ���̿� ������ ��ü�� ���� ������ �ǵ帮�� ���� ������ �ȵȴ�
		// �Ѿ�� �ϰ����� �޸� ������ �߻���
		// 
		GET_SINGLE(ObjectManager)->Remove(this);
		return;
	}
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}