#include "pch.h"
#include "ObjectManager.h"
#include "Object.h"

ObjectManager::~ObjectManager()
{
	Clear();
}

void ObjectManager::Add(Object* object)
{
	if (object == nullptr) return;

	auto findit = std::find(_objects.begin(), _objects.end(), object);

	if (findit != _objects.end()) return;

	_objects.push_back(object);
}

void ObjectManager::Remove(Object* object)
{
	if (object == nullptr)
		return;

	// remove 이상한점 : 없애는게 아니고 뒤로 보내서 찌끄레기를 남김..
	auto it = std::remove(_objects.begin(), _objects.end(), object);
	_objects.erase(it);
	// TODO : 괜찮은가?
	delete object;
}

void ObjectManager::Clear()
{

}
