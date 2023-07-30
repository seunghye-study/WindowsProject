#pragma once
class Game
{
public:
	Game();
	~Game();

public:
	void init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc = {};

private:
	// double buffering
	RECT _rect;
	HDC _hdcBack = {};
	HBITMAP _bmpBack = {};
};

