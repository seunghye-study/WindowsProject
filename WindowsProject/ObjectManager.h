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

	//객체생성
public:
	template<typename T>
	T* CreateObject()
	{
		// type trait
		// 컴파일 타임에 오브젝트 타입이여야 한다는 것을 확인해줌
		//static_assert(std::is_convertible_v<T*, Object*>);
		T* object = new T();

		//T가 뭔줄알고 오류가 안뜸?
		// -> 실행해봤을때 init이 있으면 그냥 돌아감
		// 없으면 퉤 뱉어줌 --> 템플릿이 애매한 점
		object->Init();
		return object;
	}

public:
	vector<Object*> _objects;
};

