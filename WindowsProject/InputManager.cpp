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
	// ��� Ű���� Ű�� ���¸� �����´�
	if (::GetKeyboardState(asciiKeys) == false)
		return;

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// Ű�� ���������� true
		if (asciiKeys[key] & 0x80)
		{
			KeyState& state = _states[key];

			
			// Press �Ǵ� Down �̾��ٸ� > Press
			// None �̾��ٸ� > Down
			// ���� �����ӿ� Ű�� ���� ���¸� press
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else // �ƴ϶�� Ű�� ���� �������� ����
				state = KeyState::Down;
		}
		else // Ű�� �������� �ʴٸ� 
		{
			KeyState& state = _states[key];

			// ���� �����ӿ��� Ű�� ���� ���¿��ٸ� Up
			// press / down > up
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Up;
			// �ƴ϶�� �׳� �ƹ��͵� �ƴ� ���·� ����
			else
				state = KeyState::None;
		}
	}

	// Mouse
	::GetCursorPos(&_mousePos); //Ŀ���� ��ǥ�� �˾ƿ�
	::ScreenToClient(_hwnd, &_mousePos); // â ������ ���콺 ������ ��ġ
}

