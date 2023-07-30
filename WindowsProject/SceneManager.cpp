#include "pch.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "DevScene.h"
void SceneManager::Init()
{

}

void SceneManager::Update()
{
	if (_scene)
		_scene->Update();
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
		_scene->Render(hdc);
}

void SceneManager::Clear()
{
	SAFE_DELETE(_scene);
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType) return;
	Scene* newScene = nullptr;
	switch (sceneType)
	{
	case SceneType::DevScene:
		newScene = new DevScene();
		break;
	case SceneType::GameScene:
		newScene = new GameScene();
		break;
	}
	// 씬이 존재하면 없애주고 새로운 씬으로 교체
	// 널체크, 삭제, 널로 밀어주기( SAFE DELETE macro)
	if (_scene)
	{
		delete _scene;
		_scene = nullptr;
	}
	_scene = newScene;
	_sceneType = sceneType;

	newScene->Init();
}
