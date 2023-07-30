#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"

Game::Game()
{
	// memory Leak
	// new delete
	// new�Ҷ� �޸� ����� �����س��� üũ

}

Game::~Game()
{
	// �޸� ���� Ȯ��, �������� �߰��ϸ� ��
	_CrtDumpMemoryLeaks();
}

void Game::init(HWND hwnd)
{
	// �ʱ�ȭ
	_hwnd = hwnd;
	_hdc = ::GetDC(hwnd);

	GET_SINGLE(TimeManager)->init();
	GET_SINGLE(InputManager)->init(hwnd);
}

void Game::Update()
{
	// frame ���
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	// C++20 : Format

	// mousePosition
	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"MOUSE ( x : {0}, y : {1} )", mousePos.x, mousePos.y);
		::TextOut(_hdc, 20, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	// fps update
	{
		wstring str = std::format(L"FPS ( {0} ), DT ( {1} MS )", fps, static_cast<int32>(deltaTime * 10000));
		::TextOut(_hdc, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	::Rectangle(_hdc, 200, 200, 400, 400);
}
