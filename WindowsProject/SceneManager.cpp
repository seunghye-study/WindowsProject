#include "pch.h"
#include "SceneManager.h"

void SceneManager::Init()
{

}

void SceneManager::Update()
{

}

void SceneManager::Render(HDC hdc)
{

}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType) return;
	Scene* newScene = nullptr;
	switch (sceneType)
	{
	case SceneType::DevScene:
		break;
	case SceneType::GameScene:
		break;
	default:
		break;
	}
}
