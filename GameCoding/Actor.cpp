#include "pch.h"
#include "Actor.h"

Actor::Actor()
{

}

Actor::~Actor()
{
}

void Actor::BeginPlay()
{
}

void Actor::Tick()
{
}


void Actor::Render(HDC hdc)
{

	for (Component* component : _components)
	{
		component->BeginPlay();
	}
}

void Actor::AddComponent(Component* component)
{
	if (component == nullptr)
		return;

	component->SetOwner(this);
	_components.push_back(component);
}

void Actor::RemoveComponent(Component* component)
{
	auto findit = std::find(_components.begin(), _components.end(), component);
	if (findit == _components.end())
		return;

	_components.erase(findit);
}
