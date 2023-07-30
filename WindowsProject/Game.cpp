#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Game::Game()
{
	// memory Leak
	// new delete
	// new할때 메모리 사이즈를 기입해놓고 체크
}

Game::~Game()
{
	// 메모리 누수 확인, 마지막에 추가하면 됨
	GET_SINGLE(SceneManager)->Clear();
	_CrtDumpMemoryLeaks();
}

void Game::init(HWND hwnd)
{
	// 초기화
	_hwnd = hwnd;
	_hdc = ::GetDC(hwnd);

	::GetClientRect(hwnd, &_rect);
	_hdcBack = ::CreateCompatibleDC(_hdc); // _hdc와 호환되는 dc 생성
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom); // hdc와 호환되는 비트맵 생성
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);
	::DeleteObject(prev);

	GET_SINGLE(TimeManager)->init();
	GET_SINGLE(InputManager)->init(hwnd);
	GET_SINGLE(SceneManager)->Init();
	
	// 표시할 씬 타입 초기화(dev scene)
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::DevScene);
}

void Game::Update()
{
	// frame 계산
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SceneManager)->Update();
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
	GET_SINGLE(SceneManager)->Render(_hdc);

	//double Buffering
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY); // 비트 블릿 : 고속 복사
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}
