#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Missile.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "LineMesh.h"

Player::Player() : Object(ObjectType::Player) // �ʱ�ȭ
{

}

Player::~Player()
{

}

void Player::Init()
{
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 10000000;
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
		Missile* missile = new Missile();
		missile->setPos(_pos);
		GET_SINGLE(ObjectManager)->Add(missile);
	}
}

void Player::Render(HDC hdc)
{
	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(L"Player");
	if (mesh)
		mesh->Render(hdc, _pos);
}
