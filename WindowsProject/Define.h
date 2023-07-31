#pragma once


// ´ÜÁ¡ : µð¹ö±ë
#define DECLARE_SINGLE(classname)		\
public:									\
	static classname* GetInstance()		\
	{									\
		static classname s_instance;	\
		return &s_instance;				\
	}									\
protected:								\
	classname() {}						\

#define GET_SINGLE(classname)	classname::GetInstance()

#define SAFE_DELETE(ptr)	\
	if(ptr)					\
	{						\
		delete ptr;			\
		ptr = nullptr;		\
	}						