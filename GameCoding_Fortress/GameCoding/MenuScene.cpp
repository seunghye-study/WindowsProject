#include "pch.h"
#include "MenuScene.h"
#include "LineMesh.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "SceneManager.h"

MenuScene::MenuScene()
{

}

MenuScene::~MenuScene()
{

}

void MenuScene::Init()
{

}

void MenuScene::Update()
{
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::E))
	{
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::FortressScene);
	}
}

void MenuScene::Render(HDC hdc)
{
	::Rectangle(hdc, 0, 0, GWinSizeX, GWinSizeY);

	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(L"Menu");
	if (mesh)
		mesh->Render(hdc, Pos{0, 0});

	HFONT myFont = ::CreateFont(
		30						// ����
		, 0						// �� 0�̸� ���̿� ���
		, 0						// ���� ��ü ����
		, 0						// ���ؼ��� ������ ����
		, 0						// ��Ʈ�� �β�
		, 0						// ���Ÿ�
		, 0						// ����
		, 0						// ��Ҽ�
		, DEFAULT_CHARSET		// �ɸ��� ��
		, 0						// ���е�
		, 0						// ���е�
		, 0						// ���е�
		, 0						// ���е�
		, L"�ü�ü"				// �۲��̸�
	);

	HFONT oldFont = (HFONT)::SelectObject(hdc, myFont);

	wstring message = L"PRESS 'E' TO START.";
	::TextOut(hdc, 250, 550, message.c_str(), static_cast<int32>(message.size()));

	::SelectObject(hdc, oldFont);
	::DeleteObject(myFont);
}
