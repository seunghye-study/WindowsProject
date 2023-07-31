#pragma once

class Object;

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);
	~ObjectManager();
	void Add(Object* object);
	void Remove(Object* object);
	void Clear();
	const vector<Object*>& GetObjects() { return _objects; }

	//��ü����
public:
	template<typename T>
	T* CreateObject()
	{
		// type trait
		// ������ Ÿ�ӿ� ������Ʈ Ÿ���̿��� �Ѵٴ� ���� Ȯ������
		//static_assert(std::is_convertible_v<T*, Object*>);
		T* object = new T();

		//T�� ���پ˰� ������ �ȶ�?
		// -> �����غ����� init�� ������ �׳� ���ư�
		// ������ ơ ����� --> ���ø��� �ָ��� ��
		object->Init();
		return object;
	}

public:
	vector<Object*> _objects;
};

