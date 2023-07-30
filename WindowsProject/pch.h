#pragma once

#include "Types.h"
#include "Define.h"
#include "Enum.h"

#include <Windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>


using namespace std;

#include <format>

#define _CRTDEFB_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG