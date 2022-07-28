#pragma once
//
// Created by lexi on 2022-07-27.
//
#include <vector>
#include "../attribute/attributeinfo.h"
#include "../../types.h"

struct FieldInfo
{
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    std::vector<AttributeInfo> attributes;
};