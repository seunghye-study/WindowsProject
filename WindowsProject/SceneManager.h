#pragma once

// 씬 매니저의 존재이유
// 씬이 여러개니까 관리하려고?? 
// 씬 안에서 씬을 또 관리하려면 .. 하드코딩이 답일 수 있음
// 씬 매니저가 있으면
// 여러개의 씬을 몬스터 관리하듯 바꿔가며 관리할 수 있음
class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Update();
	void Render(HDC hdc);
public:
	void ChangeScene(SceneType sceneType);
private:
	class Scene* _scene;
	SceneType _sceneType = SceneType::None;
};

