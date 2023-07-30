#include "pch.h"
#include "InputManager.h"

void InputManager::init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	//::GetAsyncKeyState()

	BYTE asciiKeys[KEY_TYPE_COUNT] = {};
	// 모든 키보드 키의 상태를 가져온다
	if (::GetKeyboardState(asciiKeys) == false)
		return;

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// 키가 눌려있으면 true
		if (asciiKeys[key] & 0x80)
		{
			KeyState& state = _states[key];

			
			// Press 또는 Down 이었다면 > Press
			// None 이었다면 > Down
			// 이전 프레임에 키를 누른 상태면 press
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else // 아니라면 키를 누른 순간으로 변경
				state = KeyState::Down;
		}
		else // 키가 눌려있지 않다면 
		{
			KeyState& state = _states[key];

			// 이전 프레임에서 키를 누른 상태였다면 Up
			// press / down > up
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Up;
			// 아니라면 그냥 아무것도 아닌 상태로 변경
			else
				state = KeyState::None;
		}
	}

	// Mouse
	::GetCursorPos(&_mousePos); //커서의 좌표를 알아옴
	::ScreenToClient(_hwnd, &_mousePos); // 창 기준의 마우스 포인터 위치
}

