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
}

void FlipbookActor::Render(HDC hdc)
{
	Super::Render(hdc);
}

void FlipbookActor::SetFlipbook(Flipbook* flipbook)
{
	_flipbook = flipbook;
	Reset();
}

void FlipbookActor::Reset()
{
	_sumTime = 0.f;
	_idx = _flipbook->GetInfo().start;
	_flipbook->
}
