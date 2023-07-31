#include "pch.h"
#include "GameScene.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	/*_player = new Player();
	_player->Init();*/

	Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
	player->setPos(Pos{ 400, 400 });
	GET_SINGLE(ObjectManager)->Add(player);

	for (int32 i = 0; i < 5; i++)
	{
		Monster* monster = GET_SINGLE(ObjectManager)->CreateObject<Monster>();
		monster->setPos(Pos{ static_cast<float>(i+1)*100, 100});
		GET_SINGLE(ObjectManager)->Add(monster);
	}
}

void GameScene::Update()
{
	/*if (_player)
		_player->Update();*/

	// ¿Ö ¿À·ù ??
	const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		object->Update();
	}
}

void GameScene::Render(HDC hdc)
{
	/*if (_player)
		_player->Render(hdc);*/
	const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();
}
