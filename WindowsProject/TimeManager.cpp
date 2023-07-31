#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	// ms�� �ʸ� ��ȯ, ���е��� ��¦ ������
	//::GetTickCount64();

	// cpu clock �� ���ļ��� ����� �ð� ��ȯ
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_prevCount)); // CPU Ŭ��
}

void TimeManager::Update()
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency); // cpuŬ��/���ļ�
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
