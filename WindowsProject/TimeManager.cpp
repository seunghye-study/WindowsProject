#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	// ms로 초를 반환, 정밀도가 살짝 떨어짐
	//::GetTickCount64();

	// cpu clock 과 주파수로 경과된 시간 반환
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_prevCount)); // CPU 클럭
}

void TimeManager::Update()
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency); // cpu클럭/주파수
	_prevCount = currentCount;

	_frameCount++;
	_frameTime += _deltaTime;

	if (_frameTime >= 1.f)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);
		_frameTime = 0.f;
		_frameCount = 0;
	}
}
