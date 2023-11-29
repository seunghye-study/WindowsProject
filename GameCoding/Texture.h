#pragma once
#include "ResourceBase.h"

class Texture : public ResourceBase
{
public:
	Texture();
	virtual ~Texture();

public:
	Texture*		LoadBmp(HWND hwnd, const wstring& path);
	HDC				GetDC();
	void			SetSize(Vec2Int size) { _size = size; }
	Vec2Int			GetSize() { return _size; }
	void			SetTransparent(uint32 transparent) { _transparent = transparent; }
	uint32			GetTransparent() { return _transparent; };
private:
	HDC				_hdc = {};
	HBITMAP			_bitmap = {};
	Vec2Int			_size = {};

	 // rgb가 아니라 rgba(알파 속성이 있으면)이면 필요없다
	uint32			_transparent = RGB(255, 0, 255);
};

