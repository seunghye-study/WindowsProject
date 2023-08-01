#pragma once
#include <cmath>
using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 =unsigned __int16;
using uint32 =unsigned __int32;
using uint64 =unsigned __int64;

struct Stat
{
	int32 hp = 0;
	int32 maxHp = 0;
	float speed = 0;
};


// position vector
struct Vector
{
	Vector() {}
	Vector(float x, float y) : x(x), y(y) {}
	Vector(POINT pt) : x((float)pt.x), y((float)pt.y) {}

	Vector operator+(const Vector& other)
	{
		Vector ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}

	Vector operator-(const Vector& other)
	{
		Vector ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}

	Vector operator*(float value)
	{
		Vector ret;
		ret.x = x * value;
		ret.y = y * value;
		return ret;
	}

	void operator+=(const Vector& other)
	{
		x += other.x;
		y += other.y;
	}

	void operator-=(const Vector& other)
	{
		x -= other.x;
		y -= other.y;
	}

	void operator*=(const Vector& other)
	{
		x *= other.x;
		y *= other.y;
	}

	// vector magnitude
	float LengthSquared() // 길이 제곱
	{
		// 루트 계산비용이 비싸서 자주 사용
		return x * x + y * y;
	}
	float Length()
	{
		return ::sqrt(LengthSquared());
	}

	// 정규화 (중요)
	void Normalize()
	{
		float length = Length();
		
		if (length < 0.00000000f) return;
		x /= length;
		y /= length;
	}

	// 내적
	float Dot(Vector other)
	{
		return x * other.x + y * other.y;
	}

	//외적
	float Cross(Vector other)
	{
		return x * other.y - other.x * y;
	}

	float x = 0;
	float y = 0;
};

using Pos = Vector;