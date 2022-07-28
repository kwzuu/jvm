#pragma once
#include "../../types.h"
#include "../attribute/attributeinfo.h"
//
// Created by lexi on 2022-07-27.
//

struct MethodInfo {
    u2                         access_flags;
    u2                         name_index;
    u2                         descriptor_index;
    u2                         attributes_count;
    std::vector<AttributeInfo> attributes;
};
