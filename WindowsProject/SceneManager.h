#pragma once

// �� �Ŵ����� ��������
// ���� �������ϱ� �����Ϸ���?? 
// �� �ȿ��� ���� �� �����Ϸ��� .. �ϵ��ڵ��� ���� �� ����
// �� �Ŵ����� ������
// �������� ���� ���� �����ϵ� �ٲ㰡�� ������ �� ����
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

