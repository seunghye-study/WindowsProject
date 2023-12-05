#include "pch.h"
#include "FlipbookActor.h"

#include "Sprite.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "Flipbook.h"

FlipbookActor::FlipbookActor()
{
}

FlipbookActor::~FlipbookActor()
{
}

void FlipbookActor::BeginPlay()
{
	Super::BeginPlay();
}

void FlipbookActor::Tick()
{
	Super::Tick();

	if (_flipbook == nullptr) return;

	const FlipbookInfo& info = _flipbook->GetInfo();
	if (info.loop == false && _idx == info.end) return;

	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	_sumTime += deltaTime;

	int32 frameCount = (info.end - info.start + 1);
	info.duration / frameCount;
}

void FlipbookActor::Render(HDC hdc)
{
	Super::Render(hdc);
}

void FlipbookActor::SetFlipbook(Flipbook* flipbook)
{
	if (flipbook && _flipbook == flipbook)
		return;


	_flipbook = flipbook;
	Reset();
}

void FlipbookActor::Reset()
{
	_sumTime = 0.f;
	_idx = _flipbook->GetInfo().start;
}
