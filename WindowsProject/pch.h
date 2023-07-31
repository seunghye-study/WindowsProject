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
#include <format>
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

#define _CRTDEFB_MAP_ALLOC

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG
