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

	// remove �̻����� : ���ִ°� �ƴϰ� �ڷ� ������ ������⸦ ����..
	auto it = std::remove(_objects.begin(), _objects.end(), object);
	_objects.erase(it);
	// TODO : ��������?
	delete object;
}

void ObjectManager::Clear()
{

}
