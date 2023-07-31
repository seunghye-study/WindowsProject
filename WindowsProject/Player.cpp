#include "pch.h"
#include "Player.h"
#include "Utils.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Missile.h"

Player::Player()
{

}

Player::~Player()
{
}

void Player::Init()
{
	// todo : data
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 500;

	_pos.x = 400;
	_pos.y = 500;
}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	// �Ÿ� = �ð�*�ӵ�
	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= _stat.speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_pos.x += _stat.speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_pos.y -= _stat.speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_pos.y += _stat.speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		//TODO : �̻��� �߻�
		Missile* misssile = new Missile();
		// �̻����� ��� ���� ��ġ�� ���ΰ�?
		// ��� ���� ��ġ�ϴ°� ���� ȿ�����ΰ�?

	}
}

void Player::Render(HDC hdc)
{
}