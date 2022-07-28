#pragma once
#include <cstdint>
#include <unordered_map>

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;

#include "class/Class.h"
typedef std::unordered_map<char*, Class> ClassMap;

#include "class/method/methodinfo.h"
typedef std::unordered_map<char*, MethodInfo> MethodMap;
