#include "pch.h"
#include "FortressScene.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "LineMesh.h"
#include "ObjectManager.h"
#include "Player.h"
#include "UIManager.h"

FortressScene::FortressScene()
{
}

FortressScene::~FortressScene()
{
}

void FortressScene::Init()
{
	GET_SINGLE(UIManager)->Init();

	// �÷��̾� ����
	{
		Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPlayerType(PlayerType::MissileTank);
		player->SetPlayerId(0);
		GET_SINGLE(ObjectManager)->Add(player);

		player->SetPos(Vector{100, 400});
		player->SetPlayerTurn(true);
	}

	{
		Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPlayerType(PlayerType::CannonTank);
		player->SetPlayerId(1);
		GET_SINGLE(ObjectManager)->Add(player);

		player->SetPos(Vector{ 700, 400 });
		player->SetPlayerTurn(false);
	}

	_playerTurn = 1;
	ChangePlayerTurn();
}

void FortressScene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	// ������Ʈ ����
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
		object->Update();

	// �ð� ����
	_sumTime += deltaTime;
	if (_sumTime >= 1.f)
	{
		_sumTime = 0.f;

		int32 time = GET_SINGLE(UIManager)->GetRemainTime();
		time = max(0, time - 1);
		GET_SINGLE(UIManager)->SetRemainTime(time);

		if (time == 0)
			ChangePlayerTurn();
	}
}

void FortressScene::Render(HDC hdc)
{
	// Scene
	//_mapLines->Render(hdc, Pos{0, 0});

	// Objects
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
		object->Render(hdc);
	
	// UI
	GET_SINGLE(UIManager)->Render(hdc);
}

void FortressScene::ChangePlayerTurn()
{
	_playerTurn = (_playerTurn + 1) % MAX_PLAYERS;

	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object->GetObjectType() != ObjectType::Player)
			continue;

		Player* player = static_cast<Player*>(object);
		if (player->GetPlayerId() == _playerTurn)
			player->SetPlayerTurn(true);
		else
			player->SetPlayerTurn(false);
	}

	GET_SINGLE(UIManager)->SetRemainTime(10);
	GET_SINGLE(UIManager)->SetStaminaPercent(100.f);
	GET_SINGLE(UIManager)->SetPowerPercent(0.f);
	GET_SINGLE(UIManager)->SetWindPercent(static_cast<float>(-100 + rand() % 200));
}
