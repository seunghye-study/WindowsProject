#pragma once

enum class KeyState
{
	None,
	Press,
	Down,
	Up,

	end
};

enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D'
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX+ 1), // 256개
	KEY_STATE_COUNT = static_cast<int32>(KeyState::end)
};

class InputManager
{
	DECLARE_SINGLE(InputManager);
public:
	void init(HWND hwnd);
	void Update();

	// 키보드 누르고 있을 때
	bool GetButton(KeyType key) { return GetState(key) == KeyState::Press; }
	// 처음 눌렀을 때
	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }
	// 눌렀다가 뗄 때
	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }
	POINT GetMousePos() { return _mousePos; }
private:
	KeyState GetState(KeyType key) { return _states[static_cast<int32>(key)]; }

private:
	HWND _hwnd = 0;
	vector<KeyState> _states;
	POINT _mousePos;
};

