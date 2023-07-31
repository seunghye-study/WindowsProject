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
	// 거리 = 시간*속도
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
		//TODO : 미사일 발사
		Missile* misssile = new Missile();
		// 미사일을 어떻게 씬에 배치할 것인가?
		// 어디 씬에 배치하는게 제일 효율적인가?

	}
}

void Player::Render(HDC hdc)
{
}
